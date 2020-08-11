#include "guiwindow.h"
#include "ui_guiwindow.h"
#include "openglwindow.h"
#include <QDebug>


#define COMBOBOX_NUM    (2)

// Hanh Nhi
using namespace cv;
using namespace std;
using namespace dnn;
/*--GUI--*/
const char* comboBox_Name[COMBOBOX_NUM] = { "comboBox_Comport","comboBox_Baudrate", };

/*--Robot--*/
double Zhigh = 120.0;
double Zlow = 38;
double Xplace = 240;
double Yplace = -170;
double roll_place = -90;
double roll_pick;
bool isFree = true;
position target;
int collum_jp = 0;
int collum_vn = 0;
int target_success_jp = 0;
int target_success_vn = 0;
/*--Camera--*/
vector<String> getOutputsNames(const Net& net);
extern VideoCapture cap;
extern Mat blob;
extern Net net;
extern vector<string> classes;
// Network Params
float confThreshold = 0.95; // Confidence threshold
float nmsThreshold = 0.5;  // Non-maximum suppression threshold
int inpWidth = 416;        // Width of network's input image
int inpHeight = 416;       // Height of network's input image
// Calibration Params
const double W11 = 144.606588, W12 = -225.306101;
const double W21 = 0.024040891, W22 = 0.741709983;
const double W31 = 0.730069443, W32 = 0.030124663;
// ROI
int count_mouse = 0;
bool flag_ROI = false;
int x_pos[2];
int y_pos[2];
// Object
int last_x, last_y, last_roll;

// Get the names of the output layers
GuiWindow::GuiWindow(QWidget *parent) :
	ui(new Ui::GuiWindow)
	
{
    ui->setupUi(this);

	// Serial for uart
	controller = new RobotControll(this);
	
	gui_init();
	robotInit();
	// Timer for update position
	timer_CAM = new QTimer(this);
	connect(timer_CAM, &QTimer::timeout, this, &GuiWindow::timer_CAM_handle);	
	// Object
	object = new Object();
	timer_OBJECT = new QTimer(this);
	connect(timer_OBJECT, &QTimer::timeout, this, &GuiWindow::timer_OBJECT_handle);
	
}

GuiWindow::~GuiWindow()
{
    delete ui;
	delete object;
}

/*--CAMERA--*/
bool GuiWindow::detectObject(Mat frame, Mat &out)
{
	if (flag_ROI)
	{
		Mat matROI;
		selectROI(frame, matROI);
		// Create a 4D blob from a frame.
		blobFromImage(matROI, blob, 1 / 255.0, Size(inpWidth, inpHeight),
						Scalar(0, 0, 0), true, false);// tao ra blob tu hinh input 
													  //true swap B ,R 
													  //false :co cat hinh ra hay khong
		//Sets the input to the network																								 //Sets the input to the network
		net.setInput(blob);
		// Runs the forward pass to get output of the output layers
		vector<Mat> outs; // local  variable
		net.forward(outs, getOutputsNames(net)); //chay mang noron
												 // Remove the bounding boxes with low 
												 //confidence
		postProcess(matROI, outs); // get outs into frame
		//imshow("Detect Object", matROI); // show frame to camera window
		out = matROI.clone();
		return true;
	}
	else
	{
		out = frame.clone();
		return false;
	}

}

// Get the names of the output layers
vector<String>  getOutputsNames(const Net& net)
{
	static vector<String> names;
	if (names.empty())
	{
		//Get the indices of the output layers, i.e. the layers with unconnected outputs
		vector<int> outLayers = net.getUnconnectedOutLayers();

		//get the names of all the layers in the network
		vector<String> layersNames = net.getLayerNames();

		// Get the names of the output layers in names
		names.resize(outLayers.size());
		for (size_t i = 0; i < outLayers.size(); ++i)
			names[i] = layersNames[outLayers[i] - 1];
	}
	return names;
}

