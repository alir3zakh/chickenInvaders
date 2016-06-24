#include "level1.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include "egg.h"
#include "plane.h"
#include "game.h"
#include "lastp.h"
#include "bulletbouncer.h"

extern Game * game;

Level1::Level1() :itemCount(0)
{
    timer3 = new QTimer();
    connect(timer3, SIGNAL(timeout()), this, SLOT(advance()));
    timer3->start(25);

    setSceneRect(0,0,1200,700);
    plane = new Plane();
    plane->setPos((width() / 2) - plane->pixmap().width()/2,
                  height() - plane->pixmap().height());
    addItem(plane);

    //adding score
    sc = new Score();
    addItem(sc);

    //adding hearts to scene
    for(int i=0; i<3;i++)
    {
        QGraphicsPixmapItem *h = new QGraphicsPixmapItem();
        h->setPixmap(QPixmap(":/img/heart.png"));
        h->setScale(.5);
        hearts.push_back(h);
        addItem(h);
    }

    hearts[0]->setPos(1100,17);
    hearts[1]->setPos(1130,17);
    hearts[2]->setPos(1160,17);

    //adding missle count
    miss = new Missle();
    addItem(miss);

    //scene points for chickens
    points.push_back(QPointF(120,30));
    for(int i=1; i<10; i++)
    {
        points.push_back(QPointF(points[i-1].x()+95,30));
    }
    points.push_back(QPointF(120,100));
    for(int i=1; i<10; i++)
    {
        points.push_back(QPointF(points[i-1].x()+95,100));
    }
    points.push_back(QPointF(120,170));
    for(int i=1; i<10; i++)
    {
        points.push_back(QPointF(points[i-1].x()+95,170));
    }
    points.push_back(QPointF(120,240));
    for(int i=1; i<10; i++)
    {
        points.push_back(QPointF(points[i-1].x()+95,240));
    }

    QTimer * timer = new QTimer();
    connect(timer , SIGNAL(timeout()) , this , SLOT(spawn()));
    timer->start(1000);

    QTimer * timer2 = new QTimer();
    connect(timer2 , SIGNAL(timeout()), this , SLOT(throwEgg()));
    timer2->start(2000);

    timer3 = new QTimer();
    connect(timer3 , SIGNAL(timeout()), this , SLOT(birdCheck()));
    timer3->start(2000);

    QTimer *timer4 = new QTimer();
    connect(timer4 , SIGNAL(timeout()), this , SLOT(killCheck()));
    timer4->start(10);
}

void Level1::spawn()
{
    if(itemCount > 39)
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
    if(birds.isEmpty())
        return;
    Egg * egg = new Egg();
    int randN = qrand()%(birds.size());
    egg->setPos(birds[randN]->x()+27 , birds[randN]->y()+66);
    addItem(egg);
}

void Level1::killCheck()
{
    if(birds.isEmpty())
        return;
    static int lastCall =0;
    if(plane->chickensKilled % 12 == 0 && plane->chickensKilled != lastCall)
    {
        bulletBouncer *bb = new bulletBouncer();
        int randN = qrand()%birds.size();
        bb->setPos(birds.at(randN)->x()+27,birds.at(randN)->y()+66);
        addItem(bb);
        lastCall = plane->chickensKilled;
    }
}

void Level1::birdCheck()
{
    if(birds.isEmpty())
    {
        lastP *lp = new lastP(QString("you won!!"));
        game->lastPage = lp;
        game->setScene(game->lastPage);
    }

//    if(i%7 == 0)
//    {

//        bulletBouncer *bb = new bulletBouncer();
//        int randN = qrand()%birds.size();
//        bb->setPos(birds.at(randN)->x()+27,birds.at(randN)->y()+66);
//        addItem(bb);
//    }
//    i++;
}
