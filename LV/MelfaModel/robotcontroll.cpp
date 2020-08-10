#include "robotcontroll.hpp"

// Constructor
RobotControll::RobotControll(QObject *parent):QObject(parent)
{

}

// Deconstructor
RobotControll::~RobotControll()
{
    if (portOpen) {
        closeComPort();
    }
}

//// Child thread call
// Unpack Respond
bool RobotControll::unPackData(QByteArray &data)
{
   // qDebug() << "unpack thread is:" << QThread::currentThreadId();
    if(data.isNull() || data.isEmpty()) {
        M_DEBUG("data input is null");
        return false;
    }
    if(data.at(0) != START_CHAR || data.at(data.length()-1) != END_CHAR) {
        M_DEBUG("begin or end charater wrong");
        return false;
    }
    QByteArray temp;

    temp.append(data);
    temp.remove(0, 1);
    temp.remove(temp.length()-1, 1);
    data.clear();
    data.append(temp);
    return true;
}

string RobotControll::qbyteArray2string(QByteArray &data)
{
    return QString::fromLocal8Bit(data).toStdString().c_str();
}

// Read Respond from Robot
void RobotControll::readData() {
        qDebug() << "readData thread is:" << QThread::currentThreadId();
        data_read.append(port->readAll());
        // Mutil command in 1 frame
        while(data_read.indexOf(END_CHAR) != -1) {
            QByteArray temp = data_read.left(data_read.indexOf(END_CHAR) +1);
            data_read.remove(0, data_read.indexOf(END_CHAR) +1);
            // Unpack Payload
            if ( this->unPackData(temp) == false ) {
                M_DEBUG("unpack fail");
                continue;
            }
            if (!processRespond(temp)) {
                M_DEBUG("error frame");
                continue;
            }
        }
}

bool   RobotControll::processRespond(QByteArray &repsond) {
    qDebug() << "processRespond thread is:" << QThread::currentThreadId();
    int id_cmd;
    QByteArray respond_code;
    bool isInt;
    QByteArrayList list = repsond.split(' ');
    id_cmd =  list.at(0).toInt(&isInt);
    if (isInt) {
        respond_code.clear();
        respond_code += list.at(1);
        // IDLE
        if (respond_code == ROBOTRESPOND[RPD_IDLE]) {
            if (list.at(2).toInt() == 1) {  scan = true;}
            else if (list.at(2).toInt() == 0) {  scan = false;}
            // Send Signal
            emit respondArrived(repsond);

        // BUSY
        } else if (respond_code == ROBOTRESPOND[RPD_BUSY]) {
            if (list.at(2).toInt() == 1) {  scan = true;}
            else if (list.at(2).toInt() == 0) {  scan = false;}
            // Send Signal
            emit respondArrived(repsond);

        // POSI
        } else if (respond_code == ROBOTRESPOND[RPD_POSITION]) {
             list2position(list);
             // Send Signal
             emit respondPosition(repsond);
        // STAR
        } else if (respond_code == ROBOTRESPOND[RPD_START]) {
            list2position(list);
            // Send Signal
            emit commandWorkStart( x, y, z, roll, var0, var1, var2, var3, lenght, time_run, time_total);
        // RUNN
        } else if (respond_code == ROBOTRESPOND[RPD_RUNNING]) {
            list2position(list);
            // Send Signal
            emit commandWorkRunning( x, y, z, roll, var0, var1, var2, var3, lenght, time_run, time_total);
        // DONE
        } else if (respond_code == ROBOTRESPOND[RPD_DONE]) {
            list2position(list);
            // Send Signal
            emit commandWorkDone(x, y, z, roll, var0, var1, var2, var3, lenght, time_run, time_total);
        // STOP
        } else if (respond_code == ROBOTRESPOND[RPD_STOP]) {
            // Send Signal
            emit commandWorkStop(repsond);
        // ERRO
        } else if (respond_code == ROBOTRESPOND[RPD_ERROR]) {
            // Send Signal
            emit commandDeny(repsond);

        // OKEY
        } else if (respond_code == ROBOTRESPOND[RPD_OK]) {
            // Send Signal
            emit commandAccept(repsond);

        // WRONG FRAME
        } else {
            return false;
        }
    }
    return true;
}

