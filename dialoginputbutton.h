#ifndef DIALOGINPUTBUTTON_H
#define DIALOGINPUTBUTTON_H

#include <QDialog>
#include <QtDebug>
#include <QMessageBox>


namespace Ui {
class DialogInputButton;
}

class DialogInputButton : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInputButton(QWidget *parent = 0);
    ~DialogInputButton();

signals:


private slots:
    void on_DialogInputButton_accepted();

private:
    Ui::DialogInputButton *ui;
};

#endif // DIALOGINPUTBUTTON_H
