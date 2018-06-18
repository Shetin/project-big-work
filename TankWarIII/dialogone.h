#ifndef DIALOGONE_H
#define DIALOGONE_H

#include <QDialog>

namespace Ui {
class DialogOne;
}

class DialogOne : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOne(QWidget *parent = 0);
    ~DialogOne();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
signals:
     void display(int number);
     void ToLevelTwo();

private:
    Ui::DialogOne *ui;

};

#endif // DIALOGONE_H
