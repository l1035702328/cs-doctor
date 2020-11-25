/****************************************************************************
** Meta object code from reading C++ file 'csqiyuan.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../csqiyuan.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'csqiyuan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_csqiyuan_t {
    QByteArrayData data[8];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_csqiyuan_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_csqiyuan_t qt_meta_stringdata_csqiyuan = {
    {
QT_MOC_LITERAL(0, 0, 8), // "csqiyuan"
QT_MOC_LITERAL(1, 9, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "checked"
QT_MOC_LITERAL(4, 38, 21), // "on_checkBox_2_clicked"
QT_MOC_LITERAL(5, 60, 21), // "on_checkBox_3_clicked"
QT_MOC_LITERAL(6, 82, 21), // "on_checkBox_4_clicked"
QT_MOC_LITERAL(7, 104, 16) // "on_zhuru_clicked"

    },
    "csqiyuan\0on_checkBox_clicked\0\0checked\0"
    "on_checkBox_2_clicked\0on_checkBox_3_clicked\0"
    "on_checkBox_4_clicked\0on_zhuru_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_csqiyuan[] = {

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
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       5,    1,   45,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

       0        // eod
};

void csqiyuan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        csqiyuan *_t = static_cast<csqiyuan *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_checkBox_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_checkBox_3_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_checkBox_4_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_zhuru_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject csqiyuan::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_csqiyuan.data,
      qt_meta_data_csqiyuan,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *csqiyuan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *csqiyuan::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_csqiyuan.stringdata0))
        return static_cast<void*>(const_cast< csqiyuan*>(this));
    return QWidget::qt_metacast(_clname);
}

int csqiyuan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
