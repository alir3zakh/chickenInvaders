#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "plane.h"
#include "level1.h"

class Game : public QGraphicsView {
public:
    Game(QWidget * parent = 0);

private:
    Level1 * lvl;
    QTimer * timer;
};

#endif // GAME_H
