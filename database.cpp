#include <database.h>

void database::initMYSQL() {
    mydb = QSqlDatabase::addDatabase("QMYSQL");
    //setting connection credentials
    mydb.setHostName("localhost");
    mydb.setUserName("root");
    mydb.setPassword("");
    mydb.setDatabaseName("car_rental_system");

    //exception handling
    try
    {
        if(mydb.open())
        {
            qDebug() << "Successfully connected to database!";

        }
        else
        // Lets the program know that it didnt connect to the server
        {
            QString error = mydb.lastError().text();
            throw error.toStdString().c_str();
        }


    }
    catch(const char * message)  //catches the exception as a char pointer
    {
        QMessageBox messagebox;
        messagebox.about(NULL,"Connection to database failed!",message);
        qFatal("Connection to database failed!");
    }
}

void database::initSQLITE(){
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(QCoreApplication::applicationDirPath() + "/FinalData.db");

    if (mydb.open()){
        qDebug() << "rasin";
    }
}


database::database() {

    initSQLITE();
}

database::~database(){
    //mydb.close();
    //QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);

    mydb.close();
    QSqlDatabase::removeDatabase( QSqlDatabase::defaultConnection );  //remove database
    return;
}

QStringList database::verifyUserSQLITE(QString name, QString pass){
    QStringList userInfo;

    // Prepare the SQL query to verify the user
    QSqlQuery query;
    query.prepare("SELECT users.user_id, users.username, users.name, users.password, roles.role_name "
                  "FROM users "
                  "INNER JOIN roles ON users.role_id = roles.role_id "
                  "WHERE users.username = :username AND users.password = :password");
    query.bindValue(":username", name);
    query.bindValue(":password", pass);

    if (!query.exec()) {
        qDebug() << "Error verifying user:" << query.lastError().text();
        return userInfo;
    }

    if (query.next()) {

        QString userId = query.value(0).toString();
        QString username = query.value(1).toString();
        QString fullName = query.value(2).toString();
        QString password = query.value(3).toString();
        QString roleName = query.value(4).toString();

        // Add user information to the QStringList
        userInfo << userId << fullName << password << username << roleName;
    }

    return userInfo;
}

QStringList database::verifyUserMySQL(QString name, QString pass){
    // query the database
   /* if (name != "" && pass != ""){return true;}
    return false; */
    QSqlQuery qry;
    qry.prepare( "SELECT users.user_id, users.name, users.password, "
                "users.username, roles.role_name, users.role_id "
                "FROM users LEFT JOIN roles ON users.role_id = roles.role_id "
                "WHERE username = :uname AND password = :pword" );
    qry.bindValue(":uname", name);
    qry.bindValue(":pword", pass);

    if( !qry.exec() ){
        qDebug() <<"Login query failed "<< mydb.lastError();
    }

    QStringList result;

    if(qry.size() == 1){
        while( qry.next() ){
            result << qry.value("user_id").toString();
            result << qry.value("name").toString();
            result << qry.value("password").toString();
            result << qry.value("username").toString();
            result << qry.value("role_name").toString();
            result << qry.value("role_id").toString();
        }

    }
    return result;
}


bool database::MakeCustomer(std::vector<QString> val){
    // Check if the vector size is correct
    if (val.size() != 5) {
        qDebug() << "Incorrect number of values provided for creating a customer.";
        return false;
    }

    // Extract values from the vector
    QString name = val[0];
    QString email = val[1];
    QString phoneNum = val[2];
    QString username = val[3];
    QString password = val[4];

    // Check if there's already a user with the same name, email, or phone number
    QSqlQuery checkQuery(mydb);
    checkQuery.prepare("SELECT * FROM users WHERE name = :name OR email = :email OR phoneNum = :phoneNum");
    checkQuery.bindValue(":name", name);
    checkQuery.bindValue(":email", email);
    checkQuery.bindValue(":phoneNum", phoneNum);
    if (checkQuery.exec() && checkQuery.next()) {
        qDebug() << "A user with the same name, email, or phone number already exists.";
        return false;
    }

    // Prepare the SQL query to insert a new row into the users table
    QSqlQuery query(mydb);
    query.prepare("INSERT INTO users (name, email, phoneNum, username, password, role_id) "
                  "VALUES (:name, :email, :phoneNum, :username, :password, 2)");
    query.bindValue(":name", name);
    query.bindValue(":email", email);
    query.bindValue(":phoneNum", phoneNum);
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error creating customer:" << query.lastError().text();
        return false;
    }

    return true;
}