void GuiWindow::postProcess(Mat& frame, const vector<Mat>& outs)
{
	vector<double> X, Y, ANGLE_TRUE, X_TRUE, Y_TRUE;
	vector<int> classIds, ID_TRUE;
	vector<float> confidences;
	vector<Rect> boxes;
	//ui->textEdit_Position->append(tr("Outsize: %1 \n").arg(outs.size()));
	for (size_t i = 0; i < outs.size(); ++i)
	{
		// Scan through all the bounding boxes output from the network and keep only the
		// ones with high confidence scores. Assign the box's class label as the class
		// with the highest score for the box.
		float* data = (float*)outs[i].data;
		for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols)
		{
			Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
			Point classIdPoint;
			double confidence;
			// Get the value and location of the maximum score
			minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
			if (confidence > confThreshold)
			{
				int x_roi = (int)(data[0] * frame.cols);
				int y_roi = (int)(data[1] * frame.rows);

				int width = (int)(data[2] * frame.cols);
				int height = (int)(data[3] * frame.rows);
				int left = x_roi - width / 2;
				int top = y_roi - height / 2;

				classIds.push_back(classIdPoint.x);
				confidences.push_back((float)confidence);
				boxes.push_back(Rect(left, top, width, height));
			}
		}
	}
	//ui->textEdit_Position->append(tr("X size: %1 \n").arg(X.size()));
	// Perform non maximum suppression to eliminate redundant overlapping 
	//boxes with lower confidences
	vector<int> indices;
	NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);
	
	for (size_t i = 0; i < indices.size(); ++i)
	{
		double angle;
		double x, y;
		int idx = indices[i];
		Rect box = boxes[idx];
		if (drawPred(classIds[idx], confidences[idx], box.x, box.y,
			box.x + box.width, box.y + box.height, frame, angle, x ,y))
		{
			ID_TRUE.push_back(classIds.at(idx));
			x = x + x_pos[0];
			y = y + y_pos[0];
			double x_absolute = W11 + W21*x + W31*y;
			double y_absolute = W12 + W22*x + W32*y;
			X_TRUE.push_back(x_absolute);
			Y_TRUE.push_back(y_absolute);
			ANGLE_TRUE.push_back(angle);
			ui->textEdit_Inform->insertPlainText(tr("Thiet = %1 %2")
				.arg(x_absolute).arg(y_absolute));
		}
	}


	if (state_robot == STATE_READY)
	{
		for (int i = 0; i < ANGLE_TRUE.size(); i++)
		{
			object->addPosition(ID_TRUE.at(i), X_TRUE.at(i),
				Y_TRUE.at(i), ANGLE_TRUE.at(i));
			displayPosition(X_TRUE.at(i),
				Y_TRUE.at(i), ANGLE_TRUE.at(i));
		}
	}
}

