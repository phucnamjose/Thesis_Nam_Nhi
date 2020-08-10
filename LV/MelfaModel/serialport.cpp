#include "serialport.hpp"

#include <QDebug>
#include <QThread>

SerialPort::SerialPort(QObject *parent):QSerialPort(parent)
{

}

SerialPort::~SerialPort() {
    qDebug() << "COMPORT CLOSE ";
    this->close();
}

void   SerialPort:: child_sendThroughSerial(QByteArray data) {
    qDebug() << "child_send thread is:" << QThread::currentThreadId();
    this->write(data);
}
