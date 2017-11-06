#include "dialog_adduser.h"
#include "ui_dialog_adduser.h"

Dialog_AddUser::Dialog_AddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddUser)
{
    ui->setupUi(this);
}

Dialog_AddUser::~Dialog_AddUser()
{
    delete ui;
}
//This adds a new user to Personell
void Dialog_AddUser::on_buttonBox_accepted()
{
    database.Insert("Personell","id,UserName,Password,Privlages",
                    "'"+QString::number((database.Size("Personell","id")+1))+"'," //This needs to update the personell ID number dynamically
                    "'"+ui->lineEdit_UserName->text()+"',"
                    "'"+ui->lineEdit_Password1->text()+"',"
                    "'"+QString::number(ui->comboBox_Privlages->currentIndex())+"'");
    emit UserAdded();
}
