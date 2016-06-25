#ifndef LEVEL1_H
#define LEVEL1_H
#include <QObject>
#include <QGraphicsScene>
#include <QVector>
#include "bird.h"
#include "plane.h"
#include "score.h"
#include "missle.h"

class Level1 :public QGraphicsScene
{
    Q_OBJECT
public:
    Level1();
    Plane * plane;
    QVector<QPointF> points;
    QVector<Bird *> birds;
    QVector<QGraphicsPixmapItem *> hearts;
    void updateFile();
    int itemCount;
    Score * sc;
    Missle * miss;
    QTimer * timer3;
public slots:
    void spawn();
    void throwEgg();
    void killCheck();
    void birdCheck();
};

#endif // LEVEL1_H
