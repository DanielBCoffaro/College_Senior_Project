#include "inventorynew.h"
#include "ui_inventorynew.h"

InventoryNew::InventoryNew(QWidget *parent, QString category ,QString supplier,QString itemname,QString amntinstock,QString threshold,QString salesprice,QString cost) :
    QWidget(parent),
    ui(new Ui::InventoryNew)
{
    ui->setupUi(this);
    
    this->category=category;
    this->supplier=supplier;
    this->itemname=itemname;
    this->amntinstock=amntinstock;
    this->threshold=threshold;
    this->salesprice=salesprice;
    this-> cost=cost;

    //creates the combobox of categories
    for(int i=0;i<database.SizeDistinct("Categories","Category");i++)
        ui->comboBox->addItem(database.GetCategories("category",i));
    //creates the combobox of suppliers
    for(int i=0;i<database.SizeDistinct("Suppliers","SupplierName");i++)
        ui->comboBox_Supplier->addItem(database.GetSupplier("suppliername",i,"DISTINCT",NULL));


    SetInvPage("Anythingelse");
    priorname = this->itemname;

}


InventoryNew::~InventoryNew()
{
    delete ui;
}
//*****************************************************************************
//Adds a new category to the list, THEN EMITS THE SIGNAL FOR CHANGED CATEGORY
//*****************************************************************************
void InventoryNew::on_InvAddNew_clicked()
{
    bool dabool=false;

    for(int i=0;i<database.SizeDistinct("Categories","Category");i++){

        //loops through category to check to see if another catgory with same name already exists
        if(ui->lineEdit_Category->text()==database.GetCategories("category",i)||ui->lineEdit_Category->text()==NULL)
            dabool=true;
    }
    if(dabool){

        QMessageBox msgBox;
        msgBox.setText("Category already in use.");
        msgBox.exec();
        SetInvPage("NUll");

        ui->lineEdit_Category->clear();
    }
    else{

        database.Insert("Categories","Category",
                        "'"+ui->lineEdit_Category->text()+"'");

        QMessageBox msgBox;
        msgBox.setText("Category added.");
        msgBox.exec();
        SetInvPage("NULL");

        emit CategoryChanged();
        ui->lineEdit_Category->clear();
    }
}

//*****************************************************************************
//Saves the information in the fields to the database, and pops up a dialog box
//****************************************************************************
void InventoryNew::on_InvSave_clicked()
{
    //If user doesn't enter a value for one this breaks, also can be injection attacked

    if(ui->comboBox->currentText() != NULL &&
            ui->lineEdit_Item->text() != NULL &&
            QString::number(ui->spinBox_Threshold->value())!= NULL &&
            QString::number(ui->spinBox_AmntStock->value()) != NULL &&
            ui->comboBox_Supplier->currentText()!= NULL &&
            ui->lineEdit_Cost->text() != NULL &&
            ui->lineEdit_SalesPrice->text() != NULL){

        if(danew){

            database.Insert("Inventory",
                            "Category,ItemName,Threshold,AmountInStock,Supplier,Cost,SalesPrice",
                            "'"+ui->comboBox->currentText()+"',"//category
                            "'"+ui->lineEdit_Item->text()+"',"//item name
                            "'"+QString::number(ui->spinBox_Threshold->value())+"',"//threshold
                            "'"+QString::number(ui->spinBox_AmntStock->value())+"',"//amount in stock
                            "'"+ui->comboBox_Supplier->currentText()+"',"
                            "'"+ui->lineEdit_Cost->text()+"',"//cost
                            "'"+ui->lineEdit_SalesPrice->text()+"'"); //salesprice
        }else{
            database.Update("Inventory","Category",ui->comboBox->currentText(),"ItemName",priorname);
            database.Update("Inventory","ItemName",ui->lineEdit_Item->text(),"ItemName",priorname);
            database.Update("Inventory","Threshold",QString::number(ui->spinBox_Threshold->value()),"ItemName",priorname);
            database.Update("Inventory","AmountInStock",QString::number(ui->spinBox_AmntStock->value()),"ItemName",priorname);
            database.Update("Inventory","Supplier",ui->comboBox_Supplier->currentText(),"ItemName",priorname);
            database.Update("Inventory","Cost",ui->lineEdit_Cost->text(),"ItemName",priorname);
            database.Update("Inventory","SalesPrice",ui->lineEdit_SalesPrice->text(),"ItemName",priorname);
        }



        //made it so it doesnt go home, speeds up multiple data entries
        //        emit InventoryChanged("new");
        //        emit InvBack(); //sends the user back to the home page

        //creates message box that saves info was saved
        QMessageBox msgBox;
        msgBox.setText("Your information was saved!");
        msgBox.exec();
        SetInvPage("NULL");
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Please fill in all fields");
        msgBox.exec();
        SetInvPage("NULL");

    }

}

//*****************************************************************************
//used to set all the values to NULL/0
//*****************************************************************************
void InventoryNew::SetInvPage(QString pass){
    if(pass=="NULL"){
        ui->lineEdit_Cost->setText(NULL);
        ui->lineEdit_Item->setText(NULL);
        ui->lineEdit_SalesPrice->setText(NULL);
        ui->lineEdit_Category->setText(NULL);
        ui->spinBox_AmntStock->setValue(0);
        ui->spinBox_Threshold->setValue(0);
        ui->comboBox->setCurrentIndex(0);
        danew=true;
    }
    else{
        ui->lineEdit_Cost->setText(cost);
        ui->lineEdit_Item->setText(itemname);
        ui->lineEdit_SalesPrice->setText(salesprice);
        ui->lineEdit_Category->setText(NULL);
        ui->spinBox_AmntStock->setValue(amntinstock.toInt());
        ui->spinBox_Threshold->setValue(threshold.toInt());
        ui->comboBox->setCurrentText(category);
        danew=false;
    }

}

void InventoryNew::on_InvAddNew_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText(ui->comboBox->currentText());
    msgBox.exec();

    database.Delete("Categories","Category","'"+ui->comboBox->currentText()+"'");

    emit CategoryChanged();
}

//beam us up scotty
void InventoryNew::on_InvBack_clicked()
{
    emit InventoryChanged("new");
    emit InvBack();
    SetInvPage("NULL");
}
