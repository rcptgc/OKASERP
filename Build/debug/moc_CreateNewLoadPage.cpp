/****************************************************************************
** Meta object code from reading C++ file 'CreateNewLoadPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OkasErp/GUI/CreateNewLoadPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateNewLoadPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CreateNewLoadPage_t {
    QByteArrayData data[8];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateNewLoadPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateNewLoadPage_t qt_meta_stringdata_CreateNewLoadPage = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CreateNewLoadPage"
QT_MOC_LITERAL(1, 18, 9), // "FillTable"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "GetOrder"
QT_MOC_LITERAL(4, 38, 11), // "DeleteOrder"
QT_MOC_LITERAL(5, 50, 15), // "AddOrderToBatch"
QT_MOC_LITERAL(6, 66, 15), // "LoadProcessPage"
QT_MOC_LITERAL(7, 82, 10) // "CreateLoad"

    },
    "CreateNewLoadPage\0FillTable\0\0GetOrder\0"
    "DeleteOrder\0AddOrderToBatch\0LoadProcessPage\0"
    "CreateLoad"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateNewLoadPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateNewLoadPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateNewLoadPage *_t = static_cast<CreateNewLoadPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->FillTable(); break;
        case 1: _t->GetOrder(); break;
        case 2: _t->DeleteOrder(); break;
        case 3: _t->AddOrderToBatch(); break;
        case 4: _t->LoadProcessPage(); break;
        case 5: _t->CreateLoad(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CreateNewLoadPage::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CreateNewLoadPage.data,
      qt_meta_data_CreateNewLoadPage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CreateNewLoadPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateNewLoadPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CreateNewLoadPage.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "PageCls"))
        return static_cast< PageCls*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CreateNewLoadPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
