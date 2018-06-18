#ifndef DLGLOSE3_H
#define DLGLOSE3_H

#include <QDialog>

namespace Ui {
class Dlglose3;
}

class Dlglose3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dlglose3(QWidget *parent = 0);
    ~Dlglose3();
signals:
     void display(int number);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dlglose3 *ui;
};

#endif // DLGLOSE3_H
