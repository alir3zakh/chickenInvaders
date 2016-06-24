#ifndef BULLETBOUNCER_H
#define BULLETBOUNCER_H

#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>

class bulletBouncer : public QObject,  public QGraphicsPixmapItem {
    Q_OBJECT
public:
    bulletBouncer();

public slots:
    void move();

private:
    QTimer * timer;
};

#endif // BULLETBOUNCER_H
