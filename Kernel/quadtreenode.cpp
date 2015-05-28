#include "quadtreenode.h"

int QuadTreeNode::loadFactor;

QuadTreeNode::QuadTreeNode(QRectF r)
    : r(r)
{
    this->son1 = nullptr;
    this->son2 = nullptr;
    this->son3 = nullptr;
    this->son4 = nullptr;
}

void QuadTreeNode::init(const QVector<QPointF>& points) {
    pts = points;
    if (points.size() > loadFactor) {
        split();
    }
}

void QuadTreeNode::split()
{
    double midX = (r.left() + r.right()) / 2;
    double midY = (r.top() + r.bottom()) / 2;

    QRectF r1(QPointF(r.left(), r.top()), QPointF(midX, midY));
    QRectF r2(QPointF(midX, r.top()), QPointF(r.right(), midY));
    QRectF r3(QPointF(r.left(), midY), QPointF(midX, r.bottom()));
    QRectF r4(QPointF(midX, midY), QPointF(r.right(), r.bottom()));

    QVector<QPointF> pts1;
    QVector<QPointF> pts2;
    QVector<QPointF> pts3;
    QVector<QPointF> pts4;

    foreach (QPointF p, pts) {
        if (r1.contains(p)) {
            pts1.push_back(p);
        } else if (r2.contains(p)) {
            pts2.push_back(p);
        } else if (r3.contains(p)) {
            pts3.push_back(p);
        } else if (r4.contains(p)) {
            pts4.push_back(p);
        }
    }

    son1 = new QuadTreeNode(r1);
    son1->init(pts1);
    son2 = new QuadTreeNode(r2);
    son2->init(pts2);
    son3 = new QuadTreeNode(r3);
    son3->init(pts3);
    son4 = new QuadTreeNode(r4);
    son4->init(pts4);
}

void QuadTreeNode::query(QRectF rectangle, QVector<QPointF>& result)
{
    result.clear();
    if (!r.intersects(rectangle)) {
        return;
    }
    if (son1 == nullptr || son2 == nullptr || son3 == nullptr || son4 == nullptr) {
        if (rectangle.contains(r)) {
            result += pts;
        } else {
            foreach (QPointF p, pts) {
                if (rectangle.contains(p)) {
                    result.push_back(p);
                }
            }
        }
    } else {
        QRectF r1 = son1->r.intersected(rectangle);
        QRectF r2 = son2->r.intersected(rectangle);
        QRectF r3 = son3->r.intersected(rectangle);
        QRectF r4 = son4->r.intersected(rectangle);
        QVector<QPointF> pts1;
        QVector<QPointF> pts2;
        QVector<QPointF> pts3;
        QVector<QPointF> pts4;
        son1->query(r1, pts1);
        son2->query(r2, pts2);
        son3->query(r3, pts3);
        son4->query(r4, pts4);
        result += pts1;
        result += pts2;
        result += pts3;
        result += pts4;
    }
}

void QuadTreeNode::setLoadFactor(int value) {
    loadFactor = value;
}

QuadTreeNode::~QuadTreeNode()
{
    if (son1 != nullptr) {
        delete son1;
    }
    if (son2 != nullptr) {
        delete son2;
    }
    if (son3 != nullptr) {
        delete son3;
    }
    if (son4 != nullptr) {
        delete son4;
    }
}

