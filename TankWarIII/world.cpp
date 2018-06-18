#include "world.h"
#include "ui_world.h"
#include "icon.h"
#include "string"
#include "rpgobj.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "one.h"
#include "widget.h"
using namespace std;

int num=3;
int flag=0;
int flag1=0;
int flag2=0;
int flag4=0;
int flag5=0;
int flag6=0;
World::World(QWidget *parent):
    QWidget(parent),
    ui(new Ui::World)
{
    ui->setupUi(this);
}

World::~World()
{
    delete ui;
}

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_tank.initObj("playerTank",":/pic/tank.png");
    this->_tank.setPosX(5);
    this->_tank.setPosY(5);


    RPGObj obj1;
    ifstream inf;
    inf.open(mapFile.c_str());
    string a,p;
    int b,c;
    while(inf >> a){
        inf >>p;
        inf >> b;
        inf >> c;
        obj1.initObj(a,p);
        obj1.setPosX(b);
        obj1.setPosY(c);
        this->_objs.push_back(obj1);
    }
}

void World::handleTankMove(int direction, int steps){
    this->_tank.move(direction, steps);
    this->act(direction, steps);
}
void World::handleBulletShow(QPainter *painter){
    this->_bullets.push_back(_tank.shoot(painter));
}
void World::handleEnemyBulletShow(QPainter *painter){
    vector<Enemy>::iterator it;
    for(it = this->_enemy.begin();it !=this->_enemy.end();it++){
       this->e_bullets.push_back((*it).shoot(painter));
    }
    if(flag6==1){
        this->_bullets.push_back(_helper[0].shoot(painter));
        this->_bullets.push_back(_helper[1].shoot(painter));
    }
}
void World::handleBulletMove(){
    vector<Player_Bullet>::iterator it;
    for(it=this->_bullets.begin();it!=this->_bullets.end();it++){
             int direction=(*it).get_direction();
             (*it).move(direction);
    }
    this->bullet_act1();
    this->bullet_act2();
    this->bullet_act3();
    this->bullet_act4();
}
void World::handleEnemyBulletMove(){
    vector<Enemy_bullet>::iterator it;
    for(it=this->e_bullets.begin();it!=this->e_bullets.end();it++){
             int direction=(*it).get_direction();
             (*it).move(direction);
    }
    this->e_bullet_act1();
    this->e_bullet_act2();
    this->e_bullet_act3();
    this->e_bullet_act4();
}
void World::act(int direction, int steps){
    vector<RPGObj>::iterator it;
    if(this->_tank.getPosX()<0||this->_tank.getPosX()>30||this->_tank.getPosY()<0||this->_tank.getPosY()>29){        this->_tank.move(direction, -1);    }
    for(it = this->_objs.begin(); it != this->_objs.end(); it++){
        flag=0;
        if(
            (abs(this->_tank.getPosX()-(*it).getPosX())<2)//(*it).getWidth())
           &&(abs(this->_tank.getPosY()-(*it).getPosY())<2)//(*it).getHeight())
           )

        {
            if((*it).canEat() == true)
            {

             if((*it).getObjType()=="magic"){
                                 this->addhelper();
                             }
                                if((*it).getObjType()=="blood"){
                                    this->addlife();
                                    num++;
                                }
              if((*it).getObjType()=="magicshot"){
                  _tank.change_mybullet();
                }
                                this->_objs.erase(it);
            }
            if((*it).canCover() == false)
            {
               this->_tank.move(direction, -1);
               break;
            }
            if((*it).canCover()==true)
            {
                flag=1;
            }
        }
        if(it == this->_objs.end()) {
            break;
        }
    }
}
void World::bullet_act1(){
    vector<Player_Bullet>::iterator it1;
    vector<RPGObj>::iterator it2;
    flag2=0;
    for(it1=this->_bullets.begin();it1!=this->_bullets.end();it1++){
        for(it2=this->_objs.begin();it2!=this->_objs.end();it2++){
            if((((*it1).get_x()) >(*it2).getPosX()*32) &&
                    ( ((*it1).get_x()) <((*it2).getPosX()*32)+((*it2).getWidth()*32) ) &&
                    ( ((*it1).get_y()) >=((*it2).getPosY()*32)                   ) &&
                    ( ((*it1).get_y()) <= ((*it2).getPosY()*32)+((*it2).getHeight()*32 ))
                    )
            {
                        if((*it2).canShoot()==true){
                            if((*it2).getObjType()=="boss") {
                                emit eatBoss();
                            }
                            (*it2).onErase();
                        it2 = this->_objs.erase(it2);
                        it1 =this->_bullets.erase(it1);
                        flag2=1;
                        break;
                }
        }
    }
        if(1==flag2) break;
}
}
void World::bullet_act2(){
    vector<Player_Bullet>::iterator it1;

    vector<RPGObj>::iterator it2;
    flag1=0;
        for(it1=this->_bullets.begin();it1!=this->_bullets.end();it1++){
            for(it2=this->_objs.begin();it2!=this->_objs.end();it2++){
                if((((*it1).get_x()) >=(*it2).getPosX()*32) &&
                        ( ((*it1).get_x()) <=((*it2).getPosX()*32)+((*it2).getWidth()*32) ) &&
                        ( ((*it1).get_y()) >=((*it2).getPosY()*32)                   ) &&
                        ( ((*it1).get_y()) <= ((*it2).getPosY()*32)+((*it2).getHeight()*32 ))
                        )
                {
                        if((*it2).canShoot()==false){
                            it1 = this->_bullets.erase(it1);
                            (*it2).onErase();
                            flag2=1;
                            break;
                        }
            }
        }
            if(flag2==1) break;
    }
}
void World::bullet_act3(){
    vector<Player_Bullet>::iterator it1;
    vector<Enemy>::iterator it2;
    flag2=0;
    for(it1=this->_bullets.begin();it1!=this->_bullets.end();it1++){
        for(it2=this->_enemy.begin();it2!=this->_enemy.end();it2++){
            if((((*it1).get_x()) >(*it2).getPosX()*32) &&
                    ( ((*it1).get_x()) <((*it2).getPosX()*32)+((*it2).getWidth()*32) ) &&
                    ( ((*it1).get_y()) >=((*it2).getPosY()*32)                   ) &&
                    ( ((*it1).get_y()) <= ((*it2).getPosY()*32)+((*it2).getHeight()*32 ))
                    )
            {
                        it2 = this->_enemy.erase(it2);
                        (*it2).onErase();
                        it1 =this->_bullets.erase(it1);
                        flag2=1;
                        break;
        }
    }
        if(1==flag2) break;
}
}
void World::bullet_act4(){
    vector<Player_Bullet >::iterator it1;
    for(it1=this->_bullets.begin();it1!=this->_bullets.end();it1++){
            if(((*it1).get_x()>1024)||((*it1).get_y()>992)||((*it1).get_x()<0)||((*it1).get_y()<0))
            {
                 this->_bullets.erase(it1);
                 break;
            }
}
}

