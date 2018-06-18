#include <enemy_bullet.h>
#include <QPainter>
#include "QPen"
#include <iostream>
using namespace std;

void Enemy_bullet::show(QPainter *pa){
    pa->setPen(QPen(Qt::black,4));
    pa->setBrush(Qt::red);
    pa->drawEllipse(_x,_y,_radius,_radius);
}

void Enemy_bullet::move(int direction){
    switch (direction) {
    case 1:
        this->_y-=(_speed);
        break;
    case 2:
        this->_y+=(_speed);
        break;
    case 3:
        this->_x-=(_speed);
        break;
    case 4:
        this->_x+=(_speed);
    default:
        break;//使子弹改变位置的函数，其实体现了子弹的速度，或许想要增加子弹的威力的时候可以加快它的速度，那么就在这里面改
    }
}
