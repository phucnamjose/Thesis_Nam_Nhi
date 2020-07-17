#ifndef ROBOTCONTROLL_H
#define ROBOTCONTROLL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>

#include <stdio.h>
#include <string.h>
#include <sstream>
//#include "debug.hpp"

#define  START_CHAR         (0x28)
#define  END_CHAR            (0x29)


using namespace std;

class RobotControll : public QSerialPort
{
    Q_OBJECT

 public:
    explicit RobotControll(QObject *parent = nullptr);
    virtual ~RobotControll();
    string qbyteArray2string(QByteArray &data);

    enum robotCommand_t {
        CMD_STOPNOW = 0,
        CMD_SCAN,
        CMD_HOME,
        CMD_MOVE_LINE,
        CMD_MOVE_CIRCLE,
        CMD_MOVE_JOINT,
        CMD_ROTATE_SINGLE,
        CMD_OUTPUT,
        CMD_READ_STATUS,
        CMD_READ_POSITION,
        CMD_SETTING,
        NUM_OF_CMD, // = 11 CMD
    };

    const char *ROBOTCOMMAND[NUM_OF_CMD] = {
        "STOP",
        "SCAN",
        "HOME",
        "MOVL",
        "MOVC",
        "MOVJ",
        "ROTA",
        "OUTP",
        "READ",
        "POSI",
        "SETT"
    };

    enum robotRespond_t {
        RPD_IDLE = 0,
        RPD_BUSY,
        RPD_POSITION,
        RPD_START,
        RPD_RUNNING,
        RPD_DONE,
        RPD_STOP,
        RPD_ERROR,
        RPD_OK,
        NUM_OF_RPD, // = 9 RPD
    };

    const char *ROBOTRESPOND[NUM_OF_RPD] = {
        "IDLE",
        "BUSY",
        "POSI",
        "STAR",
        "RUNN",
        "DONE",
        "STOP",
        "ERRO",
        "OKAY"
    };

    enum robotCoordinate_t {
          COORDINATES_ABS = 0,  /*!< Absolute position */
          COORDINATES_REL       /*!< Relative position*/
    };

    enum robotTrajectory_t {
          TRAJECTORY_LSPB	= 0,
          TRAJECTORY_SCURVE
    };

    enum robotModeInit_t {
          MODE_INIT_QVA	= 0, /*!< Consume A max, determine T max */
          MODE_INIT_QVT     /*!< Consume T max, determine A max */
    };

    enum robotParam_t {
        Param_Var0 = 0,
        Param_Var1,
        Param_Var2,
        Param_Var3,
        Param_X,
        Param_Y,
        Param_Z,
        Param_Roll,
        Param_Lenght,
        Param_Time_Total,
        Param_TimeRun
    };

	/*
	*Start NHI's Code define variable here
	*/
	bool StartDone = false;
	/*
	*Stop NHI's Code define variable here
	*/

signals:
            void    commandTimeOut();
            void    commandWorkStart(QByteArray repsond);
            void    commandWorkRunning(QByteArray repsond);
            void    commandWorkStop(QByteArray repsond);//khi co error
            void    commandWorkDone(QByteArray repsond);
            void    commandSend(QByteArray command);
            void    commandAccept(QByteArray repsond);
            void    commandDeny(QByteArray repsond);
            void    respondPosition(QByteArray repsond);
            void    respondArrived(QByteArray repsond);
			
			

private:
            bool    packData(QByteArray &data);
            bool    unPackData(QByteArray &data);
            bool    writeData(QByteArray &data);
            void    readData();
            bool   processRespond(QByteArray &respond);
            bool   list2position(QByteArrayList list);
            bool   setCommand(robotCommand_t cmd, int time, const QString para = "");
//            bool    setCommandNWait(robotCommand_t cmd, const QString para = "");

 public:
            void    robotResetId(); //
            bool    setModeInite(robotModeInit_t type); // B1 mode QVA
            bool    setAccelerate(double factor); //b2 van toc
            bool    setVelocity(double factor); // b3 gia toc
            bool    setTimeTotalLimit(double time);

            bool    robotStop();
            bool    robotScanLimit(); // Buoc 4: scan vi tri tuyet doi cua no => done => b5
            bool    robotMoveHome(); // Buoc 5: 
            bool    robotMoveLine(double x, double y, double z, double roll); // buoc v.v..

            bool    robotMoveCircle(double x, double y, double z, double roll,
                                                            double center_x, double center_y, double center_z,
                                                            int8_t direction);

            bool    robotMoveJoint(double x, double y, double z, double roll);
            bool    robotRotateSingleJoint  (int joint, double angle);
            bool    robotOutput(bool output);
            bool    robotReadStatus();//buoc 5
            bool    robotReadPosition();
            bool    robotSetting(robotCoordinate_t coordinate, robotTrajectory_t   trajectory);

			bool	isIdle();
            bool    isScan(); //b5 done => co iscan true => moveline ,movej
            double  getX();
            double  getY();
            double  getZ();
            double  getRoll();
            double  getVar0();
            double  getVar1();
            double  getVar2();
            double  getVar3();
            double  getLenght();
            double  getTotalTime();
            double  getTimeRun();
            double  getValue(robotParam_t param);

 private:
            QByteArray data_read;
            robotModeInit_t     mode_init = MODE_INIT_QVA;

            int        id_command  = 1;
            bool       istimeout         = false;

			bool		idle = false;
            bool       scan                = false;
            double     x, y, z, roll;
            double     var0, var1, var2, var3;
            double     lenght;
            double     time_run = 0;
            double     time_total = 0;
            double     factor_accelerate = 0.3;
            double     factor_velocity      = 0.3;
            double     time_total_limit     = 10;
};




#endif // ROBOTCONTROLL_H
