#ifndef START_H
#define START_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QPainter>
#include <QImage>
class One;
namespace Ui {
class Start;
}

class Start : public QWidget
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = 0);
    ~Start();
signals:
    void display(int number);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Start *ui;
    One *one;
    QMediaPlayer*myPlayer;
    QHBoxLayout *mainLayout;
    QVideoWidget *videow;
   QVideoWidget*videoWidget;
};

#endif // START_H
