#include "lastp.h"
#include <QGraphicsTextItem>

lastP::lastP(QString status)
{
    text = status;
    setSceneRect(0,0,1200,700);

    QGraphicsTextItem *t = new QGraphicsTextItem();
    t->setPlainText(text);
    t->setFont(QFont("Algerian",70));
    t->setDefaultTextColor(QColor("grey"));
    t->setPos(410,300);
    addItem(t);

    quitBtn = new Btn(0,QString("Quit"));
    quitBtn->setObjectName("quitBtn");
    quitBtn->setPos(450,620);
    addItem(quitBtn);

    menuBtn = new Btn(0, QString("main menu"));
    menuBtn->setObjectName("menuBtn");
    menuBtn->setPos(450,560);
    addItem(menuBtn);

}
