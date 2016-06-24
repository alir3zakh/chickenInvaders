#ifndef BTN_H
#define BTN_H

#include <QGraphicsObject>

class Btn : public QGraphicsObject
{
    Q_OBJECT
    const int btn_w;
    const int btn_h;
    QString text;
public:
    explicit Btn(QGraphicsItem *parent = 0 , QString t="");
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
signals:
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

public slots:

};

#endif // BTN_H
