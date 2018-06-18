#ifndef TWO_H
#define TWO_H



#include <QWidget>
#include <QImage>
#include <QPainter>
#include<QKeyEvent>
#include "rpgobj.h"
#include "world.h"
#include<QTime>
#include<QTimer>
#include "dialogtwo.h"
#include "dlglose2.h"
namespace Ui {
class Two;
}

class Two : public QWidget
{
    Q_OBJECT

public:
    explicit Two(QWidget *parent = 0);
    ~Two();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
    const World &GetWorld();
signals:
    void display(int number);

    void AfterEat();
public slots:

    void LevelTwoOver();
private slots:

    void showDialogTwo();
    void win2();
     void showlose2();
protected slots:
    void handle_Bullet();
    void randomMove();
    void handleenemy();
private:
    Ui::Two *ui;
    World _game;
    QImage _pic;
    DialogTwo *dlg;
    Dlglose2 *dlg2;
    QTimer *timer3,*timer4,*timer5;
};

#endif // TWO_H
