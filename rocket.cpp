#include "rocket.h"
#include <QGraphicsScene>
#include <QtMath>
#include <QDebug>
#include <QMediaPlayer>
#include "level1.h"
#include "game.h"

extern Game *game;

rocket::rocket()
{
    setPixmap(QPixmap(":img/rocket.png"));
    setScale(.6);

    xAnimation = new QPropertyAnimation(this);
    xAnimation->setTargetObject(this);
    xAnimation->setPropertyName("xFactor");

    yAnimation = new QPropertyAnimation(this);
    yAnimation->setTargetObject(this);
    yAnimation->setPropertyName("yFactor");

    timer = new QTimer();
    timer->start(50);

    connect(timer, SIGNAL(timeout()), this, SLOT(smash()));
}

int rocket::xFactor()
{
    return x();
}

int rocket::yFactor()
{
    return y();
}

void rocket::setXFactor(int newX)
{
    setPos(newX, y());
}

void rocket::setYFactor(int newY)
{
    setPos(x(), newY);
}

void rocket::shoot()
{
    setRotation(qRadiansToDegrees(qAtan2(600 - x(), y() - 350)));
    xAnimation->setStartValue(x());
    xAnimation->setEndValue(scene()->width()/2 - pixmap().width()/2);
    xAnimation->setDuration(1000);

    yAnimation->setStartValue(y());
    yAnimation->setEndValue(scene()->height()/2 - pixmap().height());
    yAnimation->setDuration(1000);

    xAnimation->start();
    yAnimation->start();

    QMediaPlayer * lunch = new QMediaPlayer();
    lunch->setMedia(QUrl("qrc:/sound/missile_lunch.mp3"));
    lunch->play();
}

void rocket::smash()
{
    if(xAnimation->state() == QAbstractAnimation::Stopped){
        QMediaPlayer * explode = new QMediaPlayer();
        explode->setMedia(QUrl("qrc:/sound/explosion.mp3"));
        explode->play();
        scene()->removeItem(this);

        //if(game->lvl->birds.isEmpty())
          //  return;

        for(int i =0;i<game->lvl->birds.size()/2;i++)
        {
            QVector<Bird *>::Iterator it = game->lvl->birds.begin();
            delete game->lvl->birds.at(i);
            game->lvl->birds.erase(it+i);
            game->lvl->sc->increase();
            game->lvl->plane->chickensKilled++;
        }
        delete this;
    }
}
