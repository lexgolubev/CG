#ifndef QUADTREENODE_H
#define QUADTREENODE_H

#include <vector>
#include "point.h"
#include "rectangle.h"

#include <QVector>
#include <QPointF>
#include <QRectF>

class QuadTreeNode
{
public:
    static constexpr int DEFAULT_LOAD_FACTOR = 5;
public:
    QuadTreeNode(QRectF r);

    void init(const QVector<QPointF>& points);

    void query(QRectF rectangle, QVector<QPointF>& result);

    void setLoadFactor(int value = DEFAULT_LOAD_FACTOR);

    ~QuadTreeNode();

public:
    QuadTreeNode* son1;
    QuadTreeNode* son2;
    QuadTreeNode* son3;
    QuadTreeNode* son4;

private:
    void split();

public:
    static int loadFactor;
    QRectF r;
    QVector<QPointF> pts;
};

#endif // QUADTREENODE_H
