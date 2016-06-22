#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "plane.h"
#include "level1.h"

class Game : public QGraphicsView {
public:
    Game(QWidget * parent = 0);

private:
    Level1 * lvl;
};

#endif // GAME_H