// Draw the predicted bounding box
bool GuiWindow::drawPred(int classId, double conf, int left, int top, int right, int bottom, 
				Mat& frame, double &angle, double &x, double &y)
{
	ui->textEdit_Inform->clear();
	float W1 = 89.34795488, W2 = -1.00310605;
	// BEFORE CUT IMAGE CONTAIN BOUNDING BOX
	Mat imageCrop;
	Rect2d r;
	r.x = left - 10;
	r.y = top - 10;
	r.width = right - left + 20;  //right-left is %d //r.width  is float 
	r.height = bottom - top + 20;
	//ui->textEdit_Inform->insertPlainText(tr("width: %1 pixel\n").arg(right - left));
	//ui->textEdit_Inform->insertPlainText(tr("height: %1 pixel\n").arg(bottom - top));
	if (r.x >= 0
		&& r.y >= 0
		&& r.width >= 0
		&& r.height >= 0
		&& r.x + r.width <= frame.cols
		&&  r.y + r.height <= frame.rows)
	{
		imageCrop = frame(r);
		Mat gray;
		cvtColor(imageCrop, gray, COLOR_BGR2GRAY);
		//imshow(" gray ", gray);
		//**Threshold**
		Mat frame_threshold;
		int max_value = 255;  
		int method = ADAPTIVE_THRESH_MEAN_C;
		int threshold_type = 0;
		int blockSize = 3;
		double conSub = 2;
		adaptiveThreshold(gray, frame_threshold, max_value, method, threshold_type, blockSize, conSub);
		
		//**Filter Blur**
		Mat frame_filter;
		blur(frame_threshold, frame_filter, Size(3, 3));

		//**Draw circle**
		circle(frame_filter, Point(r.width / 2, r.height / 2), 18, Scalar(255, 255, 255), -1, LINE_8);
	
		//**Detect edges using canny**
		Mat canny;
		Canny(frame_filter, canny, 300, 600, 3);
		imshow("Canny", canny);
		
		//**HoughLines**
		vector<Vec4i> lines_angle;
		vector<Vec4i> lines_intersection;
		vector<Vec3f> params_angle;
		vector<Vec3f> params_intersection;
		vector<Point> corners_angle;
		vector<Point> corners_intersection;
		vector<Point> corners_line1;
		vector<Point> corners_line2;
		vector<Point> corners_group1;
		vector<Point> corners_group2;
		vector<Point> corners_group3;
		vector<Point> corners_group4;
		// 2 line
		HoughLinesP(canny, lines_angle, 1, CV_PI / 180, 30, 50, 5);
		// 4 line
		HoughLinesP(canny, lines_intersection, 1, CV_PI / 180, 10, 10, 5);

		//**Draw a rectangle displaying the bounding box**
		rectangle(frame, Point(left, top), Point(right, bottom), Scalar(255, 178, 50), 3);

		//Get the label for the class name and its confidence
		string label = format("%.2f", conf);
		if (!classes.empty())
		{
			CV_Assert(classId < (int)classes.size());
			label = classes[classId] + ":" + label;  //ghep chuoi
		}

		//Display the label at the top of the bounding box
		int baseLine;
		Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
		top = max(top, labelSize.height);
		rectangle(frame, Point(left, top - round(labelSize.height)),
					Point(left + round(labelSize.width), top + baseLine), Scalar(255, 255, 255), FILLED);
		putText(frame, label, Point(left, top), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0), 1);

		//Calculate arctan
		Mat drawing = Mat::zeros(r.height, r.width, CV_8UC3);
		Mat drawing_2 = Mat::zeros(r.height, r.width, CV_8UC3);
		angle = 0;
		/*---  Angle  ---*/
		if (lines_angle.size()  <= 1)
		{
			return false;
		}
		else
		{
			for (size_t i = 0; i < lines_angle.size(); i++)
			{
				params_angle.push_back(calcParams(Point(lines_angle[i][0], lines_angle[i][1]),
					Point(lines_angle[i][2], lines_angle[i][3])));
			}

			for (int i = 0; i < params_angle.size(); i++)
			{
				for (int j = i; j < params_angle.size(); j++)
				{
					Point intersec = findIntersection(params_angle[i], params_angle[j]);
					if ((intersec.x > 0)
						&& (intersec.y > 0)
						&& (intersec.x < canny.cols)
						&& (intersec.y < canny.rows))
					{
						corners_angle.push_back(intersec);
					}
				}
			}

			// Check corners is exist
			if (corners_angle.size() != 0)
			{
				return false;
			}
		}
		// Compute angle thought atan2
		for (size_t i = 0; i < lines_angle.size(); i++)
		{
			if (i == 0) {
				line(drawing, Point(lines_angle[i][0], lines_angle[i][1]),
					Point(lines_angle[i][2], lines_angle[i][3]), Scalar(255, 255, 255), 1, LINE_8);
			}
			else
			{
				line(drawing, Point(lines_angle[i][0], lines_angle[i][1]),
					Point(lines_angle[i][2], lines_angle[i][3]), Scalar(0, 0, 255), 1, LINE_8);
			}
			angle += atan2((double)lines_angle[i][3] - lines_angle[i][1],
				(double)lines_angle[i][2] - lines_angle[i][0]);
		}
		angle /= lines_angle.size();
		angle = W1 + (angle * 180 / CV_PI)*W2;

		/*-- Intersection --*/
		if (lines_intersection.size() < 4)
		{
			return false;
		}
		else
		{
			for (size_t i = 0; i < lines_intersection.size(); i++)
			{
				line(drawing_2, Point(lines_intersection[i][0], lines_intersection[i][1]),
					Point(lines_intersection[i][2], lines_intersection[i][3]), Scalar(0, 0, 255), 1, LINE_8);
				params_intersection.push_back(calcParams(Point(lines_intersection[i][0], lines_intersection[i][1]),
					Point(lines_intersection[i][2], lines_intersection[i][3])));
			}

			for (int i = 0; i < params_intersection.size(); i++)
			{
				for (int j = i; j < params_intersection.size(); j++)
				{
					Point intersec = findIntersection(params_intersection[i], params_intersection[j]);
					if ((intersec.x > 0)
						&& (intersec.y > 0)
						&& (intersec.x < canny.cols)
						&& (intersec.y < canny.rows))
					{
						corners_intersection.push_back(intersec);
					}
				}
			}
			ui->textEdit_Inform->insertPlainText(tr("Corner: %1 point\n").arg(corners_intersection.size()));
			
			if (corners_intersection.size() < 4)
			{
				return false;
			}

			
			
			for (int j = 0; j < corners_intersection.size(); j++)
			{
				double distance;
				distance = disPoint2Line(params_angle.at(0), corners_intersection.at(j));
				if (distance < 5)
				{
					corners_line1.push_back(corners_intersection.at(j));
					
				}
				else
				{
					corners_line2.push_back(corners_intersection.at(j));
				
				}
			}
			ui->textEdit_Inform->insertPlainText(tr("line 1: %1 point\n").arg(corners_line1.size()));
			ui->textEdit_Inform->insertPlainText(tr("line 2: %1 point\n").arg(corners_line2.size()));
			// Line 1
			corners_group1.push_back(corners_line1.at(0));
			for (int i = 1; i < corners_line1.size(); i++)
			{
				double distance;
				distance = disPoint2Point(corners_line1.at(0), corners_line1.at(i));
				if (distance < 5)
				{
					corners_group1.push_back(corners_line1.at(i));	
				}
				else if (distance > 49)
				{
					corners_group2.push_back(corners_line1.at(i));	
				}
			}

			// Line 2
			corners_group3.push_back(corners_line2.at(0));
			for (int i = 1; i < corners_line2.size(); i++)
			{
				double distance;
				distance = disPoint2Point(corners_line2.at(0), corners_line2.at(i));
				if (distance < 5)
				{
					corners_group3.push_back(corners_line2.at(i));
				}
				else if (distance > 49 && distance < 58)
				{
					corners_group4.push_back(corners_line2.at(i));	
				}
			}
			float sum_x1 = 0, sum_y1 = 0, sum_x2 = 0, sum_y2 = 0;
			float sum_x3 = 0, sum_y3 = 0, sum_x4 = 0, sum_y4 = 0, sum_xCenter = 0, sum_yCenter = 0;
			float avr_x1, avr_y1, avr_x2, avr_y2, avr_x3, avr_y3, avr_x4, avr_y4, avr_xCenter, avr_yCenter;
			// Group 1
			for (int i = 0; i < corners_group1.size(); i++)
			{ 
				Point point = corners_group1.at(i);
				sum_x1 += point.x;
				sum_y1 += point.y;
				circle(drawing, corners_group1[i], 3, Scalar(204, 0, 102));
			}
			// Group 2
			for (int i = 0; i < corners_group2.size(); i++)
			{
				Point point = corners_group2.at(i);
				sum_x2 += point.x;
				sum_y2 += point.y;
				circle(drawing, corners_group2[i], 3, Scalar(51, 102, 0));
			}
			// Group 3
			for (int i = 0; i < corners_group3.size(); i++)
			{
				Point point = corners_group3.at(i);
				sum_x3 += point.x;
				sum_y3 += point.y;
				circle(drawing, corners_group3[i], 3, Scalar(255, 153, 0));
			}
			// Group 4
			for (int i = 0; i < corners_group4.size(); i++)
			{
				Point point = corners_group4.at(i);
				sum_x4 += point.x;
				sum_y4 += point.y;
				circle(drawing, corners_group4[i], 3, Scalar(0, 0, 200));
			}

			if (corners_group1.size() == 0
				|| corners_group2.size() == 0
				|| corners_group3.size() == 0
				|| corners_group4.size() == 0)
			{
				return false;
			}

			avr_x1 = sum_x1 / corners_group1.size();
			avr_y1 = sum_y1 / corners_group1.size();
			avr_x2 = sum_x2 / corners_group2.size();
			avr_y2 = sum_y2 / corners_group2.size();
			avr_x3 = sum_x3 / corners_group3.size();
			avr_y3 = sum_y3 / corners_group3.size();
			avr_x4 = sum_x4 / corners_group4.size();
			avr_y4 = sum_y4 / corners_group4.size();
			//-----------^ o ^-------------
			avr_xCenter = (avr_x1 + avr_x2 + avr_x3 + avr_x4) / 4;
			avr_yCenter = (avr_y1 + avr_y2 + avr_y3 + avr_y4) / 4;

			//ui->textEdit_Inform->insertPlainText(tr("Center = %1 %2 \n")
				//.arg(avr_xCenter).arg(avr_yCenter));

			Point A, B, C, D, Center;
			A.x = int(avr_x1);
			A.y = int(avr_y1);
			B.x = int(avr_x2);
			B.y = int(avr_y2);
			C.x = int(avr_x3);
			C.y = int(avr_y3);
			D.x = int(avr_x4);
			D.y = int(avr_y4);
			Center.x = int(avr_xCenter);
			Center.y = int(avr_yCenter);

			//circle(drawing_2, A, 3, Scalar(204, 0, 102));
			//circle(drawing_2, B, 3, Scalar(51, 102, 0));
			//circle(drawing_2, C, 3, Scalar(255, 153, 0));
			//circle(drawing_2, D, 3, Scalar(0, 0, 200));
			circle(drawing, Center, 3, Scalar(255, 255, 255));

			//ui->textEdit_Inform->insertPlainText(tr("Pixel = %1 %2")
				//.arg(Center.x).arg(Center.y));

			x = avr_xCenter + r.x;
			y = avr_yCenter + r.y;


			imshow("Object_1", drawing);
			imshow("Object_2", drawing_2);

		}
		return true;
	}
	return false;
}

