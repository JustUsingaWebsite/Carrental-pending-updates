#include "carlistmodel.h"

void CarListModel::setCarData(const std::vector<Car> &cars) {
    cars_ = cars;
    QStringList carDetailsList;
    for (const auto &car : cars) {
        QString availability = car.isAvailable() ? "true" : "false";
        QString carDetails = QString("%1 %2, Year: %3, Availability: %4")
                                 .arg(car.getmanufacture()).arg(car.getModel())
                                 .arg(car.getYear()).arg(availability);
        carDetailsList << carDetails;
    }
    setStringList(carDetailsList);
}

