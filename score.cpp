#include "score.h"
#include <QFont>

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
}
