#include "plane.h"
#include <QDebug>
Plane::Plane()
{
    setPixmap(QPixmap(":img/plane.png"));
    setScale(.65);

    //set

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

    default:
        break;
    }
}

void Plane::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
}

