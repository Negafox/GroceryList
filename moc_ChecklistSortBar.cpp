/****************************************************************************
** Meta object code from reading C++ file 'ChecklistSortBar.h'
**
** Created: Sun Aug 26 23:32:47 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ChecklistSortBar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChecklistSortBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChecklistSortBar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   17,   17,   17, 0x0a,
      52,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChecklistSortBar[] = {
    "ChecklistSortBar\0\0SortChanged()\0"
    "CompleteSortClick()\0NameSortClick()\0"
};

void ChecklistSortBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChecklistSortBar *_t = static_cast<ChecklistSortBar *>(_o);
        switch (_id) {
        case 0: _t->SortChanged(); break;
        case 1: _t->CompleteSortClick(); break;
        case 2: _t->NameSortClick(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ChecklistSortBar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChecklistSortBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChecklistSortBar,
      qt_meta_data_ChecklistSortBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChecklistSortBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChecklistSortBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChecklistSortBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChecklistSortBar))
        return static_cast<void*>(const_cast< ChecklistSortBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChecklistSortBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ChecklistSortBar::SortChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