Vec3f GuiWindow::calcParams(Point2f p1, Point2f p2)
{
	float a, b, c;
	if (p2.y - p1.y == 0)
	{
		a = 0.0f;
		b = -1.0f;
	}
	else if (p2.x - p1.x == 0)
	{
		a = -1.0f;
		b = 0.0f;
	}
	else
	{
		a = (p2.y - p1.y) / (p2.x - p1.x);
		b = -1.0f;
	}

	c = (-a * p1.x) - b * p1.y;
	return(Vec3f(a, b, c));
}

Point  GuiWindow::findIntersection(Vec3f params1, Vec3f params2)
{
	float x, y;
	float det = params1[0] * params2[1] - params2[0] * params1[1];
	if (det < 0.5f && det > -0.5f) // lines are approximately parallel
	{
		return(Point(-1, -1));
	}
	else
	{
		x = (params2[1] * -params1[2] - params1[1] * -params2[2]) / det;
		y = (params1[0] * -params2[2] - params2[0] * -params1[2]) / det;
	}
	return(Point(x, y));
}

double GuiWindow::disPoint2Point(Point A, Point B)
{
	double dx, dy, distance;
	dx = A.x - B.x;
	dy = A.y - B.y;
	distance = sqrt(dx*dx + dy*dy);
	return distance;
}

