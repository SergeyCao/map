#ifndef POINT_H
#define POINT_H

#include <QtWidgets>
class Point : public QGraphicsItem
{
public:
    Point(qreal x, qreal y, QString s);//初始化位置

    QRectF boundingRect() const;//返回食物点的边界（一个矩形）
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    //绘制图形
    QPainterPath shape() const;
    QString getName();
private:
    QString name;
};

#endif // POINT_H
