#ifndef RENTALS_H
#define RENTALS_H

#include "qdatetime.h"
#include <QDebug>
#include <QObject>

class Rentals
{

private:
    int rentalID;
    int customerID;
    int employeeID;
    int carID;
    QDateTime start_date;
    QDateTime return_date;
    int total_price;
    QString rental_status;

    std::vector<Rentals> loadedRentals;
public:
    Rentals();
    bool makeRentalReport(int, int, QDateTime, QDateTime, int); // customer, car, start, end, price
    void StoreRentals(std::vector<std::map<QString, QVariant>>);
    Rentals Searchrental(int);
    std::vector<Rentals> getLoadedRentals(){return loadedRentals;}

    int getRentalID() const {return rentalID;}
    int getCustomerID() const {return customerID;}
    int getEmployeeID() const {return employeeID;}
    int getCarID() const {return carID;}

    QDateTime getStartDate() const {return start_date;}
    QDateTime getReturnDate() const {return return_date;}

    int getTotalPrice() const {return total_price;}
    QString getRentalStatus() const {return rental_status;}

    void setRentalID(int id) {rentalID = id;}
    void setCustomerID(int id) {customerID = id;}
    void setEmployeeID(int id){employeeID = id;}
    void setCarID(int id) {carID = id;}
    void setStartDate(const QDateTime& date) {start_date = date;}
    void setReturnDate(const QDateTime& date) {return_date = date;}
    void setTotalPrice(int price) {total_price = price;}
    void setRentalStatus(const QString& status) {rental_status = status;}
};

#endif // RENTALS_H
