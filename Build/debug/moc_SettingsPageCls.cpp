/****************************************************************************
** Meta object code from reading C++ file 'SettingsPageCls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OkasErp/GUI/SettingsPageCls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SettingsPageCls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SettingsPageCls_t {
    QByteArrayData data[7];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsPageCls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsPageCls_t qt_meta_stringdata_SettingsPageCls = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SettingsPageCls"
QT_MOC_LITERAL(1, 16, 12), // "LoadMainPage"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 23), // "SelectAndSaveImagesPath"
QT_MOC_LITERAL(4, 54, 17), // "SaveConfiguration"
QT_MOC_LITERAL(5, 72, 15), // "LoadNewUserPage"
QT_MOC_LITERAL(6, 88, 16) // "LoadEditUserPage"

    },
    "SettingsPageCls\0LoadMainPage\0\0"
    "SelectAndSaveImagesPath\0SaveConfiguration\0"
    "LoadNewUserPage\0LoadEditUserPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsPageCls[] = {

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
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SettingsPageCls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingsPageCls *_t = static_cast<SettingsPageCls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LoadMainPage(); break;
        case 1: _t->SelectAndSaveImagesPath(); break;
        case 2: _t->SaveConfiguration(); break;
        case 3: _t->LoadNewUserPage(); break;
        case 4: _t->LoadEditUserPage(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SettingsPageCls::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SettingsPageCls.data,
      qt_meta_data_SettingsPageCls,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SettingsPageCls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsPageCls::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsPageCls.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "PageCls"))
        return static_cast< PageCls*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SettingsPageCls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
