/****************************************************************************
** Meta object code from reading C++ file 'FramelessWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../FramelessWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FramelessWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FramelessWidget__FramelessWindow_t {
    QByteArrayData data[14];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FramelessWidget__FramelessWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FramelessWidget__FramelessWindow_t qt_meta_stringdata_FramelessWidget__FramelessWindow = {
    {
QT_MOC_LITERAL(0, 0, 32), // "FramelessWidget::FramelessWindow"
QT_MOC_LITERAL(1, 33, 14), // "setWindowTitle"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 5), // "title"
QT_MOC_LITERAL(4, 55, 13), // "setWindowIcon"
QT_MOC_LITERAL(5, 69, 4), // "icon"
QT_MOC_LITERAL(6, 74, 25), // "setWindowTitleAlignCenter"
QT_MOC_LITERAL(7, 100, 11), // "centreAlign"
QT_MOC_LITERAL(8, 112, 13), // "setButtonType"
QT_MOC_LITERAL(9, 126, 16), // "WindowButtonType"
QT_MOC_LITERAL(10, 143, 16), // "windowButtonType"
QT_MOC_LITERAL(11, 160, 21), // "onMinimizeButtonClick"
QT_MOC_LITERAL(12, 182, 21), // "onMaximizeButtonClick"
QT_MOC_LITERAL(13, 204, 18) // "onCloseButtonClick"

    },
    "FramelessWidget::FramelessWindow\0"
    "setWindowTitle\0\0title\0setWindowIcon\0"
    "icon\0setWindowTitleAlignCenter\0"
    "centreAlign\0setButtonType\0WindowButtonType\0"
    "windowButtonType\0onMinimizeButtonClick\0"
    "onMaximizeButtonClick\0onCloseButtonClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FramelessWidget__FramelessWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x26 /* Public | MethodCloned */,
       8,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   67,    2, 0x08 /* Private */,
      12,    0,   68,    2, 0x08 /* Private */,
      13,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QIcon,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FramelessWidget::FramelessWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FramelessWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setWindowTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setWindowIcon((*reinterpret_cast< const QIcon(*)>(_a[1]))); break;
        case 2: _t->setWindowTitleAlignCenter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setWindowTitleAlignCenter(); break;
        case 4: _t->setButtonType((*reinterpret_cast< WindowButtonType(*)>(_a[1]))); break;
        case 5: _t->onMinimizeButtonClick(); break;
        case 6: _t->onMaximizeButtonClick(); break;
        case 7: _t->onCloseButtonClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FramelessWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FramelessWindow::setWindowTitle)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FramelessWindow::*)(const QIcon & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FramelessWindow::setWindowIcon)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FramelessWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FramelessWindow::setWindowTitleAlignCenter)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FramelessWindow::*)(WindowButtonType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FramelessWindow::setButtonType)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FramelessWidget::FramelessWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<FramelessWidget::staticMetaObject>(),
    qt_meta_stringdata_FramelessWidget__FramelessWindow.data,
    qt_meta_data_FramelessWidget__FramelessWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FramelessWidget::FramelessWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FramelessWidget::FramelessWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FramelessWidget__FramelessWindow.stringdata0))
        return static_cast<void*>(this);
    return FramelessWidget::qt_metacast(_clname);
}

int FramelessWidget::FramelessWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = FramelessWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FramelessWidget::FramelessWindow::setWindowTitle(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FramelessWidget::FramelessWindow::setWindowIcon(const QIcon & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FramelessWidget::FramelessWindow::setWindowTitleAlignCenter(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 4
void FramelessWidget::FramelessWindow::setButtonType(WindowButtonType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
