#ifndef I_RANGE_SEARCH
#define I_RANGE_SEARCH

#include <QPointF>
#include <QRectF>
#include <QVector>

class IRangeSearch
{
public:
    IRangeSearch() {}
    virtual void init(const QVector<QPointF>& points) = 0;
    virtual void search(QRectF r, QVector<QPointF>& result) = 0;
    virtual ~IRangeSearch() {}
};

#endif // I_RANGE_SEARCH

