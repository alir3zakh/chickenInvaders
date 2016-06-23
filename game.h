#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "plane.h"
#include "level1.h"
#include <QTimer>

class Game : public QGraphicsView {
public:
    Game(QWidget * parent = 0);
    Level1 * lvl;

private :
    QTimer * timer;
};

#endif // GAME_H
