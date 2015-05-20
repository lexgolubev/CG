#include "rectangle.h"

Rectangle::Rectangle(double top, double right, double bottom, double left)
    : _top(top), _right(right), _bottom(bottom), _left(left)
{
//    this->top = top;
//    this->right = right;
//    this->bottom = bottom;
//    this->left = left;
}

double Rectangle::top()
{
    return _top;
}

double Rectangle::right()
{
    return _right;
}

double Rectangle::bottom()
{
    return _bottom;
}

double Rectangle::left()
{
    return _left;
}

void Rectangle::setTop(double value)
{
    this->_top = value;
}

void Rectangle::setRight(double value)
{
    this->_right = value;
}

void Rectangle::setBottom(double value)
{
    this->_bottom = value;
}

void Rectangle::setLeft(double value)
{
    this->_left = value;
}

Location Rectangle::locationOfPoint(Point* p)
{
    if (p->y() > _top || p->y() < _bottom ||
            p->x() > _right || p->x() < _left) {
        return Location::OUTSIDE;
    }
    if (p->y() == _top || p->y() == _bottom ||
            p->x() == _right || p->x() == _left) {
        return Location::BORDER;
    }
    return Location::INSIDE;
}

Intersection Rectangle::intersection(Rectangle other) {
    if (_top < other._bottom || _bottom > other._top ||
            _right < other._left || _left > other._right) {
        return Intersection::NONE;
    }
    if (_top <= other._top && _right <= other._right &&
            _bottom >= other._bottom && _left >= other._left) {
        return Intersection::CONTAINS;
    }
    return Intersection::PART;
}

Rectangle Rectangle::intersect(Rectangle other) {
    double intersectTop = (_top >= other._top) ? other._top : _top;
    double intersectRight = (_right >= other._right) ? other._right : _right;
    double intersectBottom = (_bottom <= other._bottom) ? other._bottom : _bottom;
    double intersectLeft = (_left <= other._left) ? other._left : _left;

    if (_top >= _bottom && _right >= _left) {
        return Rectangle(intersectTop, intersectRight, intersectBottom, intersectLeft);
    } else {
        return Rectangle(INVALID_Y, INVALID_X, INVALID_Y, INVALID_X);
    }
}

Rectangle Rectangle::operator +(const Point& p) {
    return Rectangle(_top + p.y(), _right + p.x(), _bottom + p.y(), _left + p.x());
}

Rectangle::~Rectangle()
{

}

