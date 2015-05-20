#ifndef RANDOM_H
#define RANDOM_H

#include <QtGlobal>
#include "point.h"

constexpr int SEED = 0x345;

class Random
{
public:
    Random();

    std::vector<Point*> points(int length);

    Point* point();

    double number(double min, double max);

    ~Random();
};

#endif // RANDOM_H