std::vector<std::map<QString, QVariant>> database::getInventory() {
    std::vector<std::map<QString, QVariant>> inventory;

    QSqlQuery query(mydb);
    query.prepare("SELECT c.*, i.Availability_Status FROM cars c LEFT JOIN inventory i ON c.CarID = i.CarID");
    if (!query.exec()) {
        qDebug() << "Error loading inventory:" << query.lastError().text();
        return inventory;
    }

    while (query.next()) {
        std::map<QString, QVariant> carData;
        carData["CarID"] = query.value("CarID");
        carData["Manufacturer"] = query.value("Manufacturer");
        carData["Model"] = query.value("Model");
        carData["Year"] = query.value("Year");
        carData["Color"] = query.value("Color");
        carData["Rental_Price"] = query.value("Rental_price");
        carData["Availability_Status"] = query.value("Availability_Status");
        inventory.push_back(carData);
    }

    return inventory;
}

std::map<QString, QVariant> database::getUser(int userid) {
    std::map<QString, QVariant> userData;

    QSqlQuery query(mydb);
    query.prepare("SELECT * FROM users WHERE user_id = :userid");
    query.bindValue(":userid", userid);
    if (!query.exec()) {
        qDebug() << "Error retrieving user:" << query.lastError().text();
        return userData;
    }

    if (query.next()) {
        userData["user_id"] = query.value("user_id");
        userData["name"] = query.value("name");
        userData["email"] = query.value("email");
        userData["phoneNum"] = query.value("phoneNum");
        userData["username"] = query.value("username");
        userData["password"] = query.value("password");
        userData["role_id"] = query.value("role_id");
    }

    return userData;
}


std::vector<std::map<QString, QVariant>> database::getUsers() {
    std::vector<std::map<QString, QVariant>> inventory;

    QSqlQuery query(mydb);
    query.prepare("SELECT * FROM users WHERE role_id = 2"); // Assuming role_id 2 represents customers
    if (!query.exec()) {
        qDebug() << "Error loading inventory:" << query.lastError().text();
        return inventory;
    }

    while (query.next()) {
        std::map<QString, QVariant> userData;
        userData["user_id"] = query.value("user_id");
        userData["name"] = query.value("name");
        userData["email"] = query.value("email");
        userData["phoneNum"] = query.value("phoneNum");
        userData["username"] = query.value("username");
        userData["password"] = query.value("password");
        userData["role_id"] = query.value("role_id");
        inventory.push_back(userData);
    }

    return inventory;
}


std::map<QString, QVariant> database::getUserRentedCar(int userId) {
    std::map<QString, QVariant> carData;

    QSqlQuery query(mydb);
    query.prepare("SELECT c.*, i.Availability_Status, r.Start_Date, r.Return_Date, r.Total_Price, r.Rental_Status "
                  "FROM rentals r "
                  "INNER JOIN cars c ON r.CarID = c.CarID "
                  "INNER JOIN inventory i ON r.CarID = i.CarID "
                  "WHERE r.CustomerID = :userId AND r.Rental_Status != finished"); // AND r.Rental_Status != finished

    query.bindValue(":userId", userId);
    if (!query.exec()) {
        qDebug() << "Error checking user's rented car:" << query.lastError().text();
        return carData;
    }

    if (query.next()) {
        carData["CarID"] = query.value("CarID");
        carData["Manufacturer"] = query.value("Manufacturer");
        carData["Model"] = query.value("Model");
        carData["Year"] = query.value("Year");
        carData["Color"] = query.value("Color");
        carData["Rental_Price"] = query.value("Rental_price");
        carData["Availability_Status"] = query.value("Availability_Status");
        carData["Total_Price"] = query.value("Total_Price");
        carData["Rental_Status"] = query.value("Rental_Status");

        QString startDateString = query.value("Start_Date").toString();
        QString returnDateString = query.value("Return_Date").toString();

        // Set the QDateTime objects in the map
        carData["Start_Date"] = startDateString;
        carData["Return_Date"] = returnDateString;
    }

    return carData;
}

