#include "dialog_addsupplier.h"
#include "ui_dialog_addsupplier.h"

Dialog_AddSupplier::Dialog_AddSupplier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddSupplier)
{
    ui->setupUi(this);
}

Dialog_AddSupplier::~Dialog_AddSupplier()
{
    delete ui;
}

void Dialog_AddSupplier::on_buttonBox_accepted()
{
    database.Insert("Suppliers","SupplierName,PhoneNumber,Email,EstShipping",
                    "'"+ui->lineEdit_SuppName->text()+"',"
                    "'"+ui->lineEdit_Num->text()+"',"
                    "'"+ui->lineEdit_Email->text()+"',"
                    "'"+ui->lineEdit_EstShip->text()+"'");
    emit SupplierChanged();
}
