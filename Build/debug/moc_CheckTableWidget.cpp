/****************************************************************************
** Meta object code from reading C++ file 'CheckTableWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OkasErp/CheckTableWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CheckTableWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CheckTableWidget_t {
    QByteArrayData data[11];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CheckTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CheckTableWidget_t qt_meta_stringdata_CheckTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CheckTableWidget"
QT_MOC_LITERAL(1, 17, 10), // "RowChecked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "a_blnIsChecked"
QT_MOC_LITERAL(4, 44, 7), // "int32_t"
QT_MOC_LITERAL(5, 52, 14), // "a_intRowNumber"
QT_MOC_LITERAL(6, 67, 13), // "ButtonClicked"
QT_MOC_LITERAL(7, 81, 16), // "UpdateEditedList"
QT_MOC_LITERAL(8, 98, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(9, 116, 9), // "a_ItemPtr"
QT_MOC_LITERAL(10, 126, 16) // "TableItemClicked"

    },
    "CheckTableWidget\0RowChecked\0\0"
    "a_blnIsChecked\0int32_t\0a_intRowNumber\0"
    "ButtonClicked\0UpdateEditedList\0"
    "QTableWidgetItem*\0a_ItemPtr\0"
    "TableItemClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CheckTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       6,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   42,    2, 0x09 /* Protected */,
      10,    1,   45,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void CheckTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CheckTableWidget *_t = static_cast<CheckTableWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RowChecked((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2]))); break;
        case 1: _t->ButtonClicked((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        case 2: _t->UpdateEditedList((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->TableItemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CheckTableWidget::*)(bool , int32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckTableWidget::RowChecked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CheckTableWidget::*)(int32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckTableWidget::ButtonClicked)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CheckTableWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_CheckTableWidget.data,
      qt_meta_data_CheckTableWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CheckTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CheckTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CheckTableWidget.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int CheckTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CheckTableWidget::RowChecked(bool _t1, int32_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CheckTableWidget::ButtonClicked(int32_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_OrderTableWidget_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OrderTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OrderTableWidget_t qt_meta_stringdata_OrderTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 16) // "OrderTableWidget"

    },
    "OrderTableWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrderTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void OrderTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject OrderTableWidget::staticMetaObject = {
    { &CheckTableWidget::staticMetaObject, qt_meta_stringdata_OrderTableWidget.data,
      qt_meta_data_OrderTableWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OrderTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrderTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OrderTableWidget.stringdata0))
        return static_cast<void*>(this);
    return CheckTableWidget::qt_metacast(_clname);
}

int OrderTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CheckTableWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_UserTableWidget_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserTableWidget_t qt_meta_stringdata_UserTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 15) // "UserTableWidget"

    },
    "UserTableWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void UserTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject UserTableWidget::staticMetaObject = {
    { &CheckTableWidget::staticMetaObject, qt_meta_stringdata_UserTableWidget.data,
      qt_meta_data_UserTableWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UserTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserTableWidget.stringdata0))
        return static_cast<void*>(this);
    return CheckTableWidget::qt_metacast(_clname);
}

int UserTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CheckTableWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
