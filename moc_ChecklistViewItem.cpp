/****************************************************************************
** Meta object code from reading C++ file 'ChecklistViewItem.h'
**
** Created: Sun Aug 26 22:51:15 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ChecklistViewItem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChecklistViewItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChecklistViewItem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      33,   18,   18,   18, 0x05,
      45,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   59,   18,   18, 0x0a,
      91,   86,   18,   18, 0x0a,
     112,   18,   18,   18, 0x0a,
     123,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChecklistViewItem[] = {
    "ChecklistViewItem\0\0ToggledItem()\0"
    "AddedItem()\0RemovedItem()\0state\0"
    "CompleteToggled(int)\0text\0"
    "NameChanged(QString)\0AddClick()\0"
    "RemoveClick()\0"
};

void ChecklistViewItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChecklistViewItem *_t = static_cast<ChecklistViewItem *>(_o);
        switch (_id) {
        case 0: _t->ToggledItem(); break;
        case 1: _t->AddedItem(); break;
        case 2: _t->RemovedItem(); break;
        case 3: _t->CompleteToggled((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->NameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->AddClick(); break;
        case 6: _t->RemoveClick(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChecklistViewItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChecklistViewItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChecklistViewItem,
      qt_meta_data_ChecklistViewItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChecklistViewItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChecklistViewItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChecklistViewItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChecklistViewItem))
        return static_cast<void*>(const_cast< ChecklistViewItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChecklistViewItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ChecklistViewItem::ToggledItem()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ChecklistViewItem::AddedItem()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ChecklistViewItem::RemovedItem()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
