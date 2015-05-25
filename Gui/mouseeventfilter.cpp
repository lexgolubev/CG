#include "mouseeventfilter.h"

MouseEventFilter::MouseEventFilter(QObject* parent) : QObject(parent)
{

}

bool MouseEventFilter::eventFilter(QObject *, QEvent *e) {
    if (e->type() == QEvent::MouseMove)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(e);
        emit mouseMoved(mouseEvent->pos());
    }
    return false;
}

MouseEventFilter::~MouseEventFilter()
{

}

