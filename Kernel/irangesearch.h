#ifndef I_RANGE_SEARCH
#define I_RANGE_SEARCH

#include <vector>
#include <point.h>
#include <rectangle.h>

class IRangeSearch
{
public:
    virtual void init(std::vector<Point> points) = 0;
    virtual std::vector<Point> search(Rectangle r);
    virtual ~IRangeSearch() {}
};

#endif // I_RANGE_SEARCH

