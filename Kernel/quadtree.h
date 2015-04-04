#ifndef QUADTREE_H
#define QUADTREE_H

#include "quadtreenode.h"

constexpr double MIN_X = 0.0;
constexpr double MIN_Y = 0.0;
constexpr double MAX_X = 700;
constexpr double MAX_Y = 1200;

class QuadTree
{
public:
    QuadTree(const std::vector<Point*>& points);

    std::vector<Point*> query(Rectangle rectangle);

    ~QuadTree();
private:
    QuadTreeNode* root;
};

#endif // QUADTREE_H
