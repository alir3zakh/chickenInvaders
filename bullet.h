#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include "bird.h"

class bullet : public QGraphicsPixmapItem
{
public:
    bullet(qreal bulletAngel);
    ~bullet();

protected:
    void advance(int phase);

private:
    qreal angle;
    qreal speed;
    QMediaPlayer * death;
    QMediaPlayer * bulletsound;
};

#endif // BULLET_H
