#include "player_bullet.h"
#include <QPainter>
#include "QPen"
#include <iostream>
using namespace std;
int bullet_flag=0;

Player_Bullet::Player_Bullet(double radius,double x, double y,int direction,int speed): _radius(radius),_x(x),_y(y),_direction(direction),_speed(speed){

}

Player_Bullet::Player_Bullet(const Player_Bullet &player_bul):_radius(player_bul._radius), _x(player_bul._x),_y(player_bul._y),_direction(player_bul._direction),_speed(player_bul._speed){}

void Player_Bullet::show(QPainter *pa){
     pa->setPen(QPen(Qt::black,4));
     pa->setBrush(Qt::yellow);
     pa->drawEllipse(_x,_y,_radius,_radius);

}
void Player_Bullet::set_speed(int speed){
    _speed=speed;
}
void Player_Bullet::set_direction(int dire){
    _direction=dire;
}
void Player_Bullet::set_radius(double radius){
    _radius=radius;
}
void Player_Bullet::erase(){
    //flag=1;
}

void Player_Bullet::move(int direction){
    switch (direction) {
    case 1:
        this->_y-=(get_speed());
        break;
    case 2:
        this->_y+=(get_speed());
        break;
    case 3:
        this->_x-=(get_speed());
        break;
    case 4:
        this->_x+=(get_speed());
    default:
        break;//使子弹改变位置的函数，其实体现了子弹的速度，或许想要增加子弹的威力的时候可以加快它的速度，那么就在这里面改
    }
}
