#ifndef LIANGBARSKYCLIPPING_H
#define LIANGBARSKYCLIPPING_H

#include "iclipping.h"

class LiangBarskyClipping : public IClipping
{
public:
    LiangBarskyClipping();
    virtual bool clip(const QRectF& window, const QLineF& line, QLineF& clipped);
    virtual QList<QLineF> clip(const QRectF& window, const QList<QLineF>& lines);
    virtual ~LiangBarskyClipping();
private:
    bool rangeTest(qreal m, qreal c, qreal& tMin, qreal& tMax);
private:
    qreal t;
};

#endif // LIANGBARSKYCLIPPING_H
