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


#include "dialoginputbutton.h"
#include "inventorylist.h"
#include "itemselection.h"
#include "logininfo.h"
#include "supplier.h"
#include "login.h"
#include "categorybutton.h"
#include "database.h"
#include <sys/types.h>
#include "inventorynew.h"



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


    void AddNewCat(const QString& category);
    void AddNewBut();

    //slots for navigating qstacked widget
    void GoHome();
    void GoHomeLogIn(const int &username);
    void on_GoInv_clicked();
    void on_InvListBut_clicked();
    void on_EditLoginBut_clicked();
    void on_SupBut_clicked();
    void on_JumpBut_clicked();
    void on_pushButton_logout_clicked();
    void viewcatbut();
    //Slots for updating the different windows
    void UserChange();
    void SupplierChanged();
private:
    Ui::MainWindow *ui;

    InventoryList *InvList;
    InventoryNewe *InvPage;
    ItemSelection *ItemSel;
    LoginInfo *LogInfo;
    Supplier *Supp;
    Login *Log;


    QString buttontext;

    vector<QString> v;
    vector<CategoryButton*> catwidg;
    CategoryButton* acatwidg;

    int buttoncounter;
    bool buttdeleted;
    QSqlQuery query;
    Database database;
    bool deletegrid;
};

#endif // MAINWINDOW_H
