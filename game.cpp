#include "game.h"

Game::Game(QWidget * parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1250, 750);

    this->setScene(scene);
    this->setFixedSize(1250, 750);

    plane = new Plane();
    plane->setPos((scene->width() / 2) - plane->pixmap().width()/2,
                  scene->height() - plane->pixmap().height());
    scene->addItem(plane);
}

