#include "customerlistmodel.h"


void CustomerListModel::setCustomerData(const std::vector<customer> &customers){
    customer_ = customers;
    QStringList carDetailsList;
    for (const auto &cus : customers) {
        QString carDetails = QString("Name: %1, Email: %2, Phone: %3, Username: %4")
                                 .arg(cus.getName()).arg(cus.getEmail())
                                 .arg(cus.getPhone()).arg(cus.getUsername());
        carDetailsList << carDetails;
    }
    setStringList(carDetailsList);
}
