#ifndef DIALOG_ADDSUPPLIER_H
#define DIALOG_ADDSUPPLIER_H

#include <QDialog>

#include "database.h"

namespace Ui {
class Dialog_AddSupplier;
}

class Dialog_AddSupplier : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddSupplier(QWidget *parent = 0);
    ~Dialog_AddSupplier();

private slots:
    void on_buttonBox_accepted();
signals:
    void SupplierChanged();

private:
    Ui::Dialog_AddSupplier *ui;
    Database database;
};

#endif // DIALOG_ADDSUPPLIER_H
