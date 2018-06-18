#ifndef HELPER_H
#define HELPER_H
#include "rpgobj.h"
#include <QPainter>
#include <QImage>
#include "tank.h"

class Helper: public Tank
{
public:
    Helper(){}
    ~Helper(){}
    void ShowUp();
    void ShowDown();
    void ShowLeft();
    void ShowRight();
    Player_Bullet shoot(QPainter *painter);
    void set_mybullet();
    Player_Bullet get_bullet();
private:
    Player_Bullet my_bullet;
};
#endif // HELPER_H
