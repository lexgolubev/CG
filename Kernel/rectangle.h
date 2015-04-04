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
    double top;
    double right;
    double bottom;
    double left;
public:
    Rectangle(double top, double right, double bottom, double left);

    Location locationOfPoint(Point* p);
    Intersection intersection(Rectangle other);
    Rectangle intersect(Rectangle other);

    double getTop();
    double getRight();
    double getBottom();
    double getLeft();

    ~Rectangle();
};

#endif // RECTANGLE_H
