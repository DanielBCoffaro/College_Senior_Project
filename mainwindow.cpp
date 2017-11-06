#include "mainwindow.h"
#include "ui_mainwindow.h"

///-When the inventory falls below the threshold alert user via message box
///-Sort Inventory List

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    deletegrid = false; //varible to make sure initial buttons only deleted once
    
    //****************************************
    //declares other windows
    //****************************************
    InvList = new InventoryList(this);
    ItemSel = new ItemSelection(this);
    LogInfo = new LoginInfo(this);
    Supp = new Supplier(this);
    Log = new Login(this);
    PageInv = new InventoryNew(this,NULL,NULL,NULL,0,0,NULL,NULL);
    Orderspage = new Orders(this);

    //****************************************
    //adds pages to the stack widget
    //****************************************
    ui->stackedWidget->addWidget(InvList);
    ui->stackedWidget->addWidget(PageInv);
    ui->stackedWidget->addWidget(ItemSel);
    ui->stackedWidget->addWidget(LogInfo);
    ui->stackedWidget->addWidget(Supp);
    ui->stackedWidget->addWidget(Log);
    ui->stackedWidget->addWidget(Orderspage);
    
    //****************************************
    //All the connections bewtween the widgets
    //****************************************
    connect(InvList, SIGNAL(InvListHome()), this, SLOT(GoHome()));
    connect(PageInv, SIGNAL(InvBack()), this, SLOT(GoHome()));
    connect(ItemSel, SIGNAL(ItemHome()), this, SLOT(GoHome()));
    connect(LogInfo, SIGNAL(LoginHome()), this, SLOT(GoHome()));
    connect(Supp, SIGNAL(SuppHome()), this, SLOT(GoHome()));
    connect(Orderspage, SIGNAL(OrdersHome()), this, SLOT(GoHome()));

    connect(Log, SIGNAL(LogHome(const int&)), this, SLOT(GoHomeLogIn(const int&)));
    //connects add new button of new inventory to main window
    connect(PageInv, SIGNAL(AddNewBut()), this, SLOT(AddNewBut()));
    //connects the dialog input to add new catagory which adds it to a vector
    connect(PageInv, SIGNAL(addedtoVector(QString)), this, SLOT(AddNewCat(QString)));
    //all the connections regarding the updating widgets
    connect(LogInfo, SIGNAL(UserChange()), this, SLOT(UserChange()));
    connect(Supp, SIGNAL(SupplierChanged()), this, SLOT(SupplierChanged()));
    connect(PageInv, SIGNAL(CategoryChanged()), this, SLOT(CategoryChanged()));
    connect(PageInv, SIGNAL(InventoryChanged(QString)), this, SLOT(InventoryChanged(QString)));
    connect(InvList, SIGNAL(InventoryChanged(QString)), this, SLOT(InventoryChanged(QString)));

    
    //set the first page to the login page
    ui->stackedWidget->setCurrentIndex(7);

    for(int i=0;i<database.SizeDistinct("Categories","Category");i++)
        ui->comboBox_Categories->addItem(database.GetCategories("category",i));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//********************************************************
//All the functions having to do with stacked wdiget
//********************************************************
//sets qstacked widget to home page
void MainWindow::GoHome()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox_Categories->setCurrentIndex(0);
    ui->comboBox_Items->setCurrentIndex(0);
}
//sets qstacked widget to inventory list page
void MainWindow::on_InvListBut_clicked()
{
    InvListRedo();
    ui->stackedWidget->setCurrentWidget(InvList);;
}
//sets qstacked widget to inventory new page
void MainWindow::on_GoInv_clicked()
{
    ui->stackedWidget->setCurrentWidget(PageInv);
}
//sets qstacked widget to login info page
void MainWindow::on_EditLoginBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(LogInfo);
}
//sets qstacked widget to supplier page
void MainWindow::on_SupBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(Supp);
}
//set QStackwidget to orderspage
void MainWindow::on_pushButton_OrdersScreen_clicked()
{
    OrdersRedo();
    ui->stackedWidget->setCurrentWidget(Orderspage);
}
//sets sqstacked widget to logout page
void MainWindow::on_pushButton_logout_clicked()
{
    ui->stackedWidget->setCurrentWidget(Log);
}

///Pretty sure this does nothing....
void MainWindow::on_JumpBut_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Jumpbut clicked!");
    msgBox.exec();
    //ui->stackedWidget->setCurrentWidget(acatwidg);
}

