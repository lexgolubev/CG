#ifndef QUADTREE_H
#define QUADTREE_H

#include "quadtreenode.h"

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
