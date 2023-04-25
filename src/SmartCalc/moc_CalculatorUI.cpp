/****************************************************************************
** Meta object code from reading C++ file 'CalculatorUI.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Views/CalculatorUI.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalculatorUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalculatorUI_t {
    const uint offsetsAndSize[26];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CalculatorUI_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CalculatorUI_t qt_meta_stringdata_CalculatorUI = {
    {
QT_MOC_LITERAL(0, 12), // "CalculatorUI"
QT_MOC_LITERAL(13, 9), // "SetNumber"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 11), // "SetFunction"
QT_MOC_LITERAL(36, 11), // "SetOperator"
QT_MOC_LITERAL(48, 12), // "SetFactorial"
QT_MOC_LITERAL(61, 6), // "SetDot"
QT_MOC_LITERAL(68, 4), // "SetX"
QT_MOC_LITERAL(73, 14), // "SetOpenBracket"
QT_MOC_LITERAL(88, 15), // "SetCloseBracket"
QT_MOC_LITERAL(104, 5), // "Clear"
QT_MOC_LITERAL(110, 9), // "GetResult"
QT_MOC_LITERAL(120, 9) // "DrawGraph"

    },
    "CalculatorUI\0SetNumber\0\0SetFunction\0"
    "SetOperator\0SetFactorial\0SetDot\0SetX\0"
    "SetOpenBracket\0SetCloseBracket\0Clear\0"
    "GetResult\0DrawGraph"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalculatorUI[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    0,   88,    2, 0x08,    9 /* Private */,
      11,    0,   89,    2, 0x08,   10 /* Private */,
      12,    0,   90,    2, 0x08,   11 /* Private */,

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

       0        // eod
};

void CalculatorUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalculatorUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SetNumber(); break;
        case 1: _t->SetFunction(); break;
        case 2: _t->SetOperator(); break;
        case 3: _t->SetFactorial(); break;
        case 4: _t->SetDot(); break;
        case 5: _t->SetX(); break;
        case 6: _t->SetOpenBracket(); break;
        case 7: _t->SetCloseBracket(); break;
        case 8: _t->Clear(); break;
        case 9: _t->GetResult(); break;
        case 10: _t->DrawGraph(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject CalculatorUI::staticMetaObject = { {
    QMetaObject::SuperData::link<MainWindow::staticMetaObject>(),
    qt_meta_stringdata_CalculatorUI.offsetsAndSize,
    qt_meta_data_CalculatorUI,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CalculatorUI_t
, QtPrivate::TypeAndForceComplete<CalculatorUI, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CalculatorUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalculatorUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalculatorUI.stringdata0))
        return static_cast<void*>(this);
    return MainWindow::qt_metacast(_clname);
}

int CalculatorUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
