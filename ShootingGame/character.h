#ifndef CHARACTER_H
#define CHARACTER_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class character:public QObject, public QGraphicsPixmapItem
{
public:
    character();
    int HP;
    int scorenum;
};

#endif // CHARACTER_H
