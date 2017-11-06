#include "orders.h"
#include "ui_orders.h"

Orders::Orders(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Orders)
{
    ui->setupUi(this);



    //fill open order combobox
    for(int i=0; i<database.SizeDistinct("Orders WHERE Status = 'Open'","OrderNo");i++)
        ui->comboBox_OpenOrder->addItem(database.GetOrders("orderno",i,NULL," WHERE Status = 'Open'"));


    //fill enroute order combobox
    for(int i=0; i<database.SizeDistinct("Orders WHERE Status = 'Enroute'","OrderNo");i++)
        ui->comboBox_OrderEnroute->addItem(database.GetOrders("orderno",i,NULL," WHERE Status = 'Enroute'"));

    for(int i=0; i<database.SizeDistinct("Suppliers","SupplierName");i++){
        ui->comboBox_Supplier->addItem(database.GetSupplier("suppliername",i));
    }


}

Orders::~Orders()
{
    delete ui;
}

//emits signal to go home
void Orders::on_pushButton_Home_clicked()
{
    emit OrdersHome();
}

//when open order combobbox changed update the info in the layout
void Orders::on_comboBox_OpenOrder_currentIndexChanged(const QString &arg1)
{

    ui->label_SupplierOpen->setText( database.GetOrders("supplier",0,NULL," WHERE Status = 'Open' AND OrderNo = '"+ui->comboBox_OpenOrder->currentText()+"'"));


    QWidget *widget=new QWidget;
    QVBoxLayout *vLayout=new QVBoxLayout;
    QLabel* label[30];///needs to be dynamic

    for(int i=0; i<database.Size("Orders WHERE Status = 'Open' AND OrderNo = '"+ui->comboBox_OpenOrder->currentText()+"'","ItemNo");i++){

        if(database.GetOrders("itemno",i,NULL," WHERE Status = 'Open' AND OrderNo = '"+ui->comboBox_OpenOrder->currentText()+"'") != NULL){
            label[i] =new QLabel;

            QString temp = database.GetOrders("itemno",i,NULL," WHERE Status = 'Open' AND OrderNo = '"+ui->comboBox_OpenOrder->currentText()+"'");

            label[i]->setText(
                        database.GetInventory("category",0,NULL," WHERE ItemId = '"+temp+"'")+"-"+
                        database.GetInventory("itemname",0,NULL," WHERE ItemId = '"+temp+"'")+" ("+
                        database.GetOrders("amount",0,NULL," WHERE ItemNo = '"+temp+"' AND Status = 'Open' AND OrderNo = '"+ui->comboBox_OpenOrder->currentText()+"'")+")");

            vLayout->addWidget(label[i]);
        }

    }

    widget->setLayout(vLayout);
    ui->scrollArea_Open->setWidget(widget);

}

//when  order enroute combobbox changed update the info in the layout
void Orders::on_comboBox_OrderEnroute_currentIndexChanged(const QString &arg1)
{

    ui->label_SupplierEnroute->setText( database.GetOrders("supplier",0,NULL," WHERE Status = 'Enroute' AND OrderNo = '"+ui->comboBox_OrderEnroute->currentText()+"'"));
    ui->label_DateOrderedEnroute->setText( database.GetOrders("dateordered",0,NULL," WHERE Status = 'Enroute' AND OrderNo = '"+ui->comboBox_OrderEnroute->currentText()+"'"));


    QWidget *widget2=new QWidget;
    QVBoxLayout *vLayout2=new QVBoxLayout;
    QLabel* label2[30];///needs to be dynamic

    for(int i=0; i<database.Size("Orders WHERE Status = 'Enroute' AND OrderNo = '"+ui->comboBox_OrderEnroute->currentText()+"'","ItemNo");i++){

        if( database.GetOrders("itemno",i,NULL," WHERE Status = 'Enroute' AND OrderNo = '"+ui->comboBox_OrderEnroute->currentText()+"'") != NULL){
            label2[i] =new QLabel;

            QString temp = database.GetOrders("itemno",i,NULL," WHERE Status = 'Enroute' AND OrderNo = '"+ui->comboBox_OrderEnroute->currentText()+"'");
            label2[i]->setText(
                        database.GetInventory("category",0,NULL," WHERE ItemId = '"+temp+"'")+"-"+
                        database.GetInventory("itemname",0,NULL," WHERE ItemId = '"+temp+"'")+" ("+
                        database.GetOrders("amount",0,NULL," WHERE ItemNo = '"+temp+"' AND  Status = 'Enroute' AND OrderNo = '"+ui->comboBox_OrderEnroute->currentText()+"'")+")");

            vLayout2->addWidget(label2[i]);
        }

    }

    widget2->setLayout(vLayout2);
    ui->scrollArea_Enroute->setWidget(widget2);

}

