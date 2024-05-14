#ifndef CARLISTMODEL_H
#define CARLISTMODEL_H

#include <QStringListModel>
#include <car.h>


class CarListModel : public QStringListModel {
public:
    explicit CarListModel(QObject *parent = nullptr)
        : QStringListModel(parent) {}

    QVariant data(const QModelIndex &index, int role) const override {
        if (role == Qt::UserRole && index.isValid() && index.row() < cars_.size()) {
            return QVariant::fromValue(cars_[index.row()]);
        }
        return QStringListModel::data(index, role);
    }

    void setCarData(const std::vector<Car> &cars);

private:
    std::vector<Car> cars_;
};


#endif // CARLISTMODEL_H
