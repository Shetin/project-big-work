#include "icon.h"
#include <vector>
#include<iostream>
#include <map>
int ICON::GRID_SIZE = 32;


pair<string,ICON> pairArray[] =
{
    make_pair("playerTank",ICON("PlayerTank",0,8, 2, 2,"C:\\Users\\asus\\Desktop\\TankWarI\\tank.png")),
    make_pair("wall",ICON("wall",3,2, 3, 1,"C:\\Users\\asus\\Desktop\\TankWarI\\TileB.png")),//can't be shoot
    make_pair("brick",ICON("brick",5,9,2,2,"C:\\Users\\asus\\Desktop\\TankWarI\\brick2.png")),//can be shoot
    make_pair("stone",ICON("stone",1,3,3,1,"C:\\Users\\asus\\Desktop\\TankWarI\\brick2.png")),//can't be shoot
    make_pair("clock",ICON("clock",0,0,2,2,"C:\\Users\\asus\\Desktop\\TankWarI\\clock.png")),//Props:slow enemy's speed
    make_pair("blood",ICON("blood",0,0,2,2,"C:\\Users\\asus\\Desktop\\TankWarI\\blood.png")),//Props:supply blood
    make_pair("magic",ICON("magic",0,0,2,2,"C:\\Users\\asus\\Desktop\\TankWarI\\magic.png")),//enemy can't move for several seconds
    make_pair("EnemyTank",ICON("EnemyTank",4,8,2,2,"C:\\Users\\asus\\Desktop\\TankWarI\\tank.png")),
    make_pair("boss",ICON("boss",0,0,3,3,"C:\\Users\\asus\\Desktop\\TankWarI\\boss.png")),
    make_pair("brick2",ICON("brick2",1,11,1,1,"C:\\Users\\asus\\Desktop\\TankWarI\\brick2.png")),//protect the boss
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int x, int y, int w, int h,string path){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;

}

ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end()){

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();
    }
    else{
        return kv->second;
    }
}

