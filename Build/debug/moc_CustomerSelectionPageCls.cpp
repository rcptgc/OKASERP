/****************************************************************************
** Meta object code from reading C++ file 'CustomerSelectionPageCls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OkasErp/GUI/CustomerSelectionPageCls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CustomerSelectionPageCls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CustomerSelectionPageCls_t {
    QByteArrayData data[13];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomerSelectionPageCls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomerSelectionPageCls_t qt_meta_stringdata_CustomerSelectionPageCls = {
    {
QT_MOC_LITERAL(0, 0, 24), // "CustomerSelectionPageCls"
QT_MOC_LITERAL(1, 25, 24), // "SearchAndFilterTableview"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 12), // "LoadMainPage"
QT_MOC_LITERAL(4, 64, 16), // "SelectAllClicked"
QT_MOC_LITERAL(5, 81, 15), // "ClearAllClicked"
QT_MOC_LITERAL(6, 97, 23), // "LoadProductTrackingPage"
QT_MOC_LITERAL(7, 121, 14), // "RowCheckHandle"
QT_MOC_LITERAL(8, 136, 5), // "a_Row"
QT_MOC_LITERAL(9, 142, 7), // "a_State"
QT_MOC_LITERAL(10, 150, 11), // "resizeEvent"
QT_MOC_LITERAL(11, 162, 13), // "QResizeEvent*"
QT_MOC_LITERAL(12, 176, 5) // "event"

    },
    "CustomerSelectionPageCls\0"
    "SearchAndFilterTableview\0\0LoadMainPage\0"
    "SelectAllClicked\0ClearAllClicked\0"
    "LoadProductTrackingPage\0RowCheckHandle\0"
    "a_Row\0a_State\0resizeEvent\0QResizeEvent*\0"
    "event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomerSelectionPageCls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    2,   54,    2, 0x08 /* Private */,
      10,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void CustomerSelectionPageCls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustomerSelectionPageCls *_t = static_cast<CustomerSelectionPageCls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SearchAndFilterTableview(); break;
        case 1: _t->LoadMainPage(); break;
        case 2: _t->SelectAllClicked(); break;
        case 3: _t->ClearAllClicked(); break;
        case 4: _t->LoadProductTrackingPage(); break;
        case 5: _t->RowCheckHandle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CustomerSelectionPageCls::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CustomerSelectionPageCls.data,
      qt_meta_data_CustomerSelectionPageCls,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CustomerSelectionPageCls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomerSelectionPageCls::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomerSelectionPageCls.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "PageCls"))
        return static_cast< PageCls*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CustomerSelectionPageCls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
