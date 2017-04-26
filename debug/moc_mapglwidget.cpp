/****************************************************************************
** Meta object code from reading C++ file 'mapglwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/mapglwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapglwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MapGLWidget_t {
    QByteArrayData data[16];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MapGLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MapGLWidget_t qt_meta_stringdata_MapGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MapGLWidget"
QT_MOC_LITERAL(1, 12, 16), // "xRotationChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "angle"
QT_MOC_LITERAL(4, 36, 16), // "yRotationChanged"
QT_MOC_LITERAL(5, 53, 16), // "zRotationChanged"
QT_MOC_LITERAL(6, 70, 15), // "setXTranslation"
QT_MOC_LITERAL(7, 86, 3), // "t_x"
QT_MOC_LITERAL(8, 90, 15), // "setYTranslation"
QT_MOC_LITERAL(9, 106, 3), // "t_y"
QT_MOC_LITERAL(10, 110, 12), // "setXRotation"
QT_MOC_LITERAL(11, 123, 12), // "setYRotation"
QT_MOC_LITERAL(12, 136, 12), // "setZRotation"
QT_MOC_LITERAL(13, 149, 7), // "setZoom"
QT_MOC_LITERAL(14, 157, 3), // "t_z"
QT_MOC_LITERAL(15, 161, 7) // "cleanup"

    },
    "MapGLWidget\0xRotationChanged\0\0angle\0"
    "yRotationChanged\0zRotationChanged\0"
    "setXTranslation\0t_x\0setYTranslation\0"
    "t_y\0setXRotation\0setYRotation\0"
    "setZRotation\0setZoom\0t_z\0cleanup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapGLWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   73,    2, 0x0a /* Public */,
       8,    1,   76,    2, 0x0a /* Public */,
      10,    1,   79,    2, 0x0a /* Public */,
      11,    1,   82,    2, 0x0a /* Public */,
      12,    1,   85,    2, 0x0a /* Public */,
      13,    1,   88,    2, 0x0a /* Public */,
      15,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Float,   14,
    QMetaType::Void,

       0        // eod
};

void MapGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MapGLWidget *_t = static_cast<MapGLWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->yRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->zRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setXTranslation((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->setYTranslation((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->setXRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setYRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setZRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setZoom((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->cleanup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MapGLWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MapGLWidget::xRotationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MapGLWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MapGLWidget::yRotationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MapGLWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MapGLWidget::zRotationChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MapGLWidget::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_MapGLWidget.data,
      qt_meta_data_MapGLWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MapGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MapGLWidget.stringdata0))
        return static_cast<void*>(const_cast< MapGLWidget*>(this));
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(const_cast< MapGLWidget*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int MapGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MapGLWidget::xRotationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MapGLWidget::yRotationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MapGLWidget::zRotationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
