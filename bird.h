#ifndef BIRD_H
#define BIRD_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class Bird :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF position READ position WRITE setposition);
public:
    QPointF position();
    void setposition(QPointF);
    Bird();
    QPropertyAnimation * moveAnim;
};

#endif // BIRD_H
