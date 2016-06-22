#ifndef EGG_H
#define EGG_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Egg : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Egg();
public slots:
    void move();
};

#endif // EGG_H