double GuiWindow::disPoint2Line(Vec3f param, Point A)
{
	double num, den, distance;
	num = fabs(param[0] * A.x + param[1] * A.y + param[2]);
	den = sqrt(param[0] * param[0] + param[1] * param[1]);
	distance = num / den;
	return distance;
}

void GuiWindow::moveJoint(double centerX, double centerY, double Z, double roll)
{
	controller->robotMoveJoint(centerX, centerY, Z, roll);
}


void GuiWindow::selectROI(Mat frame, Mat &matROI)
{
		Rect2d ROI;
		Point pt1 = Point(x_pos[0], y_pos[0]);
		Point pt2 = Point(x_pos[1], y_pos[1]);
		ROI.x = min(pt1.x, pt2.x);
		ROI.y = min(pt1.y, pt2.y);
		ROI.width = max(pt1.x, pt2.x) - ROI.x;
		ROI.height = max(pt1.y, pt2.y) - ROI.y;

		if (ROI.x >= 0
			&& ROI.y >= 0
			&& ROI.width >= 0
			&& ROI.height >= 0
			&& ROI.x + ROI.width <= frame.cols
			&&  ROI.y + ROI.height <= frame.rows
			)
		{
			matROI = frame(ROI);
		}
		
}

void GuiWindow::mousePoints(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		x_pos[count_mouse] = x;
		y_pos[count_mouse] = y;
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		count_mouse++;
		if (count_mouse >= 2)
		{
			flag_ROI = true;
			count_mouse = 0;
			destroyAllWindows();
		}
	}
}

void GuiWindow::showFrame(bool dynamic)
{
	if (dynamic)
	{
		Mat frame, matROI,out, out_resize;
		cap >> frame;
		if (frame.empty())
		{
			printf("ERROR: Khong the mo camera\r\n");
			return;
		}
		detectObject(frame, out);
		Size size(260, 200);
		cv::resize(out, out_resize,size);
		showCamera(out_resize, QImage::Format_RGB888);
	}
}

void GuiWindow::showCamera(cv::Mat img, QImage::Format format)
{
	Mat temp;
	cvtColor(img, temp, COLOR_BGR2RGB);
	QImage* qimage = new QImage(temp.data, temp.cols, temp.rows, temp.step, format);
	ui->label_Camera->setFixedSize(qimage->size());
	ui->label_Camera->setPixmap(QPixmap::fromImage(*qimage));
	delete qimage;
}

void GuiWindow::timer_CAM_handle()
{
	showFrame(true);
	//timer_CAM->start(500);
}

void GuiWindow::timer_OBJECT_handle()
{
	if (object->isNotEmpty() && (state_robot == STATE_READY))
	{
		for (int i = 0; i < object->size(); i++)
		{
			object->getPosition(target, i);
			if (((target.class_id == 0) && !japan_full) || ((target.class_id == 1) && !vietnam_full))
			{
				connect(controller, &RobotControll::commandWorkDone, this, &GuiWindow::pickAndPlace);
				connect(controller, &RobotControll::commandDeny, this, &GuiWindow::overWorkSpace);
				pickAndPlace();
				break;
			}
		}
	}
}

