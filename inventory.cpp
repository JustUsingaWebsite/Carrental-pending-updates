#include "inventory.h"
#include "qvariant.h"

void Inventory::removeCar(const Car& carToRemove) {
    // Iterate through the cars vector
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        // Check if the current car matches the manufacturer and model of the car to remove
        if (it->getmanufacture() == carToRemove.getmanufacture() &&
            it->getModel() == carToRemove.getModel()) {
            // Remove the car from the vector
            it = cars.erase(it);
            return; // Exit the function after removing the car
        }
    }
    // If the car is not found, you can handle the error or simply do nothing
}



void Inventory::loadInventory(std::vector<std::map<QString, QVariant>> inventoryData){


    // Clear existing cars
    cars.clear();

    // Populate cars vector
    for (auto& carData : inventoryData) {
        Car car(carData["Manufacturer"].toString(),
                carData["Model"].toString(),
                carData["Year"].toInt(),
                carData["Color"].toString());
        car.setRental_Price(carData["Rental_Price"].toInt());
        car.setCarId(carData["CarID"].toInt());
        car.setAvailability(carData["Availability_Status"].toString().trimmed() == "available");
        addCar(car);
    }
}

Car Inventory::SearchInventory(QString val){

    for (auto it = cars.begin(); it != cars.end(); ++it)
    {
        if (it->getmanufacture().toLower().contains(val) || it->getModel().toLower().contains(val)){
            return *it;
        }
    }

    return Car();
}
