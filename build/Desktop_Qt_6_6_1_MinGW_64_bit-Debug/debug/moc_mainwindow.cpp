/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_login_clicked",
    "",
    "onLogoutButtonClicked",
    "showAdminPage",
    "showEmployeePage",
    "showCustomerPage",
    "on_close_clicked",
    "InventoryLoader",
    "ShowCarDetails",
    "on_cancelRentalBtn_clicked",
    "onCarListViewClicked",
    "QModelIndex",
    "index",
    "onPushButtonClicked",
    "onPaymentsButtonClicked",
    "OnCustomerListViewClicked",
    "OnRentListViewClicked",
    "OnAdminListViewClicked",
    "on_canelRentalBtn2_clicked",
    "on_saveRentalBtn_clicked",
    "CustomerLoader",
    "RentalsLoader",
    "CarLoader",
    "on_empSaveCustomerBtn_clicked",
    "on_empCancelAddCustomerBtn_clicked",
    "on_edit_car_2_textChanged",
    "arg1",
    "on_saveCustomerEditBtn_clicked",
    "on_delCustomerBtn_clicked",
    "on_cancelCustomerEditBtn_clicked",
    "on_paidBtn_clicked",
    "on_RegisterFisherSearchLineEdir_textChanged",
    "on_edit_carSearch_textChanged",
    "on_SaveEditCar_clicked",
    "on_saveAddCarBtn_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[72];
    char stringdata0[11];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[14];
    char stringdata5[17];
    char stringdata6[17];
    char stringdata7[17];
    char stringdata8[16];
    char stringdata9[15];
    char stringdata10[27];
    char stringdata11[21];
    char stringdata12[12];
    char stringdata13[6];
    char stringdata14[20];
    char stringdata15[24];
    char stringdata16[26];
    char stringdata17[22];
    char stringdata18[23];
    char stringdata19[27];
    char stringdata20[25];
    char stringdata21[15];
    char stringdata22[14];
    char stringdata23[10];
    char stringdata24[30];
    char stringdata25[35];
    char stringdata26[26];
    char stringdata27[5];
    char stringdata28[31];
    char stringdata29[26];
    char stringdata30[33];
    char stringdata31[19];
    char stringdata32[44];
    char stringdata33[30];
    char stringdata34[23];
    char stringdata35[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 16),  // "on_login_clicked"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 21),  // "onLogoutButtonClicked"
        QT_MOC_LITERAL(51, 13),  // "showAdminPage"
        QT_MOC_LITERAL(65, 16),  // "showEmployeePage"
        QT_MOC_LITERAL(82, 16),  // "showCustomerPage"
        QT_MOC_LITERAL(99, 16),  // "on_close_clicked"
        QT_MOC_LITERAL(116, 15),  // "InventoryLoader"
        QT_MOC_LITERAL(132, 14),  // "ShowCarDetails"
        QT_MOC_LITERAL(147, 26),  // "on_cancelRentalBtn_clicked"
        QT_MOC_LITERAL(174, 20),  // "onCarListViewClicked"
        QT_MOC_LITERAL(195, 11),  // "QModelIndex"
        QT_MOC_LITERAL(207, 5),  // "index"
        QT_MOC_LITERAL(213, 19),  // "onPushButtonClicked"
        QT_MOC_LITERAL(233, 23),  // "onPaymentsButtonClicked"
        QT_MOC_LITERAL(257, 25),  // "OnCustomerListViewClicked"
        QT_MOC_LITERAL(283, 21),  // "OnRentListViewClicked"
        QT_MOC_LITERAL(305, 22),  // "OnAdminListViewClicked"
        QT_MOC_LITERAL(328, 26),  // "on_canelRentalBtn2_clicked"
        QT_MOC_LITERAL(355, 24),  // "on_saveRentalBtn_clicked"
        QT_MOC_LITERAL(380, 14),  // "CustomerLoader"
        QT_MOC_LITERAL(395, 13),  // "RentalsLoader"
        QT_MOC_LITERAL(409, 9),  // "CarLoader"
        QT_MOC_LITERAL(419, 29),  // "on_empSaveCustomerBtn_clicked"
        QT_MOC_LITERAL(449, 34),  // "on_empCancelAddCustomerBtn_cl..."
        QT_MOC_LITERAL(484, 25),  // "on_edit_car_2_textChanged"
        QT_MOC_LITERAL(510, 4),  // "arg1"
        QT_MOC_LITERAL(515, 30),  // "on_saveCustomerEditBtn_clicked"
        QT_MOC_LITERAL(546, 25),  // "on_delCustomerBtn_clicked"
        QT_MOC_LITERAL(572, 32),  // "on_cancelCustomerEditBtn_clicked"
        QT_MOC_LITERAL(605, 18),  // "on_paidBtn_clicked"
        QT_MOC_LITERAL(624, 43),  // "on_RegisterFisherSearchLineEd..."
        QT_MOC_LITERAL(668, 29),  // "on_edit_carSearch_textChanged"
        QT_MOC_LITERAL(698, 22),  // "on_SaveEditCar_clicked"
        QT_MOC_LITERAL(721, 24)   // "on_saveAddCarBtn_clicked"
    },
    "MainWindow",
    "on_login_clicked",
    "",
    "onLogoutButtonClicked",
    "showAdminPage",
    "showEmployeePage",
    "showCustomerPage",
    "on_close_clicked",
    "InventoryLoader",
    "ShowCarDetails",
    "on_cancelRentalBtn_clicked",
    "onCarListViewClicked",
    "QModelIndex",
    "index",
    "onPushButtonClicked",
    "onPaymentsButtonClicked",
    "OnCustomerListViewClicked",
    "OnRentListViewClicked",
    "OnAdminListViewClicked",
    "on_canelRentalBtn2_clicked",
    "on_saveRentalBtn_clicked",
    "CustomerLoader",
    "RentalsLoader",
    "CarLoader",
    "on_empSaveCustomerBtn_clicked",
    "on_empCancelAddCustomerBtn_clicked",
    "on_edit_car_2_textChanged",
    "arg1",
    "on_saveCustomerEditBtn_clicked",
    "on_delCustomerBtn_clicked",
    "on_cancelCustomerEditBtn_clicked",
    "on_paidBtn_clicked",
    "on_RegisterFisherSearchLineEdir_textChanged",
    "on_edit_carSearch_textChanged",
    "on_SaveEditCar_clicked",
    "on_saveAddCarBtn_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  200,    2, 0x08,    1 /* Private */,
       3,    0,  201,    2, 0x08,    2 /* Private */,
       4,    0,  202,    2, 0x08,    3 /* Private */,
       5,    0,  203,    2, 0x08,    4 /* Private */,
       6,    0,  204,    2, 0x08,    5 /* Private */,
       7,    0,  205,    2, 0x08,    6 /* Private */,
       8,    0,  206,    2, 0x08,    7 /* Private */,
       9,    0,  207,    2, 0x08,    8 /* Private */,
      10,    0,  208,    2, 0x08,    9 /* Private */,
      11,    1,  209,    2, 0x08,   10 /* Private */,
      14,    0,  212,    2, 0x08,   12 /* Private */,
      15,    0,  213,    2, 0x08,   13 /* Private */,
      16,    1,  214,    2, 0x08,   14 /* Private */,
      17,    1,  217,    2, 0x08,   16 /* Private */,
      18,    1,  220,    2, 0x08,   18 /* Private */,
      19,    0,  223,    2, 0x08,   20 /* Private */,
      20,    0,  224,    2, 0x08,   21 /* Private */,
      21,    0,  225,    2, 0x08,   22 /* Private */,
      22,    0,  226,    2, 0x08,   23 /* Private */,
      23,    0,  227,    2, 0x08,   24 /* Private */,
      24,    0,  228,    2, 0x08,   25 /* Private */,
      25,    0,  229,    2, 0x08,   26 /* Private */,
      26,    1,  230,    2, 0x08,   27 /* Private */,
      28,    0,  233,    2, 0x08,   29 /* Private */,
      29,    0,  234,    2, 0x08,   30 /* Private */,
      30,    0,  235,    2, 0x08,   31 /* Private */,
      31,    0,  236,    2, 0x08,   32 /* Private */,
      32,    1,  237,    2, 0x08,   33 /* Private */,
      33,    1,  240,    2, 0x08,   35 /* Private */,
      34,    0,  243,    2, 0x08,   37 /* Private */,
      35,    0,  244,    2, 0x08,   38 /* Private */,

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
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_login_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLogoutButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showAdminPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showEmployeePage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showCustomerPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_close_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'InventoryLoader'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ShowCarDetails'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cancelRentalBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCarListViewClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'onPushButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPaymentsButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnCustomerListViewClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'OnRentListViewClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'OnAdminListViewClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_canelRentalBtn2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_saveRentalBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CustomerLoader'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RentalsLoader'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CarLoader'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_empSaveCustomerBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_empCancelAddCustomerBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_edit_car_2_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_saveCustomerEditBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_delCustomerBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cancelCustomerEditBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_paidBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_RegisterFisherSearchLineEdir_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_edit_carSearch_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_SaveEditCar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_saveAddCarBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_login_clicked(); break;
        case 1: _t->onLogoutButtonClicked(); break;
        case 2: _t->showAdminPage(); break;
        case 3: _t->showEmployeePage(); break;
        case 4: _t->showCustomerPage(); break;
        case 5: _t->on_close_clicked(); break;
        case 6: _t->InventoryLoader(); break;
        case 7: _t->ShowCarDetails(); break;
        case 8: _t->on_cancelRentalBtn_clicked(); break;
        case 9: _t->onCarListViewClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 10: _t->onPushButtonClicked(); break;
        case 11: _t->onPaymentsButtonClicked(); break;
        case 12: _t->OnCustomerListViewClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 13: _t->OnRentListViewClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 14: _t->OnAdminListViewClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 15: _t->on_canelRentalBtn2_clicked(); break;
        case 16: _t->on_saveRentalBtn_clicked(); break;
        case 17: _t->CustomerLoader(); break;
        case 18: _t->RentalsLoader(); break;
        case 19: _t->CarLoader(); break;
        case 20: _t->on_empSaveCustomerBtn_clicked(); break;
        case 21: _t->on_empCancelAddCustomerBtn_clicked(); break;
        case 22: _t->on_edit_car_2_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 23: _t->on_saveCustomerEditBtn_clicked(); break;
        case 24: _t->on_delCustomerBtn_clicked(); break;
        case 25: _t->on_cancelCustomerEditBtn_clicked(); break;
        case 26: _t->on_paidBtn_clicked(); break;
        case 27: _t->on_RegisterFisherSearchLineEdir_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 28: _t->on_edit_carSearch_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->on_SaveEditCar_clicked(); break;
        case 30: _t->on_saveAddCarBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 31;
    }
    return _id;
}
QT_WARNING_POP
