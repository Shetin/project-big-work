#include "three.h"
#include "ui_three.h"
int flag_three=0;

Three::Three(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Three)
{
    ui->setupUi(this);
    _game.initWorld("map3.txt");//TODO 应该是输入有效的地图文件
    connect(this,&Three::AfterEat,this,&Three::showDialogThree);
    dlg=new DialogThree(this);
    connect(&this->GetWorld(),World::lose1,this,&Three::showlose3);
    //connect(dlg,&DialogThree::ToLevelThree,this,&Two::win2);
    //connect(dlg,&DialogThree::ToManu,this,&Three::ReturnManu);
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
    timer1->setInterval(500);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(handleenemy()));
    timer2->start(0);
    timer2->setInterval(6000);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

Three::~Three()
{
    delete ui;
}



void Three::LevelThreeOver()
{
    //cout<<"WELL"<<endl;
    //emit display(2);
    emit AfterEat();
}



void Three::showDialogThree()
{
    close();
    dlg->show();

}
void Three::showlose3(){

    close();
    dlg3=new Dlglose3(this);
    dlg3->show();

}
const World &Three::GetWorld()
{
    return _game;

}

void Three::paintEvent(QPaintEvent *){
    setFixedSize(1040,980);
    QPainter *pa;
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/pic/map.jpg"));
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
    if(flag_three==1)
    {
        _game.handleEnemyBulletShow(pa);
    }
    pa->end();
    delete pa;
}

void Three::keyPressEvent(QKeyEvent *e)
{
    flag_three=0;
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



void Three::handle_Bullet(){
    _game.handleBulletMove();
    _game.handleEnemyBulletMove();
    flag_three=0;
    this->repaint();
}


void Three::randomMove(){
    flag_three=0;
    this->_game.handleEnemyMove();
    flag_three=1;
    this->repaint();
}

void Three::handleenemy(){
    flag_three=0;
    _game.addenemy();
    this->repaint();
}