std::tuple<bool, QString> database::cancelRental(int carId) {
    // Check if the car exists in the rentals table
    QSqlQuery checkQuery(mydb);
    checkQuery.prepare("SELECT * FROM rentals WHERE CarID = :carId");
    checkQuery.bindValue(":carId", carId);
    if (!checkQuery.exec()) {
        qDebug() << "Error checking rental for car:" << checkQuery.lastError().text();
        return std::make_tuple(false, "Failed to cancel rental. Please try again later.");
    }

    if (!checkQuery.next()) {
        return std::make_tuple(false, "Car not found in rentals.");
    }

    // Update the rental status to "cancelled"
    QSqlQuery cancelQuery(mydb);
    cancelQuery.prepare("UPDATE rentals SET Rental_Status = 'cancelled' WHERE CarID = :carId AND Rental_Status = 'pending'");
    cancelQuery.bindValue(":carId", carId);
    if (!cancelQuery.exec()) {
        qDebug() << "Error cancelling rental:" << cancelQuery.lastError().text();
        return std::make_tuple(false, "Failed to cancel rental. Please try again later.");
    }

    // Update the availability status in the inventory table to "available"
    QSqlQuery updateInventoryQuery(mydb);
    updateInventoryQuery.prepare("UPDATE inventory SET CustomerID = 8, Availability_Status = 'available' WHERE CarID = :carId");
    updateInventoryQuery.bindValue(":carId", carId);
    if (!updateInventoryQuery.exec()) {
        qDebug() << "Error updating inventory:" << updateInventoryQuery.lastError().text();
        // This error is not critical, so just log it without affecting the return value
    }

    // If update is successful, return true with success message
    return std::make_tuple(true, "Rental cancelled successfully.");
}

bool database::AddCar(QString manufacturer, QString model, int year, QString color, int adminID) {
    // Check if the car already exists in the cars table
    QSqlQuery checkQuery(mydb);
    checkQuery.prepare("SELECT COUNT(*) FROM cars WHERE Manufacturer = :manufacturer AND Model = :model AND Year = :year");
    checkQuery.bindValue(":manufacturer", manufacturer);
    checkQuery.bindValue(":model", model);
    checkQuery.bindValue(":year", year);
    if (!checkQuery.exec()) {
        qDebug() << "Error checking existing car:" << checkQuery.lastError().text();
        return false;
    }

    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if (count > 0) {
        qDebug() << "Car already exists in the database.";
        return false;
    }

    // Generate a random number between 1 and 10 for rental price
    int rentPrice = QRandomGenerator::global()->bounded(1, 11) * 10;

    // Insert the new car into the cars table
    QSqlQuery query(mydb);
    query.prepare("INSERT INTO cars (Manufacturer, Model, Year, Color, Rental_price, AdminID) VALUES (:manufacturer, :model, :year, :color, :rentPrice, :adminID)");
    query.bindValue(":manufacturer", manufacturer);
    query.bindValue(":model", model);
    query.bindValue(":year", year);
    query.bindValue(":color", color);
    query.bindValue(":rentPrice", rentPrice);
    query.bindValue(":adminID", adminID);

    if (!query.exec()) {
        qDebug() << "Error adding car:" << query.lastError().text();
        return false;
    }

    // Retrieve the CarID of the newly added car
    int carID = query.lastInsertId().toInt();

    // Insert the new car into the inventory table with availability set to "available"
    QSqlQuery inventoryQuery(mydb);
    inventoryQuery.prepare("INSERT INTO inventory (CarID, EmployeeID, CustomerID, Availability_Status) VALUES (:carID, :adminID, 8, 'available')");
    inventoryQuery.bindValue(":carID", carID);
    inventoryQuery.bindValue(":adminID", adminID);

    if (!inventoryQuery.exec()) {
        qDebug() << "Error adding car to inventory:" << inventoryQuery.lastError().text();
        // Rollback the addition of the car to the cars table
        QSqlQuery rollbackQuery(mydb);
        rollbackQuery.exec("DELETE FROM cars WHERE CarID = " + QString::number(carID));
        return false;
    }

    return true;
}



bool database::UpdateCar(int carid, QString manufacturer, QString model, int year, QString Color, int adminID) {
    QSqlQuery query(mydb);
    query.prepare("UPDATE cars SET Manufacturer = :manufacturer, Model = :model, Year = :year, Color = :color, AdminID = :adminID WHERE CarID = :carid");
    query.bindValue(":manufacturer", manufacturer);
    query.bindValue(":model", model);
    query.bindValue(":year", year);
    query.bindValue(":color", Color);
    query.bindValue(":adminID", adminID);
    query.bindValue(":carid", carid);

    if (!query.exec()) {
        qDebug() << "Error updating car:" << query.lastError().text();
        return false;
    }

    return true;
}


