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
double Zlow = 44.0;
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
float confThreshold = 0.9; // Confidence threshold
float nmsThreshold = 0.5;  // Non-maximum suppression threshold
int inpWidth = 416;        // Width of network's input image
int inpHeight = 416;       // Height of network's input image
// Calibration Params
const double W11 = 153.554757, W12 = -212.873131;
const double W21 = 0.0110744904, W22 = 0.718174295;
const double W31 = 0.706857752, W32 = 0.00278501969;
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
	//openGLWindow(new OpenGLWindow)
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
	timer_IDLE = new QTimer(this);
	connect(timer_OBJECT, &QTimer::timeout, this, &GuiWindow::timer_IDLE_handle);
	// Pain
	timer_PAIN = new QTimer(this);
	connect(timer_PAIN, &QTimer::timeout, this, &GuiWindow::timer_PAIN_handle);
	
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

				int x_cam = x_roi + x_pos[0];
				int y_cam = y_roi + y_pos[0];

				double x_absolute = W11 + W21*x_cam + W31*y_cam;
				double y_absolute = W12 + W22*x_cam + W32*y_cam;
				printf(" toa do x= %d, y = %d \r\n", x_absolute, y_absolute);

				X.push_back(x_absolute);
				Y.push_back(y_absolute);
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
		int idx = indices[i];
		Rect box = boxes[idx];
		if (drawPred(classIds[idx], confidences[idx], box.x, box.y,
			box.x + box.width, box.y + box.height, frame, angle))
		{
			ID_TRUE.push_back(classIds.at(idx));
			//ui->textEdit_Position->append(tr("ID CLASS: %1 \n").arg(classIds.at(idx)));
			X_TRUE.push_back(X.at(idx));
			Y_TRUE.push_back(Y.at(idx));
			ANGLE_TRUE.push_back(angle);
		}
	}
	if (ANGLE_TRUE.size() == 1)
	{
		if (k == 0)
		{
			timer_TRACKING.start();
		}
		curent_X = X_TRUE.at(0);
		curent_Y = Y_TRUE.at(0);
		curent_T = timer_TRACKING.elapsed();

		if (k == 2)
		{
			Point0_X = curent_X;
			Point0_Y = curent_Y;
		}

		if (k >= 2)
		{
			V_x = fabs((curent_X - last_X) / ((curent_T - last_T)*0.001));
			V_y = fabs((curent_Y - last_Y) / ((curent_T - last_T)*0.001));
		}

		//----------------update---------
		k++;
		last_X = curent_X;
		last_Y = curent_Y;
		last_T = curent_T;
	}

	Point1_X = Point0_X + V_x*0.2;
	Point1_Y = Point0_Y + V_y*0.2;

	if (state_robot == STATE_READY)
	{
		for (int i = 0; i < ANGLE_TRUE.size(); i++)
		{
			object->addPosition(ID_TRUE.at(i), X_TRUE.at(i),
				Y_TRUE.at(i), ANGLE_TRUE.at(i));
		}
	}
}

