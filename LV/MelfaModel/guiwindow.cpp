#include "guiwindow.h"
#include "ui_guiwindow.h"
#include "openglwindow.h"
#include <QDebug>


#define COMBOBOX_NUM    (2)


using namespace cv;
using namespace std;
using namespace dnn;
/*--GUI--*/
const char* comboBox_Name[COMBOBOX_NUM] = { "comboBox_Comport","comboBox_Baudrate", };

/*--Robot--*/
double Zhigh = 100.0;
double Zlow = 45.0;
double Xplace = 300;
double Yplace = -120;
double roll_place = 0;
bool isFree = true;

/*--Camera--*/
extern VideoCapture cap;
extern Mat blob;
extern Net net;
extern vector<string> classes;
vector<String> getOutputsNames(const Net& net);

float confThreshold = 0.7; // Confidence threshold
float nmsThreshold = 0.5;  // Non-maximum suppression threshold
int inpWidth = 416;        // Width of network's input image
int inpHeight = 416;       // Height of network's input image
     
int i = 0;
bool flag_ROI = false;
int x_pos[2];
int y_pos[2];
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
	//Icon
	ui->pushButton_StartCamera->setIcon(QIcon("/HANH_NHI/final_project/LUAN_VAN/8-7_phucnam/Capture_OFF.JPG"));
	ui->pushButton_StartCamera->setCheckable(true);
	// Timer for update position
	timer_CAM = new QTimer(this);
	connect(timer_CAM, &QTimer::timeout, this, &GuiWindow::timer_CAM_handle);	
	
}

GuiWindow::~GuiWindow()
{
    delete ui;
}

/*--CAMERA--*/
bool GuiWindow::detectObject(Mat frame, Mat &out)
{
	if (flag_ROI)
	{
		Mat matROI;
		selectROI(frame, matROI);
		// Create a 4D blob from a frame.
		blobFromImage(matROI, blob, 1 / 255.0, Size(inpWidth, inpHeight), Scalar(0, 0, 0), true, false);// tao ra blob tu hinh input //true swap B ,R //false :co cat hinh ra hay khong
		//Sets the input to the network																								 //Sets the input to the network
		net.setInput(blob);
		// Runs the forward pass to get output of the output layers
		vector<Mat> outs; // local  variable
		net.forward(outs, getOutputsNames(net)); //chay mang noron
												 // Remove the bounding boxes with low confidence
		postprocess(matROI, outs); // get outs into frame
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
vector<String> getOutputsNames(const Net& net)
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

void GuiWindow::postprocess(Mat& frame, const vector<Mat>& outs)
{
	
	//if (!controller->isScan())  // not scan => out 
	//return;
	double X, Y;
	double W11 = 153.554757, W12 = -212.873131, W21 = 0.0110744904, W22 = 0.718174295, W31 = 0.706857752, W32 = 0.00278501969;
	vector<int> classIds;
	vector<float> confidences;
	vector<Rect> boxes;

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
				int centerX = (int)(data[0] * frame.cols);
				int centerY = (int)(data[1] * frame.rows);

				int width = (int)(data[2] * frame.cols);
				int height = (int)(data[3] * frame.rows);
				int left = centerX - width / 2;
				int top = centerY - height / 2;

				int Xc = centerX + x_pos[0];
				int Yc = centerY + y_pos[0];

				X = W11 + W21*Xc + W31*Yc;
				Y = W12 + W22*Xc + W32*Yc;
				printf(" toa do x= %d, y = %d \r\n", X, Y);
				
				//moveJoint(X, Y, Zlow, 0);
				//if (controller->robotOutput(1))
				//{
					//moveJoint(0, 0, Zlow, 0);
				//}
				
				classIds.push_back(classIdPoint.x);
				confidences.push_back((float)confidence);
				boxes.push_back(Rect(left, top, width, height));
			}
		}
	}

	// Perform non maximum suppression to eliminate redundant overlapping boxes with lower confidences
	vector<int> indices;
	NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);
	double angle;
	for (size_t i = 0; i < indices.size(); ++i)
	{
		angle = 0;
		int idx = indices[i];
		Rect box = boxes[idx];
		drawPred(classIds[idx], confidences[idx], box.x, box.y,box.x + box.width, box.y + box.height, frame, angle);	
	}

	displayPosition(X, Y, angle);
	

	last_x = X;
	last_y = Y;
	last_roll = angle;
	
	/*if (pick)
	{
		x = X;
		y = Y;
		roll = angle;
		controller->robotMoveJoint(x, y, 45, roll);
		pick = false;
	}*/

}

// Draw the predicted bounding box
bool GuiWindow::drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat& frame, double &angle)
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
		imageCrop = frame(r);
		//**Convert image from BGR -> Gray**
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
		
		//**HoughLines**
		vector<Vec4i> lines;
		HoughLinesP(canny, lines, 1, CV_PI / 180, 35, 45, 10);

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
		rectangle(frame, Point(left, top - round(1.5*labelSize.height)), Point(left + round(1.5*labelSize.width), top + baseLine), Scalar(255, 255, 255), FILLED);
		putText(frame, label, Point(left, top), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 0), 1);

		//Calculate arctan
		Mat drawing = Mat::zeros(r.width, r.height, CV_8UC3);
		if (lines.size() == 0)
		{
			return false;
		}
		for (size_t i = 0; i < lines.size(); i++)
		{
			line(drawing, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 1, LINE_8);
			angle += atan2((double)lines[i][3] - lines[i][1], (double)lines[i][2] - lines[i][0]);
		}
		angle /= lines.size();
		angle = W1 + (angle * 180 / CV_PI)*W2;
		printf(" goc nghieng = %f \r\n  ", angle);
		imshow("Object", drawing);
	return true;
	}
}

