#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class Level;
class Start;
class One;
class Two;
class Three;
class QStackedLayout;
class QVBoxLayout;
class World;
//class DialogOne;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Level *level;
    One *one;
    Two *two;
    Three *three;
    World *world;
    Start *start;
    QStackedLayout *stackLayout;
    QVBoxLayout *mainLayout;
    //DialogOne *dlg1;
};

#endif // WIDGET_H
