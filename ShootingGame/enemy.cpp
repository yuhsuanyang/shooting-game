#include "enemy.h"

Enemy::Enemy(){
}

void Enemy::EnemyMove()
{
    srand( (int)time(NULL));
    int posx=rand()%1100;
    int posy=rand()%500;
    setPos(posx-400,posy);
}

