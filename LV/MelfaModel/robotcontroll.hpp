#ifndef ROBOTCONTROLL_H
#define ROBOTCONTROLL_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>
#include <QSerialPortInfo>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include "serialport.hpp"

#define  START_CHAR         (0x28)
#define  END_CHAR            (0x29)

using namespace std;

class RobotControll : public QObject
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
        CMD_METHOD_CHANGE,// 12 normal
        CMD_JOB_NEW,
        CMD_JOB_DELETE,
        CMD_JOB_PUSH_MOVE_LINE,
        CMD_JOB_PUSH_MOVE_JOINT,
        CMD_JOB_PUSH_OUTPUT,
        CMD_JOB_TEST,
        CMD_JOB_RUN,// 7 job
        CMD_KEYBOARD, // 2 key
        CMD_KEY_SPEED,
        NUM_OF_CMD // = 19 CMD
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
        "SETT",
        "METH",// 12 normal

        "JNEW",
        "JDEL",
        "JPML",
        "JPMJ",
        "JPOP",
        "JTES",
        "JRUN ", // 7 job

        "KEYB",// 2 key
        "KSPE"
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

    enum robotKeyBoard_t{
        KEY_X_INC = 0,
        KEY_X_DEC,
        KEY_Y_INC,
        KEY_Y_DEC,
        KEY_Z_INC,
        KEY_Z_DEC,
        KEY_ROLL_INC,
        KEY_ROLL_DEC,
        KEY_VAR0_INC,
        KEY_VAR0_DEC,
        KEY_VAR1_INC,
        KEY_VAR1_DEC,
        KEY_VAR2_INC,
        KEY_VAR2_DEC,
        KEY_VAR3_INC,
        KEY_VAR3_DEC,
        NUM_OF_KEY// 16 key board
    };

    enum robotMethod_t {
          METHOD_MANUAL = 0,
          METHOD_SEMI_AUTO,
          METHOD_AUTO
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

    const int keyboard_time_period = 600;
    const int update_period = 200;
  signals:
            // to main thread
            void    commandTimeOut();
            void    commandWorkStart(double x,double y, double z, double roll,
                                                                    double var0, double var1, double var2, double var3,
                                                                    double lenght, double time_run, double time_total);
            void    commandWorkRunning(double x,double y, double z, double roll,
                                                                    double var0, double var1, double var2, double var3,
                                                                    double lenght, double time_run, double time_total);
            void    commandWorkStop(QByteArray repsond);
            void    commandWorkDone(double x,double y, double z, double roll,
                                                                    double var0, double var1, double var2, double var3,
                                                                    double lenght, double time_run, double time_total);
            void    commandSend(QByteArray command);
            void    commandAccept(QByteArray repsond);
            void    commandDeny(QByteArray repsond);
            void    respondPosition(QByteArray repsond);
            void    respondArrived(QByteArray repsond);

            void    updatePosition(double x,double y, double z, double roll,
                                   double var0, double var1, double var2, double var3,
                                   double lenght, double time_run, double time_total);
            //to child thread
            void    main_sendThroughSerial(QByteArray data);

private slots:
            void    child_updatePosition();
private:
            // child thread call
            bool    unPackData(QByteArray &data);
            void    readData();
            bool   processRespond(QByteArray &respond);
            bool   list2position(QByteArrayList list);
            // main thread call
            bool    writeData(QByteArray &data);
            bool    packData(QByteArray &data);
            bool   setCommand(robotCommand_t cmd, const QString para = "");
            //bool   getCommand(robotCommand_t cmd, const QString para = "");

 public:
            bool   isOpen();
            bool   openComPort(QString port_name);
            bool   closeComPort();

            void    robotResetId();
            bool    setModeInite(robotModeInit_t type);
            bool    setAccelerate(double factor);
            bool    setVelocity(double factor);
            bool    setTimeTotalLimit(double time);
            // 11 normal
            bool    robotStop();
            bool    robotScanLimit();
            bool    robotMoveHome();
            bool    robotMoveLine(double x, double y, double z, double roll);

            bool    robotMoveCircle(double x, double y, double z, double roll,
                                                            double center_x, double center_y, double center_z,
                                                            int8_t direction);

            bool    robotMoveJoint(double x, double y, double z, double roll);
            bool    robotRotateSingleJoint  (int joint, double angle);
            bool    robotOutput(bool output);
            bool    robotOutputToggle();
            bool    robotReadStatus();
            bool    robotReadPosition();
            bool    robotSetting(robotCoordinate_t coordinate, robotTrajectory_t   trajectory);
            bool    robotMethodChange(robotMethod_t method);

            // 7 job
            bool    robotJobNew();
            bool    robotJobDelete();
            bool    robotJobPushMoveLine(double x, double y, double z, double roll);
            bool    robotJobPushMoveJoint(double x, double y, double z, double roll);
            bool    robotJobPushOutput(bool output);
            bool    robotJobTest();
            bool    robotJobRun();
            // 3 key board
            bool    robotKeyBoard(robotKeyBoard_t key);
            bool    robotKeySpeedInc();
            bool    robotKeySpeedDec();

 private:
            SerialPort  *port;
            QThread     *my_thread;
            QTimer        *timer_update;
            // receive variable ---> child thread ---> main thread do not access
            QByteArray data_read;
            int              id_command  = 1;
            bool          istimeout         = false;
            bool          scan                    = false;
            double     x, y, z, roll;
            double     var0 = 0, var1 = 0, var2 = 0, var3 = 0;
            double     lenght;

            // transmit varialble ---> main thread
            bool           portOpen = false;
            robotModeInit_t     mode_init = MODE_INIT_QVA;
            bool          output_robot = false;
            double     time_run = 0;
            double     time_total = 0;
            double     factor_accelerate = 0.3;
            double     factor_velocity      = 0.3;
            double     time_total_limit              = 10;
            int              key_speed = 1;
};

#endif // ROBOTCONTROLL_H
