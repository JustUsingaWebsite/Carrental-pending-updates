#include "admin.h"

admin::admin() : User("", "", "", ""){}
admin::admin(QString username, QString pass, QString email, QString phone)
    :User(username, pass, email, phone){
}
