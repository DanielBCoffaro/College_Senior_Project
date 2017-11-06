#include "logininfo.h"
#include "ui_logininfo.h"

LoginInfo::LoginInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginInfo)
{
    ui->setupUi(this);

    msgBox=new Dialog_AddUser;

    widget=new QWidget;
    vLayout=new QVBoxLayout;

    for (int i=0;i<database.Size("Personell","UserName");i++) {
        label[i] = new LogingListWidget();
        //this takes the information from the database class and passes it to the logininfo class filling it with the right info
        label[i]->setLoginInfo(database.GetPersonell("id",i),database.GetPersonell("username",i),database.GetPersonell("password",i),database.GetPersonell("privlages",i).toInt());
        label[i]->setFixedSize(570,125);
        vLayout->addWidget(label[i]);
        connect(label[i], SIGNAL(UserChange()), this, SLOT(Slot_UserChange()));
    }
    //connects the adduser dialog to this class
    connect(msgBox, SIGNAL(UserAdded()), this, SLOT(Slot_UserChange()));



    widget->setLayout(vLayout);
    ui->scrollArea->setWidget(widget);
}

LoginInfo::~LoginInfo()
{
    delete ui;
}


void LoginInfo::on_pushButton_clicked()
{
    //Dialog_AddUser* msgBox=new Dialog_AddUser;//NOT NEED BECAUSE DECLARED IN WHOLE CLASS NOW
    msgBox->exec();
}

void LoginInfo::Slot_UserChange(){
    emit UserChange();
}


