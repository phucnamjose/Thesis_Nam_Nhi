#ifndef GUIWINDOW_H
#define GUIWINDOW_H

#include <QMainWindow>
#include <QTimer>
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

#include <string>


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
	bool drawPred(int classId, double conf, int left, int top, int right, int bottom, cv::Mat& frame, double &angle);
	void showFrame(bool dynamic);
	void showCamera(cv::Mat img, QImage::Format format);
	// Select ROI
	void selectROI(cv::Mat frame, cv::Mat &matROI);
	void displayPosition(double x, double y, double roll);

	/*--Robot--*/
	void robotInit();
	void serial_openPort();
	void serial_closePort();
	void fold_Object(double X, double Y, double Z, double angle);
	void drop_Object(double X, double Y, double Z, double angle);
	void getpos();

public slots:
	static void mousePoints(int event, int x, int y, int flags, void* userdata);


private slots:
	/*--GUI--*/
	void on_pushButton_Connect_clicked();
	void on_pushButton_Scan_clicked();
	void on_pushButton_TestMoveJoint_clicked();
	void on_pushButton_Home_clicked();
	void on_pushButton_Stop_clicked();
	void on_pushButton_StartCamera_toggled(bool checked);
	void on_pushButton_SetROI_clicked();
	void on_pushButton_Pick_clicked();
	void on_pushButton_Place_clicked();
	void on_pushButton_Hold_clicked();
	void slide_Velocity();
	void slide_Accelerate();
	

	/*--Camera--*/
	
	void moveJoint(double centerX, double centerY, double Z, double roll);
	bool checkFree();
	void FreeMCU();
	void timer_CAM_handle();
	void timer_OBJECT_handle();

	/*--Robot--*/
	void serial_updatePortName();                                   // connect timeout timer check
	void serial_updateSetting();                                    // connect current text change
	void serial_handleError(QSerialPort::SerialPortError error);    // connect error handle
	void pickAndPlace();
private:
	/*--GUI--*/
    Ui::GuiWindow *ui;

	/*--Camera--*/
	QTimer *timer_CAM;
	bool	pick = false;
	Object	*object = nullptr;
	/*--Robot--*/
    RobotControll *controller;
	QTimer *timer_serial_comboBox = nullptr;
	bool output_robot;
	robotPickAndPlace_t state_robot;

	/*--ROBOT--*/
	QTimer *timer_OBJECT;
};

#endif // GUIWINDOW_H