//************************************************************************************************
//comes from login page and sets shown buttons to do privlages
//************************************************************************************************
void MainWindow::GoHomeLogIn(const int & username)
{
    ui->EditLoginBut->setVisible(true);
    ui->InvListBut->setVisible(true);
    ui->SupBut->setVisible(true);
    ui->GoInv->setVisible(true);
    
    //does a switch based on the index sent to it
    switch (username)
    {
    case 0:
        //give full privlages
        break;
    case 1:
        //give limited privlages
        ui->EditLoginBut->setVisible(false);
        break;
    case 2:
        //give no privlages
        ui->EditLoginBut->setVisible(false);
        ui->InvListBut->setVisible(false);
        ui->SupBut->setVisible(false);
        ui->GoInv->setVisible(false);

        break;
    default:
        break;
    }
    ui->stackedWidget->setCurrentIndex(0); //sets index to home window
}

//************************************************************************************************
//Called everytime a user is changed in the program. This is a slot which then updates the
//the program to reflect these changes.
//************************************************************************************************
void MainWindow::UserChange(){
    Log->redo();
    //Log->update(); //Probably not needed

    //Deletes then recreates the login list page so that it updates
    LogInfoRedo();
}

//************************************************************************************************
//Called everytime a supplier is changed in the program. This is a slot which then updates the
//the program to reflect these changes.
//************************************************************************************************
void MainWindow::SupplierChanged(){
    
    //Deletes then recreates the inventory list page so that it updates
    InvListRedo();
    //Deletes then recreates the new inventory page page so that it updates
    PageInvRedo();
}
//************************************************************************************************
//Called everytime a category is changed in the program. This is a slot which then updates the
//the program to reflect these changes.
//************************************************************************************************
void MainWindow::CategoryChanged(){
    //Need to update mainwindow,inventory new

    //Deletes then recreates the inventory list page so that it updates
    InvListRedo();
    //Deletes then recreates the new inventory page page so that it updates
    PageInvRedo();
    //sets current stacked widget to the inventory new page.
    ui->stackedWidget->setCurrentWidget(PageInv);
}
//************************************************************************************************
//Called everytime inventory is changed in the program. This is a slot which then updates the
//the program to reflect these changes.
//************************************************************************************************
void MainWindow::InventoryChanged(QString whatwindow){

    //sets current stacked widget to the appropriate page.
    if(whatwindow == "new"){

        //Deletes then recreates the new inventory page page so that it updates
        PageInvRedo();

        ui->stackedWidget->setCurrentIndex(0);
    }
    else if (whatwindow == "list"){

        InvListRedo();

        ui->stackedWidget->setCurrentWidget(InvList);

    }
}

//************************************************************************************************
//This adds the buttons to the main window based on the categories. Then connects the newly made
//buttons to the category button
//************************************************************************************************

//************************************************************************************************
//This fills the item combobox based on the category chosen
//************************************************************************************************
void MainWindow::on_comboBox_Categories_currentIndexChanged(const QString &arg1)
{


    QMessageBox msgBox;
    //if the catgory is empty, just say its empty
    if(database.Size("Inventory WHERE Category = '"+ui->comboBox_Categories->currentText()+"'","Category")==0){

        QMessageBox msgBox;
        msgBox.setText("Category Empty");
        msgBox.exec();

    } else{

        ui->comboBox_Items->clear();

        for(int i=0;i<database.Size("Inventory WHERE Category = '"+ui->comboBox_Categories->currentText()+"'","Category");i++)
            ui->comboBox_Items->addItem(database.GetInventory("itemname",i,NULL,"WHERE category = '"+ui->comboBox_Categories->currentText()+"'"));
    }
}

//************************************************************************************************
//This is called when the items combo box is changed to set the right values
//************************************************************************************************
void MainWindow::on_comboBox_Items_currentIndexChanged(const QString &arg1)
{


    ui->label_AmntInStock->setText(database.GetInventory("amountinstock",0,NULL," WHERE ItemName = '"+ui->comboBox_Items->currentText()+"'"));
    ui->label_Cost->setText(database.GetInventory("cost",0,NULL," WHERE ItemName = '"+ui->comboBox_Items->currentText()+"'"));
    ui->label_Price->setText(database.GetInventory("salesprice",0,NULL," WHERE ItemName = '"+ui->comboBox_Items->currentText()+"'"));
}

