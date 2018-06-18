#ifndef TANK_H
#define TANK_H
#include "rpgobj.h"
#include "player_bullet.h"
#include <QImage>
class Tank:public RPGObj
{
public:
public:
    Tank();
    ~Tank();
    void move(int direction, int steps=1);
    void showup();
    void showdown();
    void showleft();
    void showright();
    int Getdir(){return tankdir;}
    Player_Bullet shoot(QPainter *painter);
    void set_mybullet();
    void change_mybullet();
    Player_Bullet get_bullet();
private:
    Player_Bullet my_bullet;
    int tankdir;

};

#endif // TANK_H
