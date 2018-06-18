#include "dialogthree.h"
#include "ui_dialogthree.h"

DialogThree::DialogThree(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogThree)
{
    ui->setupUi(this);

}

DialogThree::~DialogThree()
{
    delete ui;
}


void DialogThree::on_pushButton_2_clicked()
{

    myPlayer=new QMediaPlayer;
    videoWidget=new QVideoWidget;
    mainLayout=new QHBoxLayout(this);
    myPlayer->setVideoOutput(videoWidget);
    QPalette* palette = new QPalette();
       palette->setBrush(QPalette::Background, Qt::black);
       videoWidget->setPalette(*palette);
       videoWidget->setAutoFillBackground(true);
       delete palette;
      // videoWidget->setAspectRatioMode(Qt::IgnoreAspectRatio);

    myPlayer->setMedia(QUrl::fromLocalFile("C:\\Users\\asus\\Desktop\\TankWarIII\\endshow.avi"));
    mainLayout->addWidget(videoWidget);
    myPlayer->play();
}
