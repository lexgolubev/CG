#ifndef LINEARRANGESEARCH_H
#define LINEARRANGESEARCH_H

#include "irangesearch.h"

class LinearRangeSearch : public IRangeSearch
{
public:
    LinearRangeSearch();

    virtual void init(const QVector<QPointF>& points);
    virtual void search(QRectF r, QVector<QPointF>& result);

    ~LinearRangeSearch();

private:
    QVector<QPointF> points;
};

#endif // LINEARRANGESEARCH_H
