#ifndef POINT_H
#define POINT_H


class Point
{
private:
    double x;
    double y;

public:
    Point(double x = 0.0, double y = 0.0);

    void setX(double value);
    void setY(double value);

    double getX() const;
    double getY() const;

    ~Point();
};

#endif // POINT_H
