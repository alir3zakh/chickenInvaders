#include "score.h"
#include <QFont>
#include "game.h"

extern Game * game;

Score::Score()
    :score(0)
{
    setPlainText(QString::number(score));
    setFont(QFont("Algerian",25));
    setDefaultTextColor(QColor("grey"));
    setPos(1000,0);
}

int Score::getScore()
{
    return score;
}

void Score::increase()
{
    score +=100;
    setPlainText(QString::number(score));
    setFont(QFont("Algerian",25));
    setDefaultTextColor(QColor("grey"));
    setPos(1000,0);
    if((score % 500) == 0){
        game->lvl->miss->increase();
    }
}
