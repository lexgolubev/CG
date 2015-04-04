#ifndef QUADTREENODE_H
#define QUADTREENODE_H

#include <vector>
#include "point.h"
#include "rectangle.h"

constexpr int MAX_POINT_IN_RECTANGLE = 5;

class QuadTreeNode
{
public:
    QuadTreeNode(Rectangle r, const std::vector<Point*>& points);

    std::vector<Point*> query(Rectangle rectangle);

    ~QuadTreeNode();

public:
    QuadTreeNode* son1;
    QuadTreeNode* son2;
    QuadTreeNode* son3;
    QuadTreeNode* son4;

private:
    void split();

private:
    Rectangle r;
    std::vector<Point*> pts;
};

#endif // QUADTREENODE_H
