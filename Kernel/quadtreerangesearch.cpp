#include "quadtreerangesearch.h"

QuadTreeRangeSearch::QuadTreeRangeSearch() : IRangeSearch()
{

}

void QuadTreeRangeSearch::init(const QVector<QPointF>& points) {
    tree = new QuadTree(points);
}

void QuadTreeRangeSearch::search(QRectF r, QVector<QPointF>& result) {
    tree->query(r, result);
}

QuadTreeRangeSearch::~QuadTreeRangeSearch()
{
    delete tree;
}

