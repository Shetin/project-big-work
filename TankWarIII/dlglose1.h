#ifndef DLGLOSE1_H
#define DLGLOSE1_H

#include <QDialog>

namespace Ui {
class Dlglose1;
}

class Dlglose1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dlglose1(QWidget *parent = 0);
    ~Dlglose1();
signals:
     void display(int number);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dlglose1 *ui;
};

#endif // DLGLOSE1_H
