#ifndef GUIWINDOW_H
#define GUIWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QElapsedTimer>
#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>
#include <opencv2/dnn.hpp>
#include <robotcontroll.hpp>
#include <qpixmap.h>
#include <qimage.h>
#include <object_detect.h>
#include <openglwindow.h>
#include <string>

using namespace cv;
using namespace std;
using namespace dnn;

namespace Ui {
class GuiWindow;
}

class GuiWindow : public QMainWindow
{
    Q_OBJECT

public:
	
    explicit GuiWindow(QWidget *parent = 0);
    ~GuiWindow();


	enum robotPickAndPlace_t
	{
		STATE_READY = 0,
		STATE_PICK,
		STATE_DOWN1,
		STATE_HOLD,
		STATE_UP1,
		STATE_PLACE,
		STATE_DOWN2,
		STATE_DROP,
		STATE_UP2,
		STATE_FINISH
	};


private:
	/*--GUI--*/
	void gui_init();

	/*--Camera--*/
	bool detectObject(cv::Mat frame, cv::Mat &out);
	// Remove the bounding boxes with low confidence using non-maxima suppression
	void postProcess(cv::Mat& frame, const std::vector<cv::Mat>& outs);

	// Draw the predicted bounding box
	bool drawPred(int classId, double conf, int left, int top, int right, int bottom,
					cv::Mat& frame, double &angle, double &x, double &y);
	void showFrame(bool dynamic);
	void showCamera(cv::Mat img, QImage::Format format);
	Vec3f calcParams(Point2f p1, Point2f p2);
	Point findIntersection(Vec3f params1, Vec3f params2);
	double disPoint2Line(Vec3f param, Point A);
	double disPoint2Point(Point A, Point B);

	// Select ROI
	void selectROI(cv::Mat frame, cv::Mat &matROI);
	void displayPosition(double x, double y, double roll);

	/*--Robot--*/
	void robotInit();
	void serial_openPort();
	void serial_closePort();
	double angleProcess(double x, double y, double angle);

public slots:
	static void mousePoints(int event, int x, int y, int flags, void* userdata);


private slots:
	/*--GUI--*/
	void on_pushButton_Connect_clicked();
	void on_pushButton_Scan_clicked();
	void on_pushButton_Home_clicked();
	void on_pushButton_Stop_clicked();
	void on_pushButton_StartCamera_toggled(bool checked);
	void on_pushButton_SetROI_clicked();
	void on_pushButton_Start_clicked();
	void on_pushButton_Japan_Full_clicked();
	void on_pushButton_Vietnam_Full_clicked();
	void slide_Velocity();
	void slide_Accelerate();
	

	/*--Camera--*/
	
	void moveJoint(double centerX, double centerY, double Z, double roll);
	void timer_CAM_handle();
	void timer_OBJECT_handle();

	/*--Robot--*/
	void serial_updatePortName();                                   // connect timeout timer check
	void serial_updateSetting();                                    // connect current text change
	void serial_handleError(QSerialPort::SerialPortError error);    // connect error handle
	void pickAndPlace();
	void overWorkSpace();
	void updatePosition(double x, double y, double z, double roll,
						double var0, double var1, double var2, double var3,
						double lenght, double time_run, double time_total);
private:
	/*--GUI--*/
    Ui::GuiWindow *ui;
	OpenGLWindow *openGLWindow;
	/*--Camera--*/
	QTimer *timer_CAM;
	bool	pick = false;
	Object	*object = nullptr;
	/*--Robot--*/
    RobotControll *controller;
	QTimer *timer_serial_comboBox = nullptr;
	bool output_robot;
	robotPickAndPlace_t state_robot = STATE_READY;
	bool	japan_full = false; 
	bool	vietnam_full = false;

	/*--ROBOT--*/
	QTimer *timer_OBJECT;
	bool idle_robot = false;
	QString portName;

};

#endif // GUIWINDOW_H
