#include "icon.h"
#include <vector>
#include<iostream>
#include <map>
int ICON::GRID_SIZE = 32;


pair<string,ICON> pairArray[] =
{
    make_pair("playerTank",ICON("PlayerTank",0,8, 2, 2,":/pic/tank.png")),
    make_pair("house",ICON("house",8,0, 5, 5,":/pic/wall2.png")),//can't be shoot
    make_pair("brick",ICON("brick",5,9,2,2,":/pic/brick2.png")),//can be shoot
    make_pair("stone",ICON("stone",2,0,2,2,":/pic/brick2.png")),//can't be shoot
    make_pair("clock",ICON("clock",0,0,2,2,":/pic/clock.png")),//Props:slow enemy's speed
    make_pair("blood",ICON("blood",0,0,2,2,":/pic/blood.png")),//Props:supply blood
    make_pair("magic",ICON("magic",0,0,2,2,":/pic/magic.png")),//enemy can't move for several seconds
    make_pair("EnemyTank",ICON("EnemyTank",4,8,2,2,":/pic/tank.png")),
    make_pair("tree",ICON("tree",0,0,2,2,":/pic/tree.png")),
    make_pair("boss",ICON("boss",0,0,2,2,":/pic/boss.png")),
    make_pair("2brick",ICON("2brick",0,2,2,2,":/pic/wall.png")),//map2
    make_pair("2wall",ICON("2wall",0,0,2,2,":/pic/wall.png")),//map2
    make_pair("2fence",ICON("2fence",0,6,2,2,":/pic/wall3.png")),//can cover the tank
    make_pair("2stone",ICON("2stone",3,0,2,2,":/pic/wall.png")),//map2
    make_pair("3brick",ICON("3brick",0,0,2,2,":/pic/wall3.png")),//map3
    make_pair("3stone",ICON("3stone",0,0,2,2,":/pic/3stone.png")),//map3
    make_pair("3stee",ICON("3stee",0,0,2,2,":/pic/tree.png")),//map3
    make_pair("life",ICON("life",0,0,1,1,":/pic/life.png")),
    make_pair("dead",ICON("dead",0,0,1,1,":/pic/dead.png")),
    make_pair("magicshot",ICON("magicshot",0,0,2,2,":/pic/magicshot.png")),
    make_pair("HelpTank",ICON("HelpTank",8,12,2,2,":/pic/tank.png")),
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

