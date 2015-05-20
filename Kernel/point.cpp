#include "point.h"

Point::Point(double x, double y) : _x(x), _y(y)
{
//    this->x = x;
//    this->y = y;
}

void Point::setX(double value)
{
    this->setX(value);
}

void Point::setY(double value)
{
    this->setY(value);
}

double Point::x() const
{
    return _x;
}

double Point::y() const
{
    return _y;
}

Point::~Point()
{

}

