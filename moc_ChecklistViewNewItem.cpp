/****************************************************************************
** Meta object code from reading C++ file 'ChecklistViewNewItem.h'
**
** Created: Sun Aug 26 16:34:01 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ChecklistViewNewItem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChecklistViewNewItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChecklistViewNewItem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChecklistViewNewItem[] = {
    "ChecklistViewNewItem\0\0AddedItem()\0"
    "AddClick()\0"
};

void ChecklistViewNewItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChecklistViewNewItem *_t = static_cast<ChecklistViewNewItem *>(_o);
        switch (_id) {
        case 0: _t->AddedItem(); break;
        case 1: _t->AddClick(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ChecklistViewNewItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChecklistViewNewItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChecklistViewNewItem,
      qt_meta_data_ChecklistViewNewItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChecklistViewNewItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChecklistViewNewItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChecklistViewNewItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChecklistViewNewItem))
        return static_cast<void*>(const_cast< ChecklistViewNewItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChecklistViewNewItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ChecklistViewNewItem::AddedItem()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