//************************************************************************************************
//This is called to deduct the proper ammount from inventory for that item
//************************************************************************************************
void MainWindow::on_pushButton_Deduct_clicked()
{
    //temp = the amount in stock - combobox
    ///May have to make this check both comboboxes
    int temp  = (database.GetInventory("amountinstock",0,NULL," WHERE ItemName = '"+ui->comboBox_Items->currentText()+"'")).toInt()-(ui->spinBox->value());

    //if the transaction leave with - values don't allow
    if (temp<0){
        QMessageBox msgBox;
        msgBox.setText("There are not that many Items in stock");
        msgBox.exec();
    }else{

        //sets database to the right amount in stock
        database.Update("Inventory","AmountInStock",QString::number(temp),"ItemName",ui->comboBox_Items->currentText());
        //sets label to the right amount in stock
        ui->label_AmntInStock->setText(QString::number(temp));

    }
}


void MainWindow::PageInvRedo(){
    delete PageInv;
    PageInv = new InventoryNew(this,NULL,NULL,NULL,0,0,NULL,NULL);
    ui->stackedWidget->addWidget(PageInv);
    connect(PageInv, SIGNAL(InvBack()), this, SLOT(GoHome()));
    connect(PageInv, SIGNAL(AddNewBut()), this, SLOT(AddNewBut()));
    connect(PageInv, SIGNAL(addedtoVector(QString)), this, SLOT(AddNewCat(QString)));///prob not needed
    connect(PageInv, SIGNAL(CategoryChanged()), this, SLOT(CategoryChanged()));
    connect(PageInv, SIGNAL(InventoryChanged(QString)), this, SLOT(InventoryChanged(QString)));

}
void MainWindow::InvListRedo(){
    delete InvList;
    InvList = new InventoryList(this);
    ui->stackedWidget->addWidget(InvList);
    connect(InvList, SIGNAL(InvListHome()), this, SLOT(GoHome()));
    connect(InvList, SIGNAL(InventoryChanged(QString)), this, SLOT(InventoryChanged(QString)));
}
void MainWindow::LogInfoRedo(){
    delete LogInfo;
    LogInfo = new LoginInfo (this);
    ui->stackedWidget->addWidget(LogInfo);
    ui->stackedWidget->setCurrentWidget(LogInfo);
    connect(LogInfo, SIGNAL(LoginHome()), this, SLOT(GoHome()));
    connect(LogInfo, SIGNAL(UserChange()), this, SLOT(UserChange()));
}
void MainWindow::OrdersRedo(){
    delete Orderspage;
    Orderspage = new Orders (this);
    ui->stackedWidget->addWidget(Orderspage);
    connect(Orderspage, SIGNAL(OrdersHome()), this, SLOT(GoHome()));
}

void MainWindow::on_pushButton_Edir_clicked()
{
    delete PageInv;
    PageInv = new InventoryNew(this,
                               database.GetInventory("category",0,NULL," WHERE ItemName = '"+ui->comboBox_Items->currentText()+"'"),
                               database.GetInventory("supplier",0,NULL," WHERE ItemName = '"+ui->comboBox_Items->currentText()+"'"),
                               database.GetInventory("itemname",0,NULL," WHERE ItemName = '"+ui->comboBox_Items->currentText()+"'"),
                               database.GetInventory("amountinstock",0,NULL," WHERE ItemName = '"+ui->comboBox_Items->currentText()+"'"),
                               database.GetInventory("threshold",0,NULL," WHERE ItemName = '"+ui->comboBox_Items->currentText()+"'"),
                               database.GetInventory("salesprice",0,NULL," WHERE ItemName = '"+ui->comboBox_Items->currentText()+"'"),
                               database.GetInventory("cost",0,NULL," WHERE ItemName = '"+ui->comboBox_Items->currentText()+"'"));
    ui->stackedWidget->addWidget(PageInv);
    connect(PageInv, SIGNAL(InvBack()), this, SLOT(GoHome()));
    connect(PageInv, SIGNAL(AddNewBut()), this, SLOT(AddNewBut()));
    connect(PageInv, SIGNAL(addedtoVector(QString)), this, SLOT(AddNewCat(QString)));///prob not needed
    connect(PageInv, SIGNAL(CategoryChanged()), this, SLOT(CategoryChanged()));
    connect(PageInv, SIGNAL(InventoryChanged(QString)), this, SLOT(InventoryChanged(QString)));
    on_GoInv_clicked();
}
