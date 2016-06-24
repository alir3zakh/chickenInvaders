#include "game.h"
#include "level1.h"
#include <QTimer>
#include "mainpage.h"

Game::Game(QWidget * parent) : QGraphicsView(parent) {
    lvl = new Level1();
    mainPage = new mainP();
    ne = new nameEnter();

    setStyleSheet("background-image: url(:/img/Bground.jpg); background-position: 0px 0px;"
                  "background-repeat: repeat-x; background-attachment: scroll");

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(mainPage);
    this->setFixedSize(1200, 700);

    this->show();
}