bool database::RentCar(std::tuple<int, int, QDateTime, QDateTime, int> rentalData) {
    int customerId = std::get<0>(rentalData);
    int carId = std::get<1>(rentalData);
    QDateTime startDate = std::get<2>(rentalData);
    QDateTime returnDate = std::get<3>(rentalData);
    int totalPrice = std::get<4>(rentalData);

    qDebug() << customerId;

    // Check if the customer already has an entry
    QSqlQuery checkQuery(mydb);
    checkQuery.prepare("SELECT * FROM rentals WHERE CustomerID = :customerId");
    checkQuery.bindValue(":customerId", customerId);
    if (!checkQuery.exec()) {
        qDebug() << "Error checking rental for customer:" << checkQuery.lastError().text();
        return false;
    }

    if (checkQuery.next()) {
        // Customer already has an entry
        qDebug() << checkQuery.value("Rental_Status").toString();
        if (checkQuery.value("Rental_Status").toString() == "active" || checkQuery.value("Rental_Status").toString() == "pending") {
            // Active rental found, return false
            return false;
        } else {
            // Update existing entry
            QSqlQuery updateQuery(mydb);
            updateQuery.prepare("UPDATE rentals SET CarID = :carId, Start_Date = :startDate, Return_Date = :returnDate, Total_Price = :totalPrice, Rental_Status = 'pending' "
                                "WHERE CustomerID = :customerId");
            updateQuery.bindValue(":carId", carId);
            updateQuery.bindValue(":startDate", startDate.toString("yyyy-MM-dd hh:mm:ss"));
            updateQuery.bindValue(":returnDate", returnDate.toString("yyyy-MM-dd hh:mm:ss"));
            updateQuery.bindValue(":totalPrice", totalPrice);
            updateQuery.bindValue(":customerId", customerId);
            if (!updateQuery.exec()) {
                qDebug() << "Error updating rental:" << updateQuery.lastError().text();
                return false;
            }
        }
    } else {
        qDebug() << checkQuery.value("Rental_Status").toString();
        // No entry found, insert a new entry
        QSqlQuery insertQuery(mydb);
        insertQuery.prepare("INSERT INTO rentals (CustomerID, EmployeeID, CarID, Start_Date, Return_Date, Total_Price, Rental_Status) "
                            "VALUES (:customerId, 8, :carId, :startDate, :returnDate, :totalPrice, 'pending')");
        insertQuery.bindValue(":customerId", customerId);
        insertQuery.bindValue(":carId", carId);
        insertQuery.bindValue(":startDate", startDate.toString("yyyy-MM-dd hh:mm:ss"));
        insertQuery.bindValue(":returnDate", returnDate.toString("yyyy-MM-dd hh:mm:ss"));
        insertQuery.bindValue(":totalPrice", totalPrice);
        if (!insertQuery.exec()) {
            qDebug() << "Error inserting rental:" << insertQuery.lastError().text();
            return false;
        }
    }

    // Query to check if an entry with the same customer ID exists
    QSqlQuery checkExistingQuery(mydb);
    checkExistingQuery.prepare("SELECT * FROM inventory WHERE CustomerID = :customerId");
    checkExistingQuery.bindValue(":customerId", customerId);
    if (!checkExistingQuery.exec()) {
        qDebug() << "Error checking existing entry in inventory:" << checkExistingQuery.lastError().text();
        // Handle error if needed
    } else {
        // If an entry with the same customer ID exists, update it
        if (checkExistingQuery.next()) {
            QSqlQuery updateExistingQuery(mydb);
            updateExistingQuery.prepare("UPDATE inventory SET Availability_Status = 'available', CustomerID = 8 WHERE CustomerID = :customerId");
            updateExistingQuery.bindValue(":customerId", customerId);
            if (!updateExistingQuery.exec()) {
                qDebug() << "Error updating existing entry in inventory:" << updateExistingQuery.lastError().text();
                // Handle error if needed
            }
        }
    }

    // Update the inventory entry for the current rental
    QSqlQuery inventoryQuery(mydb);
    inventoryQuery.prepare("UPDATE inventory SET Availability_Status = 'rented', CustomerID = :customerId WHERE CarID = :carId");
    inventoryQuery.bindValue(":customerId", customerId);
    inventoryQuery.bindValue(":carId", carId);
    if (!inventoryQuery.exec()) {
        qDebug() << "Error updating inventory:" << inventoryQuery.lastError().text();
        // Handle error if needed
    }


    return true;
}

