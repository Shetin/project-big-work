#include "two.h"
#include "ui_two.h"
#include "QProcess"
int flag_two=0;
Two::Two(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Two)
{
    ui->setupUi(this);
    _game.initWorld("map2.txt");//TODO 应该是输入有效的地图文件
    connect(this,&Two::AfterEat,this,&Two::showDialogTwo);
    dlg=new DialogTwo(this);
    connect(dlg,&DialogTwo::ToLevelThree,this,&Two::win2);
    connect(&this->GetWorld(),World::lose1,this,&Two::showlose2);
    //connect(dlg,&DialogTwo::ToManu,this,&Two::ReturnManu);
    timer3 = new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(handle_Bullet()));//timeoutslot()为自定义槽
        //时钟事件与handle_bullet函数绑定
    timer3->start(100);
    timer3->setInterval(100);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//设置随机数种子
    timer4 = new QTimer(this);
    connect(timer4,SIGNAL(timeout()),this,SLOT(randomMove()));//timeoutslot()为自定义槽
            //时钟事件与randomMove函数绑定
    timer4->start(100);
    timer4->setInterval(500);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    timer5 = new QTimer(this);
    connect(timer5,SIGNAL(timeout()),this,SLOT(handleenemy()));
    timer5->start(0);
    timer5->setInterval(6000);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

Two::~Two()
{
    delete ui;
}

void Two::LevelTwoOver()
{
    emit AfterEat();
}
void Two::win2()
{
    qApp->closeAllWindows();
    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
    emit display(4);
}



void Two::showDialogTwo()
{
    close();
    dlg->show();


}
void Two::showlose2(){

    close();
    dlg2=new Dlglose2(this);
    dlg2->show();

}

const World &Two::GetWorld()
{
    return _game;

}

void Two::paintEvent(QPaintEvent *){
      //setFixedSize(1040,980);
    QPainter *pa;
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/pic/map003.png"));
    pa = new QPainter();
    pa->begin(this);
    this->_game.show(pa);
    //this->_pic.load(":/pic/life.png");
    //pa->drawImage(0,0,this->_pic);
    //pa->drawImage(32,0,this->_pic);
    //pa->drawImage(64,0,this->_pic);
    vector<Player_Bullet>::iterator it;
    for(it=this->_game._bullets.begin();it!=this->_game._bullets.end();it++){
             (*it).show(pa);
    }
    vector<Enemy_bullet>::iterator it1;
    for(it1=this->_game.e_bullets.begin();it1!=this->_game.e_bullets.end();it1++){
             (*it1).show(pa);
    }
    if(flag_two==1)
    {
        _game.handleEnemyBulletShow(pa);
    }
    pa->end();
    delete pa;
}

void Two::keyPressEvent(QKeyEvent *e)
{
    flag_two=0;
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
void Two::randomMove(){
    flag_two=0;
    this->_game.handleEnemyMove();
    flag_two=1;
    this->repaint();
}

void Two::handleenemy(){
    flag_two=0;
    _game.addenemy();
    this->repaint();
}
void Two::handle_Bullet(){
    _game.handleBulletMove();
    _game.handleEnemyBulletMove();
    flag_two=0;
    this->repaint();
}
