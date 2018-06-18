#include "widget.h"
#include "ui_widget.h"
#include "one.h"

#include "two.h"
#include "three.h"
#include "level.h"
#include "world.h"
#include "iostream"
#include "start.h"
#include <QStackedLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include "dialogone.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    //setFixedSize(400,300);
    level =new Level;
    setFixedSize(1024,992);
    start = new Start;
    one = new One;
    two = new Two;
    three = new Three;
    world= new World;
    //dlg1=new DialogOne;

    stackLayout = new QStackedLayout;
    stackLayout->addWidget(start);
    stackLayout->addWidget(level);
    stackLayout->addWidget(one);
    stackLayout->addWidget(two);
    stackLayout->addWidget(three);
    //cout<<dlg1<<endl;
    //cout<<&one->GetDialogOne()<<endl;
    connect(&one->GetWorld(), &World::eatBoss, one, &One::LevelOneOver);
    connect(&two->GetWorld(), &World::eatBoss, two, &Two::LevelTwoOver);
    connect(world,&World::eatBoss,one,&One::LevelOneOver);
    connect(world,&World::eatBoss,two,&Two::LevelTwoOver);
    connect(&three->GetWorld(), &World::eatBoss, three, &Three::LevelThreeOver);
    connect(start, &Start::display, stackLayout, &QStackedLayout::setCurrentIndex);//0
    connect(level, &Level::display, stackLayout, &QStackedLayout::setCurrentIndex);   //1
    connect(one, &One::display, stackLayout, &QStackedLayout::setCurrentIndex);             // 2
    connect(two, &Two::display, stackLayout, &QStackedLayout::setCurrentIndex);             // 3
    connect(three, &Three::display, stackLayout, &QStackedLayout::setCurrentIndex);       // 4


    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(stackLayout);
    setLayout(mainLayout);



}

Widget::~Widget()
{
}


