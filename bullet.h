#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include "bird.h"

class bullet : public QGraphicsPixmapItem
{
public:
    bullet(qreal bulletAngel);

protected:
    void advance(int phase);

private:
    qreal angle;
    qreal speed;
};

#endif // BULLET_H
