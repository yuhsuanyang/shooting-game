#ifndef ENEMY_H
#define ENEMY_H
#include<stdlib.h>
#include <time.h>
#include "character.h"

class Enemy: public character
{
     Q_OBJECT
public:
    Enemy();
private slots:
    void EnemyMove();
};

#endif // ENEMY_H
