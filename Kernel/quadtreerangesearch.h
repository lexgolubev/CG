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

    virtual void init(const std::vector<Point*>& points);
    virtual std::vector<Point*> search(Rectangle r);

    virtual ~QuadTreeRangeSearch();
};

#endif // QUADTREERANGESEARCH_H
