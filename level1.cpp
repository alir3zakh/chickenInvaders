#include "level1.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include "egg.h"
#include "plane.h"

Level1::Level1()
    :itemCount(0)
{
    setSceneRect(0,0,1200,700);
    plane = new Plane();
    plane->setPos((width() / 2) - plane->pixmap().width()/2,
                  height() - plane->pixmap().height());
    addItem(plane);

    points.push_back(QPointF(25,0));
    for(int i=1; i<10; i++)
    {
        points.push_back(QPointF(points[i-1].x()+120,0));
    }
    points.push_back(QPointF(25,100));
    for(int i=1; i<10; i++)
    {
        points.push_back(QPointF(points[i-1].x()+120,100));
    }
    points.push_back(QPointF(25,200));
    for(int i=1; i<10; i++)
    {
        points.push_back(QPointF(points[i-1].x()+120,200));
    }

    QTimer * timer = new QTimer();
    connect(timer , SIGNAL(timeout()) , this , SLOT(spawn()));
    timer->start(1000);

    QTimer * timer2 = new QTimer();
    connect(timer2 , SIGNAL(timeout()), this , SLOT(throwEgg()));
    timer2->start(2000);
}

void Level1::spawn()
{
    if(itemCount > 29)
        return;
    Bird * bird = new Bird();
    birds.push_back(bird);
    addItem(bird);
    int x = points.begin()->x();
    int y = points.begin()->y();
    QVector<QPointF>::Iterator it = points.begin();

    bird->moveAnim->setStartValue(bird->pos());
    bird->moveAnim->setEndValue(QPointF(x,y));
    bird->moveAnim->setDuration(2000);
    bird->moveAnim->start();

    points.erase(it);
    itemCount++;
}

void Level1::throwEgg()
{
    Egg * egg = new Egg();
    int randN = qrand()%(birds.size());
    egg->setPos(birds[randN]->x()+47 , birds[randN]->y()+95);
    addItem(egg);
}