/*--ROBOT--*/
void GuiWindow::robotInit() 
{
	ui->comboBox_Baudrate->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
	ui->comboBox_Baudrate->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
	ui->comboBox_Baudrate->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
	ui->comboBox_Baudrate->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
	serial_updatePortName();
	serial_updateSetting();
	for (int i = 0; i < COMBOBOX_NUM; i++) {
		connect(this->findChild<QComboBox*>(comboBox_Name[i]), &QComboBox::currentTextChanged,
			this, &GuiWindow::serial_updateSetting, Qt::QueuedConnection);
	}
	
	timer_serial_comboBox = new QTimer(this);
	connect(timer_serial_comboBox, &QTimer::timeout, this, &GuiWindow::serial_updatePortName);
	timer_serial_comboBox->start(1000);

}

void GuiWindow::serial_openPort() {
	if (!controller->isOpen()) {
		controller->openComPort(portName);
		timer_serial_comboBox->stop();
		ui->comboBox_Baudrate->setEnabled(false);
		ui->comboBox_Comport->setEnabled(false);
		ui->pushButton_Connect->setText(tr("Disconnect"));
	}
	else {
		QMessageBox::critical(this, tr("Error"), "Close Comport SUCCESS");
	}
}

void GuiWindow::serial_closePort() {
	if (controller->isOpen()) {
		controller->closeComPort();
		ui->comboBox_Baudrate->setEnabled(true);
		ui->comboBox_Comport->setEnabled(true);
		ui->pushButton_Connect->setText("Connect");
		timer_serial_comboBox->start(1000);
	}
	else {
		QMessageBox::critical(this, tr("Error"), "Close Comport FAIL");
	}
}

void GuiWindow::serial_updatePortName() {
	const auto port_info = QSerialPortInfo::availablePorts();
	int count_port = port_info.count();
	int count_item = ui->comboBox_Comport->count();

	if (count_port < count_item) {
		for (int i = count_port; i < count_item; i++) {
			ui->comboBox_Comport->removeItem(i);
		}
		count_item = count_port;
	}
	else if (count_port > count_item) {
		for (int i = count_item; i < count_port; i++) {
			ui->comboBox_Comport->addItem(port_info.at(i).portName());
		}
	}
	for (int i = 0; i < count_item; i++) {
		if (port_info.at(i).portName() != ui->comboBox_Comport->itemText(i)) {
			ui->comboBox_Comport->removeItem(i);
			ui->comboBox_Comport->addItem(port_info.at(i).portName());
		}
	}
}

void GuiWindow::serial_updateSetting() {
	portName = ui->comboBox_Comport->currentText();
}

void GuiWindow::serial_handleError(QSerialPort::SerialPortError error)
{
	if (error == QSerialPort::ResourceError) {
		QMessageBox::critical(this, tr("Critical Error"), "Serial Error");
		serial_closePort();
	}
}

