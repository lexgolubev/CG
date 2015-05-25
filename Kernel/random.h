#ifndef RANDOM_H
#define RANDOM_H

#include <QPointF>
#include <QList>
#include <QLineF>
#include "point.h"
#include <time.h>

constexpr int SEED = 0x345;

class Random
{
public:
    Random();

    std::vector<Point*> points(int length);

    QList<QPointF> qpoints(int length);

    QList<QLineF> qlines(int length);

    Point* point();

    QPointF qpoint();

    double number(double min, double max);

    ~Random();
};

#endif // RANDOM_H
