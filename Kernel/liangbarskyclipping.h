#ifndef LIANGBARSKYCLIPPING_H
#define LIANGBARSKYCLIPPING_H

#include "iclipping.h"

class LiangBarskyClipping : public IClipping
{
public:
    LiangBarskyClipping();
    virtual bool clip(const QRectF& window, const QLineF& line, QLineF& clipped);
    bool rangeTest(qreal m, qreal c, qreal& tMin, qreal& tMax);
    virtual ~LiangBarskyClipping();
private:
    qreal t;
};

#endif // LIANGBARSKYCLIPPING_H
