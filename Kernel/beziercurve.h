#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include <QVector>
#include <QPointF>

class BezierCurve
{
public:
    BezierCurve(const QVector<QPointF>& points);

    QPointF at(qreal t);

    ~BezierCurve();

private:

    QVector<QPointF> points;

    int n;

    qreal* b;
    qreal* x;
    qreal* y;
};

#endif // BEZIERCURVE_H
