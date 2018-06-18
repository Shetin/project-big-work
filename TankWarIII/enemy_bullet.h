#ifndef ENEMY_BULLET
#define ENEMY_BULLET
#include <player_bullet.h>

class Enemy_bullet:public Player_Bullet{
    friend class Enemy;
public:
    Enemy_bullet(){_radius=0,_speed=0;_x=0;_y=0;_direction=0;}
    void show(QPainter *pa);
    int get_direction(){
        return _direction;
    }
    int get_x(){return this->_x;}
    int get_y(){return this->_y;}
    void move(int direction);
private:
    double _radius;
    int _speed;
    double _x;
    double _y;
    int _direction;
};

#endif // ENEMY_BULLET*/

