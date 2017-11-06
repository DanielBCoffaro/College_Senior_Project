#ifndef INVENTORYLIST_H
#define INVENTORYLIST_H

#include <QWidget>
#include <QMessageBox>
#include <QString>

#include "invlistinfo.h"
#include "database.h"



namespace Ui {
class InventoryList;
}

class InventoryList : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryList(QWidget *parent = 0);
    ~InventoryList();

signals:
    void InvListHome();
    void InventoryChanged(QString whatwindow);

private slots:
    //connects button to home
    void on_BackInvList_clicked(){emit InvListHome();}
    void Inventory_Changed(){emit InventoryChanged("list");}

private:
    Ui::InventoryList *ui;
    Database database;

};

#endif // INVENTORYLIST_H

