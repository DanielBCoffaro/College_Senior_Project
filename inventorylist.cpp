#include "inventorylist.h"
#include "ui_inventorylist.h"

InventoryList::InventoryList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryList)
{
    ui->setupUi(this);

    QWidget *widget=new QWidget;
    QVBoxLayout *vLayout=new QVBoxLayout;
    InvListInfo* label[database.Size("Inventory","Category")]; ///needs to be dynamic



    for(int i =0;i<(database.Size("Inventory","Category"));i++){
        ///Have to make it so that there is a last ordered has a value in database,Previously ordered
        ///when an order is placed denote that a shipment is on its way,save date of the shipment to the database


        // database.Everything("SELECT Category FROM Inventory ORDER BY ((SELECT threshold from Inventory)-(SELECT AmountInStock from Inventory)) ASC  ")

        QString status;
        QString itemid=database.GetInventory("itemid",i,NULL," ORDER BY ((SELECT threshold from Inventory)-(SELECT AmountInStock from Inventory)) ASC  ");
        //database.Everything("SELECT count(1) from Orders where ItemNo = "+itemid);

//        QMessageBox msgBox;
//        msgBox.setText(database.GetInventory("amountinstock",i,NULL," ORDER BY ((SELECT threshold from Inventory)-(SELECT AmountInStock from Inventory)) ASC  "));
//        msgBox.exec();

//        //QMessageBox msgBox;
//        msgBox.setText(database.GetInventory("threshold",i,NULL," ORDER BY ((SELECT threshold from Inventory)-(SELECT AmountInStock from Inventory)) ASC  "));
//        msgBox.exec();


        //if its in a set with open order say that
        if(database.Size("Orders WHERE ItemNo = '"+itemid+"' AND Status = 'Open'","*")){
            status = "Placed in order";
        //if its in a set with Enroute order say that
        }else if(database.Size("Orders WHERE ItemNo = '"+itemid+"' AND Status = 'Enroute'","*")){
            status = "Order Enroute";
        //if its in a low but has no order say that
        }else if((database.GetInventory("amountinstock",i,NULL," ORDER BY ((SELECT threshold from Inventory)-(SELECT AmountInStock from Inventory)) ASC  ").toInt())
                 <(database.GetInventory("threshold",i,NULL," ORDER BY ((SELECT threshold from Inventory)-(SELECT AmountInStock from Inventory)) ASC  ").toInt())){
            status = "LOW!";
        //if none of those say its fine
        }else{
            status= "Fine";
        }
///Some Problem here
        label[i] = new InvListInfo(0,
                                   //Item Name
                                   "Item: "+database.GetInventory("category",i,NULL," ORDER BY ((SELECT threshold from Inventory)-(SELECT AmountInStock from Inventory)) ASC  ")
                                   +"-"+database.GetInventory("itemname",i,NULL," ORDER BY ((SELECT threshold from Inventory)-(SELECT AmountInStock from Inventory)) ASC  ")
                                   //cost
                                   ,database.GetInventory("cost",i,NULL," ORDER BY ((SELECT threshold from Inventory)-(SELECT AmountInStock from Inventory)) ASC  ")
                                   //amnt in stock
                                   ,database.GetInventory("amountinstock",i,NULL," ORDER BY ((SELECT threshold from Inventory)-(SELECT AmountInStock from Inventory)) ASC  ")
                                   //ItemId
                                   ,database.GetInventory("itemid",i,NULL," ORDER BY ((SELECT threshold from Inventory)-(SELECT AmountInStock from Inventory)) ASC  ").toInt()
                                   ,status);



        label[i]->setFixedSize(730,155);
        vLayout->addWidget(label[i]);

        connect(label[i], SIGNAL(InventoryChangedInfo()), this, SLOT(Inventory_Changed()));

    }

    widget->setLayout(vLayout);
    ui->scrollArea->setWidget(widget);
}

InventoryList::~InventoryList()
{
    delete ui;
}
