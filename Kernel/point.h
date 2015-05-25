#ifndef POINT_H
#define POINT_H

constexpr double MIN_X = 0.0;
constexpr double MIN_Y = 0.0;
constexpr double MAX_X = 1100;
constexpr double MAX_Y = 620;

class Point
{
private:
    double _x;
    double _y;

public:
    Point(double x = 0.0, double y = 0.0);

    void setX(double value);
    void setY(double value);

    double x() const;
    double y() const;

    ~Point();
};

#endif // POINT_H
