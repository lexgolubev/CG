#ifndef GRAHAMHULL_H
#define GRAHAMHULL_H

#include <ihull.h>
#include <QtAlgorithms>
#include <QQueue>

class GrahamHull : public IHull
{
public:
    GrahamHull();

    virtual QList<QPointF> build(const QList<QPointF> &points);

    virtual ~GrahamHull();

private:
    bool rightTurn(const QPointF& p1, const QPointF& p2, const QPointF& p3);

private:
    QPointF left;
};

#endif // GRAHAMHULL_H