bool   RobotControll::list2position(QByteArrayList list) {
    double value[11];
    bool isdouble[11];
    if (list.length() != 13) {
        return false;
    }
    for (int i = 2; i < list.length() ; ++i) {
        value[i - 2] = list.at(i).toDouble(&isdouble[i - 2]);
        if ( ! isdouble[i -2]) {
            return false;
        }
    }
    var0  = value[0];
    var1   = value[1];
    var2  = value[2];
    var3  = value[3];
    x        = value[4];
    y        = value[5];
    z        = value[6];
    roll    = value[7];
    lenght = value[8];
    time_total = value[9];
    time_run = value[10];
    return true;
}


void RobotControll::child_updatePosition() {
    qDebug() << "child_update thread is:" << QThread::currentThreadId();
    emit updatePosition(x, y, z, roll, var0, var1, var2, var3 , lenght, time_run, time_total);
}

//// Main thread call

// Intergrate parameters to Command
bool RobotControll::setCommand(robotCommand_t cmd, const QString para) {
    QByteArray command;
    QByteArray command_pack;
    command.clear();
    command_pack.clear();
    if(para == "") {
        command.append(tr("%1 %2").arg(QString::number(id_command))
                       .arg(ROBOTCOMMAND[cmd]));
    } else {
        command.append(tr("%1 %2 %3").arg(QString::number(id_command))
                       .arg(ROBOTCOMMAND[cmd]).arg(para));
    }
    command_pack.append(command);
    if(writeData(command_pack) == false) {
        M_DEBUG("write data fail");
        Debug::_delete(command);
        return false;
    }
    emit commandSend(command);    // Set Signal
    id_command++;
    Debug::_delete(command);
    return true;
}

// Pack Command
bool RobotControll::packData(QByteArray &data)
{
    if(data.isNull() || data.isEmpty()) {
        M_DEBUG("data input is empty");
        return false;
    }
    // packing
    QByteArray temp;
    temp.append(data);
    temp.push_front((char)START_CHAR);
    temp.push_back((char)END_CHAR);
    data.clear();
    data.append(temp);

    Debug::_delete(temp);
    return true;
}

// Send Command to Robot
bool RobotControll::writeData(QByteArray &data) {
    qDebug() << "writeData thread is:" << QThread::currentThreadId();
    if(portOpen) {
        // Pack Payload
        if( this->packData(data) == false ) {
            M_DEBUG("pack fail");
            return false;
        }
        emit main_sendThroughSerial(data);
    } else {
        M_DEBUG("no device");
        return false;
    }
    return true;
}

/*Publid  For user */
bool  RobotControll::isOpen() {
    return portOpen;
}

bool  RobotControll::openComPort(QString port_name) {
     qDebug() << "openComPort thread is:" << QThread::currentThreadId();
    if (portOpen) {
        qDebug() << "ERROR: Port is opened!!!";
        return false;
    }
    port = new SerialPort;
    port->setPortName(port_name);
    port->setBaudRate(QSerialPort::Baud115200);
    port->setDataBits(QSerialPort::Data8); //data bits
    port->setStopBits(QSerialPort::OneStop); //stop bit
    port->setParity(QSerialPort::NoParity); //Parity
    port->setFlowControl(QSerialPort::NoFlowControl); //flow control
    if (port->open(QIODevice::ReadWrite)) {
         qDebug() << "Port open SUCCESS!!!";
         connect(port, &QSerialPort::readyRead, this, &RobotControll::readData, Qt::DirectConnection);
         connect(this, &RobotControll::main_sendThroughSerial,
                            port, &SerialPort::child_sendThroughSerial, Qt::QueuedConnection);
         timer_update = new QTimer();
         connect(timer_update, &QTimer::timeout, this, &RobotControll::child_updatePosition);

         my_thread = new QThread();
         connect(my_thread, &QThread::finished, port, &SerialPort::deleteLater);
         connect(my_thread, &QThread::finished, timer_update, &QTimer::deleteLater);
         timer_update->start(update_period);
         timer_update->moveToThread(my_thread);
         port->moveToThread(my_thread);
         my_thread->start();
         portOpen = true;
         return true;
    } else {
         qDebug() << "Port open FAIL!!!";

         return false;
    }
}

