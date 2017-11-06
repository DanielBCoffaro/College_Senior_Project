#ifndef INVLISTINFO_H
#define INVLISTINFO_H

#include <QWidget>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class InvListInfo;
}

class InvListInfo : public QWidget
{
    Q_OBJECT

public:
    explicit InvListInfo(QWidget *parent = 0, QString Item=NULL,QString Cost=NULL,QString amountinstock=NULL,int itemid=0,QString status=NULL );
    ~InvListInfo();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_PlaceOrder_clicked();

signals:
    void InventoryChangedInfo();

private:
    Ui::InvListInfo *ui;
    Database database;
    int itemid;
};

#endif // INVLISTINFO_H
