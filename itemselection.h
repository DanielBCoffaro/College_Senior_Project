#ifndef ITEMSELECTION_H
#define ITEMSELECTION_H

#include <QWidget>

#include "database.h"

namespace Ui {
class ItemSelection;
}

class ItemSelection : public QWidget
{
    Q_OBJECT

public:
    explicit ItemSelection(QWidget *parent = 0);
    ~ItemSelection();

private slots:
    void on_ButBackItemSel_clicked(){emit ItemHome();}

signals:
    void ItemHome();

private:
    Ui::ItemSelection *ui;
};

#endif // ITEMSELECTION_H
