#ifndef QUADTREERANGESEARCH_H
#define QUADTREERANGESEARCH_H

#include "irangesearch.h"
#include "quadtree.h"

class QuadTreeRangeSearch : public IRangeSearch
{
private:
    QuadTree* tree;
public:
    QuadTreeRangeSearch();

    virtual void init(const QVector<QPointF>& points);
    virtual void search(QRectF r, QVector<QPointF>& result);

    virtual ~QuadTreeRangeSearch();
};

#endif // QUADTREERANGESEARCH_H
