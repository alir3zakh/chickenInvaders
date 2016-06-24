#include "mainp.h"
#include <QGraphicsScene>
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include "btn.h"



mainP::mainP()
{
    setSceneRect(0,0,800,600);

    QGraphicsPixmapItem * logo = new QGraphicsPixmapItem(QPixmap(":/img/logo.png"));
    logo->setPos(308,50);
    addItem(logo);

    QGraphicsTextItem *text = new QGraphicsTextItem();
    text->setPlainText("Main Menu");
    text->setFont(QFont("Algerian",25));
    text->setDefaultTextColor(QColor("grey"));
    text->setPos(313 , 180);
    addItem(text);
    Btn *stwbtn = new Btn(0,QString("Save The World"));
    stwbtn->setPos(250,250);
    addItem(stwbtn);

    Btn *hofBtn = new Btn(0,QString("Half Of Fame"));
    hofBtn->setPos(250,320);
    addItem(hofBtn);

    Btn *quitBtn = new Btn(0,QString("Quit"));
    quitBtn->setPos(250,450);
    addItem(quitBtn);
    quitBtn->setObjectName("quitBtn");
    hofBtn->setObjectName("hofBtn");
    stwbtn->setObjectName("stwBtn");
}


