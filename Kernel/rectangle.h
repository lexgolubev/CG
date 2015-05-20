#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

constexpr double INVALID_X = -1000;
constexpr double INVALID_Y = -1000;

enum Location
{
    OUTSIDE, INSIDE, BORDER
};

enum Intersection
{
    NONE, PART, CONTAINS
};

class Rectangle
{
private:
    double _top;
    double _right;
    double _bottom;
    double _left;
public:
    Rectangle(double top = 0, double right = 0, double bottom = 0, double left = 0);

    Location locationOfPoint(Point* p);
    Intersection intersection(Rectangle other);
    Rectangle intersect(Rectangle other);

    double top();
    double right();
    double bottom();
    double left();

    void setTop(double value);
    void setRight(double value);
    void setBottom(double value);
    void setLeft(double value);

    //move on dx dy
    Rectangle operator+(const Point& p);

    ~Rectangle();
};

#endif // RECTANGLE_H
