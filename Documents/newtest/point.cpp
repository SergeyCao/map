#include "point.h"
#include <QtWidgets>

static const qreal FOOD_RADIUS = 5;

Point::Point(qreal x, qreal y, QString s){
    setPos(x, y);
    name = s;
}

QRectF Point::boundingRect() const{
    return QRectF(-10, -10,
                  20, 20);
}

void Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red);
    painter->restore();
}

QPainterPath Point::shape() const{
    QPainterPath p;
    p.addEllipse(QPointF(5, 5), FOOD_RADIUS, FOOD_RADIUS);
    return p;
}

QString Point :: getName() {
    return name;
}
