#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <QWidget>

#include "dialog_addsupplier.h"
#include "database.h"

namespace Ui {
class Supplier;
}

class Supplier : public QWidget
{
    Q_OBJECT

public:
    explicit Supplier(QWidget *parent = 0);
    ~Supplier();

private slots:
    void on_BackSupplier_clicked(){emit SuppHome();}

    void on_pushButton_clicked();

    void on_comboBox_SuppList_currentIndexChanged(const QString &arg1);
    void Slot_SupplierChanged();

    void on_pushButton_dlete_clicked();

    void on_pushButton_2_clicked();

signals:
    void SuppHome();
    void SupplierChanged();

private:
    Ui::Supplier *ui;

    Database database;
    Dialog_AddSupplier* msgBox;
};

#endif // SUPPLIER_H
