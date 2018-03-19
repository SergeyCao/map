#ifndef ROUTE_H
#define ROUTE_H

#include <QtWidgets>

class Route
{
public:
    Route();
    Route(int to, double length);
    void changeLength(double _length);
    double getLength();
    int getTo();
private:
    int to;
    double length;
};

#endif // ROUTE_H
