#include "beziercurve.h"

BezierCurve::BezierCurve(const QVector<QPointF> &points) {
    this->points = points;
    n = points.size();
    b = new qreal[n];
    x = new qreal[n];
    y = new qreal[n];
}

QPointF BezierCurve::at(qreal t) {
    memset(b, 0, n * sizeof(qreal));
    for (int i = 0; i < n; i ++) {
        x[i] = points[i].x();
        y[i] = points[i].y();
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            x[j] = x[j] * (1 - t) + x[j + 1] * t;
            y[j] = y[j] * (1 - t) + y[j + 1] * t;
        }
    }
    return QPointF(x[0], y[0]);
}

BezierCurve::~BezierCurve()
{

}

