#include "categorybutton.h"
#include "ui_categorybutton.h"

CategoryButton::CategoryButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CategoryButton)
{
    ui->setupUi(this);
}

CategoryButton::~CategoryButton()
{
    delete ui;
}


void CategoryButton::SetupPage(QString category){
    ui->pushButton_item1->setText("here");
    //ui->pushButton_item1->setText(database.GetSupplier("itemname",0,NULL,"Where category ='"+category+"'"));
    //ui->pushButton_item2->setText(database.GetSupplier("itemname",1,NULL,"Where category ='"+category+"'"));
    //ui->pushButton_item3->setText(database.GetSupplier("itemname",2,NULL,"Where category ='"+category+"'"));
}
