#ifndef DLGLOSE2_H
#define DLGLOSE2_H

#include <QDialog>

namespace Ui {
class Dlglose2;
}

class Dlglose2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dlglose2(QWidget *parent = 0);
    ~Dlglose2();
signals:
     void display(int number);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dlglose2 *ui;
};

#endif // DLGLOSE2_H
