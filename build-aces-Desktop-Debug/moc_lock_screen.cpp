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
    QByteArrayData data[24];
    char stringdata0[336];
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
QT_MOC_LITERAL(6, 107, 22), // "close_Lock1_SerialPort"
QT_MOC_LITERAL(7, 130, 14), // "readData_lock1"
QT_MOC_LITERAL(8, 145, 8), // "LogEvent"
QT_MOC_LITERAL(9, 154, 7), // "EventID"
QT_MOC_LITERAL(10, 162, 6), // "genkey"
QT_MOC_LITERAL(11, 169, 11), // "std::string"
QT_MOC_LITERAL(12, 181, 11), // "const char*"
QT_MOC_LITERAL(13, 193, 9), // "challenge"
QT_MOC_LITERAL(14, 203, 3), // "rot"
QT_MOC_LITERAL(15, 207, 5), // "char*"
QT_MOC_LITERAL(16, 213, 6), // "char[]"
QT_MOC_LITERAL(17, 220, 1), // "b"
QT_MOC_LITERAL(18, 222, 4), // "seed"
QT_MOC_LITERAL(19, 227, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(20, 251, 11), // "MyTimerSlot"
QT_MOC_LITERAL(21, 263, 24), // "on_pushButton_12_clicked"
QT_MOC_LITERAL(22, 288, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(23, 312, 23) // "on_pushButton_7_clicked"

    },
    "lock_screen\0on_pushButton_clicked\0\0"
    "on_pushButton_2_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_4_clicked\0close_Lock1_SerialPort\0"
    "readData_lock1\0LogEvent\0EventID\0genkey\0"
    "std::string\0const char*\0challenge\0rot\0"
    "char*\0char[]\0b\0seed\0on_pushButton_6_clicked\0"
    "MyTimerSlot\0on_pushButton_12_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_7_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lock_screen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    1,   90,    2, 0x08 /* Private */,
      10,    1,   93,    2, 0x08 /* Private */,
      14,    2,   96,    2, 0x08 /* Private */,
      19,    0,  101,    2, 0x08 /* Private */,
      20,    0,  102,    2, 0x08 /* Private */,
      21,    0,  103,    2, 0x08 /* Private */,
      22,    0,  104,    2, 0x08 /* Private */,
      23,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QByteArray,
    QMetaType::Void, QMetaType::QString,    9,
    0x80000000 | 11, 0x80000000 | 12,   13,
    0x80000000 | 15, 0x80000000 | 16, QMetaType::Char,   17,   18,
    QMetaType::Void,
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
        case 4: _t->close_Lock1_SerialPort(); break;
        case 5: { QByteArray _r = _t->readData_lock1();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->LogEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: { std::string _r = _t->genkey((*reinterpret_cast< const char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 8: { char* _r = _t->rot((*reinterpret_cast< char(*)[]>(_a[1])),(*reinterpret_cast< char(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< char**>(_a[0]) = std::move(_r); }  break;
        case 9: _t->on_pushButton_6_clicked(); break;
        case 10: _t->MyTimerSlot(); break;
        case 11: _t->on_pushButton_12_clicked(); break;
        case 12: _t->on_pushButton_3_clicked(); break;
        case 13: _t->on_pushButton_7_clicked(); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
