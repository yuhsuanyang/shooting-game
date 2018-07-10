#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 500, 800)),
    bullettimer(new QTimer),enemytimer(new QTimer),boostertimer(new QTimer),owl(new Enemy),player(new character)
{
    ui->setupUi(this);
    switchoff=0;
    ui->graphicsView->setScene(scene);
    setWindowTitle(tr("NIGHT WAR"));
    background = new QGraphicsPixmapItem(QPixmap(":/res/night.png"));
    background->setScale(1.2);
    scene->addItem(background);
    player ->setPixmap(QPixmap(":/res/rocket.png"));
    owl->setPixmap(QPixmap(":/res/owl.png"));
    owl->setPos(0,10);
    owl->setScale(0.2);
    player->setScale(0.2);
    player->setPos(-200, 700);
    scene->addItem(player);
    scene->addItem(static_cast<QGraphicsPixmapItem*>(owl));
    background->setPos(-400,-20);
    bullettimer->start(10);
    enemytimer->start(1000);
    boostertimer->start(3000);
    acenum=5;
    /////////////////////////////////////
    acelogo=new QLabel(this);
    acelogo->setGeometry(20,865,30,30);
    acelogo->setPixmap(QPixmap(":/res/flower.png").scaled(30, 30));
    ace = new QLabel(this);
    QFont font;
    font.setPixelSize(30);
    ace->setFont(font);
    ace->setNum(acenum);
    ace->setGeometry(60,860,100,40);
    acelogo=new QLabel(this);
    acelogo->setGeometry(20,865,30,30);
    /////////////////////////////////////
    playerHPlogo = new QLabel(this);
    playerHPlogo->setPixmap(QPixmap(":/res/blood.png").scaled(30, 30));
    playerHPlogo->setGeometry(100,860,100,40);
    playerHP = new QLabel(this);
    playerHP->setFont(font);
    playerHP->setNum(player->HP);
    playerHP->setGeometry(140,860,100,40);
    /////////////////////////////////////
    scorelogo = new QLabel(this);
    scorelogo->setPixmap(QPixmap(":/res/score.png").scaled(300,200));
    scorelogo->setGeometry(160,865,300,70);
    score = new QLabel(this);
    score->setFont(font);
    score->setNum(player->scorenum);
    score->setGeometry(340,860,100,40);
    ////////////////////////////////////
    owlHPlogo = new QLabel(this);
    owlHPlogo->setPixmap(QPixmap(":/res/blood.png").scaled(30, 30));
    owlHPlogo->setGeometry(1000,60,100,40);
    owlHP = new QLabel(this);
    owlHP->setStyleSheet("color:white; font:30px");
    owlHP->setNum(owl->HP);
    owlHP->setGeometry(1040,60,100,40);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(switchoff==1){
        bullet *b;
        switch(e->key()) {
        case Qt::Key_Up:
            player->setPos(player->x(), player->y() - 10);
            break;
        case Qt::Key_Down:
            player->setPos(player->x(), player->y() + 10);
            break;
        case Qt::Key_Left:
            player->setPos(player->x() - 10, player->y());
            break;
        case Qt::Key_Right:
            player->setPos(player->x() + 10, player->y());
            break;
        case Qt::Key_S:
        {
            player->setTransformOriginPoint(player->x()*0.001 , player->y()*0.001);
            player->setRotation(0);
            break;
        }
        case Qt::Key_D:
        {
            player->setTransformOriginPoint(player->x()*0.001 , player->y()*0.001);
            player->setRotation(180);
            break;
        }
        case Qt::Key_Shift:
        {
           b = new bullet(owl,player);
           if(player->rotation()==0){
               b->setPos(player->x()+ player->pixmap().width() / 14, player->y());
               b->connect(bullettimer, SIGNAL(timeout()), b, SLOT(flyup()));
           }else{
               b->setPos(player->x()- player->pixmap().width() / 7.5, player->y()- player->pixmap().width() / 20);
               b->connect(bullettimer, SIGNAL(timeout()), b, SLOT(flydown()));
           }

           scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
           b->connect(bullettimer, SIGNAL(timeout()), b, SLOT(docollide()));
           connect(bullettimer, SIGNAL(timeout()), this, SLOT(kill()));
           break;
        }
        case Qt::Key_A: {
            if(acenum>0){
                b = new bulletF(owl,player);

                if(player->rotation()==0){
                    b->setPos(player->x()+ player->pixmap().width() / 20, player->y()-30);
                    b->connect(bullettimer, SIGNAL(timeout()), b, SLOT(flyup()));
                }else{
                    b->setPos(player->x()- player->pixmap().width() / 6.7, player->y());
                    b->connect(bullettimer, SIGNAL(timeout()), b, SLOT(flydown()));
                }
                scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
                b->connect(bullettimer, SIGNAL(timeout()), b, SLOT(docollide()));
                acenum--;
                ace->setNum(acenum);
            }else{

            }

            break;
        }
        }
    }

}

