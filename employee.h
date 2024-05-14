#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <users.h>

class employee : public User
{
public:
    employee();
    employee(QString, QString, QString, QString);

    bool payments();
    QString CheckCustomer(QString, QString, QString, QString, QString);
    QString editDelCustomer();
};

#endif // EMPLOYEE_H