void Orders::on_pushButton_Recieved_2_clicked() //order placed
{
    //gets current date
    QDate date = QDate::currentDate();
    QString dateString = date.toString();
    database.Update("Orders","DateOrdered",dateString,"Status","Open' AND OrderNo = '"+ui->comboBox_OpenOrder->currentText());
    database.Update("Orders","Status","Enroute","Status","Open' AND OrderNo = '"+ui->comboBox_OpenOrder->currentText());
    RedoCombos();
}

void Orders::on_pushButton_Recieved_clicked()
{
    //gets current date
    QDate date = QDate::currentDate();
    QString dateString = date.toString();

    for(int i=0; i<database.Size("Orders WHERE Status = 'Enroute' AND OrderNo = '"+ui->comboBox_OrderEnroute->currentText()+"'","ItemNo");i++){

        if( database.GetOrders("itemno",i,NULL," WHERE Status = 'Enroute' AND OrderNo = '"+ui->comboBox_OrderEnroute->currentText()+"'") != NULL){


            QString temp = database.GetOrders("itemno",i,NULL," WHERE Status = 'Enroute' AND OrderNo = '"+ui->comboBox_OrderEnroute->currentText()+"'");
            database.Update("Inventory","AmountInStock",
                            QString::number(database.GetOrders("amount",0,NULL," WHERE ItemNo = '"+temp+"' AND  Status = 'Enroute' AND OrderNo = '"+ui->comboBox_OrderEnroute->currentText()+"'").toInt()+
                                            database.GetInventory("amountinstock",0,NULL," WHERE ItemId = '"+temp+"'").toInt()),
                            "ItemId",temp);
        }

    }

    database.Update("Orders","DateRecieved",dateString,"Status","Enroute' AND OrderNo = '"+ui->comboBox_OrderEnroute->currentText());
    database.Update("Orders","Status","Closed","Status","Enroute' AND OrderNo = '"+ui->comboBox_OrderEnroute->currentText());

    RedoCombos();
}

void Orders::RedoCombos(){

    ui->comboBox_OpenOrder->clear();
    ui->comboBox_OrderEnroute->clear();



    //fill open order combobox
    for(int i=0; i<database.SizeDistinct("Orders WHERE Status = 'Open'","OrderNo");i++)
        ui->comboBox_OpenOrder->addItem(database.GetOrders("orderno",i,NULL," WHERE Status = 'Open'"));


    //fill enroute order combobox
    for(int i=0; i<database.SizeDistinct("Orders WHERE Status = 'Enroute'","OrderNo");i++)
        ui->comboBox_OrderEnroute->addItem(database.GetOrders("orderno",i,NULL," WHERE Status = 'Enroute'"));
}

void Orders::on_pushButton_CreateOrder_clicked()
{
    QString temp = QString::number(database.Everything("Select MAX(OrderNo) from Orders").toInt()+1);

    QMessageBox msgBox;
    msgBox.setText("Order Number: "+temp+" Placed");
    msgBox.exec();

    database.Insert("Orders","OrderNo,Status,Supplier",
                    "'"+(temp)+"',"
                    "'"+"Open"+"',"
                    "'"+ui->comboBox_Supplier->currentText()+"'");
    RedoCombos();
}
