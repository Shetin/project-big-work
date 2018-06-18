#include "helper.h"
#include "world.h"
#include <QPainter>
#include <QApplication>
#include <iostream>
#include "player_bullet.h"
using namespace std;

void Helper::set_mybullet(){
    my_bullet.set_speed(32);
    my_bullet.set_radius(8.0);
    my_bullet.setposx((this->getPosX()+1)*32);
    my_bullet.setposy((this->getPosY()+1)*32);//这个地方定义每辆坦克的子弹射出的初始位置
    my_bullet.set_direction(2);
}

Player_Bullet Helper::get_bullet(){
    return my_bullet;
}

void Helper::ShowUp(){
    this->_pic.load(":/pic/tank.png");
    _pic=_pic.copy(QRect(256,256,64,64));
}

void Helper::ShowDown(){
    this->_pic.load(":/pic/tank.png");
    _pic=_pic.copy(QRect(256,384,64,64));
}

void Helper::ShowLeft(){
    this->_pic.load(":/pic/tank.png");
    _pic=_pic.copy(QRect(256,448,64,64));
}

void Helper::ShowRight(){
    this->_pic.load(":/pic/tank.png");
    _pic=_pic.copy(QRect(256,320,64,64));
}

Player_Bullet Helper::shoot(QPainter *painter){
    this->set_mybullet();
    Player_Bullet new_bullet=this->get_bullet();
    //painter->setPen(QPen(Qt::black,4));
    new_bullet.show(painter);
    return new_bullet;
}
