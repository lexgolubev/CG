#include "quadtree.h"

QuadTree::QuadTree(const std::vector<Point*>& points)
{
    Rectangle r(MAX_Y, MAX_X, MIN_Y, MIN_X);
    root = new QuadTreeNode(r, points);
}

std::vector<Point*> QuadTree::query(Rectangle rectangle)
{
    return root->query(rectangle);
}

QuadTree::~QuadTree()
{
    delete root;
}

