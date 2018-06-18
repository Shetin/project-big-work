#include "tank.h"
#include "icon.h"
#include "world.h"
#include <iostream>
#include <QPainter>
#include <QApplication>
using namespace std;

int flag8=0;
Tank::Tank()
{
}
void Tank::set_mybullet(){
    my_bullet._speed=1*32;
    my_bullet._radius=8;
    my_bullet._x=((this->getPosX()+1)*32);
    my_bullet._y=((this->getPosY()+1)*32);//这个地方定义每辆坦克的子弹射出的初始位置
    my_bullet._direction=tankdir;
}
void Tank::change_mybullet(){
    flag8=1;
    my_bullet._speed=2*32;
    my_bullet._radius=12;
}

Player_Bullet Tank::get_bullet(){
    return my_bullet;
}

Tank::~Tank()
{

}
void Tank::move(int direction, int steps){
    switch (direction){
        case 1:
            this->_pos_y -= steps;
            this->showup();
            tankdir=1;
            break;
        case 2:
            this->_pos_y += steps;
            this->showdown();
            tankdir=2;
            break;
        case 3:
            this->_pos_x -= steps;
            this->showleft();
            tankdir=3;
            break;
        case 4:
            this->_pos_x += steps;
            this->showright();
            tankdir=4;
            break;
    }
}

void Tank::showup(){
    this->_pic.load(":/pic/tank.png");
    _pic=_pic.copy(QRect(0,256,64,64));
}

void Tank::showdown(){
    this->_pic.load(":/pic/tank.png");
    _pic=_pic.copy(QRect(0,384,64,64));
}

void Tank::showleft(){
    this->_pic.load(":/pic/tank.png");
    _pic=_pic.copy(QRect(0,448,64,64));
}

void Tank::showright(){
    this->_pic.load(":/pic/tank.png");
    _pic=_pic.copy(QRect(0,320,64,64));
}

Player_Bullet Tank::shoot(QPainter *painter){
    this->set_mybullet();
    if(flag8==1) change_mybullet();
    Player_Bullet new_bullet=my_bullet;
    //painter->setPen(QPen(Qt::black,4));
    new_bullet.show(painter);
    return new_bullet;
}

