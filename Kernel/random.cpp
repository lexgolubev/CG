#include "random.h"

Random::Random()
{
    qsrand(SEED);
}

std::vector<Point*> Random::points(int length) {
    std::vector<Point*> points;
    for (int i = 0; i < length; i++) {
        points.push_back(point());
    }
    return points;
}

Point* Random::point()
{
    return new Point(number(MIN_X, MAX_X), number(MIN_Y, MAX_Y));
}

double Random::number(double min, double max) {
    double x = (double)qrand() / (double)RAND_MAX;
    return x * (max - min) + min;
}

Random::~Random()
{

}

