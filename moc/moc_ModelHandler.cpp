/****************************************************************************
** Meta object code from reading C++ file 'ModelHandler.h'
**
** Created: Tue Sep 10 19:20:53 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ModelHandler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModelHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ModelHandler[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   13,   13,   13, 0x0a,
      50,   13,   13,   13, 0x0a,
      66,   13,   13,   13, 0x0a,
      76,   13,   13,   13, 0x0a,
      83,   13,   13,   13, 0x08,
     104,   13,   13,   13, 0x08,
     130,  123,  118,   13, 0x08,
     156,   13,  118,   13, 0x28,
     171,   13,   13,   13, 0x08,
     183,  123,  118,   13, 0x08,
     209,   13,  118,   13, 0x28,
     224,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ModelHandler[] = {
    "ModelHandler\0\0f\0builLists(QList<F*>)\0"
    "showDialog()\0updateActions()\0execute()\0"
    "draw()\0insertGridImporter()\0insertChild()\0"
    "bool\0parent\0insertColumn(QModelIndex)\0"
    "insertColumn()\0insertRow()\0"
    "removeColumn(QModelIndex)\0removeColumn()\0"
    "removeRow()\0"
};

void ModelHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ModelHandler *_t = static_cast<ModelHandler *>(_o);
        switch (_id) {
        case 0: _t->builLists((*reinterpret_cast< QList<F*>(*)>(_a[1]))); break;
        case 1: _t->showDialog(); break;
        case 2: _t->updateActions(); break;
        case 3: _t->execute(); break;
        case 4: _t->draw(); break;
        case 5: _t->insertGridImporter(); break;
        case 6: _t->insertChild(); break;
        case 7: { bool _r = _t->insertColumn((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->insertColumn();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->insertRow(); break;
        case 10: { bool _r = _t->removeColumn((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->removeColumn();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: _t->removeRow(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ModelHandler::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ModelHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ModelHandler,
      qt_meta_data_ModelHandler, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ModelHandler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ModelHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ModelHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModelHandler))
        return static_cast<void*>(const_cast< ModelHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int ModelHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ModelHandler::builLists(QList<F*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
