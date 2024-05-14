#include "car.h"

Car::Car() {}

void Car::setAvailability(bool val){
    available = val; return;
}
void Car::setManufacture(QString val){
    manufacture = val; return;
};
void Car::setModel(QString val){
    model = val; return;
};
void Car::setColor(QString val){
    color = val; return;
};
void Car::setCarId(int val){
    carID = val; return;
}
void Car::setYear(int val){
    year = val; return;
};
void Car::setRental_Price(int val){
    rental_price = val; return;
};


QString Car::getCarDetails(Car& val){

    QString availability = val.isAvailable() ? "true" : "false";
    QString carDetails = QString("Car id: %1,  %2 %3, Year: %4, Color: %5, Rental Price: %6, Availability: %7")
                             .arg(val.getCarId()).arg(val.getmanufacture()).arg(val.getModel())
                             .arg(val.getYear()).arg(val.getColor()).arg(val.getRental_Price()).arg(availability);

    return carDetails;
}
