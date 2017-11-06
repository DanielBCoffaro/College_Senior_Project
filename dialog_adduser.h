#ifndef DIALOG_ADDUSER_H
#define DIALOG_ADDUSER_H

#include <QDialog>

#include "QMessageBox"
#include "database.h"

namespace Ui {
class Dialog_AddUser;
}

class Dialog_AddUser : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddUser(QWidget *parent = 0);
    ~Dialog_AddUser();

private slots:
    void on_buttonBox_accepted();

signals:
    void UserAdded();

private:
    Ui::Dialog_AddUser *ui;
    Database database;
};

#endif // DIALOG_ADDUSER_H
