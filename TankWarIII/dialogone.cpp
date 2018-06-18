#include "dialogone.h"
#include "ui_dialogone.h"
#include "one.h"
#include "two.h"
#include "widget.h"
#include <QApplication>
#include "QProcess"
#include <QBitmap>
#include <QHBoxLayout>

DialogOne::DialogOne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOne)
{

    ui->setupUi(this);

}

DialogOne::~DialogOne()
{
    delete ui;
}

void DialogOne::on_pushButton_clicked()
{

    emit ToLevelTwo();
    close();
}

void DialogOne::on_pushButton_2_clicked()
{
    emit display(0);
    close();
}


