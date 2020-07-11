/****************************************************************************
** Meta object code from reading C++ file 'robotcontroll.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../robotcontroll.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotcontroll.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RobotControll_t {
    QByteArrayData data[14];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotControll_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotControll_t qt_meta_stringdata_RobotControll = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RobotControll"
QT_MOC_LITERAL(1, 14, 14), // "commandTimeOut"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "commandWorkStart"
QT_MOC_LITERAL(4, 47, 7), // "repsond"
QT_MOC_LITERAL(5, 55, 18), // "commandWorkRunning"
QT_MOC_LITERAL(6, 74, 15), // "commandWorkStop"
QT_MOC_LITERAL(7, 90, 15), // "commandWorkDone"
QT_MOC_LITERAL(8, 106, 11), // "commandSend"
QT_MOC_LITERAL(9, 118, 7), // "command"
QT_MOC_LITERAL(10, 126, 13), // "commandAccept"
QT_MOC_LITERAL(11, 140, 11), // "commandDeny"
QT_MOC_LITERAL(12, 152, 15), // "respondPosition"
QT_MOC_LITERAL(13, 168, 14) // "respondArrived"

    },
    "RobotControll\0commandTimeOut\0\0"
    "commandWorkStart\0repsond\0commandWorkRunning\0"
    "commandWorkStop\0commandWorkDone\0"
    "commandSend\0command\0commandAccept\0"
    "commandDeny\0respondPosition\0respondArrived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotControll[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,
       6,    1,   71,    2, 0x06 /* Public */,
       7,    1,   74,    2, 0x06 /* Public */,
       8,    1,   77,    2, 0x06 /* Public */,
      10,    1,   80,    2, 0x06 /* Public */,
      11,    1,   83,    2, 0x06 /* Public */,
      12,    1,   86,    2, 0x06 /* Public */,
      13,    1,   89,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QByteArray,    4,

       0        // eod
};

void RobotControll::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotControll *_t = static_cast<RobotControll *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->commandTimeOut(); break;
        case 1: _t->commandWorkStart((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->commandWorkRunning((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->commandWorkStop((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->commandWorkDone((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->commandSend((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->commandAccept((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->commandDeny((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->respondPosition((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->respondArrived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RobotControll::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotControll::commandTimeOut)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotControll::commandWorkStart)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotControll::commandWorkRunning)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotControll::commandWorkStop)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotControll::commandWorkDone)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotControll::commandSend)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotControll::commandAccept)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotControll::commandDeny)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotControll::respondPosition)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotControll::respondArrived)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject RobotControll::staticMetaObject = {
    { &QSerialPort::staticMetaObject, qt_meta_stringdata_RobotControll.data,
      qt_meta_data_RobotControll,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RobotControll::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotControll::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RobotControll.stringdata0))
        return static_cast<void*>(const_cast< RobotControll*>(this));
    return QSerialPort::qt_metacast(_clname);
}

int RobotControll::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSerialPort::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void RobotControll::commandTimeOut()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void RobotControll::commandWorkStart(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RobotControll::commandWorkRunning(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RobotControll::commandWorkStop(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RobotControll::commandWorkDone(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RobotControll::commandSend(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RobotControll::commandAccept(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void RobotControll::commandDeny(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void RobotControll::respondPosition(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void RobotControll::respondArrived(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
