#include "egg.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "plane.h"
#include "game.h"

extern Game * game;

Egg::Egg()
{
    setPixmap(QPixmap(":/img/egg.png"));
    setScale(.7);

    QTimer *timer = new QTimer();
    connect(timer , SIGNAL(timeout()), this , SLOT(move()));
    timer->start(50);
}

void Egg::move()
{
    setPos(x(),y()+10);
    //if collides with the plane decrease the player's health
    QList<QGraphicsItem *> items = collidingItems();
    for(int i=0 ; i<items.size() ;i++)
    {
        if(typeid(*(items[i])) == typeid(Plane))
        {
            int size = game->lvl->hearts.size();

            if(size==1)
                exit(0);

            delete this;
            delete game->lvl->hearts.at(size-1);
            game->lvl->hearts.pop_back();
            return;
        }
    }

    if(y()>700)
    {
        scene()->removeItem(this);
        delete this;
    }

}
