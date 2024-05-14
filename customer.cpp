#include "customer.h"

customer::customer() : User("", "", "", "") {} // Default constructor initializing the base class
customer::customer(QString username, QString password, QString email, QString phone)
    : User(username, password, email, phone) {} // Constructor with parameters initializing the base class


void customer::StoreCustomers(std::vector<std::map<QString, QVariant>> inventoryData){

    loadedCustomers.clear();

    for (auto& CustomerData: inventoryData){
        customer Cus(CustomerData["username"].toString(),
                     CustomerData["password"].toString(),
                     CustomerData["email"].toString(),
                     CustomerData["phoneNum"].toString());
        Cus.setName(CustomerData["name"].toString());
        Cus.setUserID(CustomerData["user_id"].toString());
        loadedCustomers.push_back(Cus);
    }
}

customer customer::Searchcustomer(QString val){
    for(auto it = loadedCustomers.begin(); it != loadedCustomers.end(); ++it){
        if (it->getName().toLower().contains(val.toLower())){
            return *it;
        }
    }

    return customer("", "", "", "");
}
