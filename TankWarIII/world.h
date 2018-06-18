#ifndef WORLD_H
#define WORLD_H

#include <QWidget>
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include "tank.h"
#include "widget.h"
#include "enemy.h"
#include "helper.h"
#include "enemy_bullet.h"
#include <QObject>
namespace Ui {
class World;
}

class World : public QWidget
{
    Q_OBJECT
    friend class One;
    friend class Two;
    friend class Three;
public:
    explicit World(QWidget *parent = 0);
    ~World();
    void act(int direction, int steps);
    void bullet_act1();
    void bullet_act2();
    void bullet_act3();
    void bullet_act4();
    void e_bullet_act1();
    void e_bullet_act2();
    void e_bullet_act3();
    void e_bullet_act4();
    void initWorld(string mapFile);
    void Act(int direction,int steps);
    void Act1(int direction,int steps);
    void show(QPainter * painter);
        //显示游戏世界所有对象
    void addenemy();
    void handleTankMove(int direction, int steps);
    void handleBulletMove();
    void handleBulletShow(QPainter *painter);
    void handleEnemyMove();
    void handleEnemyBulletShow(QPainter *painter);
    void handleEnemyBulletMove();
    void addhelper();
    void addlife();
    void deletelife();
signals:
    void eatBoss();
    void lose1();
private:
    vector<RPGObj> _objs;
    Tank _tank;
    Ui::World *ui;
    vector<Enemy> _enemy;
    vector<Player_Bullet> _bullets;
    vector<Enemy_bullet> e_bullets;
    vector<Helper> _helper;
};

#endif // WORLD_H