void GuiWindow::moveJoint(double centerX, double centerY, double Z, double roll)
{
	controller->robotMoveJoint(centerX, centerY, Z, roll);
}

bool GuiWindow::checkFree()
{
	return isFree;
}

void GuiWindow::FreeMCU()
{
	isFree = true;
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
		x_pos[i] = x;
		y_pos[i] = y;
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		i++;
		if (i >= 2)
		{
			flag_ROI = true;
			i = 0;
		}
	}
}

void GuiWindow::show_Frame(bool dynamic)
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
		show_Camera(out_resize, QImage::Format_RGB888);
	}
}

void GuiWindow::show_Camera(cv::Mat img, QImage::Format format)
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
	show_Frame(true);
	timer_CAM->start(100);
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
	//connect(ui->pushButton_LogsClear, &QPushButton::clicked, this, &GuiWindow::logs_clear);
	//connect(ui->pushButton_Request, &QPushButton::clicked, this, &GuiWindow::manual_checkPara_setCommand);
	//connect(serial, &RobotControll::commandSend, this, &GuiWindow::serial_logCommand);

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
	//qDebug() << controller->portName() << controller->baudRate();
}

void GuiWindow::serial_handleError(QSerialPort::SerialPortError error)
{
	if (error == QSerialPort::ResourceError) {
		QMessageBox::critical(this, tr("Critical Error"), controller->errorString());
		serial_closePort();
	}
}

void GuiWindow::fold_Object(double X, double Y, double Z, double angle)
{  
	/*if (
	{  moveJoint(X, Y, Zhigh, angle);
		for ( int i=0;i<=40;i=i+4)
		{
			moveJoint(X, Y, i, angle);
		}
	}*/
}

void GuiWindow::drop_Object(double X, double Y, double Z, double angle)
{
	/*if (controller->robotReadStatus)
	{
		for (int i = 0; i <= 40; i = i + 4)
		{
			moveJoint(X, Y, i, angle);
		}
	}*/

}

void GuiWindow::pickAndPlace()
{
	state_robot = static_cast<robotPickAndPlace_t>(static_cast<int>(state_robot) + 1);
	switch (state_robot) 
	{

		case STATE_PICK:
			{
				getpos();
				controller->robotMoveJoint(x, y, Zhigh, roll);
			}
		break;


		case STATE_DOWN1:
			{
				controller->robotMoveJoint(x, y, Zlow, roll);
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
				controller->robotMoveJoint(x, y, Zhigh, roll);
			}
		break;


		case STATE_PLACE:
			{
				controller->robotMoveJoint(Xplace, Yplace, Zhigh, roll_place);
			}
		break;


		case STATE_DOWN2:
			{
				controller->robotMoveJoint(Xplace, Yplace, Zlow, roll_place);
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
				controller->robotMoveJoint(Xplace, Yplace, Zhigh, roll_place);
			}
		break;


		case STATE_FINISH:
			{
				state_robot = STATE_READY;  
				disconnect(controller, &RobotControll::commandWorkDone, this, &GuiWindow::pickAndPlace);
			}
		break;
		default: {}
	}
}

/*--GUI--*/
void GuiWindow::gui_init()
{
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
	if (ui->pushButton_Connect->text() == "Connect") {
		serial_openPort();
	}
	else {
		serial_closePort();
	}
}

void GuiWindow::on_pushButton_Scan_clicked()
{
	controller->robotScanLimit();
}

void GuiWindow::on_pushButton_TestMoveJoint_clicked() 
{
	controller->robotMoveJoint(250, 0, 100, 0);
}

void GuiWindow::on_pushButton_Home_clicked()
{
	controller->robotMoveHome();
}

void  GuiWindow::on_pushButton_Stop_clicked()
{   //XXXXXXXXXXXXXXXXX
	controller->setAccelerate(0);
	controller->setAccelerate(0);
}

void GuiWindow::on_pushButton_StartCamera_toggled(bool checked)
{
	if (checked)
	{
		ui->pushButton_StartCamera->setIcon(QIcon("/HANH_NHI/final_project/LUAN_VAN/8-7_phucnam/Capture_ON.JPG"));
		timer_CAM->start(100);
	}
	else
	{
		ui->pushButton_StartCamera->setIcon(QIcon("/HANH_NHI/final_project/LUAN_VAN/8-7_phucnam/Capture_OFF.JPG"));	
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


void GuiWindow::on_pushButton_Pick_clicked()
{
	if (state_robot == STATE_READY)
	{
		connect(controller, &RobotControll::commandWorkDone, this, &GuiWindow::pickAndPlace);
		pickAndPlace();
	}
	//pick = true;
}

void GuiWindow::on_pushButton_Place_clicked()
{
	controller->robotMoveJoint(300, -125, 45, 0);
}

void GuiWindow::on_pushButton_Hold_clicked()
{
	output_robot = !output_robot;
	controller->robotOutput(output_robot);
	if (output_robot) {
		ui->pushButton_Hold->setText("DROP");
	}
	else
	{
		ui->pushButton_Hold->setText("HOLD");
	}

}

void GuiWindow::displayPosition(double x, double y, double roll) 
{
	ui->textEdit_Position->setText(tr("X: %1 \nY: %2 \nPhi: %3\n").arg(x).arg(y).arg(roll));
}

void GuiWindow::getpos()
{
	x = last_x;
	y = last_y;
	roll = last_roll;
}