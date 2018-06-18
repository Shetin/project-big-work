#ifndef LEVEL_H
#define LEVEL_H

#include <QDialog>

namespace Ui {
class Level;
}

class Level : public QDialog
{
    Q_OBJECT

public:
    explicit Level(QWidget *parent = 0);
    ~Level();
signals:
    void display(int number);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Level *ui;
};

#endif // LEVEL_H
