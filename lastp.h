#ifndef LASTP_H
#define LASTP_H
#include <QGraphicsScene>
#include "btn.h"

class lastP : public QGraphicsScene
{
public:
    lastP(QString status);
    Btn *quitBtn;
    QString text;
    Btn * menuBtn;
};

#endif // LASTP_H
