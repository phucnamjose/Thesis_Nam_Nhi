#include "debug.hpp"

Debug::Debug()
{

}

Debug::~Debug()
{

}

void Debug::deBug(string file, int line, string function, string message)
{
    ostringstream oss;
    oss << file << "(" << line << ")" << "/" << function << ":" << message << endl;
    qDebug().noquote() << oss.str().c_str();
}

void Debug::deBug(string file, int line, string function, const char *message)
{
    ostringstream oss;
    oss << file << "(" << line << ")" << "/" << function << ":" << message << endl;
    qDebug().noquote() << oss.str().c_str();
}


void Debug::deBug(string file, int line, string function, QString message)
{
    ostringstream oss;
    oss << file << "(" << line << ")" << "/" << function << ":" << message.toStdString() << endl;
    qDebug().noquote() << oss.str().c_str();
}

