#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QtDebug>

#include "database.h"


namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    void redo();
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_comboBox_currentIndexChanged(const QString &arg1);

signals:
    void LogHome(const int& username);

private:
    Ui::Login *ui;
    QString passwordstring;
    int privlages;
    Database database;

};

#endif // LOGIN_H
