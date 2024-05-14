#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "database.h"
#include "inventory.h"
#include <car.h>
#include <admin.h>
#include <employee.h>
#include <customer.h>
#include <rentals.h>
#include <QMessageBox>
#include <carlistmodel.h>
#include <customerlistmodel.h>
#include <rentalslistmodel.h>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_clicked();

    void onLogoutButtonClicked();

    void showAdminPage();

    void showEmployeePage();

    void showCustomerPage();

    void on_close_clicked();

    void InventoryLoader();
    void ShowCarDetails();
    void on_cancelRentalBtn_clicked();

    void onCarListViewClicked(const QModelIndex &index);
    void onPushButtonClicked();
    void onPaymentsButtonClicked();

    void OnCustomerListViewClicked(const QModelIndex &index);
    void OnRentListViewClicked(const QModelIndex &index);
    void OnAdminListViewClicked(const QModelIndex &index);
    void on_canelRentalBtn2_clicked();
    void on_saveRentalBtn_clicked();

    void CustomerLoader();
    void RentalsLoader();
    void CarLoader();

    void on_empSaveCustomerBtn_clicked();

    void on_empCancelAddCustomerBtn_clicked();

    void on_edit_car_2_textChanged(const QString &arg1);

    void on_saveCustomerEditBtn_clicked();

    void on_delCustomerBtn_clicked();

    void on_cancelCustomerEditBtn_clicked();

    void on_paidBtn_clicked();

    void on_RegisterFisherSearchLineEdir_textChanged(const QString &arg1);

    void on_edit_carSearch_textChanged(const QString &arg1);

    void on_SaveEditCar_clicked();

    void on_saveAddCarBtn_clicked();

private:
    Ui::MainWindow *ui;
    database mydb;
    Inventory inv;
    admin UniversalAdmin;
    customer UniversalCustomer;
    customer MainWindowCustomer;
    employee UniversalEmployee;
    Car MainWindowCar;
    Car UniversalCar;
    Rentals UniversalRental;
    Rentals MainWindowRental;

};
#endif // MAINWINDOW_H
