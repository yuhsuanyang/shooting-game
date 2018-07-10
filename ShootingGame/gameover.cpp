#include "gameover.h"
#include "ui_gameover.h"

gameover::gameover(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameover)
{

    ui->setupUi(this);
    r=new QLabel(this);
    s=new QLabel(this);
    n=new QLabel(this);
    r->setGeometry(0,0,500,300);
    s->setGeometry(-70,300,600,200);
    s->setPixmap(QPixmap(":/res/score.png").scaled(600,400));
    n->setGeometry(300,350,100,40);
    n->setStyleSheet("color:blue; font:40px; font-weight:bold");
}

gameover::~gameover()
{
    delete ui;
}
