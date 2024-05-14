#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <users.h>

class customer: public User
{
private:
    std::vector<customer> loadedCustomers;
public:
    customer();
    customer(QString, QString, QString, QString);

    void StoreCustomers(std::vector<std::map<QString, QVariant>>);
    std::vector<customer> getLoadedCustomers(){return loadedCustomers;}
    customer Searchcustomer(QString);
};

#endif // CUSTOMER_H