bool  RobotControll:: closeComPort() {
    if (portOpen) {
        //port->close();
        //port->deleteLater();
        my_thread->quit();
        my_thread->wait();
        my_thread->deleteLater();

        portOpen = false;
        return true;
    } else {
        return false;
    }
}

void RobotControll::robotResetId() {
    id_command = 1;
}

bool    RobotControll::setModeInite(robotModeInit_t type) {
    if ( type == MODE_INIT_QVA || type == MODE_INIT_QVT) {
         mode_init = type;
         return true;
    } else {
        return false;
    }
}

bool    RobotControll::setAccelerate(double factor) {
    if ( factor > 0 && factor <= 1) {
        factor_accelerate = factor;
        return true;
    } else {
        return false;
    }
}

bool    RobotControll::setVelocity(double factor) {
    if ( factor > 0 && factor <= 1) {
        factor_velocity = factor;
        return true;
    } else {
        return false;
    }
}

bool    RobotControll::setTimeTotalLimit(double time) {
    if ( time > 0 && time <30) {
        time_total_limit = time;
        return true;
    } else {
        return false;
    }
}

bool RobotControll::robotStop() {
    if(this->setCommand(this->CMD_STOPNOW, tr("")) == false ) {
        return false;
    }
   return true;
}

bool RobotControll::robotScanLimit() {
    if(this->setCommand(this->CMD_SCAN, tr("")) == false ) {
        return false;
    }
   return true;
}

bool RobotControll::robotMoveHome() {
    if(this->setCommand(this->CMD_HOME, tr("%1 %2").arg(factor_velocity).arg(factor_accelerate)) == false ) {
        return false;
    }
   return true;
}

bool RobotControll::robotMoveLine(double x, double y, double z, double roll){
    double temp;
    if (mode_init == MODE_INIT_QVA) {
        temp = factor_accelerate;
    } else {
        temp = time_total_limit;
    }
    if(this->setCommand(this->CMD_MOVE_LINE, tr("%1 %2 %3 %4 %5 %6 %7")
                              .arg(x)
                              .arg(y)
                              .arg(z)
                              .arg(roll)
                              .arg(factor_velocity)
                              .arg(int(mode_init))
                              .arg(temp)) == false ){
        return false;
    }
    return true;
}

bool RobotControll::robotMoveCircle(double x, double y, double z, double roll,
                                    double center_x, double center_y, double center_z,
                                    int8_t direction){
    double temp;
    if (mode_init == MODE_INIT_QVA) {
        temp = factor_accelerate;
    } else {
        temp = time_total_limit;
    }
    if(this->setCommand(this->CMD_MOVE_CIRCLE, tr("%1 %2 %3 %4 %5 %6 %7 %8 %9 %10 %11")
                                              .arg(x)
                                              .arg(y)
                                              .arg(z)
                                              .arg(roll)
                                              .arg(center_x)
                                              .arg(center_y)
                                              .arg(center_z)
                                              .arg(direction)
                                              .arg(factor_velocity)
                                              .arg(int(mode_init))
                                              .arg(temp)) == false ){
        return false;
    }
    return true;
}

bool RobotControll::robotMoveJoint( double x, double y, double z, double roll){
    double temp;
    if (mode_init == MODE_INIT_QVA) {
        temp = factor_accelerate;
    } else {
        temp = time_total_limit;
    }
    if(this->setCommand(this->CMD_MOVE_JOINT, tr("%1 %2 %3 %4 %5 %6 %7")
                                              .arg(x)
                                              .arg(y)
                                              .arg(z)
                                              .arg(roll)
                                              .arg(factor_velocity)
                                              .arg(int(mode_init))
                                              .arg(temp)) == false ){
        return false;
    }
    return true;
}

bool RobotControll::robotRotateSingleJoint(int joint, double angle) {
    double temp;
    if (mode_init == MODE_INIT_QVA) {
        temp = factor_accelerate;
    } else {
        temp = time_total_limit;
    }
    if(this->setCommand(this->CMD_ROTATE_SINGLE, tr("%1 %2 %3 %4 %5")
                              .arg(joint)
                              .arg(angle)
                              .arg(factor_velocity)
                              .arg(int(mode_init))
                              .arg(temp)) == false ){
        return false;
    }
    return true;
}

