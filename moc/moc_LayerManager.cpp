/****************************************************************************
** Meta object code from reading C++ file 'LayerManager.h'
**
** Created: Fri Mar 14 12:58:43 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/Model/Tree Model/LayerManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LayerManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LayerManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      39,   37,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LayerManager[] = {
    "LayerManager\0\0editCompleted(QString)\0"
    "f\0builLists(QList<F*>)\0draw()\0"
};

void LayerManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LayerManager *_t = static_cast<LayerManager *>(_o);
        switch (_id) {
        case 0: _t->editCompleted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->builLists((*reinterpret_cast< QList<F*>(*)>(_a[1]))); break;
        case 2: _t->draw(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LayerManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LayerManager::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_LayerManager,
      qt_meta_data_LayerManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LayerManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LayerManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LayerManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LayerManager))
        return static_cast<void*>(const_cast< LayerManager*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int LayerManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
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
void LayerManager::editCompleted(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LayerManager::builLists(QList<F*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
