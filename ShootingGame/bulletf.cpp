#include "bulletf.h"
#include "character.h"

bulletF::bulletF(character *w, character *u):bullet(w,u)
{
    setPixmap(QPixmap(":/res/flower.png").scaled(30, 30));
};

void bulletF::docollide()
{
    if (collision()==true && v->HP>2){
        v->HP=v->HP-3;
        t->scorenum=t->scorenum+300;
    }

};

