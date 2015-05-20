#ifndef IHULL
#define IHULL

#include <QList>
#include <QPointF>

class IHull {
public:
    IHull() {}

    virtual QList<QPointF> build(const QList<QPointF>& points) = 0;

    virtual ~IHull() {}
};

#endif // IHULL

