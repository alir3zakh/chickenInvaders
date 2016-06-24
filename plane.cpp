#include "plane.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include "game.h"

extern Game * game;

Plane::Plane()
    :chickensKilled(0)
{
    setPixmap(QPixmap(":img/plane.png"));
    setScale(.65);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    rAnimation = new QPropertyAnimation(this);
    rAnimation->setTargetObject(this);
    rAnimation->setPropertyName("xFactor");
    rAnimation->setStartValue(x());
    rAnimation->setEndValue(x() + 40);
    rAnimation->setDuration(100);

    lAnimation = new QPropertyAnimation(this);
    lAnimation->setTargetObject(this);
    lAnimation->setPropertyName("xFactor");
    lAnimation->setStartValue(x());
    lAnimation->setEndValue(x() - 40);
    lAnimation->setDuration(100);

    uAnimation = new QPropertyAnimation(this);
    uAnimation->setTargetObject(this);
    uAnimation->setPropertyName("yFactor");
    uAnimation->setStartValue(y());
    uAnimation->setEndValue(y() - 40);
    uAnimation->setDuration(100);

    dAnimation = new QPropertyAnimation(this);
    dAnimation->setTargetObject(this);
    dAnimation->setPropertyName("yFactor");
    dAnimation->setStartValue(y());
    dAnimation->setEndValue(y() + 40);
    dAnimation->setDuration(100);

    shootAnimation = new QPropertyAnimation(this);
    shootAnimation->setTargetObject(this);
    shootAnimation->setPropertyName("yFactor");
    shootAnimation->setStartValue(y());
    shootAnimation->setEndValue(y() + 10);
    shootAnimation->setKeyValueAt(0.5, y() + 10);
    shootAnimation->setDuration(100);

    bulletPower = 1;
    missileCount = 1;
}

int Plane::xFactor()
{
    return x();
}

int Plane::yFactor()
{
    return y();
}

void Plane::setXFactor(int newX)
{
    setPos(newX, y());
}

void Plane::setYFactor(int newY)
{
    setPos(x(), newY);
}

void Plane::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Right:
        if(x() < 1130) {
        rAnimation->setStartValue(x());
        rAnimation->setEndValue(x() + 40);
        rAnimation->start();
        }
        break;

    case Qt::Key_Left:
        if(x() > 0){
        lAnimation->setStartValue(x());
        lAnimation->setEndValue(x() - 40);
        lAnimation->start();
        }
        break;

    case Qt::Key_Up:
        if(y() > 30){
        uAnimation->setStartValue(y());
        uAnimation->setEndValue(y() - 40);
        uAnimation->start();
        }
        break;

    case Qt::Key_Down:
        if(y() < 580){
        dAnimation->setStartValue(y());
        dAnimation->setEndValue(y() + 40);
        dAnimation->start();
        }
        break;

    case Qt::Key_Space:{
        if(!missileCount)
            break;
        rocket * myRocket = new rocket();
        scene()->addItem(myRocket);
        myRocket->setPos(x() + 35, y() + 20);
        myRocket->shoot();
        game->lvl->miss->decrease();
        break;
    }

    case Qt::Key_Control:{
        shootAnimation->setStartValue(y());
        shootAnimation->setEndValue(y());
        shootAnimation->setKeyValueAt(0.5, y() + 10);
        shootAnimation->start();
        int regionCount = bulletPower + 3;
        qreal baseAngel = 180 / regionCount;
        for(int i = 0; i < bulletPower; i++){
            bullet * newBullet = new bullet((i+2) * baseAngel);
            newBullet->setPos(x() + 35, y() + 10);
            scene()->addItem(newBullet);
        }

        QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl("qrc:/sound/bullet.mp3"));
        bulletsound->play();
        break;
    }

    case Qt::Key_W:
        bulletPower++;
        break;

    case Qt::Key_S:
        bulletPower--;
        break;

    default:
        break;
    }
}

void Plane::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
}

void Plane::increaseBulletPower()
{
    if(bulletPower == 4)
        return;
    bulletPower++;
}

void Plane::decreaseBulletPower()
{
    if(bulletPower == 2){
        bulletPower--;
        return;
    }

    if(bulletPower == 1){
        return;
    }

    bulletPower -= 2;
}

