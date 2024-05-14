#include "rentalslistmodel.h"


void RentalsListModel::setRentalData(const std::vector<Rentals> &rentals){
    rentals_ = rentals;
    QStringList carDetailsList;
    for (const auto &cus : rentals) {
        QString carDetails = QString("rentalID: %1, start date: %2, return date: %3, total cost: %4, rental status: %5")
                                 .arg(cus.getRentalID()).arg(cus.getStartDate().toString())
                                 .arg(cus.getReturnDate().toString()).arg(cus.getTotalPrice()).arg(cus.getRentalStatus());
        carDetailsList << carDetails;
    }
    setStringList(carDetailsList);
}

