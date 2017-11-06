#ifndef CATEGORYBUTTON_H
#define CATEGORYBUTTON_H

#include <QWidget>
#include "database.h"

namespace Ui {
class CategoryButton;
}

class CategoryButton : public QWidget
{
    Q_OBJECT

public:
    explicit CategoryButton(QWidget *parent = 0);
    ~CategoryButton();

private slots:
    void on_pushButton_12_clicked(){emit catbutgohome();}
    void SetupPage(QString category);


    signals:
    void catbutgohome();


private:
    Ui::CategoryButton *ui;
    Database database;
};

#endif // CATEGORYBUTTON_H
