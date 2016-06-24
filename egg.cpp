#include "egg.h"
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QList>
#include "plane.h"
#include "game.h"
#include "lastp.h"

extern Game * game;

Egg::Egg()
{
    QMediaPlayer * chickenLay = new QMediaPlayer(this);
    chickenLay->setMedia(QUrl("qrc:/sound/Chicken_lay.mp3"));
    chickenLay->play();

    setPixmap(QPixmap(":/img/egg.png"));
    setScale(.7);

    timer = new QTimer();
    connect(timer , SIGNAL(timeout()), this , SLOT(move()));
    timer->start(25);

    opacityAnimation = new QPropertyAnimation(this);
    opacityAnimation->setTargetObject(this);
    opacityAnimation->setPropertyName("opacity");
    opacityAnimation->setStartValue(1);
    opacityAnimation->setEndValue(0);
    opacityAnimation->setDuration(1500);
}

void Egg::move()
{
    if(y() > 650){
        QMediaPlayer * eggSplat = new QMediaPlayer();
        eggSplat->setMedia(QUrl("qrc:sound/Egg_splat.mp3"));
        eggSplat->play();

        setPixmap(QPixmap(":/img/broken-egg.png"));
        opacityAnimation->start();
        timer->stop();
        QTimer::singleShot(2000, this, SLOT(destroy()));
        return;
    }

    setPos(x(),y() + 5);
    //if collides with the plane decrease the player's health
    QList<QGraphicsItem *> items = collidingItems();
    for(int i=0 ; i<items.size() ;i++)
    {
        if(typeid(*(items[i])) == typeid(Plane))
        {
            int size = game->lvl->hearts.size();
            game->lvl->plane->decreaseBulletPower();

            QMediaPlayer * herodeath = new QMediaPlayer();
            herodeath->setMedia(QUrl("qrc:/sound/Hero_death.mp3"));
            herodeath->play();

            if(size==1)
            {
                lastP *lp = new lastP(QString("you Lost!"));
                game->lastPage = lp;
                game->setScene(game->lastPage);
                return;
            }
            delete this;
            delete game->lvl->hearts.at(size-1);
            game->lvl->hearts.pop_back();
            return;
        }
    }

}

void Egg::destroy()
{
    scene()->removeItem(this);
    delete this;
}

