#ifndef CUSTOMERLISTMODEL_H
#define CUSTOMERLISTMODEL_H

#include <QStringListModel>
#include <customer.h>

class CustomerListModel : public QStringListModel
{
public:
    explicit CustomerListModel(QObject *parent = nullptr)
        : QStringListModel(parent) {}

    QVariant data(const QModelIndex &index, int role) const override {
        if (role == Qt::UserRole && index.isValid() && index.row() < customer_.size()) {
            return QVariant::fromValue(customer_[index.row()]);
        }
        return QStringListModel::data(index, role);
    }

    void setCustomerData(const std::vector<customer> &customers);

private:
    std::vector<customer> customer_;
};

#endif // CUSTOMERLISTMODEL_H
