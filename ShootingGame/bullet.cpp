#include "bullet.h"


bullet::bullet(character *w, character *u):v(w), t(u)
{
    setPixmap(QPixmap(":/res/star.png").scaled(30, 30));
}

bool bullet::collision()
{
    if(v->rotation()==180){
        if(x()<v->x()-30 && x()>v->x()-100 &&
                y()<v->y()-20 && y()>v->y()-75){
            qDebug()<<x()<<y()<<v->x()<<v->y()<<v->rotation();
            delete this;
            return true;
        }else{
            return false;
        }
    }else{
        if(x()<v->x()+85 && x()>v->x() &&
                y()<v->y()+65 && y()>v->y()-10){
            qDebug()<<x()<<y()<<v->x()<<v->y()<<v->rotation();
            delete this;
            return true;
        }else{
            return false;
        }
    }

}



void bullet::flyup()
{
    setPos(x(), y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::flydown()
{
    setPos(x(), y() + 3);
    if(y() >800) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::docollide()
{
    if (collision()==true && v->HP>0){
        v->HP--;
        t->scorenum=t->scorenum+100;
    }

}



