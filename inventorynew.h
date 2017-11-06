#ifndef INVENTORYNEW_H
#define INVENTORYNEW_H

#include <QWidget>
#include <QMessageBox>
#include <QString>

#include "dialoginputbutton.h"
#include "database.h"

namespace Ui {
class InventoryNew;
}

class InventoryNew : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryNew(QWidget *parent, QString category ,QString supplier,QString itemname,QString amntinstock,QString threshold,QString salesprice,QString cost);
    ~InventoryNew();

signals:
    void InvBack();
    void AddNewBut();
    void addedtoVector(const QString& category);
    void CategoryChanged();
    void InventoryChanged(QString whatwindow);
private slots:
    //connects button to home
    void on_InvBack_clicked();
    void on_InvSave_clicked();
    void on_InvAddNew_clicked();

    void on_InvAddNew_2_clicked();

private:
    Ui::InventoryNew *ui;
    void SetInvPage(QString Pass);
    //void SetInvPage(float cost, QString itemname, float salesprice, int amntstock, int threshold);

    Database database;

    QString category , supplier, itemname, amntinstock, threshold, salesprice, cost;

    bool danew = true;

    QString priorname;

};

#endif // INVENTORYNEW_H
