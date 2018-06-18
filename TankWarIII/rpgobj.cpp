#include "rpgobj.h"
#include "QPainter.h"
#include <iostream>

void RPGObj::initObj(string type,string path)
{
    //TODO 所支持的对象类型应定义为枚举
    if (type.compare("wall")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_shootable = false;
    }

    else if (type.compare("brick")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_shootable = true;
    }
    else if (type.compare("tree")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_shootable = false;
    }
    else if (type.compare("clock")==0){
        this->_coverable = false;
        this->_eatable = true;
        this->_shootable = false;
    }
    else if(type.compare("blood")==0){
        this->_coverable = false;
        this->_eatable = true;
        this->_shootable = false;
    }
    else if(type.compare("stone")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_shootable = false;
    }
    else if(type.compare("magic")==0){
        this->_coverable = false;
        this->_eatable = true;
        this->_shootable = false;
    }
    else if(type.compare("EnemyTank")==0){
        this->_coverable = false;
        this->_eatable = true;
        this->_shootable = true;
        this->_dieable=true;
    }
    else if(type.compare("boss")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_shootable = true;

    }

    else if(type.compare("playerTank")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_shootable = true;
    }
    else if(type.compare("2stone")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_shootable = false;
    }
    else if(type.compare("2brick")==0){
        this->_coverable = false;
        this->_eatable = true;
        this->_shootable = true;
    }
    else if(type.compare("2fence")==0){
        this->_coverable = true;
        this->_eatable = false;
        this->_shootable = false;
    }
    else if(type.compare("2wall")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_shootable = true;
    }
    else if(type.compare("3brick")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_shootable =true;
    }
    else if(type.compare("3stone")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_shootable = false;
    }
    else if(type.compare("3stee")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_shootable = true;
    }
    else if(type.compare("dead")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if(type.compare("magicshot")==0){
        this->_coverable = true;
        this->_eatable = true;
    }

    else if(type.compare("life")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if(type.compare("HelpTank")==0){
        this->_coverable = false;
        this->_eatable = false;
        this->_shootable = true;
    }
    else{
        //TODO 应由专门的错误日志文件记录
        cout<<"invalid ICON type."<<endl;
        return;
    }
    QImage all;
    this->_icon = ICON::findICON(type);
    all.load(path.c_str());
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
}

void RPGObj::show(QPainter * pa){
    int gSize = ICON::GRID_SIZE;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}


void RPGObj::onErase(){
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:\\Users\\asus\Desktop\\TankWarIII\\cannot.mp3"));
    player->setVolume(150);
    player->play();
}




