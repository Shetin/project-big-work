#ifndef ONE_H
#define ONE_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include<QKeyEvent>
#include "rpgobj.h"
#include "world.h"
#include<QTime>
#include<QTimer>
#include "dialogone.h"
#include "dlglose1.h"
namespace Ui {
class One;
}

class One : public QWidget
{
    Q_OBJECT

public:
    explicit One(QWidget *parent = 0);
    ~One();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
    const World &GetWorld();
    //const DialogOne &GetDialogOne();
    //DialogOne *dlg;
signals:
   // void eatBoss();
    void display(int number);
    void AfterEat();
    //void showDialogOne();
public slots:

    void LevelOneOver();
private slots:
    void showDialogOne();
    void win1();
    void showlose1();
protected slots:
    void handle_Bullet();
    void randomMove();
    void handleenemy();
private:
    Ui::One *ui;
    World _game;
    DialogOne *dlg;
    Dlglose1 *dlg1;
    QTimer *timer,*timer1,*timer2;
};

#endif // ONE_H