// Draw the predicted bounding box
bool GuiWindow::drawPred(int classId, double conf, int left, int top, int right, int bottom, Mat& frame, double &angle)
{
	float W1 = 88.12453094, W2 = -1.00672202;
	// BEFORE CUT IMAGE CONTAIN BOUNDING BOX
	Mat imageCrop;
	Rect2d r;
	r.x = left - 10;
	r.y = top - 10;
	r.width = right - left + 20;  //right-left is %d //r.width  is float 
	r.height = bottom - top + 20;

	if (r.x >= 0
		&& r.y >= 0
		&& r.width >= 0
		&& r.height >= 0
		&& r.x + r.width <= frame.cols
		&&  r.y + r.height <= frame.rows)
	{
		//ui->textEdit_Position->append(tr("qua kiem r"));
		imageCrop = frame(r);
		//**Convert image from BGR -> HSV**
		Mat gray;
		cvtColor(imageCrop, gray, COLOR_BGR2GRAY);

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
		vector<Vec4i> lines;
		HoughLinesP(canny, lines, 1, CV_PI / 180, 30, 50, 10);
		ui->textEdit_Position->append(tr("line : %1 \n  ").arg(lines.size()));

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
		rectangle(frame, Point(left, top - round(labelSize.height)), Point(left + round(labelSize.width), top + baseLine), Scalar(255, 255, 255), FILLED);
		putText(frame, label, Point(left, top), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0), 1);

		//Calculate arctan
		Mat drawing = Mat::zeros(r.width, r.height, CV_8UC3);
		angle = 0;

		if (lines.size() == 0 )
		{
			return false;
		}
		
		if (lines.size() >= 2)
		{
			vector<Vec3f> params(4);
			for (size_t i = 0; i < lines.size(); i++)
			{
				params.push_back(calcParams(Point(lines[i][0], lines[i][1]),
											Point(lines[i][2], lines[i][3])));
			}

			vector<Point> corners;
			for (int i = 0; i < params.size(); i++)
			{
				for (int j = i; j < params.size(); j++)
				{
					Point intersec = findIntersection(params[i], params[j]);
					if ((intersec.x > 0)
						&& (intersec.y > 0)
						&& (intersec.x < canny.cols)
						&& (intersec.y < canny.rows))
					{
						corners.push_back(intersec);
					}
				}
			}

			for (int i = 0; i < corners.size(); i++)
			{
				circle(drawing, corners[i], 3, Scalar(0, 255, 0));
			}

			if (corners.size() != 0)
			{
				return false;
			}
		}
		for (size_t i = 0; i < lines.size(); i++)
		{
			line(drawing, Point(lines[i][0], lines[i][1]),
				Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 1, LINE_8);
			angle += atan2((double)lines[i][3] - lines[i][1], (double)lines[i][2] - lines[i][0]);
		}
		angle /= lines.size();
		angle = W1 + (angle * 180 / CV_PI)*W2;
		ui->textEdit_Position->setText(tr("angle: %1 \n").arg(angle));
		imshow("Object", drawing);
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
	float x = -1, y = -1;
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
	timer_CAM->start(500);
}

void GuiWindow::timer_OBJECT_handle()
{
	if (object->isNotEmpty() && (state_robot == STATE_READY))
	{
		object->getPosition(target);
		connect(controller, &RobotControll::commandWorkDone, this, &GuiWindow::pickAndPlace);
		connect(controller, &RobotControll::commandDeny, this, &GuiWindow::overWorkSpace);
		pickAndPlace();
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
	if (controller->open(QIODevice::ReadWrite)) {
		timer_serial_comboBox->stop();
		ui->comboBox_Baudrate->setEnabled(false);
		ui->comboBox_Comport->setEnabled(false);
		ui->pushButton_Connect->setText(tr("Disconnect"));
		//ui->label_connectStatus->setText(tr("Connected"));
	}
	else {
		QMessageBox::critical(this, tr("Error"), controller->errorString());
	}
}

void GuiWindow::serial_closePort() {
	if (controller->isOpen()) {
		controller->close();
		ui->comboBox_Baudrate->setEnabled(true);
		ui->comboBox_Comport->setEnabled(true);
		ui->pushButton_Connect->setText("Connect");
		timer_serial_comboBox->start(1000);
	}
	else {
		QMessageBox::critical(this, tr("Error"), controller->errorString());
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
	controller->setPortName(ui->comboBox_Comport->currentText());
	controller->setBaudRate(static_cast<QSerialPort::BaudRate>
		(ui->comboBox_Baudrate->itemData(ui->comboBox_Baudrate->currentIndex()).toInt()));
	controller->setDataBits(QSerialPort::Data8);
	controller->setParity(QSerialPort::NoParity);
	controller->setStopBits(QSerialPort::OneStop);
	controller->setFlowControl(QSerialPort::NoFlowControl);
}

void GuiWindow::serial_handleError(QSerialPort::SerialPortError error)
{
	if (error == QSerialPort::ResourceError) {
		QMessageBox::critical(this, tr("Critical Error"), controller->errorString());
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
					ui->textEdit_Position->append(tr("JAPAN"));
				}
				else
				{
					ui->textEdit_Position->append(tr("VIETNAM"));
				}
				displayPosition(target.x, target.y, target.angle);
				roll_pick = angleProcess(target.x, target.y, target.angle);
				ui->textEdit_Position->append(tr("roll pick: %1 \n").arg(roll_pick));
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
				pickAndPlace(); // khong co command work done, phải gọi pickAndPlace tiep, tang len state_up2
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
						ui->textEdit_Waring->append("WARNING: Exceeding the height of Japan bundle");
						target_success_jp = 0;
					}	
				}
				else
				{
					target_success_vn++;
					if (target_success_vn == 5)
					{
						ui->textEdit_Waring->append("WARNING: Exceeding the height of Viet Nam bundle");
						target_success_vn = 0;
					}
				}
				state_robot = STATE_READY;  
				object->deletePosition(0);
				disconnect(controller, &RobotControll::commandWorkDone, this, &GuiWindow::pickAndPlace);

			}
		break;
		default: {}
	}
}

