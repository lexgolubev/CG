#ifndef QUADTREE_H
#define QUADTREE_H

#include <QDebug>
#include "quadtreenode.h"

class QuadTree
{
public:
    QuadTree(const QVector<QPointF>& points);

    void query(QRectF rectangle, QVector<QPointF>& result);

    ~QuadTree();
private:
    QuadTreeNode* root;
};

#endif // QUADTREE_H
