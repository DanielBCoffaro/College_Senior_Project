#include "inventorypage.h"
#include "ui_inventorypage.h"

InventoryPage::InventoryPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryPage)
{
    ui->setupUi(this);
}

InventoryPage::~InventoryPage()
{
    delete ui;
}
