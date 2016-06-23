#include "plane.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QMediaPlayer>

Plane::Plane()
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

    bulletPower = 1;
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
        if(rAnimation->state() == QAbstractAnimation::Stopped){
        rAnimation->setStartValue(x());
        rAnimation->setEndValue(x() + 40);
        rAnimation->start();
        }
        break;

    case Qt::Key_Left:
        lAnimation->setStartValue(x());
        lAnimation->setEndValue(x() - 40);
        lAnimation->start();
        break;

    case Qt::Key_Up:
        uAnimation->setStartValue(y());
        uAnimation->setEndValue(y() - 40);
        uAnimation->start();
        break;

    case Qt::Key_Down:
        dAnimation->setStartValue(y());
        dAnimation->setEndValue(y() + 40);
        dAnimation->start();
        break;

    case Qt::Key_Space:{
        rocket * myRocket = new rocket();
        scene()->addItem(myRocket);
        myRocket->setPos(x() + 35, y() + 20);
        myRocket->shoot();
        break;
    }

    case Qt::Key_Control:{
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

