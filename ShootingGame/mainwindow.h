#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QLabel>
#include <qglobal.h>
#include <QKeyEvent>
#include "bulletf.h"
#include "bulletp.h"
#include "bullet.h"
#include "enemy.h"
#include "info.h"
#include "gameover.h"
#include "character.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

int posy=rand()%500;
    character *player;
public slots:
    virtual void keyPressEvent(QKeyEvent *e);


private slots:
    void EnemyAttack();
    void kill();
    void end();
    void boost();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Enemy *owl;
    QGraphicsPixmapItem *background;
    QTimer *bullettimer;
    QTimer *enemytimer;
    QTimer *boostertimer;
    int acenum;
    QLabel *ace;
    QLabel *playerHP;
    QLabel *owlHP;
    QLabel *score;
    QLabel *acelogo;
    QLabel *playerHPlogo;
    QLabel *owlHPlogo;
    QLabel *scorelogo;
    int switchoff;
    //bool collision(QGraphicsPixmapItem *w, QGraphicsPixmapItem *v);
};


#endif // MAINWINDOW_H