void World::e_bullet_act1(){
    vector<Enemy_bullet>::iterator it1;
    vector<RPGObj>::iterator it2;
    flag4=0;
    for(it1=this->e_bullets.begin();it1!=this->e_bullets.end();it1++){
        for(it2=this->_objs.begin();it2!=this->_objs.end();it2++){
            if((((*it1).get_x()) >(*it2).getPosX()*32) &&
                    ( ((*it1).get_x()) <((*it2).getPosX()*32)+((*it2).getWidth()*32) ) &&
                    ( ((*it1).get_y()) >=((*it2).getPosY()*32)                   ) &&
                    ( ((*it1).get_y()) <= ((*it2).getPosY()*32)+((*it2).getHeight()*32 ))
                    )
            {
                        if((*it2).canShoot()==true&&(*it2).getObjType()!="boss"){
                        (*it2).onErase();
                        it2 = this->_objs.erase(it2);
                        it1 =this->e_bullets.erase(it1);
                        flag4=1;
                        break;
                }
        }
    }
        if(1==flag4) break;
}
}
void World::e_bullet_act4(){
    vector<Enemy_bullet >::iterator it1;
    for(it1=this->e_bullets.begin();it1!=this->e_bullets.end();it1++){
            if(((*it1).get_x()>1024)||((*it1).get_y()>992)||((*it1).get_x()<0)||((*it1).get_y()<0))
            {
                        this->e_bullets.erase(it1);
                        break;
        }
}
}
void World::e_bullet_act2(){
    vector<Enemy_bullet>::iterator it1;
    vector<RPGObj>::iterator it2;

    flag5=0;
        for(it1=this->e_bullets.begin();it1!=this->e_bullets.end();it1++){
            for(it2=this->_objs.begin();it2!=this->_objs.end();it2++){
                if((((*it1).get_x()) >=(*it2).getPosX()*32) &&
                        ( ((*it1).get_x()) <=((*it2).getPosX()*32)+((*it2).getWidth()*32) ) &&
                        ( ((*it1).get_y()) >=((*it2).getPosY()*32)                   ) &&
                        ( ((*it1).get_y()) <= ((*it2).getPosY()*32)+((*it2).getHeight()*32 ))
                        )
                {
                        if((*it2).canShoot()==false){
                            (*it2).onErase();
                            it1 = this->e_bullets.erase(it1);
                            flag5=1;
                            break;
                        }
            }
        }
            if(flag5==1) break;
    }
}
void World::e_bullet_act3(){
    vector<Enemy_bullet>::iterator it1;
        for(it1=this->e_bullets.begin();it1!=this->e_bullets.end();it1++){
                if((((*it1).get_x()) >=_tank.getPosX()*32) &&
                        ( ((*it1).get_x()) <=(_tank.getPosX()*32)+(_tank.getWidth()*32) ) &&
                        ( ((*it1).get_y()) >=(_tank.getPosY()*32)                   ) &&
                        ( ((*it1).get_y()) <= (_tank.getPosY()*32)+(_tank.getHeight()*32 ))
                        )
                {
                            _tank.onErase();
                            it1 = this->e_bullets.erase(it1);
                            _tank.setPosX(5);
                            _tank.setPosY(5);
                            _tank.showdown();
                            this->deletelife();
                            num--;
                            if(num==0)emit lose1();
                            break;
            }
        }
}
void World::show(QPainter * painter){
    this->_tank.show(painter);
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    vector<Enemy>::iterator it1;
    for(it1=this->_enemy.begin();it1!=this->_enemy.end();it1++){
        (*it1).show(painter);
    }
    vector<Helper>::iterator it2;
    for(it2=this->_helper.begin();it2!=this->_helper.end();it2++)
    {
        (*it2).show(painter);
    }
}
void World::handleEnemyMove(){
    vector<Enemy>::iterator it;
    for(it = this->_enemy.begin(); it != this->_enemy.end(); it++){
        int x=(*it).getPosX(),y=(*it).getPosY();
        int s1=(x-_tank.getPosX())*(x-_tank.getPosX())+(y-1-_tank.getPosY())*(y-1-_tank.getPosY()),
        s2=(x-_tank.getPosX())*(x-_tank.getPosX())+(y+1-_tank.getPosY())*(y+1-_tank.getPosY()),
        s3=(x-1-_tank.getPosX())*(x-1-_tank.getPosX())+(y-_tank.getPosY())*(y-_tank.getPosY()),
        s4=(x+1-_tank.getPosX())*(x+1-_tank.getPosX())+(y-_tank.getPosY())*(y-_tank.getPosY());

        int d=1,min=s1,d1=2,min1=s2;
        if(s2<min){
            d=2,d1=1;
            min=s2,min1=s1;
        }
        if(s3<min){
            d1=d,d=3;
            min1=min,min=s3;
        }
        if(s3>=min&&s3<min1&&d!=3){
            d1=3;
            min1=s3;
        }
        if(s4<min){
            d1=d,d=4;
            min1=min,min=s4;
        }
        if(s4>=min&&s4<min1&&d!=4){
            d1=4;
            min1=s4;
        }
        (*it).Move(d,1);
        this->Act(d,1);
        if(((d==1||d==2)&&y==(*it).getPosY())||((d==3||d==4)&&x==(*it).getPosX())){
            (*it).Move(d1,1);
            this->Act(d1,1);
        }
    }
}
void World::Act(int direction, int steps){
    vector<RPGObj>::iterator it;
    vector<Enemy>::iterator it1;
    for(it1=this->_enemy.begin();it1!=this->_enemy.end();it1++){
    for(it = this->_objs.begin(); it != this->_objs.end(); it++){
        flag=0;
        if(
            (abs((*it1).getPosX()-(*it).getPosX())<2)//(*it).getWidth())
           &&(abs((*it1).getPosY()-(*it).getPosY())<2)//(*it).getHeight())
           )

        {
            if((*it).canEat() == true)
            {

             this->_objs.erase(it);

            }
            if((*it).canCover() == false)
            {
               (*it1).Move(direction, -1);
                flag=1;
               break;
            }
        }
        if(it == this->_objs.end()) {
            break;
        }
    }}
}

void World::addenemy(){
    Enemy enemy;
    enemy.initObj("EnemyTank",":/pic/tank.png");
    enemy.setPosX(3);
    enemy.setPosY(20);
    this->_enemy.push_back(enemy);
}

void World::addhelper(){
    Helper helper;
    helper.initObj("HelpTank",":/pic/tank.png");
    this->_helper.push_back(helper);
    this->_helper.push_back(helper);
    _helper[0].setPosX(7),_helper[0].setPosY(1);
    _helper[0].ShowDown();
    _helper[1].setPosX(23),_helper[1].setPosY(1);
    _helper[1].ShowDown();
    flag6=1;
}

void World::addlife(){
    RPGObj obj1;
    obj1.initObj("life",":/pic/life.png");
    obj1.setPosX(num);
    obj1.setPosY(0);
    this->_objs.push_back(obj1);
}

void World::deletelife(){
    RPGObj obj1;
    obj1.initObj("dead",":/pic/dead.png");
    obj1.setPosX(num-1);
    obj1.setPosY(0);
    this->_objs.push_back(obj1);
}

