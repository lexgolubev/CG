#ifndef QUADTREENODE_H
#define QUADTREENODE_H

#include <vector>
#include "point.h"
#include "rectangle.h"

class QuadTreeNode
{
public:
    static constexpr int DEFAULT_LOAD_FACTOR = 5;
public:
    QuadTreeNode(Rectangle r);

    void init(const std::vector<Point*>& points);

    std::vector<Point*> query(Rectangle rectangle);

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
    Rectangle r;
    std::vector<Point*> pts;
};

#endif // QUADTREENODE_H
