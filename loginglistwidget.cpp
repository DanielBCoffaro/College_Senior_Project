#include "loginglistwidget.h"
#include "ui_loginglistwidget.h"

LogingListWidget::LogingListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogingListWidget)
{
    ui->setupUi(this);


}

LogingListWidget::~LogingListWidget()
{
    delete ui;
}
//used to set the initial values of the line edits
void LogingListWidget::setLoginInfo(QString ID,QString username,QString password,int privlages){
    ui->lineEdit_UserName->setText(username);
    ui->lineEdit_Password->setText(password);
    ui->comboBox_Privlages->setCurrentIndex(privlages);
    widgetsid = ID;

}
//called when users hits save button in widget. updates db from ui lines
void LogingListWidget::on_pushButton_SaveChanges_clicked()
{
    database.Update("Personell","UserName",ui->lineEdit_UserName->text(),"ID",widgetsid);
    database.Update("Personell","Password",ui->lineEdit_Password->text(),"ID",widgetsid);
    database.Update("Personell","Privlages",QString::number(ui->comboBox_Privlages->currentIndex()),"ID",widgetsid);
    emit UserChange();
}

void LogingListWidget::on_pushButton_clicked()
{
    database.Delete("Personell","id",widgetsid);
    emit UserChange();
}
