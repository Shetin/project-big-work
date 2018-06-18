#include "start.h"
#include "ui_start.h"
#include "QProcess"
Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    setFixedSize(1000,800);
    myPlayer=new QMediaPlayer;
    videoWidget=new QVideoWidget;
    mainLayout=new QHBoxLayout(this);
    myPlayer->setVideoOutput(videoWidget);
    /*QPalette* palette = new QPalette();
       palette->setBrush(QPalette::Background, Qt::black);
       videoWidget->setPalette(*palette);
       videoWidget->setAutoFillBackground(true);
       delete palette;*/
      // videoWidget->setAspectRatioMode(Qt::IgnoreAspectRatio);

    myPlayer->setMedia(QUrl::fromLocalFile("C:\\Users\\asus\\Desktop\\TankWarIII\\startshow.avi"));
    mainLayout->addWidget(videoWidget);
    myPlayer->play();
}

Start::~Start()
{
    delete ui;
}

void Start::on_pushButton_clicked()
{

    emit display(1);
    QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->setCurrentIndex(1);
    QMediaPlayer *player = new QMediaPlayer;
    player->setPlaylist(playlist);
    player->setMedia(QUrl::fromLocalFile("C:\\Users\\asus\\Desktop\\TankWarIII\\back.mp3"));
    player->setVolume(150);
    player->play();
}