void GuiWindow::pickAndPlace()
{
	state_robot = static_cast<robotPickAndPlace_t>(static_cast<int>(state_robot) + 1);
	switch (state_robot) 
	{

		case STATE_PICK:
			{
				if (target.class_id == 0)
				{
					//ui->textEdit_Position->append(tr("JAPAN"));
				}
				else
				{
					//ui->textEdit_Position->append(tr("VIETNAM"));
				}
				displayPosition(target.x, target.y, target.angle);
				roll_pick = angleProcess(target.x, target.y, target.angle);
				if (roll_pick > 0)
				{
					roll_place = 90;
				}
				else
				{
					roll_place = -90;
				}
				controller->robotMoveJoint(target.x, target.y,
											Zhigh, roll_pick);
			}
		break;


		case STATE_DOWN1:
			{
				controller->robotMoveJoint(target.x, target.y,
											Zlow, roll_pick);
			}
		break;


		case STATE_HOLD:
			{
				controller->robotOutput(true);  
				output_robot = true;
				pickAndPlace();  // khong co command work done, phải gọi pickAndPlace tiep, tang len state_up1
			}
		break;


		case STATE_UP1:
			{
			controller->robotMoveJoint(target.x, target.y,
										Zhigh, roll_pick);
			}
		break;


		case STATE_PLACE:
			{	
				if (target.class_id == 0)
				{	
					controller->robotMoveJoint(Xplace , Yplace, Zhigh, roll_place);
				}
				else
				{
					controller->robotMoveJoint(Xplace + 50 , Yplace, Zhigh, roll_place);
				}
				
			}
		break;


		case STATE_DOWN2:
			{
				if (target.class_id == 0)
				{	
					controller->robotMoveJoint(Xplace , Yplace, Zlow + 5.5* target_success_jp, roll_place);
				}
				else
				{
					controller->robotMoveJoint(Xplace +50 , Yplace, Zlow + 5.5* target_success_vn, roll_place);
				}		
			}
		break;


		case STATE_DROP:
			{
				controller->robotOutput(false);
				output_robot = false;
				pickAndPlace(); 
				// khong co command work done, phải gọi pickAndPlace tiep, tang len state_up2
			}
		break;


		case STATE_UP2:
			{
				if (target.class_id == 0)
				{
					controller->robotMoveJoint(Xplace , Yplace, Zhigh, roll_place);
				}
				else
				{
					controller->robotMoveJoint(Xplace +50 , Yplace, Zhigh, roll_place);
				}	
			}
		break;


		case STATE_FINISH:
			{
				if (target.class_id == 0)
				{
					target_success_jp++;
					if (target_success_jp == 5)
					{
						ui->textEdit_Waring->insertPlainText("WARNING: FULL JAPAN COLLUMN");
						japan_full = true;
					}	
				}
				else
				{
					target_success_vn++;
					if (target_success_vn == 5)
					{
						ui->textEdit_Waring->insertPlainText("WARNING: FULL VIETNAM COLLUMN");
						vietnam_full = true;
					}
				}
				state_robot = STATE_READY;  
				object->clear();
				disconnect(controller, &RobotControll::commandWorkDone, this, &GuiWindow::pickAndPlace);
				disconnect(controller, &RobotControll::commandDeny, this, &GuiWindow::overWorkSpace);
			}
		break;
		default: {}
	}
}

void GuiWindow::overWorkSpace()
{
	ui->textEdit_Waring->insertPlainText("ERROR: Over workspace");
	ui->textEdit_Waring->insertPlainText("Skip Point:");
	ui->textEdit_Waring->insertPlainText(tr("X: %1\n Y: %2\n Phi: %3\n")
							.arg(target.x).arg(target.y).arg(target.angle));
	object->deletePosition(0);
	disconnect(controller, &RobotControll::commandWorkDone, this, &GuiWindow::pickAndPlace);
	state_robot = STATE_READY;
}

void GuiWindow::gui_init()
{
	ui->textEdit_Waring->ensureCursorVisible();
	ui->textEdit_Waring->ensureCursorVisible();

	//Icon
	QIcon Off("F:/HANH_NHI/Thesis_Nam_Nhi/LV/MelfaModel/Capture_OFF.JPG");
	ui->pushButton_StartCamera->setIcon(Off);
	ui->pushButton_StartCamera->setIconSize(QSize(30, 30));
	ui->pushButton_StartCamera->setCheckable(true);

	QPixmap p1 = QPixmap("F:/HANH_NHI/Thesis_Nam_Nhi/LV/MelfaModel/JP.JPG"); // load pixmap
			   // get label dimensions
	int w1 = ui->label_Japan->width();
	int h1 = ui->label_Japan->height();
	ui->label_Japan->setPixmap(p1.scaled(w1, h1, Qt::KeepAspectRatio));

	QPixmap p2 = QPixmap("F:/HANH_NHI/Thesis_Nam_Nhi/LV/MelfaModel/VN.JPG"); // load pixmap
																			// get label dimensions
	int w2 = ui->label_Vietnam->width();
	int h2 = ui->label_Vietnam->height();
	ui->label_Vietnam->setPixmap(p2.scaled(w2, h2, Qt::KeepAspectRatio));


	connect(ui->sliderVelocity, &QAbstractSlider::valueChanged,
		this, &GuiWindow::slide_Velocity);

	connect(ui->sliderAccerlerate, &QAbstractSlider::valueChanged,
		this, &GuiWindow::slide_Accelerate);

	connect(controller, &RobotControll::updatePosition, this, &GuiWindow::updatePosition);
}

void GuiWindow::slide_Velocity()
{
	ui->label_Velocity->setText(tr("VELOCITY: %1 %").arg((ui->sliderVelocity->value())));
	controller->setAccelerate(((double)ui->sliderVelocity->value())/100);
}

void GuiWindow::slide_Accelerate()
{
	ui->label_Accelerate->setText(tr("ACCELERATE: %1 %").arg((ui->sliderAccerlerate->value())));
	controller->setAccelerate(((double)ui->sliderAccerlerate->value())/100);
}
	

