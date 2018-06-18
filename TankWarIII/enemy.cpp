#include "enemy.h"
#include "world.h"
#include <QPainter>
#include <QApplication>
#include <iostream>
using namespace std;

void Enemy::Move(int direction, int steps){
    switch (direction){
        case 1:
            this->_pos_y -= steps;
            this->_pos_y -= steps;
            this->Showup();
            tankdir=1;
            break;
        case 2:
            this->_pos_y += steps;
            this->_pos_y += steps;
            this->Showdown();
            tankdir=2;
            break;
        case 3:
            this->_pos_x -= steps;
            this->_pos_x -= steps;
            this->Showleft();
            tankdir=3;
            break;
        case 4:
            this->_pos_x += steps;
            this->_pos_x += steps;
            this->Showright();
            tankdir=4;
            break;
    }
}

void Enemy::Showup(){
    this->_pic.load(":/pic/tank.png");
    _pic=_pic.copy(QRect(128,256,64,64));
}

void Enemy::Showdown(){
    this->_pic.load(":/pic/tank.png");
    _pic=_pic.copy(QRect(128,384,64,64));
}

void Enemy::Showleft(){
    this->_pic.load(":/pic/tank.png");
    _pic=_pic.copy(QRect(128,448,64,64));
}

void Enemy::Showright(){
    this->_pic.load(":/pic/tank.png");
    _pic=_pic.copy(QRect(128,320,64,64));
}

Enemy_bullet Enemy::shoot(QPainter *painter){
    this->set_mybullet();
    Enemy_bullet new_bullet=this->get_bullet();
    //painter->setPen(QPen(Qt::black,4));
    new_bullet.show(painter);
    return new_bullet;
}

void Enemy::set_mybullet(){
    e_myBullet._speed=1*32;
    e_myBullet._radius=8;
    e_myBullet._x=((this->getPosX()+1)*32);
    e_myBullet._y=((this->getPosY()+1)*32);//这个地方定义每辆坦克的子弹射出的初始位置
    e_myBullet._direction=this->tankdir;
}
