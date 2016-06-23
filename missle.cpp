#include "missle.h"
#include "game.h"

extern Game *game;

Missle::Missle()
    :missle(1)
{
    setPlainText("missle : " + QString::number(missle));
    setFont(QFont("Algerian",20));
    setDefaultTextColor(QColor("grey"));
    setPos(0,650);
}


int Missle::getMissle()
{
    return missle;
}

void Missle::increase()
{
    game->lvl->plane->missileCount++;
    missle++;

    setPlainText("missle : " + QString::number(missle));
    setFont(QFont("Algerian",20));
    setDefaultTextColor(QColor("grey"));
    setPos(0,650);
}

void Missle::decrease()
{
    game->lvl->plane->missileCount--;
    missle--;

    setPlainText("missle : " + QString::number(missle));
    setFont(QFont("Algerian",20));
    setDefaultTextColor(QColor("grey"));
    setPos(0,650);
}