void GuiWindow::on_pushButton_Connect_clicked()
{
	if (ui->pushButton_Connect->text() == "Connect")
	{ 
		ui->textEdit_Waring->insertPlainText("WARNING: Robot is connecting\n");
		serial_openPort();
	}
	else 
	{
		ui->textEdit_Waring->insertPlainText("WARNING: Robot is disconnecting\n");
		serial_closePort();
	}
}

void GuiWindow::on_pushButton_Scan_clicked()
{
	ui->textEdit_Waring->insertPlainText("WARNING: Robot is scanning");
	controller->robotScanLimit();
}


void GuiWindow::on_pushButton_Home_clicked()
{ 
	ui->textEdit_Waring->insertPlainText("WARNING: Robot is at home status");
	timer_OBJECT->stop();
	disconnect(controller, &RobotControll::commandWorkDone, this, &GuiWindow::pickAndPlace);
	disconnect(controller, &RobotControll::commandDeny, this, &GuiWindow::overWorkSpace);
	state_robot = STATE_READY;
	object->clear();
	controller->robotOutput(false);
	controller->robotMoveHome();

}

void  GuiWindow::on_pushButton_Stop_clicked()
{
	ui->textEdit_Waring->insertPlainText("WARNING: Robot is stopping");
	timer_OBJECT->stop();
}

void GuiWindow::on_pushButton_StartCamera_toggled(bool checked)
{
	if (checked)
	{
		QIcon On("F:/HANH_NHI/Thesis_Nam_Nhi/LV/MelfaModel/Capture_ON.JPG");
		ui->pushButton_StartCamera->setIcon(On);
		ui->pushButton_StartCamera->setIconSize(QSize(20, 20));
		timer_CAM->start(200);
	}
	else
	{
		QIcon Off("F:/HANH_NHI/Thesis_Nam_Nhi/LV/MelfaModel/Capture_OFF.JPG");
		ui->pushButton_StartCamera->setIcon(Off);
		ui->pushButton_StartCamera->setIconSize(QSize(20, 20));
		timer_CAM->stop();
		ui->label_Camera->clear();
	}
}

void GuiWindow::on_pushButton_SetROI_clicked()
{	
	flag_ROI = false;
	Mat Select_Window;
	cap >> Select_Window;
	imshow("Camera", Select_Window);
	setMouseCallback("Camera", mousePoints, NULL);
}

void GuiWindow::on_pushButton_Start_clicked()
{
	ui->textEdit_Waring->insertPlainText("WARNING: Robot is starting");
	timer_OBJECT->start(200);
}

void GuiWindow::on_pushButton_Japan_Full_clicked()
{
	japan_full = false;
	target_success_jp = 0;
	ui->textEdit_Waring->insertPlainText("JAPAN COL IS CLEAR");
}

void GuiWindow::on_pushButton_Vietnam_Full_clicked()
{
	vietnam_full = false;
	target_success_vn = 0;
	ui->textEdit_Waring->insertPlainText("VIETNAM COL IS CLEAR");
}

void GuiWindow::displayPosition(double x, double y, double roll) 
{
	//ui->textEdit_Position->append(tr("X: %1 \nY: %2 \nPhi: %3").arg(x).arg(y).arg(roll));
}

void GuiWindow::updatePosition(double x, double y, double z, double roll,
	double var0, double var1, double var2, double var3,
	double lenght, double time_run, double time_total)
{
	ui->openGL->setAngle(var0, var1, var2, var3);
	ui->textEdit_Japan_Num->setText(tr("%1").arg(target_success_jp));
	ui->textEdit_Vietnam_Num->setText(tr("%1").arg(target_success_vn));
	ui->textEdit_X->setText(tr("%1").arg(x));
	ui->textEdit_Y->setText(tr("%1").arg(y));
	ui->textEdit_Z->setText(tr("%1").arg(z));
	ui->textEdit_Roll->setText(tr("%1").arg(roll));
	ui->textEdit_Theta1->setText(tr("%1").arg(var0));
	ui->textEdit_Theta2->setText(tr("%1").arg(var1));
	ui->textEdit_D3->setText(tr("%1").arg(var2));
	ui->textEdit_Theta4->setText(tr("%1").arg(var3));
}

double GuiWindow::angleProcess(double x, double y, double angle)
{
	if (x > 250 && fabs(angle) > 90)
	{
		if (angle > 0)
		{
			return (angle - 180);
		}
		else
		{
			return (180 + angle);
		}
	}
	else
	{
		return angle;
	}
}