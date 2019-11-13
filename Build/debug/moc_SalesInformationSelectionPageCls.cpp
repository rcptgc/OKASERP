/****************************************************************************
** Meta object code from reading C++ file 'SalesInformationSelectionPageCls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OkasErp/GUI/SalesInformationSelectionPageCls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SalesInformationSelectionPageCls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SalesInformationSelectionPageCls_t {
    QByteArrayData data[5];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SalesInformationSelectionPageCls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SalesInformationSelectionPageCls_t qt_meta_stringdata_SalesInformationSelectionPageCls = {
    {
QT_MOC_LITERAL(0, 0, 32), // "SalesInformationSelectionPageCls"
QT_MOC_LITERAL(1, 33, 18), // "LoadSalesEntryPage"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 19), // "LoadSalesReportPage"
QT_MOC_LITERAL(4, 73, 12) // "LoadMainPage"

    },
    "SalesInformationSelectionPageCls\0"
    "LoadSalesEntryPage\0\0LoadSalesReportPage\0"
    "LoadMainPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SalesInformationSelectionPageCls[] = {

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
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SalesInformationSelectionPageCls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SalesInformationSelectionPageCls *_t = static_cast<SalesInformationSelectionPageCls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LoadSalesEntryPage(); break;
        case 1: _t->LoadSalesReportPage(); break;
        case 2: _t->LoadMainPage(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SalesInformationSelectionPageCls::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SalesInformationSelectionPageCls.data,
      qt_meta_data_SalesInformationSelectionPageCls,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SalesInformationSelectionPageCls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SalesInformationSelectionPageCls::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SalesInformationSelectionPageCls.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "PageCls"))
        return static_cast< PageCls*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SalesInformationSelectionPageCls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
