#include "world.h"
#include "icon.h"
#include "string"
#include "rpgobj.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int flag=0;

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_tank.initObj("playerTank","C:\\Users\\asus\\Desktop\\TankWarI\\tank.png");
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


void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    if(flag==0) this->_tank.show(painter);
}

void World::handleTankMove(int direction, int steps){
    this->_tank.move(direction, steps);
    this->act(direction, steps);
}


void World::act(int direction, int steps){
    vector<RPGObj>::iterator it;
    for(it = this->_objs.begin(); it != this->_objs.end(); it++){
        flag=0;
        if(
                this->_tank.getPosX()==(*it).getPosX() &&

                this->_tank.getPosY()== ((*it).getPosY()-1)
           )

        {
            if((*it).canEat() == true)
            {

             this->_objs.erase(it);

            }
            if((*it).canCover() == false)
            {
               this->_tank.move(-1*direction, steps);
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

