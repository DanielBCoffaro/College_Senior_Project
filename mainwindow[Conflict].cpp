#include "mainwindow.h"
#include "ui_mainwindow.h"

///MainWindow   (Inventory Changes -> Button)
///InvNew       (Supplier +/- -> supplier list)  ~~~This would be done except for issues with the scope~~~
///InvList      (Supplier +/- -> Supplier list, +/- inventory -> the list itself)
///EditLog      (+/- user -> the list itself)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    deletegrid = false;

    ///Main windows passes the database as it creates the windows...those windows pass that

    //****************************************
    //declares other windows
    //****************************************
    //DialogInputButton *DialogInput = new DialogInputButton(this);
    InvList = new InventoryList(this);
    ItemSel = new ItemSelection(this);
    LogInfo = new LoginInfo(this);
    Supp = new Supplier(this);
    Log = new Login(this);
    //InventoryNew * PageInv = new InventoryNew(this);
    PageInv = new InventoryNew(this);

    //****************************************
    //adds pages to the stack widget
    //****************************************
    ui->stackedWidget->addWidget(InvList);
    ui->stackedWidget->addWidget(PageInv);
    ui->stackedWidget->addWidget(ItemSel);
    ui->stackedWidget->addWidget(LogInfo);
    ui->stackedWidget->addWidget(Supp);
    ui->stackedWidget->addWidget(Log);

    //****************************************
    //All the connections bewtween the widgets
    //****************************************
    //connects home/back buttons to main window

    connect(InvList, SIGNAL(InvListHome()), this, SLOT(GoHome()));

    //connect (pageemit, Signal(signalemmitted()),recivingpage, SLOT(slotreciving))


    connect(PageInv, SIGNAL(InvBack()), this, SLOT(GoHome()));
    connect(ItemSel, SIGNAL(ItemHome()), this, SLOT(GoHome()));
    connect(LogInfo, SIGNAL(LoginHome()), this, SLOT(GoHome()));
    connect(Supp, SIGNAL(SuppHome()), this, SLOT(GoHome()));
    connect(Log, SIGNAL(LogHome(const int&)), this, SLOT(GoHomeLogIn(const int&)));
    //connects add new button of new inventory to main window
    connect(PageInv, SIGNAL(AddNewBut()), this, SLOT(AddNewBut()));
    //connects the dialog input to add new catagory which adds it to a vector
    connect(PageInv, SIGNAL(addedtoVector(QString)), this, SLOT(AddNewCat(QString)));

    //all the connections regarding the updating widgets
    connect(LogInfo, SIGNAL(UserChange()), this, SLOT(UserChange()));
    connect(Supp, SIGNAL(SupplierChanged()), this, SLOT(SupplierChanged()));

    //set the first page to the login page
    ui->stackedWidget->setCurrentIndex(7);
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
    AddNewBut();
    ui->stackedWidget->setCurrentIndex(0);
}
//sets qstacked widget to inventory list page
void MainWindow::on_InvListBut_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
//sets qstacked widget to inventory new page
void MainWindow::on_GoInv_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
//sets qstacked widget to item selction page
void MainWindow::on_JumpBut_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
//sets qstacked widget to login info page
void MainWindow::on_EditLoginBut_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
//sets qstacked widget to supplier page
void MainWindow::on_SupBut_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
//sets sqstacked widget to logout page
void MainWindow::on_pushButton_logout_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}
//sets qwidget to the sub-categories page
void MainWindow::viewcatbut(){
    ui->stackedWidget->setCurrentIndex(8);
    ///will need to set info based on which one was clicked
}
//comes from login page and sets shown buttons to do privlages
void MainWindow::GoHomeLogIn(const int & username)
{
    AddNewBut(); //function call that creates the buttons for the page

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

    //deletes the buttons that were only used to create the proper form. silly QT
    if(buttdeleted){
        delete ui->buthide1;
        delete ui->buthide2;
        delete ui->buthide3;
        delete ui->buthide4;
        buttdeleted =false;
    }

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::UserChange(){
    Log->redo();
    LogInfo->update();

}
void MainWindow::SupplierChanged(){
    //Supp->redo();
}




//********************************************************
//
//********************************************************
void MainWindow::AddNewBut()
{

    for(int i=0;i<database.SizeDistinct("Inventory","Category");i++) {

        ///make it not repeat.
        QVector<QPushButton*> btn;          //creates a vector of buttons called btn
        QPushButton *b = new QPushButton;   //creates a new button named b
        b->setText(database.GetInventory("category",i,"DISTINCT",NULL)); //This sets the text of the newly created button
        b->setGeometry(0,0,600,600);        //sets the geometry (haven't played with)
        ui->gridLayout_2->addWidget(b);     //cann set grid if needed
        btn << b;                           //adds b to the btn i think
        acatwidg = new CategoryButton;      //creates a new button widget
        ui->stackedWidget->addWidget(acatwidg); //adds the buttonwidget to the stacked widget
        connect(b,SIGNAL(clicked()),this,SLOT(viewcatbut())); ///will need to pass the one thats clicked so can go to the right view
        connect(acatwidg, SIGNAL(catbutgohome()), this, SLOT(GoHome()));
    }

}

void MainWindow::AddNewCat(const QString& category){
    v.push_back(category);
    AddNewBut();
}