void MainWindow::EnemyAttack()
{
    bullet *c;
    if(qrand() % 2 == 0) {
            c=new bulletF(player,owl);
        }
        else {
            c=new bullet(player,owl);
        }

    c->setPos(owl->x()+owl->pixmap().width() / 15,owl->y()+owl->pixmap().height() / 15);
    if(owl->y()<400){
       c->connect(bullettimer, SIGNAL(timeout()), c, SLOT(flydown()));
    }else{
        c->connect(bullettimer, SIGNAL(timeout()), c, SLOT(flyup()));
    }

    scene->addItem(static_cast<QGraphicsPixmapItem*>(c));
    c->connect(bullettimer, SIGNAL(timeout()), c, SLOT(docollide()));

}

void MainWindow::kill()
{
    owlHP->setNum(owl->HP);
    playerHP->setNum(player->HP);
    score->setNum(player->scorenum);
}

void MainWindow::end()
{
    if(player->HP<=0 || owl->HP<=0){
        player->scorenum=50*acenum+player->scorenum+100*player->HP;
        switchoff=0;
        disconnect(enemytimer,SIGNAL(timeout()),this,SLOT(end()));
        disconnect(enemytimer,SIGNAL(timeout()),this,SLOT(EnemyAttack()));
        disconnect(enemytimer,SIGNAL(timeout()),owl,SLOT(EnemyMove()));
        disconnect(boostertimer,SIGNAL(timeout()),this,SLOT(boost()));
        gameover *f = new gameover;
        f->setWindowTitle(tr("Game Over"));
        f->n->setNum(player->scorenum);
        if(player->HP<=0 ){
            f->r->setPixmap(QPixmap(":/res/loser.png").scaled(500, 300));

        }else{
            f->r->setPixmap(QPixmap(":/res/winner.png").scaled(500, 300));
        }
        f->show();
    }else{
    }
}

void MainWindow::boost()
{
    bulletP *p;
    p=new bulletP(player,owl);
    p->setPos(qrand()%1000,0);
    scene->addItem(static_cast<QGraphicsPixmapItem*>(p));
    p->connect(bullettimer, SIGNAL(timeout()), p, SLOT(flydown()));
    p->connect(bullettimer, SIGNAL(timeout()), p, SLOT(docollide()));

}

void MainWindow::on_pushButton_clicked()
{
    switchoff=1;
    owl->connect(enemytimer,SIGNAL(timeout()),owl,SLOT(EnemyMove()));
    connect(enemytimer,SIGNAL(timeout()),this,SLOT(EnemyAttack()));
    connect(bullettimer, SIGNAL(timeout()), this, SLOT(kill()));
    connect(enemytimer,SIGNAL(timeout()),this,SLOT(end()));
    connect(boostertimer,SIGNAL(timeout()),this,SLOT(boost()));
    bullettimer->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    switchoff=0;
    disconnect(enemytimer,SIGNAL(timeout()),owl,SLOT(EnemyMove()));
    disconnect(enemytimer,SIGNAL(timeout()),this,SLOT(EnemyAttack()));
    disconnect(boostertimer,SIGNAL(timeout()),this,SLOT(boost()));
    owl->setPos(owl->x(),owl->y());
    bullettimer->stop();
}

void MainWindow::on_pushButton_3_clicked()
{
    info *g=new info;
    g->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    switchoff=1;
    owl->connect(enemytimer,SIGNAL(timeout()),owl,SLOT(EnemyMove()));
    connect(enemytimer,SIGNAL(timeout()),this,SLOT(EnemyAttack()));
    connect(bullettimer, SIGNAL(timeout()), this, SLOT(kill()));
    connect(enemytimer,SIGNAL(timeout()),this,SLOT(end()));
    connect(boostertimer,SIGNAL(timeout()),this,SLOT(boost()));
    owl->HP=10;
    player->HP=10;
    owl->scorenum=0;
    player->scorenum=0;
    acenum=5;
    ace->setNum(acenum);
    player->setRotation(0);
}
