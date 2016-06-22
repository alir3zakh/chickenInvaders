#ifndef LEVEL1_H
#define LEVEL1_H
#include <QObject>
#include <QGraphicsScene>
#include <QVector>
#include "bird.h"
#include "plane.h"

class Level1 :public QGraphicsScene
{
    Q_OBJECT
public:
    Level1();
    Plane * plane;
    QVector<QPointF> points;
    QVector<Bird *> birds;
    int itemCount;
public slots:
    void spawn();
    void throwEgg();
};

#endif // LEVEL1_H
