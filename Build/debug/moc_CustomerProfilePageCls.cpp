/****************************************************************************
** Meta object code from reading C++ file 'CustomerProfilePageCls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OkasErp/GUI/CustomerProfilePageCls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CustomerProfilePageCls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CustomerProfilePageCls_t {
    QByteArrayData data[9];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomerProfilePageCls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomerProfilePageCls_t qt_meta_stringdata_CustomerProfilePageCls = {
    {
QT_MOC_LITERAL(0, 0, 22), // "CustomerProfilePageCls"
QT_MOC_LITERAL(1, 23, 12), // "LoadMainPage"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 14), // "AddNewCustomer"
QT_MOC_LITERAL(4, 52, 14), // "UpdateCustomer"
QT_MOC_LITERAL(5, 67, 8), // "FillForm"
QT_MOC_LITERAL(6, 76, 12), // "CustomerCls&"
QT_MOC_LITERAL(7, 89, 10), // "a_Customer"
QT_MOC_LITERAL(8, 100, 9) // "ClearForm"

    },
    "CustomerProfilePageCls\0LoadMainPage\0"
    "\0AddNewCustomer\0UpdateCustomer\0FillForm\0"
    "CustomerCls&\0a_Customer\0ClearForm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomerProfilePageCls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

void CustomerProfilePageCls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustomerProfilePageCls *_t = static_cast<CustomerProfilePageCls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LoadMainPage(); break;
        case 1: _t->AddNewCustomer(); break;
        case 2: _t->UpdateCustomer(); break;
        case 3: _t->FillForm((*reinterpret_cast< CustomerCls(*)>(_a[1]))); break;
        case 4: _t->ClearForm(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CustomerProfilePageCls::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CustomerProfilePageCls.data,
      qt_meta_data_CustomerProfilePageCls,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CustomerProfilePageCls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomerProfilePageCls::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomerProfilePageCls.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "PageCls"))
        return static_cast< PageCls*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CustomerProfilePageCls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
