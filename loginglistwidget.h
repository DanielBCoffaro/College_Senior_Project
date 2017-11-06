#ifndef LOGINGLISTWIDGET_H
#define LOGINGLISTWIDGET_H

#include <QWidget>

#include "database.h"

namespace Ui {
class LogingListWidget;
}

class LogingListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogingListWidget(QWidget *parent = 0);
    ~LogingListWidget();
    void setLoginInfo (QString ID=NULL,QString username=NULL,QString password=NULL,int privlages=0);

private slots:

    void on_pushButton_SaveChanges_clicked();

    void on_pushButton_clicked();

signals:
    void UserChange();

private:
    Ui::LogingListWidget *ui;
    Database database;
    QString widgetsid;

};

#endif // LOGINGLISTWIDGET_H
