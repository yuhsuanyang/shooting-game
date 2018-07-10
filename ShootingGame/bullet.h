#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QLabel>
#include <QDebug>

//#include "mainwindow.h"
#include "character.h"

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet(character *w, character *u);
    bool collision();

public slots:
    void flyup();
    void flydown();
    virtual void docollide();
protected:
    character *v;
    character *t;
};

#endif // BULLET_H
