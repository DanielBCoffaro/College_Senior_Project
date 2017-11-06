#include "dialoginputbutton.h"
#include "ui_dialoginputbutton.h"

DialogInputButton::DialogInputButton(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInputButton)
{
    ui->setupUi(this);

}

DialogInputButton::~DialogInputButton()
{
    delete ui;
}


void DialogInputButton::on_DialogInputButton_accepted()
{
    QMessageBox msgBox;
    msgBox.setText("It gets here");
    msgBox.exec();
    //emit addedtoVector(ui->lineEdit->text());
}
