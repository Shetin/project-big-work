#include "dlglose3.h"
#include "ui_dlglose3.h"

Dlglose3::Dlglose3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlglose3)
{
    ui->setupUi(this);
}

Dlglose3::~Dlglose3()
{
    delete ui;
}

void Dlglose3::on_pushButton_clicked()
{
    close();
    emit display(1);
}
