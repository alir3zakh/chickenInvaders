#include "bulletbouncer.h"
#include "plane.h"
#include "game.h"
#include <QGraphicsScene>
#include <QList>

extern Game * game;

bulletBouncer::bulletBouncer()
{
    setPixmap(QPixmap(":/img/bounce.png"));
    setScale(1.5);

    timer = new QTimer();
    connect(timer , SIGNAL(timeout()), this , SLOT(move()));
    timer->start(50);
}

void bulletBouncer::move()
{
    if(y() > 700){
        scene()->removeItem(this);
        delete this;
        return;
    }
    setPos(x(),y() + 5);
    //if collides with the plane increase the player's bullet power
    QList<QGraphicsItem *> items = collidingItems();
    for(int i=0 ; i<items.size() ;i++)
    {
        if(typeid(*(items[i])) == typeid(Plane))
        {
            /*QMediaPlayer * playerDeath = new QMediaPlayer();
            playerDeath->setMedia(QUrl("qrc:sound/Hero_death.mp3"));
            playerDeath->play();*/

            game->lvl->plane->increaseBulletPower();
            scene()->removeItem(this);

            delete this;
            return;
        }
    }
}

