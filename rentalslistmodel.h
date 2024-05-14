#ifndef RENTALSLISTMODEL_H
#define RENTALSLISTMODEL_H

#include <QStringListModel>
#include <rentals.h>

class RentalsListModel : public QStringListModel
{
public:
    explicit RentalsListModel(QObject *parent = nullptr)
        : QStringListModel(parent) {}

    QVariant data(const QModelIndex &index, int role) const override {
        if (role == Qt::UserRole && index.isValid() && index.row() < rentals_.size()) {
            return QVariant::fromValue(rentals_[index.row()]);
        }
        return QStringListModel::data(index, role);
    }

    void setRentalData(const std::vector<Rentals> &rentals);

private:
    std::vector<Rentals> rentals_;
};

#endif // RENTALSLISTMODEL_H
