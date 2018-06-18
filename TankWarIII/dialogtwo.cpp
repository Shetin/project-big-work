#include "dialogtwo.h"
#include "ui_dialogtwo.h"

DialogTwo::DialogTwo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTwo)
{
    ui->setupUi(this);
}

DialogTwo::~DialogTwo()
{
    delete ui;
}

void DialogTwo::on_pushButton_clicked()
{
    emit ToLevelThree();
    close();
}

void DialogTwo::on_pushButton_2_clicked()
{
    emit display(0);
    close();
}
