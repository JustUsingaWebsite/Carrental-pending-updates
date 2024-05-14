#ifndef CAR_H
#define CAR_H
#include <QString>
#include <QList>

class Car {
private:
    QString manufacture;
    QString model;
    QString color;

    int carID;
    int year;
    int rental_price;

    bool available;



public:
    Car();
    Car(const QString& manufacture, const QString& model, int year, const QString& color)
        : manufacture(manufacture), model(model), color(color), year(year), available(true) {}

    // Getters
    QString getmanufacture() const { return manufacture; }
    QString getModel() const { return model; }
    QString getColor() const { return color; }

    int getCarId() const {return carID;}
    int getYear() const { return year; }
    int getRental_Price() const {return rental_price;}

    bool isAvailable() const { return available; }

    // Setter
    void setAvailability(bool);
    void setManufacture(QString);
    void setModel(QString);
    void setColor(QString);
    void setCarId(int);
    void setYear(int);
    void setRental_Price(int);

    //misc func
    QString getCarDetails(Car&);
};

#endif // CAR_H
