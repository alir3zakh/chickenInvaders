#include "halloffame.h"
#include <QFile>
#include <QTextStream>
#include <QGraphicsTextItem>
#include <QDebug>
#include "btn.h"

HallOfFame::HallOfFame()
{
    setSceneRect(0,0,1200,700);
    QFile file("/Users/alireza/Documents/QT/chickenInvaders-local5/records.txt");
    QTextStream in(&file);
    QString line;
    QStringList list;

    if(file.open(QFile::Text | QFile::ReadOnly))
    {
        int i =0 , h=200;

        while(i<5)
        {
            if(in.atEnd())
            {
                Btn *menu = new Btn(0, QString("main menu"));
                menu->setPos(450,620);
                menu->setObjectName("mmBtn");
                addItem(menu);
                return;
            }
            line = in.readLine();
            list = line.split(" ");

            QGraphicsTextItem * text = new QGraphicsTextItem();
            text->setPlainText(list.at(0));
            text->setFont(QFont("Algerian",30));
            text->setDefaultTextColor(QColor("grey"));
            text->setPos(350 , h);
            addItem(text);

            QGraphicsTextItem * score = new QGraphicsTextItem();
            score->setPlainText(list.at(1));
            score->setFont(QFont("Algerian",30));
            score->setDefaultTextColor(QColor("grey"));
            score->setPos(750 , h);
            addItem(score);
            i++;
            h+=70;
        }
    }
    Btn *menu = new Btn(0, QString("main menu"));
    menu->setPos(450,620);
    menu->setObjectName("mmBtn");
    addItem(menu);
}
