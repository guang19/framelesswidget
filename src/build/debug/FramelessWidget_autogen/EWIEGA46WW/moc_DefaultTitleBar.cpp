/****************************************************************************
** Meta object code from reading C++ file 'DefaultTitleBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../DefaultTitleBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DefaultTitleBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FramelessWidget__DefaultTitleBar_t {
    QByteArrayData data[11];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FramelessWidget__DefaultTitleBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FramelessWidget__DefaultTitleBar_t qt_meta_stringdata_FramelessWidget__DefaultTitleBar = {
    {
QT_MOC_LITERAL(0, 0, 32), // "FramelessWidget::DefaultTitleBar"
QT_MOC_LITERAL(1, 33, 13), // "setWindowIcon"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 4), // "icon"
QT_MOC_LITERAL(4, 53, 14), // "setWindowTitle"
QT_MOC_LITERAL(5, 68, 5), // "title"
QT_MOC_LITERAL(6, 74, 25), // "setWindowTitleAlignCenter"
QT_MOC_LITERAL(7, 100, 11), // "centreAlign"
QT_MOC_LITERAL(8, 112, 13), // "setButtonType"
QT_MOC_LITERAL(9, 126, 16), // "WindowButtonType"
QT_MOC_LITERAL(10, 143, 16) // "windowButtonType"

    },
    "FramelessWidget::DefaultTitleBar\0"
    "setWindowIcon\0\0icon\0setWindowTitle\0"
    "title\0setWindowTitleAlignCenter\0"
    "centreAlign\0setButtonType\0WindowButtonType\0"
    "windowButtonType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FramelessWidget__DefaultTitleBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QIcon,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void FramelessWidget::DefaultTitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DefaultTitleBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setWindowIcon((*reinterpret_cast< const QIcon(*)>(_a[1]))); break;
        case 1: _t->setWindowTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setWindowTitleAlignCenter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setButtonType((*reinterpret_cast< WindowButtonType(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FramelessWidget::DefaultTitleBar::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractTitleBar::staticMetaObject>(),
    qt_meta_stringdata_FramelessWidget__DefaultTitleBar.data,
    qt_meta_data_FramelessWidget__DefaultTitleBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FramelessWidget::DefaultTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FramelessWidget::DefaultTitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FramelessWidget__DefaultTitleBar.stringdata0))
        return static_cast<void*>(this);
    return AbstractTitleBar::qt_metacast(_clname);
}

int FramelessWidget::DefaultTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractTitleBar::qt_metacall(_c, _id, _a);
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
