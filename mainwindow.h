#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QtGui>
#include <QTextStream>
#include <QtDebug>
#include <QMessageBox>
#include <vector>

#include "inventorynew.h"
#include "inventorylist.h"
#include "itemselection.h"
#include "logininfo.h"
#include "supplier.h"
#include "login.h"
#include "categorybutton.h"
#include "database.h"
#include "orders.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    //slots for navigating qstacked widget
    void GoHome();
    void GoHomeLogIn(const int &username);
    void on_GoInv_clicked();
    void on_InvListBut_clicked();
    void on_EditLoginBut_clicked();
    void on_SupBut_clicked();
    void on_JumpBut_clicked();
    void on_pushButton_logout_clicked();
    //Slots for updating the different windows
    void UserChange();
    void SupplierChanged();
    void CategoryChanged();
    void InventoryChanged(QString whatwindow);

    void on_comboBox_Categories_currentIndexChanged(const QString &arg1);

    void on_comboBox_Items_currentIndexChanged(const QString &arg1);

    void on_pushButton_Deduct_clicked();

    void on_pushButton_Edir_clicked();

    void on_pushButton_OrdersScreen_clicked();

signals:
    void ItemPage(QString category);

private:
    Ui::MainWindow *ui;

    //Declares the various windows called from mainwindow
    InventoryList *InvList;
    InventoryNew *PageInv;
    ItemSelection *ItemSel;
    LoginInfo *LogInfo;
    Supplier *Supp;
    Login *Log;
    CategoryButton* acatwidg;
    Orders* Orderspage;

    QString buttontext;
    //for creating cat button
    vector<QPushButton*> btn;
    QPushButton *b;

    vector<QString> v;
    vector<CategoryButton*> catwidg;


    int buttoncounter;
    bool buttdeleted;
    QSqlQuery query;
    Database database;
    bool deletegrid;

    void PageInvRedo();
    void InvListRedo();
    void LogInfoRedo();
    void OrdersRedo();

    QGridLayout * gridLayout;

};

#endif // MAINWINDOW_H
