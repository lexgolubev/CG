#include "quadtreerangesearch.h"

QuadTreeRangeSearch::QuadTreeRangeSearch() : IRangeSearch()
{

}

void QuadTreeRangeSearch::init(const std::vector<Point*>& points) {
    tree = new QuadTree(points);
}

std::vector<Point*> QuadTreeRangeSearch::search(Rectangle r) {
    return tree->query(r);
}

QuadTreeRangeSearch::~QuadTreeRangeSearch()
{
    delete tree;
}

