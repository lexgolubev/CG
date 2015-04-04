#include "rectangle.h"

Rectangle::Rectangle(double top, double right, double bottom, double left)
    : top(top), right(right), bottom(bottom), left(left)
{
//    this->top = top;
//    this->right = right;
//    this->bottom = bottom;
//    this->left = left;
}

double Rectangle::getTop()
{
    return top;
}

double Rectangle::getRight()
{
    return right;
}

double Rectangle::getBottom()
{
    return bottom;
}

double Rectangle::getLeft()
{
    return left;
}

Location Rectangle::locationOfPoint(Point* p)
{
    if (p->getX() > top || p->getX() < bottom ||
            p->getY() > right || p->getY() < left) {
        return Location::OUTSIDE;
    }
    if (p->getX() == top || p->getX() == bottom ||
            p->getY() == right || p->getY() == left) {
        return Location::BORDER;
    }
    return Location::INSIDE;
}

Intersection Rectangle::intersection(Rectangle other) {
    if (top < other.bottom || bottom > other.top ||
            right < other.left || left > other.right) {
        return Intersection::NONE;
    }
    if (top <= other.top && right <= other.right &&
            bottom >= other.bottom && left >= other.left) {
        return Intersection::CONTAINS;
    }
    return Intersection::PART;
}

Rectangle Rectangle::intersect(Rectangle other) {
    double intersectTop = (top >= other.top) ? other.top : top;
    double intersectRight = (right >= other.right) ? other.right : right;
    double intersectBottom = (bottom <= other.bottom) ? other.bottom : bottom;
    double intersectLeft = (left <= other.left) ? other.left : left;

    if (top >= bottom && right >= left) {
        return Rectangle(intersectTop, intersectRight, intersectBottom, intersectLeft);
    } else {
        return Rectangle(INVALID_Y, INVALID_X, INVALID_Y, INVALID_X);
    }
}

Rectangle::~Rectangle()
{

}