void GuiWindow::overWorkSpace()
{
	ui->textEdit_Inform->insertPlainText("ERROR: Over workspace");
	ui->textEdit_Inform->insertPlainText("Skip Point:");
	ui->textEdit_Inform->insertPlainText(tr("X: %1\n Y: %2\n Phi: %3\n")
							.arg(target.x).arg(target.y).arg(target.angle));
	object->deletePosition(0);
	disconnect(controller, &RobotControll::commandWorkDone, this, &GuiWindow::pickAndPlace);
	state_robot = STATE_READY;
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
/*--GUI--*/
void GuiWindow::gui_init()
{
	ui->textEdit_Inform->ensureCursorVisible();

	//Icon
	QIcon Off("F:/HANH_NHI/Thesis_Nam_Nhi/LV/MelfaModel/Capture_OFF.JPG");
	ui->pushButton_StartCamera->setIcon(Off);
	ui->pushButton_StartCamera->setIconSize(QSize(20, 20));
	ui->pushButton_StartCamera->setCheckable(true);

	connect(ui->sliderVelocity, &QAbstractSlider::valueChanged,
		this, &GuiWindow::slide_Velocity);

	connect(ui->sliderAccerlerate, &QAbstractSlider::valueChanged,
		this, &GuiWindow::slide_Accelerate);
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
		ui->textEdit_Waring->setText("WARNING: Robot is connecting");
		serial_openPort();
	}
	else 
	{
		ui->textEdit_Waring->setText("WARNING: Robot is disconnecting");
		serial_closePort();
	}
}

void GuiWindow::on_pushButton_Scan_clicked()
{
	ui->textEdit_Waring->setText("WARNING: Robot is scanning");
	controller->robotScanLimit();
}

void GuiWindow::on_pushButton_TestMoveJoint_clicked() 
{
	timer_PAIN->start(400);
}

void GuiWindow::on_pushButton_Home_clicked()
{ 
	ui->textEdit_Waring->setText("WARNING: Robot is at home status");
	state_robot = STATE_READY;
	target_success_jp = 0;
	target_success_vn = 0;
	collum_jp = 0;
	collum_vn = 0;
	timer_OBJECT->stop();
	timer_IDLE->stop();
	object->clear();
	controller->robotOutput(false);
	controller->robotMoveHome();
}

void  GuiWindow::on_pushButton_Stop_clicked()
{
	ui->textEdit_Waring->setText("WARNING: Robot is stopping");
	timer_OBJECT->stop();
}

void GuiWindow::on_pushButton_StartCamera_toggled(bool checked)
{
	if (checked)
	{
		QIcon On("F:/HANH_NHI/Thesis_Nam_Nhi/LV/MelfaModel/Capture_ON.JPG");
		ui->pushButton_StartCamera->setIcon(On);
		ui->pushButton_StartCamera->setIconSize(QSize(20, 20));
		timer_CAM->start(500);
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
	ui->textEdit_Waring->setText("WARNING: Robot is starting");
	timer_OBJECT->start(200);
	timer_IDLE->start(100);	
}

void GuiWindow::displayPosition(double x, double y, double roll) 
{
	ui->textEdit_Position->append(tr("X: %1 \nY: %2 \nPhi: %3").arg(x).arg(y).arg(roll));
}

void GuiWindow::timer_PAIN_handle()
{
	{
		double deg0, deg1, deg2, deg3;
		deg0 = controller->getVar0();
		deg1 = controller->getVar1();
		deg2 = controller->getVar2();
		deg3 = controller->getVar3();
		openGLWindow->setAngle(deg0, deg1, deg2, deg3);
		ui->textEdit_Inform->clear();
		ui->textEdit_Inform->append(tr("%1 %2 %3 %4").arg(deg0).arg(deg1).arg(deg2).arg(deg3));
	}
}

void GuiWindow::timer_IDLE_handle()
{
	idle_robot = controller->isIdle();
}