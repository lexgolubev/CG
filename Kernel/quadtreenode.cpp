#include "quadtreenode.h"

QuadTreeNode::QuadTreeNode(Rectangle r, const std::vector<Point*>& points)
    : r(r), pts(points)
{
    this->son1 = nullptr;
    this->son2 = nullptr;
    this->son3 = nullptr;
    this->son4 = nullptr;

    if (points.size() > MAX_POINT_IN_RECTANGLE) {
        split();
    }
}

void QuadTreeNode::split()
{
    double midX = (r.getLeft() + r.getRight()) / 2;
    double midY = (r.getTop() + r.getBottom()) / 2;

    //order: top -> right -> bottom -> left
    Rectangle r1(r.getTop(), midX, midY, r.getLeft());
    Rectangle r2(r.getTop(), r.getRight(), midY, midX);
    Rectangle r3(midY, r.getRight(), r.getBottom(), midX);
    Rectangle r4(midY, midX, r.getBottom(), r.getLeft());

    std::vector<Point*> pts1;
    std::vector<Point*> pts2;
    std::vector<Point*> pts3;
    std::vector<Point*> pts4;

    for (auto it = pts.begin(); it != pts.end(); ++it) {
        if (r1.locationOfPoint(*it) != Location::OUTSIDE) {
            pts1.push_back(*it);
        } else if (r2.locationOfPoint(*it) != Location::OUTSIDE) {
            pts2.push_back(*it);
        } else if (r3.locationOfPoint(*it) != Location::OUTSIDE) {
            pts3.push_back(*it);
        } else if (r4.locationOfPoint(*it) != Location::OUTSIDE) {
            pts4.push_back(*it);
        }
    }

    son1 = new QuadTreeNode(r1, pts1);
    son2 = new QuadTreeNode(r2, pts2);
    son3 = new QuadTreeNode(r3, pts3);
    son4 = new QuadTreeNode(r4, pts4);
}

std::vector<Point*> QuadTreeNode::query(Rectangle rectangle)
{
    std::vector<Point*> result;
    Intersection intersection = r.intersection(rectangle);
    if (intersection == Intersection::NONE) {
        return result;
    }
    if (son1 == nullptr || son2 == nullptr || son3 == nullptr || son4 == nullptr) {
        if (intersection == Intersection::CONTAINS) {
            result.insert(result.end(), pts.begin(), pts.end());
        } else if (intersection == Intersection::PART) {
            for (auto it = pts.begin(); it != pts.end(); ++it) {
                if (rectangle.locationOfPoint(*it) != Location::OUTSIDE) {
                    result.push_back(*it);
                }
            }
        }
    } else {
        Rectangle r1 = son1->r.intersect(rectangle);
        Rectangle r2 = son2->r.intersect(rectangle);
        Rectangle r3 = son3->r.intersect(rectangle);
        Rectangle r4 = son4->r.intersect(rectangle);
        auto pts1 = son1->query(r1);
        auto pts2 = son2->query(r2);
        auto pts3 = son3->query(r3);
        auto pts4 = son4->query(r4);
        result.insert(result.end(), pts1.begin(), pts1.end());
        result.insert(result.end(), pts2.begin(), pts2.end());
        result.insert(result.end(), pts3.begin(), pts3.end());
        result.insert(result.end(), pts4.begin(), pts4.end());
    }
    return result;
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

