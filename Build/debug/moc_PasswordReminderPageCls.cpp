/****************************************************************************
** Meta object code from reading C++ file 'PasswordReminderPageCls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OkasErp/GUI/PasswordReminderPageCls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PasswordReminderPageCls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PasswordReminderPageCls_t {
    QByteArrayData data[6];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PasswordReminderPageCls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PasswordReminderPageCls_t qt_meta_stringdata_PasswordReminderPageCls = {
    {
QT_MOC_LITERAL(0, 0, 23), // "PasswordReminderPageCls"
QT_MOC_LITERAL(1, 24, 17), // "ReturnToLoginPage"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 9), // "SendEmail"
QT_MOC_LITERAL(4, 53, 8), // "mailSent"
QT_MOC_LITERAL(5, 62, 6) // "status"

    },
    "PasswordReminderPageCls\0ReturnToLoginPage\0"
    "\0SendEmail\0mailSent\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PasswordReminderPageCls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    1,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void PasswordReminderPageCls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PasswordReminderPageCls *_t = static_cast<PasswordReminderPageCls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReturnToLoginPage(); break;
        case 1: _t->SendEmail(); break;
        case 2: _t->mailSent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PasswordReminderPageCls::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PasswordReminderPageCls.data,
      qt_meta_data_PasswordReminderPageCls,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PasswordReminderPageCls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PasswordReminderPageCls::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PasswordReminderPageCls.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "PageCls"))
        return static_cast< PageCls*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PasswordReminderPageCls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
