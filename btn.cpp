#include "btn.h"
#include <QPainter>
#include <QPropertyAnimation>
#include "nameenter.h"
#include "mainp.h"
#include "game.h"
#include "level1.h"

extern Game * game;

Btn::Btn(QGraphicsItem *parent,QString t) :
    QGraphicsObject(parent),btn_w(300),btn_h(50)
{
   setAcceptHoverEvents(true);
   text = t;
}

void Btn::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF btnRect(1,1,btn_w-2,btn_h-2);
    painter->setBrush(QBrush(QColor(21,10,75)));
    painter->drawRoundedRect(btnRect,10,10);
    painter->setFont(QFont("Algerian",15));
    painter->setPen(QPen(QColor(Qt::gray)));
    painter->drawText(btnRect,Qt::AlignCenter,text);

}


QRectF Btn::boundingRect() const
{
    return QRectF(0,0,btn_w,btn_h);
}

void Btn::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QPropertyAnimation *anim = new QPropertyAnimation(this,"scale");
    setTransformOriginPoint(boundingRect().center());;
    anim->setEasingCurve(QEasingCurve::OutElastic);
    anim->setStartValue(1);
    anim->setEndValue(1.1);
    anim->setDuration(100);
    anim->start(QAbstractAnimation::DeleteWhenStopped);

}

void Btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QPropertyAnimation *anim = new QPropertyAnimation(this,"scale");
    setTransformOriginPoint(boundingRect().center());;

    anim->setStartValue(1.1);
    anim->setEndValue(1);
    anim->setDuration(100);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void Btn::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->objectName() == "quitBtn")
        exit(0);

    if(this->objectName() == "stwBtn")
    {
        game->setScene(game->ne);
    }
    if(this->objectName() == "enterBtn")
    {
        game->lvl = new Level1();
        game->setScene(game->lvl);
    }
}

