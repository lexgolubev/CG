#include "liangbarskyclipping.h"

LiangBarskyClipping::LiangBarskyClipping()
{

}

QList<QLineF> LiangBarskyClipping::clip(const QRectF& window, const QList<QLineF>& lines) {
    QList<QLineF> result;
    foreach (QLineF line, lines) {
        QLineF clipped;
        if (clip(window, line, clipped)) {
            result.push_back(clipped);
        }
    }
    return result;
}

bool LiangBarskyClipping::clip(const QRectF& window, const QLineF& line, QLineF& clipped) {
    qreal tMin = 0.0;
    qreal tMax = 1.0;

    qreal m[4];
    m[0] = line.x1() - line.x2();
    m[1] = -m[0];
    m[2] = line.y1() - line.y2();
    m[3] = -m[2];

    qreal c[4];
    c[0] = line.x1() - window.left();
    c[1] = window.right() - line.x1();
    c[2] = line.y1() - window.top();
    c[3] = window.bottom() - line.y1();

    for (int i = 0; i < 4; i++) {
        if (!rangeTest(m[i], c[i], tMin, tMax)) {
            return false;
        }
//        rangeTest(m[i], c[i], tMin, tMax);
    }
    clipped.setLine((line.x2() - line.x1()) * tMin + line.x1(),
                    (line.y2() - line.y1()) * tMin + line.y1(),
                    (line.x2() - line.x1()) * tMax + line.x1(),
                    (line.y2() - line.y1()) * tMax + line.y1());
    return true;
}

bool LiangBarskyClipping::rangeTest(qreal m, qreal c, qreal& tMin, qreal& tMax) {
    if (m > 0) {
        qreal b = c / m;
        if (b <= tMin) {
            return false;
        } else if (b >= tMax) {
            return true;
        } else {
            tMax = b;
            return true;
        }
    } else if (m < 0) {
        qreal b = c / m;
        if (b <= tMin) {
            return true;
        } else if (b >= tMax) {
            return false;
        } else {
            tMin = b;
            return true;
        }
    } else {
        if (c <= 0) {
            return false;
        } else {
            return true;
        }
    }
}

LiangBarskyClipping::~LiangBarskyClipping()
{

}

