#ifndef QUADTREERANGESEARCH_H
#define QUADTREERANGESEARCH_H

#include "irangesearch.h"

class QuadTreeRangeSearch : IRangeSearch
{
private:

public:
    QuadTreeRangeSearch();

    virtual void init(std::vector<Point> points);

    virtual ~QuadTreeRangeSearch();
};

#endif // QUADTREERANGESEARCH_H