bool database::UpdateUser(int userid, QString name, QString email, QString phone, QString username, QString password) {
    QSqlQuery query(mydb);

    // Check if the user exists
    query.prepare("SELECT * FROM users WHERE user_id = :userid");
    query.bindValue(":userid", userid);
    if (!query.exec()) {
        qDebug() << "Error checking user for update:" << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        qDebug() << "User not found for update.";
        return false;
    }

    // Update the user record
    query.prepare("UPDATE users SET name = :name, email = :email, phoneNum = :phone, username = :username, password = :password WHERE user_id = :userid");
    query.bindValue(":name", name);
    query.bindValue(":email", email);
    query.bindValue(":phone", phone);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":userid", userid);

    if (!query.exec()) {
        qDebug() << "Error updating user:" << query.lastError().text();
        return false;
    }

    return true;
}

bool database::DeleteUser(int userid) {
    QSqlQuery query(mydb);

    // Check if the user exists
    query.prepare("SELECT * FROM users WHERE user_id = :userid");
    query.bindValue(":userid", userid);
    if (!query.exec()) {
        qDebug() << "Error checking user for deletion:" << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        qDebug() << "User not found for deletion.";
        return false;
    }

    // Delete the user record
    query.prepare("DELETE FROM users WHERE user_id = :userid");
    query.bindValue(":userid", userid);

    if (!query.exec()) {
        qDebug() << "Error deleting user:" << query.lastError().text();
        return false;
    }

    return true;
}

bool database::MakePayment(int customerID, int employeeID, QDateTime paymentDate, int total) {
    // Query the rentals table to find the latest pending rental for the customer
    QSqlQuery selectQuery(mydb);
    selectQuery.prepare("SELECT ID FROM rentals WHERE CustomerID = :customerID AND Rental_Status = 'pending' ORDER BY ID DESC LIMIT 1");
    selectQuery.bindValue(":customerID", customerID);

    if (!selectQuery.exec()) {
        qDebug() << "Error selecting pending rental:" << selectQuery.lastError().text();
        return false;
    }

    if (!selectQuery.next()) {
        qDebug() << "No pending rental found for customer:" << customerID;
        return false;
    }

    int rentalID = selectQuery.value("ID").toInt();

    // Update the rental status to 'active' after making the payment
    QSqlQuery updateQuery(mydb);
    updateQuery.prepare("UPDATE rentals SET Rental_Status = 'active' WHERE ID = :rentalID");
    updateQuery.bindValue(":rentalID", rentalID);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating rental status:" << updateQuery.lastError().text();
        return false;
    }

    // Insert the payment record into the payments table
    QSqlQuery insertQuery(mydb);
    insertQuery.prepare("INSERT INTO payments (RentalID, CustomerID, EmployeeID, PaymentDate, Amount) VALUES (:rentalID, :customerID, :employeeID, :paymentDate, :total)");
    insertQuery.bindValue(":rentalID", rentalID);
    insertQuery.bindValue(":customerID", customerID);
    insertQuery.bindValue(":employeeID", employeeID);
    insertQuery.bindValue(":paymentDate", paymentDate);
    insertQuery.bindValue(":total", total);

    if (!insertQuery.exec()) {
        qDebug() << "Error inserting payment record:" << insertQuery.lastError().text();
        return false;
    }

    return true;
}


std::vector<std::map<QString, QVariant>> database::GetRentals() {
    std::vector<std::map<QString, QVariant>> rentals;

    QSqlQuery query(mydb);
    query.prepare("SELECT * FROM rentals");
    if (!query.exec()) {
        qDebug() << "Error retrieving rentals:" << query.lastError().text();
        return rentals;
    }

    while (query.next()) {
        std::map<QString, QVariant> rentalData;
        rentalData["ID"] = query.value("ID");
        rentalData["CustomerID"] = query.value("CustomerID");
        rentalData["EmployeeID"] = query.value("EmployeeID");
        rentalData["CarID"] = query.value("CarID");
        rentalData["Total_Price"] = query.value("Total_Price");
        rentalData["Rental_Status"] = query.value("Rental_Status");

        QString startdate = query.value("Start_Date").toString();
        QString returndate = query.value("Return_Date").toString();
        rentalData["Start_Date"] = startdate;
        rentalData["Return_Date"] = returndate;
        rentals.push_back(rentalData);
    }

    return rentals;
}

