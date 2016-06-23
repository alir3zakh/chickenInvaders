#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
    int score;
public:
    Score();
    int getScore();
    void increase();
};

#endif // SCORE_H
