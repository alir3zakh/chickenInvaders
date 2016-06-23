#include "game.h"
#include "level1.h"

Game::Game(QWidget * parent) : QGraphicsView(parent) {
    lvl = new Level1();
    setStyleSheet("background-image: url(:/img/Bground.jpg); background-position: 0px 0px;"
                  "background-repeat: repeat-x; background-attachment: scroll");

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(lvl);
    this->setFixedSize(1200, 700);

    this->show();

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), lvl, SLOT(advance()));
    timer->start(25);
}

