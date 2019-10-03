/****************************************************************************
** Meta object code from reading C++ file 'lock_screen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../aces/lock_screen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lock_screen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_lock_screen_t {
    QByteArrayData data[14];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lock_screen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lock_screen_t qt_meta_stringdata_lock_screen = {
    {
QT_MOC_LITERAL(0, 0, 11), // "lock_screen"
QT_MOC_LITERAL(1, 12, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 59, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(5, 83, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(6, 107, 21), // "open_Lock1_SerialPort"
QT_MOC_LITERAL(7, 129, 22), // "close_Lock1_SerialPort"
QT_MOC_LITERAL(8, 152, 15), // "writeData_lock1"
QT_MOC_LITERAL(9, 168, 4), // "data"
QT_MOC_LITERAL(10, 173, 14), // "readData_lock1"
QT_MOC_LITERAL(11, 188, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(12, 212, 19), // "getLock1DoorSensors"
QT_MOC_LITERAL(13, 232, 11) // "MyTimerSlot"

    },
    "lock_screen\0on_pushButton_clicked\0\0"
    "on_pushButton_2_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_4_clicked\0open_Lock1_SerialPort\0"
    "close_Lock1_SerialPort\0writeData_lock1\0"
    "data\0readData_lock1\0on_pushButton_6_clicked\0"
    "getLock1DoorSensors\0MyTimerSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lock_screen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    1,   75,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void lock_screen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        lock_screen *_t = static_cast<lock_screen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_5_clicked(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        case 4: _t->open_Lock1_SerialPort(); break;
        case 5: _t->close_Lock1_SerialPort(); break;
        case 6: _t->writeData_lock1((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 7: _t->readData_lock1(); break;
        case 8: _t->on_pushButton_6_clicked(); break;
        case 9: _t->getLock1DoorSensors(); break;
        case 10: _t->MyTimerSlot(); break;
        default: ;
        }
    }
}

const QMetaObject lock_screen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_lock_screen.data,
      qt_meta_data_lock_screen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *lock_screen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lock_screen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_lock_screen.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int lock_screen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
