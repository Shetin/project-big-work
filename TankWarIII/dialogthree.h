#ifndef DIALOGTHREE_H
#define DIALOGTHREE_H

#include <QDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QWidget>
#include <QVBoxLayout>
namespace Ui {
class DialogThree;
}

class DialogThree : public QDialog
{
    Q_OBJECT

public:
    explicit DialogThree(QWidget *parent = 0);
    ~DialogThree();


signals:
     void display(int number);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::DialogThree *ui;
    QMediaPlayer*myPlayer;
    QHBoxLayout *mainLayout;
    QVideoWidget *videow;
   QVideoWidget*videoWidget;
};

#endif // DIALOGTHREE_H
