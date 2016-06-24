#ifndef EGG_H
#define EGG_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QPropertyAnimation>
#include <QMediaPlayer>

class Egg : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)

public:
    Egg();

public slots:
    void move();
    void destroy();

private:
    QPropertyAnimation * opacityAnimation;
    QTimer *timer;
    QMediaPlayer * chickenLay;
    QMediaPlayer * eggSplat;
    QMediaPlayer * playerDeath;
};

#endif // EGG_H
