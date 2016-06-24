#ifndef NAMEENTER_H
#define NAMEENTER_H
#include <QGraphicsScene>
#include "btn.h"
#include <QtWidgets>
#include <QGraphicsTextItem>

class nameEnter : public QGraphicsScene
{
public:
    nameEnter();
    Btn *login;
    QLineEdit * le;
    QGraphicsTextItem *text;
};

#endif // NAMEENTER_H
