#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    for(int i=0;i<database.SizeDistinct("Personell","UserName");i++) {
        ui->comboBox->addItem(database.GetPersonell("username", i));
    }
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString password=NULL;
    password  = ui->lineEdit->text();

    //passwordstring is set when the combobox is changed
    if(password==passwordstring||password==NULL){ ///get rid of the NULL in final edit
        //makes the password correct box pop up
        QMessageBox msgBox;
        msgBox.setText("Correct Password!");
        msgBox.exec();

        emit LogHome(privlages);            //causes it to go to the main view with the right privlages
        ui->lineEdit->setText(NULL);        //sets the line back to Null so there empty when the user returns
        ui->comboBox->setCurrentIndex(0);   //sets the combo to 0 so its always on the same user
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Try Again!");
        msgBox.exec();
    }

}
//makes it so if the user hits enter it does the same thing as if they hit the button
void Login::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void Login::on_comboBox_currentIndexChanged(const QString &arg1)
{
    //sets passwordstring to whatever password is correlated to the index currentley chosen
    passwordstring = database.GetPersonell("password",ui->comboBox->currentIndex());
    //sets privlages to whatever privlage is correlated to the index currentley chosen
    privlages = database.GetPersonell("privlages",ui->comboBox->currentIndex()).toInt();
}
void Login::redo(){
    ui->comboBox->clear();
    for(int i=0;i<database.SizeDistinct("Personell","UserName");i++) {
        ui->comboBox->addItem(database.GetPersonell("username", i));
    }
}
