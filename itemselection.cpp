#include "itemselection.h"
#include "ui_itemselection.h"

ItemSelection::ItemSelection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemSelection)
{
    ui->setupUi(this);
}

ItemSelection::~ItemSelection()
{
    delete ui;
}
