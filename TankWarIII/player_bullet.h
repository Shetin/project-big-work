#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H
#include "rpgobj.h"
#include "QMainWindow"
#include <QImage>
#include <QPainter>

class Player_Bullet/*public QMainWindow*/
{
public:
    //explicit Player_Bullet(QWidget *parent=0);
    //~Player_Bullet();
    friend class Tank;
    Player_Bullet(){_radius=0,_speed=0;_x=0;_y=0;_direction=0;}
    //explicit Player_Bullet(QWidget *parent=0,const char *name=0);
    Player_Bullet(double radius,double x,double y, int direction,int speed);
    Player_Bullet(const Player_Bullet &player_bul);
    void set_speed(int speed);
    void set_direction(int dire);
    void set_radius(double radius);
    int get_speed(){return _speed;}
    int get_direction(){return _direction;}
    int get_x(){return this->_x;}
    int get_y(){return this->_y;}
    int get_radius(){return this->_radius;}
    void erase();
    void show(QPainter *pa);
    void move(int direction);
    void setposx(int x){
        this->_x=x;
    }
    void setposy(int y){
        this->_y=y;
    }
private:
    double _radius;
    double _x;
    double _y;
    int _speed;
    int _direction;
    QImage _pic;
    //QTimer *shoot_timer;
};

#endif // PLAYER_BULLET_H

