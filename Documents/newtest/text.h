#ifndef TEXT_H
#define TEXT_H
#include<QtWidgets>

class Text : public QGraphicsTextItem
{
public:
    Text(QString s, qreal x, qreal y);
};

#endif // TEXT_H
