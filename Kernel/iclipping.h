#ifndef ICLIPPING
#define ICLIPPING

#include <QRectF>
#include <QLineF>

class IClipping {
public:
    IClipping() {}
    virtual bool clip(const QRectF& window, const QLineF& line, QLineF& clipped) = 0;
    virtual ~IClipping() {}
};

#endif // ICLIPPING

