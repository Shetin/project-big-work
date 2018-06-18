#include "one.h"
#include "ui_one.h"
#include "two.h"
#include "widget.h"
#include <QApplication>
#include <QPainter>
#include <QBitmap>
#include <QHBoxLayout>
#include "iostream"
#include "dialogone.h"
#include "QProcess"
int flag_one=0;
using namespace std;
One::One(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::One)
{

    ui->setupUi(this);
    _game.initWorld("map1.txt");//TODO 应该是输入有效的地图文件
   connect(this,&One::AfterEat,this,&One::showDialogOne);
   dlg=new DialogOne(this);
   connect(dlg,&DialogOne::ToLevelTwo,this,&One::win1);
   //connect(dlg,&DialogOne::ToManu,this,&One::ReturnManu);
   connect(&this->GetWorld(),World::lose1,this,&One::showlose1);
    //connect(ui->showChildButton,&QPushButton::clicked,this,&One::showDialogOne);
   timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(handle_Bullet()));//timeoutslot()为自定义槽
       //时钟事件与handle_bullet函数绑定
   timer->start(100);
   timer->setInterval(100);
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//设置随机数种子*/
   timer1 = new QTimer(this);
   connect(timer1,SIGNAL(timeout()),this,SLOT(randomMove()));//timeoutslot()为自定义槽
           //时钟事件与randomMove函数绑定
   timer1->start(100);
   timer1->setInterval(1000);
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

   timer2 = new QTimer(this);
   connect(timer2,SIGNAL(timeout()),this,SLOT(handleenemy()));
   timer2->start(0);
   timer2->setInterval(6000);
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

}
One::~One()
{
    delete ui;

}

void One::LevelOneOver()
{
    //cout<<"WELL"<<endl;
    //emit display(2);
    emit AfterEat();
}
void One::win1()
{
    qApp->closeAllWindows();
    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
    emit display(3);
}


void One::showlose1()
{

    close();
    dlg1=new Dlglose1(this);
    dlg1->show();
}

void One::showDialogOne()
{
    close();
    dlg->show();

}

const World &One::GetWorld()
{
    return _game;

}

void One::paintEvent(QPaintEvent *){
      setFixedSize(1040,980);
    QPainter *pa;
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/pic/map006.png"));
    pa = new QPainter();
    pa->begin(this);
    this->_game.show(pa);
    vector<Player_Bullet>::iterator it;
    for(it=this->_game._bullets.begin();it!=this->_game._bullets.end();it++){
             (*it).show(pa);
    }
    vector<Enemy_bullet>::iterator it1;
    for(it1=this->_game.e_bullets.begin();it1!=this->_game.e_bullets.end();it1++){
             (*it1).show(pa);
    }
    if(flag_one==1)
    {
        _game.handleEnemyBulletShow(pa);
    }
    pa->end();
    delete pa;
}

void One::keyPressEvent(QKeyEvent *e)
{
    flag_one=0;
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handleTankMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handleTankMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handleTankMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handleTankMove(2,1);
    }
    //this->repaint();//repaint的作用是再调用一次paintEvent函数
    if(e->key() ==Qt::Key_Space){
        QPainter *pa;
        pa = new QPainter();
        pa->begin(this);
        this->_game.handleBulletShow(pa);//利用空格键操纵使发射子弹
        pa->end();
        delete pa;
    }
    this->repaint();//repaint的作用是再调用一次paintEvent函数
}

void One::handle_Bullet(){
    _game.handleBulletMove();
    _game.handleEnemyBulletMove();
    flag_one=0;
    this->repaint();
}

void One::randomMove(){
    flag_one=0;
    this->_game.handleEnemyMove();
    flag_one=1;
    this->repaint();
}

void One::handleenemy(){
    flag_one=0;
    _game.addenemy();
    //flag_one=1;
    this->repaint();
}
