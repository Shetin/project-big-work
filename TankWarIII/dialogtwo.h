#ifndef DIALOGTWO_H
#define DIALOGTWO_H

#include <QDialog>

namespace Ui {
class DialogTwo;
}

class DialogTwo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTwo(QWidget *parent = 0);
    ~DialogTwo();
signals:
     void display(int number);
     void ToLevelThree();

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::DialogTwo *ui;
};

#endif // DIALOGTWO_H
