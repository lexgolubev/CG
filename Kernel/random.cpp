#include "random.h"

Random::Random()
{
    qsrand(time(NULL));
//    qsrand(SEED);
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

QList<QPointF> Random::qpoints(int length) {
    QList<QPointF> points;
    for (int i = 0; i < length; i++) {
        points.push_back(qpoint());
    }
    return points;
}

QVector<QPointF> Random::qpoints_vector(int length) {
    QVector<QPointF> points;
    for (int i = 0; i < length; i++) {
        points.push_back(qpoint());
    }
    return points;
}

QPointF Random::qpoint()
{
    return QPointF(number(MIN_X, MAX_X), number(MIN_Y, MAX_Y));
}

QList<QLineF> Random::qlines(int length) {
    QList<QLineF> lines;
    for (int i = 0; i < length; i++) {
        lines.push_back(QLineF(qpoint(), qpoint()));
    }
    return lines;
}

double Random::number(double min, double max) {
    double x = (double)qrand() / (double)RAND_MAX;
    return x * (max - min) + min;
}

Random::~Random()
{

}

