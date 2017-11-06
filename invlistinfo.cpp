#include "invlistinfo.h"
#include "ui_invlistinfo.h"

InvListInfo::InvListInfo(QWidget *parent,QString Item,QString Cost,QString amountinstock,int itemid,QString status) :
    QWidget(parent),
    ui(new Ui::InvListInfo)
{

    ui->setupUi(this);

    this->itemid=itemid;

    for(int i=0; i<database.SizeDistinct("Orders WHERE Status = 'Open'","OrderNo");i++)
        ui->comboBox_2->addItem(database.GetOrders("orderno",i,NULL," WHERE Status = 'Open'"));

    ui->label_Item->setText(Item);
    ui->label_Cost->setText(Cost);
    ui->label_AmntInStock->setText(amountinstock);
    ui->label_Status->setText(status);
    if(status == "LOW!")
        ui->label_Status->setStyleSheet("QLabel { color: red }");

}

InvListInfo::~InvListInfo()
{
    delete ui;
}

void InvListInfo::on_pushButton_3_clicked() //delete button
{


    database.Delete("Inventory","ItemId","'"+QString::number(itemid)+"'");

    database.Delete("Orders","ItemNo","'"+QString::number(itemid)+"' AND Status = 'Open'");
    database.Delete("Orders","ItemNo","'"+QString::number(itemid)+"' AND Status = 'Enroute'");

    QMessageBox msgBox;
    msgBox.setText("Item Deleted");
    msgBox.exec();

    emit InventoryChangedInfo();
}

void InvListInfo::on_pushButton_PlaceOrder_clicked()
{

    ///Doesnt add supplier
    database.Insert("Orders","Amount,OrderNo,ItemNo,Status,Supplier",
                    "'"+ui->lineEdit_OThisTime->text()+"',"
                    "'"+ui->comboBox_2->currentText()+"',"
                    "'"+QString::number(itemid)+"',"
                    "'Open',"
                    "'"+(database.GetOrders("supplier",0,NULL," WHERE ItemNo = '"+QString::number(itemid)+"' AND  Status = 'Open' AND OrderNo = '"+ui->comboBox_2->currentText()+"'"))+"'");

}
