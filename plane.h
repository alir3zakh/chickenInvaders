#ifndef PLANE_H
#define PLANE_H

#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QObject>
#include "rocket.h"
#include "bullet.h"

class Plane : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    Q_PROPERTY(int xFactor READ xFactor WRITE setXFactor)
    Q_PROPERTY(int yFactor READ yFactor WRITE setYFactor)
public:
    Plane();
    int missileCount;
    int chickensKilled;
    int xFactor();
    int yFactor();
    void setXFactor(int newX);
    void setYFactor(int newY);

    void keyPressEvent(QKeyEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    void increaseBulletPower();
    void decreaseBulletPower();

private:
    int bulletPower;
    QPropertyAnimation * rAnimation;
    QPropertyAnimation * lAnimation;
    QPropertyAnimation * uAnimation;
    QPropertyAnimation * dAnimation;
};

#endif // PLANE_H
