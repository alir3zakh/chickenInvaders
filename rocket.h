#ifndef ROCKET_H
#define ROCKET_H

#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QObject>
#include <QTimer>

class rocket : public QObject,  public QGraphicsPixmapItem{
    Q_OBJECT
    Q_PROPERTY(int xFactor READ xFactor WRITE setXFactor)
    Q_PROPERTY(int yFactor READ yFactor WRITE setYFactor)
public:
    rocket();
    int xFactor();
    int yFactor();
    void setXFactor(int newX);
    void setYFactor(int newY);

    void shoot();

private:
    QPropertyAnimation * xAnimation;
    QPropertyAnimation * yAnimation;
    QTimer * timer;

private slots:
    void smash();
};

#endif // ROCKET_H
