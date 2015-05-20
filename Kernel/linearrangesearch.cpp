#include "linearrangesearch.h"

LinearRangeSearch::LinearRangeSearch()
{

}

void LinearRangeSearch::init(const std::vector<Point *> &points)
{
    this->points.insert(this->points.end(), points.begin(), points.end());
}

std::vector<Point*> LinearRangeSearch::search(Rectangle r)
{
    std::vector<Point*> found;
    for (auto it = points.begin(); it != points.end(); ++it) {
        if (r.locationOfPoint(*it) != Location::OUTSIDE) {
            found.push_back(*it);
        }
    }
    return found;
}

LinearRangeSearch::~LinearRangeSearch()
{
    points.clear();
}

