#include "level.h"
#include "ui_level.h"
#include "QProcess"
Level::Level(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Level)
{
    ui->setupUi(this);

}

Level::~Level()
{
    delete ui;
}

void Level::on_pushButton_clicked()
{

    emit display(2);
}

void Level::on_pushButton_2_clicked()
{
    emit display(3);
}

void Level::on_pushButton_3_clicked()
{

    emit display(4);
}
