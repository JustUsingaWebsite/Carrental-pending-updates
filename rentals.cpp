#include "rentals.h"

Rentals::Rentals() {}

Rentals Rentals::Searchrental(int val){
    for(auto it = loadedRentals.begin(); it != loadedRentals.end(); ++it){
        if (it->getCustomerID() == val){
            return *it;
        }
    }

    return Rentals();
}

void Rentals::StoreRentals(std::vector<std::map<QString, QVariant>> inventoryData){
    loadedRentals.clear();

    for (auto& rentalData: inventoryData){
        Rentals Rent;
        Rent.setRentalID(rentalData["ID"].toInt());
        Rent.setCarID(rentalData["CarID"].toInt());
        Rent.setEmployeeID(rentalData["EmployeeID"].toInt());
        Rent.setCustomerID(rentalData["CustomerID"].toInt());
        Rent.setStartDate(rentalData["Start_Date"].toDateTime());
        Rent.setReturnDate(rentalData["Return_Date"].toDateTime());
        Rent.setTotalPrice(rentalData["Total_Price"].toInt());
        Rent.setRentalStatus(rentalData["Rental_Status"].toString());
        loadedRentals.push_back(Rent);
    }
}
