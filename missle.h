#ifndef MISSLE_H
#define MISSLE_H
#include <QGraphicsTextItem>

class Missle : public QGraphicsTextItem
{
    int missle;
public:
    Missle();
    int getMissle();
    void increase();
    void decrease();
};

#endif // MISSLE_H
