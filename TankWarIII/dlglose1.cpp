#include "dlglose1.h"
#include "ui_dlglose1.h"
#include "QProcess"
Dlglose1::Dlglose1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlglose1)
{
    ui->setupUi(this);
}

Dlglose1::~Dlglose1()
{
    delete ui;
}

void Dlglose1::on_pushButton_clicked()
{
    close();
    qApp->closeAllWindows();
    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}
