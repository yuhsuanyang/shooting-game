#include "bulletp.h"
#include "character.h"


bulletP::bulletP(character *w ,character *u):bullet(w,u)
{
    setPixmap(QPixmap(":/res/pill.png").scaled(60, 60));

}

bool bulletP::gethelp()
{
   if(x()<t->x()+85 && x()>t->x() && y()<t->y()+65 && y()>t->y()-10){
        qDebug()<<x()<<y()<<t->x()<<t->y()<<t->rotation();
        delete this;
        return true;
   }else {
       return false;
   }
}
void bulletP::docollide()
{
    if (collision()==true){
        v->HP=v->HP+1;
    }else if(gethelp()==true){
        t->HP=t->HP+1;
    }else{
    }

};
