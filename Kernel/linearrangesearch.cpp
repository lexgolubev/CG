#include "linearrangesearch.h"

LinearRangeSearch::LinearRangeSearch()
{

}

void LinearRangeSearch::init(const QVector<QPointF>& points)
{
    this->points = points;
}

void LinearRangeSearch::search(QRectF r, QVector<QPointF>& result)
{
    result.clear();
    foreach (QPointF p, points) {
        if (r.contains(p)) {
            result.push_back(p);
        }
    }
}

LinearRangeSearch::~LinearRangeSearch()
{
    points.clear();
}

