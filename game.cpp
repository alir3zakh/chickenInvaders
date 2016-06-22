#include "game.h"
#include "level1.h"

Game::Game(QWidget * parent) : QGraphicsView(parent) {
    lvl = new Level1();
    setStyleSheet("background-image: url(:/img/Bground.jpg); background-position: 0px 0px;");

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(lvl);
    this->setFixedSize(1250, 700);

    this->show();

}

