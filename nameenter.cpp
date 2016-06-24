#include "nameenter.h"
#include <QGraphicsTextItem>
#include <QtWidgets>
#include "btn.h"

nameEnter::nameEnter()
{
    setSceneRect(0,0,800,600);
    text = new QGraphicsTextItem();
    text->setPlainText("enter you name :");
    text->setFont(QFont("Algerian",30));
    text->setDefaultTextColor(QColor("grey"));
    text->setPos(220,200);
    login = new Btn(0,QString("Enter"));
    login->setObjectName("enterBtn");
    login->setPos(250,450);
    le = new QLineEdit();
    le->resize(400,30);
    le->move(200,300);
    addWidget(le);
    addItem(login);
    addItem(text);
}
