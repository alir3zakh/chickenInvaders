#include "bird.h"

Bird::Bird()
{
    setPixmap(QPixmap(":/img/bird.png"));

    //moveAnim
    moveAnim = new QPropertyAnimation(this);
    moveAnim->setTargetObject(this);
    moveAnim->setPropertyName("position");
    moveAnim->setEasingCurve(QEasingCurve(QEasingCurve::InBounce));

    //set random start position
    static int rand = 1;
    if(rand)
    {
        setPos(1250+119,qrand()%350);
        rand -=1;
    }
    else
    {
        setPos(-119,qrand()%350);
        rand +=1;
    }
}


void Bird::setposition(QPointF p)
{
    setPos(p);
}


QPointF Bird::position()
{
    return pos();
}
