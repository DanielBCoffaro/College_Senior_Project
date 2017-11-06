#ifndef LOGININFO_H
#define LOGININFO_H

#include <QWidget>
#include <QMessageBox>
#include <QBoxLayout>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QtSql/QSqlDatabase>
#include <QSignalMapper>

#include "loginglistwidget.h"
#include "dialog_adduser.h"
#include "database.h"

namespace Ui {
class LoginInfo;
}

class LoginInfo : public QWidget
{
    Q_OBJECT

public:
    explicit LoginInfo(QWidget *parent = 0);
    ~LoginInfo();

private slots:

    void on_BackLoginInfo_clicked(){emit LoginHome();}

    void on_pushButton_clicked();

    void Slot_UserChange();

signals:
    void LoginHome();
    void UserChange();

private:
    Ui::LoginInfo *ui;

    Database database;
    Dialog_AddUser* msgBox;

    QWidget *widget;
    QVBoxLayout *vLayout;
    LogingListWidget* label[9];

    //QSignalMapper * sigmap;
    //QSlider *
};

#endif // LOGININFO_H
