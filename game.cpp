#include "game.h"
#include "level1.h"
#include <QTimer>

Game::Game(QWidget * parent) : QGraphicsView(parent) {

    mainPage = new mainP();
    ne = new nameEnter();
    lastPage = new lastP(QString(""));

    setStyleSheet("background-image: url(:/img/Bground.jpg); background-position: 0px 0px;"
                  "background-repeat: repeat-x; background-attachment: scroll");

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(mainPage);
    this->setFixedSize(1200, 700);

    this->show();
}

