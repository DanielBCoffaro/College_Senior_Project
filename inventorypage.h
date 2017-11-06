#ifndef INVENTORYPAGE_H
#define INVENTORYPAGE_H

#include <QWidget>

namespace Ui {
class InventoryPage;
}

class InventoryPage : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryPage(QWidget *parent = 0);
    ~InventoryPage();

private:
    Ui::InventoryPage *ui;
};

#endif // INVENTORYPAGE_H
