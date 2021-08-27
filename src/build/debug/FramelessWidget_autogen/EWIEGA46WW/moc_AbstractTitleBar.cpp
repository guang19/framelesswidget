/****************************************************************************
** Meta object code from reading C++ file 'AbstractTitleBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../AbstractTitleBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AbstractTitleBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FramelessWidget__AbstractTitleBar_t {
    QByteArrayData data[17];
    char stringdata0[293];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FramelessWidget__AbstractTitleBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FramelessWidget__AbstractTitleBar_t qt_meta_stringdata_FramelessWidget__AbstractTitleBar = {
    {
QT_MOC_LITERAL(0, 0, 33), // "FramelessWidget::AbstractTitl..."
QT_MOC_LITERAL(1, 34, 23), // "onMinimizeButtonClicked"
QT_MOC_LITERAL(2, 58, 0), // ""
QT_MOC_LITERAL(3, 59, 23), // "onMaximizeButtonClicked"
QT_MOC_LITERAL(4, 83, 20), // "onCloseButtonClicked"
QT_MOC_LITERAL(5, 104, 13), // "setWindowIcon"
QT_MOC_LITERAL(6, 118, 4), // "icon"
QT_MOC_LITERAL(7, 123, 14), // "setWindowTitle"
QT_MOC_LITERAL(8, 138, 5), // "title"
QT_MOC_LITERAL(9, 144, 25), // "setWindowTitleAlignCenter"
QT_MOC_LITERAL(10, 170, 11), // "centreAlign"
QT_MOC_LITERAL(11, 182, 13), // "setButtonType"
QT_MOC_LITERAL(12, 196, 16), // "WindowButtonType"
QT_MOC_LITERAL(13, 213, 16), // "windowButtonType"
QT_MOC_LITERAL(14, 230, 21), // "onMinimizeButtonClick"
QT_MOC_LITERAL(15, 252, 21), // "onMaximizeButtonClick"
QT_MOC_LITERAL(16, 274, 18) // "onCloseButtonClick"

    },
    "FramelessWidget::AbstractTitleBar\0"
    "onMinimizeButtonClicked\0\0"
    "onMaximizeButtonClicked\0onCloseButtonClicked\0"
    "setWindowIcon\0icon\0setWindowTitle\0"
    "title\0setWindowTitleAlignCenter\0"
    "centreAlign\0setButtonType\0WindowButtonType\0"
    "windowButtonType\0onMinimizeButtonClick\0"
    "onMaximizeButtonClick\0onCloseButtonClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FramelessWidget__AbstractTitleBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   67,    2, 0x0a /* Public */,
       7,    1,   70,    2, 0x0a /* Public */,
       9,    1,   73,    2, 0x0a /* Public */,
      11,    1,   76,    2, 0x0a /* Public */,
      14,    0,   79,    2, 0x0a /* Public */,
      15,    0,   80,    2, 0x0a /* Public */,
      16,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QIcon,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FramelessWidget::AbstractTitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AbstractTitleBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onMinimizeButtonClicked(); break;
        case 1: _t->onMaximizeButtonClicked(); break;
        case 2: _t->onCloseButtonClicked(); break;
        case 3: _t->setWindowIcon((*reinterpret_cast< const QIcon(*)>(_a[1]))); break;
        case 4: _t->setWindowTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setWindowTitleAlignCenter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setButtonType((*reinterpret_cast< WindowButtonType(*)>(_a[1]))); break;
        case 7: _t->onMinimizeButtonClick(); break;
        case 8: _t->onMaximizeButtonClick(); break;
        case 9: _t->onCloseButtonClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AbstractTitleBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractTitleBar::onMinimizeButtonClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AbstractTitleBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractTitleBar::onMaximizeButtonClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AbstractTitleBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractTitleBar::onCloseButtonClicked)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FramelessWidget::AbstractTitleBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FramelessWidget__AbstractTitleBar.data,
    qt_meta_data_FramelessWidget__AbstractTitleBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FramelessWidget::AbstractTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FramelessWidget::AbstractTitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FramelessWidget__AbstractTitleBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FramelessWidget::AbstractTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void FramelessWidget::AbstractTitleBar::onMinimizeButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FramelessWidget::AbstractTitleBar::onMaximizeButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FramelessWidget::AbstractTitleBar::onCloseButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
