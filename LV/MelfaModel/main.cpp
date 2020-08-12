#include <QApplication>
#include <openglwindow.h>
#include <guiwindow.h>

using namespace cv;
using namespace std;
using namespace dnn;

vector<string> classes;
VideoCapture cap(0);
Mat frame, blob, matROI;
Net net;

int main(int argc, char *argv[])
{ 
    QApplication a(argc, argv);

	 

	if (!cap.isOpened())
	{
		printf("ERROR: khong the mo camera \r\n");
		return(0);
	}
	// Load names of classes
	string classesFile = "C:/custom.names"; //chuoi ten file 
	ifstream ifs(classesFile.c_str()); // 
	string line;
	while (getline(ifs, line)) classes.push_back(line);
	String modelConfiguration = "C:/yolov3-tiny.cfg"; //duong dan
	String modelWeights = "C:/yolov3-tiny_old2.weights";
	// Load the network
	net = readNetFromDarknet(modelConfiguration, modelWeights); //doc 2 file nay
	net.setPreferableBackend(DNN_BACKEND_OPENCV); //dua tren thu vien opencv
	net.setPreferableTarget(DNN_TARGET_CPU); // xu li tren CPU hay GPU

    
	GuiWindow g;
    g.show();
    return a.exec();

	printf("Tat camera\r\n");
	cap.release();
	destroyAllWindows();
}
