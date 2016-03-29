/****************************************************************************
** Meta object code from reading C++ file 'clienttcp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ProjetTerm/clienttcp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clienttcp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientTCP_t {
    QByteArrayData data[10];
    char stringdata[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientTCP_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientTCP_t qt_meta_stringdata_ClientTCP = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 21),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 14),
QT_MOC_LITERAL(4, 48, 9),
QT_MOC_LITERAL(5, 58, 3),
QT_MOC_LITERAL(6, 62, 12),
QT_MOC_LITERAL(7, 75, 1),
QT_MOC_LITERAL(8, 77, 12),
QT_MOC_LITERAL(9, 90, 7)
    },
    "ClientTCP\0vers_IHM_connexion_OK\0\0"
    "vers_IHM_texte\0recoit_IP\0IP2\0recoit_texte\0"
    "t\0connexion_OK\0lecture"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientTCP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   48,    2, 0x0a /* Public */,
       6,    1,   51,    2, 0x0a /* Public */,
       8,    0,   54,    2, 0x08 /* Private */,
       9,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClientTCP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientTCP *_t = static_cast<ClientTCP *>(_o);
        switch (_id) {
        case 0: _t->vers_IHM_connexion_OK(); break;
        case 1: _t->vers_IHM_texte((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->recoit_IP((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->recoit_texte((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->connexion_OK(); break;
        case 5: _t->lecture(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClientTCP::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientTCP::vers_IHM_connexion_OK)) {
                *result = 0;
            }
        }
        {
            typedef void (ClientTCP::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientTCP::vers_IHM_texte)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ClientTCP::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientTCP.data,
      qt_meta_data_ClientTCP,  qt_static_metacall, 0, 0}
};


const QMetaObject *ClientTCP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientTCP::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientTCP.stringdata))
        return static_cast<void*>(const_cast< ClientTCP*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientTCP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ClientTCP::vers_IHM_connexion_OK()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ClientTCP::vers_IHM_texte(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