void database::updateRentalHistory() {
    QSqlQuery selectQuery(mydb);
    selectQuery.prepare("SELECT * FROM rentals");
    if (!selectQuery.exec()) {
        qDebug() << "Error selecting rentals data:" << selectQuery.lastError().text();
        return;
    }

    while (selectQuery.next()) {
        int rentalID = selectQuery.value("ID").toInt();
        int customerID = selectQuery.value("CustomerID").toInt();
        int carID = selectQuery.value("CarID").toInt();
        QDateTime startDate = selectQuery.value("Start_Date").toDateTime();
        QDateTime returnDate = selectQuery.value("Return_Date").toDateTime();
        double totalPrice = selectQuery.value("Total_Price").toDouble();

        // Check if the rental already exists in rental_history
        QSqlQuery checkQuery(mydb);
        checkQuery.prepare("SELECT COUNT(*) FROM rental_history WHERE ID = :rentalID");
        checkQuery.bindValue(":rentalID", rentalID);
        if (!checkQuery.exec()) {
            qDebug() << "Error checking existing rental in rental_history:" << checkQuery.lastError().text();
            continue;
        }

        checkQuery.next();
        int count = checkQuery.value(0).toInt();

        if (count > 0) {
            // Rental already exists, update it
            QSqlQuery updateQuery(mydb);
            updateQuery.prepare("UPDATE rental_history SET CostumerID = :customerID, CarID = :carID, Admin_ID = :employeeID, Start_date = :startDate, Return_date = :returnDate, Total_amount = :totalPrice WHERE ID = :rentalID");
            updateQuery.bindValue(":customerID", customerID);
            updateQuery.bindValue(":carID", carID);
            updateQuery.bindValue(":employeeID", 8);
            updateQuery.bindValue(":startDate", startDate);
            updateQuery.bindValue(":returnDate", returnDate);
            updateQuery.bindValue(":totalPrice", totalPrice);
            updateQuery.bindValue(":rentalID", rentalID);

            if (!updateQuery.exec()) {
                qDebug() << "Error updating rental history:" << updateQuery.lastError().text();
            }
        } else {
            // Rental doesn't exist, insert it
            QSqlQuery insertQuery(mydb);
            insertQuery.prepare("INSERT INTO rental_history (ID, CostumerID, CarID, Admin_ID, Start_date, Return_date, Total_amount) VALUES (:rentalID, :customerID, :carID, :employeeID, :startDate, :returnDate, :totalPrice)");
            insertQuery.bindValue(":rentalID", rentalID);
            insertQuery.bindValue(":customerID", customerID);
            insertQuery.bindValue(":carID", carID);
            insertQuery.bindValue(":employeeID", 8);
            insertQuery.bindValue(":startDate", startDate);
            insertQuery.bindValue(":returnDate", returnDate);
            insertQuery.bindValue(":totalPrice", totalPrice);

            if (!insertQuery.exec()) {
                qDebug() << "Error inserting rental history:" << insertQuery.lastError().text();
            }
        }
    }
}

void database::UpdateData() {
    QSqlQuery query(mydb);
    query.prepare("SELECT * FROM rentals");
    if (!query.exec()) {
        qDebug() << "Error retrieving rentals:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        int rentalID = query.value("ID").toInt();
        int carID = query.value("CarID").toInt();
        QString rentalStatus = query.value("Rental_Status").toString();
        QDateTime returnDate = query.value("Return_Date").toDateTime();

        QDateTime currentDateTime = QDateTime::currentDateTime();

        if (currentDateTime > returnDate) {
            if (rentalStatus == "pending") {
                // Remove the entry from rentals table
                QSqlQuery removeQuery(mydb);
                removeQuery.prepare("DELETE FROM rentals WHERE ID = :rentalID");
                removeQuery.bindValue(":rentalID", rentalID);
                if (!removeQuery.exec()) {
                    qDebug() << "Error removing overdue pending rental:" << removeQuery.lastError().text();
                }
            } else if (rentalStatus == "active") {
                // Update rental status to finished
                QSqlQuery updateQuery(mydb);
                updateQuery.prepare("UPDATE rentals SET Rental_Status = 'finished' WHERE ID = :rentalID");
                updateQuery.bindValue(":rentalID", rentalID);
                if (!updateQuery.exec()) {
                    qDebug() << "Error updating overdue active rental:" << updateQuery.lastError().text();
                }

                // Change inventory status
                QSqlQuery inventoryQuery(mydb);
                inventoryQuery.prepare("UPDATE inventory SET CustomerID = 8, Availability_Status = 'available' WHERE CarID = :carID");
                inventoryQuery.bindValue(":carID", carID);
                if (!inventoryQuery.exec()) {
                    qDebug() << "Error updating inventory for overdue active rental:" << inventoryQuery.lastError().text();
                }
            }
        }
    }
}
