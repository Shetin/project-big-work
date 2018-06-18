#ifndef THREE_H
#define THREE_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include<QKeyEvent>
#include "rpgobj.h"
#include "world.h"
#include<QTime>
#include<QTimer>
#include "dialogthree.h"
#include "dlglose3.h"
namespace Ui {
class Three;
}

class Three : public QWidget
{
    Q_OBJECT

public:
    explicit Three(QWidget *parent = 0);
    ~Three();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
    const World &GetWorld();

signals:

    void display(int number);
    void AfterEat();

public slots:

    void LevelThreeOver();
private slots:
    void showDialogThree();
     void showlose3();

protected slots:
    void handle_Bullet();
    void randomMove();
    void handleenemy();
private:
    Ui::Three *ui;
    World _game;
    QImage _pic;
    DialogThree *dlg;
    Dlglose3 *dlg3;
    QTimer *timer,*timer1,*timer2;
};

#endif // THREE_H
