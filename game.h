#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "plane.h"

class Game : public QGraphicsView {
public:
    Game(QWidget * parent = 0);

private:
    QGraphicsScene * scene;
    Plane * plane;
};

#endif // GAME_H
