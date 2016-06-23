#ifndef LEVEL1_H
#define LEVEL1_H
#include <QObject>
#include <QGraphicsScene>
#include <QVector>
#include "bird.h"
#include "plane.h"
#include "score.h"

class Level1 :public QGraphicsScene
{
    Q_OBJECT
public:
    Level1();
    Plane * plane;
    QVector<QPointF> points;
    QVector<Bird *> birds;
    QVector<QGraphicsPixmapItem *> hearts;
    int itemCount;
    Score * sc;
public slots:
    void spawn();
    void throwEgg();
};

#endif // LEVEL1_H
