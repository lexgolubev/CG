#include "quadtree.h"

QuadTree::QuadTree(const QVector<QPointF>& points)
{
    QRectF r(QPointF(MIN_X, MIN_Y), QPointF(MAX_X, MAX_Y));
    root = new QuadTreeNode(r);
    root->setLoadFactor(100);
    root->init(points);
}

void QuadTree::query(QRectF rectangle, QVector<QPointF>& result)
{
    return root->query(rectangle, result);
}

QuadTree::~QuadTree()
{
    delete root;
}

