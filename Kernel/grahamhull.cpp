#include "grahamhull.h"

GrahamHull::GrahamHull()
{

}

//compare for sort points in ascending order
class TanCmp
{
public:
    TanCmp(const QPointF& p) {
        this->p = p;
    }

    inline bool operator()(const QPointF &p1, const QPointF &p2) const
    {
        return tan(p1, p) < tan(p2, p);
    }

    qreal tan(const QPointF& p1, const QPointF& p2) const {
        return (p2.y() - p1.y()) / (p2.x() - p1.x());
    }

    QPointF p;
};

QList<QPointF> GrahamHull::build(const QList<QPointF> &points) {
    if (points.size() <= 0) {
        return QList<QPointF>();
    }
    QQueue<QPointF> hull;
    QList<QPointF> pts = points;

    left = pts.first();
    foreach (QPointF p, pts) {
        if (p.x() < left.x()) {
            left = p;
        }
    }
    std::sort(pts.begin(), pts.end(), TanCmp(left));

    hull.push_back(left);
    QPointF v = pts.takeFirst();
    QPointF w = pts.takeFirst();
    while (w != left) {
        if (rightTurn(hull.last(), v, w)) {
            v = hull.takeLast();
        } else {
            hull.push_back(v);
            v = w;
            w = pts.takeFirst();
        }
    }
    return hull;
}


bool GrahamHull::rightTurn(const QPointF& p1, const QPointF& p2, const QPointF& p3) {
    return (p3.x() - p1.x()) * (p2.y() - p1.y()) - (p3.y() - p1.y()) * (p2.x() - p1.x()) >= 0;
}

GrahamHull::~GrahamHull()
{

}

