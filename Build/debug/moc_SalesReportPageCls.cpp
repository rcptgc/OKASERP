/****************************************************************************
** Meta object code from reading C++ file 'SalesReportPageCls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OkasErp/GUI/SalesReportPageCls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SalesReportPageCls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SalesReportPageCls_t {
    QByteArrayData data[8];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SalesReportPageCls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SalesReportPageCls_t qt_meta_stringdata_SalesReportPageCls = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SalesReportPageCls"
QT_MOC_LITERAL(1, 19, 21), // "CreateReportFromTable"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 17), // "ShowSelectedSales"
QT_MOC_LITERAL(4, 60, 17), // "LoadSalesMainPage"
QT_MOC_LITERAL(5, 78, 14), // "FillSalesTable"
QT_MOC_LITERAL(6, 93, 15), // "QList<OrderCls>"
QT_MOC_LITERAL(7, 109, 11) // "a_OrderList"

    },
    "SalesReportPageCls\0CreateReportFromTable\0"
    "\0ShowSelectedSales\0LoadSalesMainPage\0"
    "FillSalesTable\0QList<OrderCls>\0"
    "a_OrderList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SalesReportPageCls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void SalesReportPageCls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SalesReportPageCls *_t = static_cast<SalesReportPageCls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateReportFromTable(); break;
        case 1: _t->ShowSelectedSales(); break;
        case 2: _t->LoadSalesMainPage(); break;
        case 3: _t->FillSalesTable((*reinterpret_cast< QList<OrderCls>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SalesReportPageCls::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SalesReportPageCls.data,
      qt_meta_data_SalesReportPageCls,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SalesReportPageCls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SalesReportPageCls::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SalesReportPageCls.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "PageCls"))
        return static_cast< PageCls*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SalesReportPageCls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
