#ifndef BULLETF_H
#define BULLETF_H

#include "bullet.h"
//#include "character.h"
class character;
class bulletF : public bullet
{
    Q_OBJECT
public:
    bulletF(character *w, character *u);
public slots:
    void docollide();


};

#endif // BULLETF_H

