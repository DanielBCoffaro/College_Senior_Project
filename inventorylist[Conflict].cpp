#include "inventorylist.h"
#include "ui_inventorylist.h"

InventoryList::InventoryList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryList)
{
    ui->setupUi(this);

    QWidget *widget=new QWidget;
    QVBoxLayout *vLayout=new QVBoxLayout;
    InvListInfo* label[9];


    for(int i =0;i<(database.Size("Inventory","Category"));i++){
        ///Have to make it so that there is a last ordered has a value in database,Previously ordered
        ///when an order is placed denote that a shipment is on its way,save dat of this shipment to the database

        label[i] = new InvListInfo(0,"Item: "+database.GetInventory("category",i)+"-"+database.GetInventory("itemname",i),0,
                                   database.GetInventory("cost",i),QString::number(i),QString::number(i),database.GetInventory("supplier",i).toInt());
        label[i]->setFixedSize(730,155);
        vLayout->addWidget(label[i]);
    }

    widget->setLayout(vLayout);
    ui->scrollArea->setWidget(widget);
}

InventoryList::~InventoryList()
{
    delete ui;
}
