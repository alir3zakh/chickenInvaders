#ifndef EGG_H
#define EGG_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QPropertyAnimation>

class Egg : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)

public:
    Egg();

public slots:
    void move();

private:
    QPropertyAnimation * opacityAnimation;
    QTimer *timer;
};

#endif // EGG_H
