#ifndef ADMIN_H
#define ADMIN_H

#include <users.h>

class admin : public User
{
public:
    admin();
    admin(QString, QString, QString, QString);

    QStringList generateReport();
    QString addCar();
    QString editCar();
};

#endif // ADMIN_H
