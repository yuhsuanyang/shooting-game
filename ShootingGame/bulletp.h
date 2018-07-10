#ifndef BULLETP_H
#define BULLETP_H

#include "bullet.h"
//#include "character.h"
class character;
class bulletP : public bullet
{
    Q_OBJECT
public:
    bulletP(character *w, character *u);
    bool gethelp();
public slots:
    void docollide();

};

#endif // BULLETP_H
