#include "score.h"
#include <QFont>
#include "game.h"

extern Game * game;

Score::Score()
    :score(0)
{
    setPlainText("Score : " + QString::number(score));
    setFont(QFont("Algerian",25));
    setDefaultTextColor(QColor("grey"));
    setPos(0,600);
}

int Score::getScore()
{
    return score;
}

void Score::increase()
{
    score +=100;
    setPlainText("Score : " + QString::number(score));
    setFont(QFont("Algerian",25));
    setDefaultTextColor(QColor("grey"));
    setPos(0,600);
    if((score % 500) == 0){
        game->lvl->plane->missileCount += 1;
    }
}
