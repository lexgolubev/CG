#ifndef LINEARRANGESEARCH_H
#define LINEARRANGESEARCH_H

#include "irangesearch.h"

class LinearRangeSearch : public IRangeSearch
{
public:
    LinearRangeSearch();

    virtual void init(const std::vector<Point *> &points);
    virtual std::vector<Point*> search(Rectangle r);

    ~LinearRangeSearch();

private:
    std::vector<Point*> points;
};

#endif // LINEARRANGESEARCH_H
