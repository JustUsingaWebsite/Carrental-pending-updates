#ifndef INVENTORY_H
#define INVENTORY_H
#include "car.h"
#include "qdebug.h"
#include <vector>
#include <map>

class Inventory {
private:
    std::vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void removeCar(const Car&);

    std::vector<Car> getCars() const {
        return cars;
    }

    void loadInventory(std::vector<std::map<QString, QVariant>>);
    Car SearchInventory(QString);
    // Other functions for managing user's inventory
};

#endif // INVENTORY_H
