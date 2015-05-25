#ifndef ICLIPPING
#define ICLIPPING

#include <QRectF>
#include <QLineF>
#include <QList>

class IClipping {
public:
    IClipping() {}
    virtual bool clip(const QRectF& window, const QLineF& line, QLineF& clipped) = 0;
    virtual QList<QLineF> clip(const QRectF& window, const QList<QLineF>& lines) = 0;
    virtual ~IClipping() {}
};

#endif // ICLIPPING

