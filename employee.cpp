#include "employee.h"

employee::employee() : User("", "", "", "") {}
employee::employee(QString username, QString pass, QString email, QString phone)
    :User(username, pass, email, phone){
}

QString employee::CheckCustomer(QString name, QString email, QString phoneNum,
QString username, QString password )
{
    if (name == ""){return "Please enter name";}
    if (email == ""){return "Please enter email";}
    if (phoneNum == ""){return "Please enter phone number";}
    if (username == ""){return "Please enter username";}
    if (password == ""){return "Please enter password";}

    return "Everything looks fine";
}
