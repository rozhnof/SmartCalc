/****************************************************************************
** Meta object code from reading C++ file 'CalcSlots.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Views/CalcSlots.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalcSlots.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalcSlots_t {
    const uint offsetsAndSize[28];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CalcSlots_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CalcSlots_t qt_meta_stringdata_CalcSlots = {
    {
QT_MOC_LITERAL(0, 9), // "CalcSlots"
QT_MOC_LITERAL(10, 9), // "SetNumber"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 11), // "SetOperator"
QT_MOC_LITERAL(33, 12), // "SetFactorial"
QT_MOC_LITERAL(46, 6), // "SetDot"
QT_MOC_LITERAL(53, 14), // "SetOpenBracket"
QT_MOC_LITERAL(68, 15), // "SetCloseBracket"
QT_MOC_LITERAL(84, 4), // "SetX"
QT_MOC_LITERAL(89, 11), // "SetFunction"
QT_MOC_LITERAL(101, 8), // "ClearAll"
QT_MOC_LITERAL(110, 5), // "Equal"
QT_MOC_LITERAL(116, 9), // "DrawGraph"
QT_MOC_LITERAL(126, 11) // "SwitchToWin"

    },
    "CalcSlots\0SetNumber\0\0SetOperator\0"
    "SetFactorial\0SetDot\0SetOpenBracket\0"
    "SetCloseBracket\0SetX\0SetFunction\0"
    "ClearAll\0Equal\0DrawGraph\0SwitchToWin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalcSlots[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    0,   88,    2, 0x08,    3 /* Private */,
       5,    0,   89,    2, 0x08,    4 /* Private */,
       6,    0,   90,    2, 0x08,    5 /* Private */,
       7,    0,   91,    2, 0x08,    6 /* Private */,
       8,    0,   92,    2, 0x08,    7 /* Private */,
       9,    0,   93,    2, 0x08,    8 /* Private */,
      10,    0,   94,    2, 0x08,    9 /* Private */,
      11,    0,   95,    2, 0x08,   10 /* Private */,
      12,    0,   96,    2, 0x08,   11 /* Private */,
      13,    0,   97,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CalcSlots::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalcSlots *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SetNumber(); break;
        case 1: _t->SetOperator(); break;
        case 2: _t->SetFactorial(); break;
        case 3: _t->SetDot(); break;
        case 4: _t->SetOpenBracket(); break;
        case 5: _t->SetCloseBracket(); break;
        case 6: _t->SetX(); break;
        case 7: _t->SetFunction(); break;
        case 8: _t->ClearAll(); break;
        case 9: _t->Equal(); break;
        case 10: _t->DrawGraph(); break;
        case 11: _t->SwitchToWin(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject CalcSlots::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CalcSlots.offsetsAndSize,
    qt_meta_data_CalcSlots,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CalcSlots_t
, QtPrivate::TypeAndForceComplete<CalcSlots, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CalcSlots::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalcSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalcSlots.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CalcSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