bool RobotControll::robotOutput(bool output){
    int value = 0;
    if(output){
        value = 1;
    }
    if(this->setCommand(this->CMD_OUTPUT, tr("%1")
                              .arg(value)) == false ){
        return false;
    }
    output_robot = output;
    return true;
}

bool  RobotControll::robotOutputToggle() {
    return robotOutput(!output_robot);
}

bool RobotControll::robotReadStatus(){
    if(this->setCommand(this->CMD_READ_STATUS, tr("")) == false ) {
        return false;
    }
    return true;
}

bool RobotControll::robotReadPosition(){
    if(this->setCommand(this->CMD_READ_POSITION, tr("")) == false ) {
        return false;
    }
    return true;
}

bool RobotControll::robotSetting(robotCoordinate_t coordinate, robotTrajectory_t   trajectory) {
    if(this->setCommand(this->CMD_SETTING, tr("%1 %2")
                                              .arg(int(coordinate))
                                               .arg(int(trajectory))) == false ){
        return false;
    }
    return true;
}

bool  RobotControll::robotMethodChange(robotMethod_t method) {
    if(this->setCommand(this->CMD_METHOD_CHANGE, tr("%1")
                                               .arg(int(method))) == false ){
        return false;
    }
    return true;
}

bool RobotControll:: robotJobNew() {
    if(this->setCommand(this->CMD_JOB_NEW, tr("")) == false ) {
        return false;
    }
    return true;
}

bool RobotControll::robotJobDelete() {
    if(this->setCommand(this->CMD_JOB_DELETE, tr("")) == false ) {
        return false;
    }
    return true;
}

bool RobotControll::robotJobPushMoveLine(double x, double y, double z, double roll) {
    double temp;
    if (mode_init == MODE_INIT_QVA) {
        temp = factor_accelerate;
    } else {
        temp = time_total_limit;
    }
    if(this->setCommand(this->CMD_JOB_PUSH_MOVE_LINE, tr("%1 %2 %3 %4 %5 %6 %7")
                              .arg(x)
                              .arg(y)
                              .arg(z)
                              .arg(roll)
                              .arg(factor_velocity)
                              .arg(int(mode_init))
                              .arg(temp)) == false ){
        return false;
    }
    return true;
}

bool RobotControll:: robotJobPushMoveJoint(double x, double y, double z, double roll) {
    double temp;
    if (mode_init == MODE_INIT_QVA) {
        temp = factor_accelerate;
    } else {
        temp = time_total_limit;
    }
    if(this->setCommand(this->CMD_JOB_PUSH_MOVE_JOINT, tr("%1 %2 %3 %4 %5 %6 %7")
                                              .arg(x)
                                              .arg(y)
                                              .arg(z)
                                              .arg(roll)
                                              .arg(factor_velocity)
                                              .arg(int(mode_init))
                                              .arg(temp)) == false ){
        return false;
    }
    return true;
}

bool RobotControll::robotJobPushOutput(bool output) {
    int value = 0;
    if(output){ value = 1;}
    if(this->setCommand(this->CMD_JOB_PUSH_OUTPUT, tr("%1")
                              .arg(value)) == false ){
        return false;
    }
    return true;
}

bool RobotControll:: robotJobTest() {
    if(this->setCommand(this->CMD_JOB_TEST, tr("")) == false ) {
        return false;
    }
    return true;
}

bool RobotControll:: robotJobRun() {
    if(this->setCommand(this->CMD_JOB_RUN, tr("")) == false ) {
        return false;
    }
    return true;
}

bool  RobotControll::robotKeyBoard(robotKeyBoard_t key) {
    if(this->setCommand(this->CMD_KEYBOARD, tr("%1").arg(int(key))) == false ) {
        return false;
    }
   return true;
}

bool  RobotControll::robotKeySpeedInc() {
    if ( key_speed > 1) {
        key_speed--;
    }
    if(this->setCommand(this->CMD_KEY_SPEED, tr("%1").arg(int(key_speed))) == false ) {
        return false;
    }
    return true;
}

bool  RobotControll::robotKeySpeedDec() {
    if ( key_speed < 5) {
        key_speed++;
    }
    if(this->setCommand(this->CMD_KEY_SPEED, tr("%1").arg(int(key_speed))) == false ) {
        return false;
    }
    return true;
}

