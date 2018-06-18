#ifndef ENEMY_H
#define ENEMY_H
#include "rpgobj.h"
#include <QPainter>
#include <QImage>
#include <enemy_bullet.h>
#include <tank.h>

class Enemy:public Tank
{
public:
    Enemy(){}
    ~Enemy(){}
    void Move(int direction, int steps=1);
    void Showup();
    void Showdown();
    void Showleft();
    void Showright();
    int Getdir(){return tankdir;}
    Enemy_bullet get_bullet(){
        return e_myBullet;
    }
    void set_mybullet();
    Enemy_bullet shoot(QPainter *painter);
private:
    int tankdir;
    Enemy_bullet e_myBullet;
};

#endif // ENEMY_H

