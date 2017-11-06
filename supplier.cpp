#include "supplier.h"
#include "ui_supplier.h"


Supplier::Supplier(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Supplier)
{
    ui->setupUi(this);

    msgBox=new Dialog_AddSupplier;

    for(int i=0; i<database.SizeDistinct("Suppliers","SupplierName");i++){
        ui->comboBox_SuppList->addItem(database.GetSupplier("suppliername",i));
    }

    ui->lineEdit_PhoneNumber->setText((database.GetSupplier("phonenumber",0)));
    ui->lineEdit_EmailAdress->setText((database.GetSupplier("email",0)));
    ui->lineEdit_EstShip->setText((database.GetSupplier("estshipping",0)));

    connect(msgBox, SIGNAL(SupplierChanged()), this, SLOT(Slot_SupplierChanged()));

}
Supplier::~Supplier()
{
    delete ui;
}

void Supplier::on_pushButton_clicked()
{
    msgBox->exec();
}

//******************************************************************************************
// When the combo box is changed it reflects the new information in line edits
//******************************************************************************************
void Supplier::on_comboBox_SuppList_currentIndexChanged(const QString &arg1)
{
    int cursup = (ui->comboBox_SuppList->currentIndex());

    ui->lineEdit_PhoneNumber->setText((database.GetSupplier("phonenumber",cursup)));
    ui->lineEdit_EmailAdress->setText((database.GetSupplier("email",cursup)));
    ui->lineEdit_EstShip->setText((database.GetSupplier("estshipping",cursup)));

}
//******************************************************************************************
//not sure.....
//******************************************************************************************
void Supplier::Slot_SupplierChanged(){
    emit SupplierChanged();

    ui->comboBox_SuppList->clear();

    for(int i=0; i<database.SizeDistinct("Suppliers","SupplierName");i++){
        ui->comboBox_SuppList->addItem(database.GetSupplier("suppliername",i));
    }

    ui->lineEdit_PhoneNumber->setText((database.GetSupplier("phonenumber",0)));
    ui->lineEdit_EmailAdress->setText((database.GetSupplier("email",0)));
    ui->lineEdit_EstShip->setText((database.GetSupplier("estshipping",0)));

}
//******************************************************************************************
//deletes the current supplier selected in the combo box
//******************************************************************************************
void Supplier::on_pushButton_dlete_clicked()
{

    QString temp = database.Everything("SELECT SupplierId FROM Suppliers WHERE SupplierName = '"+ui->comboBox_SuppList->currentText()+"'");

    database.Delete("Suppliers","SupplierID",temp);

    ui->comboBox_SuppList->clear();

    for(int i=0; i<database.SizeDistinct("Suppliers","SupplierName");i++){
        ui->comboBox_SuppList->addItem(database.GetSupplier("suppliername",i));
    }

    ui->lineEdit_PhoneNumber->setText((database.GetSupplier("phonenumber",0)));
    ui->lineEdit_EmailAdress->setText((database.GetSupplier("email",0)));
    ui->lineEdit_EstShip->setText((database.GetSupplier("estshipping",0)));
    emit SupplierChanged();

}
//******************************************************************************************
//Updates the database to reflect current info in line edits
//******************************************************************************************
void Supplier::on_pushButton_2_clicked()
{
    database.Update("Suppliers","PhoneNumber",ui->lineEdit_PhoneNumber->text(),"SupplierName",ui->comboBox_SuppList->currentText());
    database.Update("Suppliers","Email",ui->lineEdit_EmailAdress->text(),"SupplierName",ui->comboBox_SuppList->currentText());
    database.Update("Suppliers","EstShipping",ui->lineEdit_EstShip->text(),"SupplierName",ui->comboBox_SuppList->currentText());
}
