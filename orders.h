#ifndef ORDERS_H
#define ORDERS_H

#include <QWidget>
#include <QMessageBox>
#include <QDateTime>

#include "database.h"

namespace Ui {
class Orders;
}

class Orders : public QWidget
{
    Q_OBJECT

public:
    explicit Orders(QWidget *parent = 0);
    ~Orders();

private slots:
    void on_pushButton_Home_clicked();

    void on_comboBox_OpenOrder_currentIndexChanged(const QString &arg1);

    void on_comboBox_OrderEnroute_currentIndexChanged(const QString &arg1);

    void on_pushButton_Recieved_2_clicked();

    void on_pushButton_Recieved_clicked();

    void on_pushButton_CreateOrder_clicked();

signals:
    void OrdersHome();

private:
    Ui::Orders *ui;

    Database database;

    void RedoCombos();
};

#endif // ORDERS_H
