#include "dlglose2.h"
#include "ui_dlglose2.h"

Dlglose2::Dlglose2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlglose2)
{
    ui->setupUi(this);
}

Dlglose2::~Dlglose2()
{
    delete ui;
}

void Dlglose2::on_pushButton_clicked()
{
    close();
    emit display(1);
}
