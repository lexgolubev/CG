#ifndef MOUSEEVENTFILTER_H
#define MOUSEEVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QMouseEvent>

class MouseEventFilter : public QObject
{
    Q_OBJECT

public:
    MouseEventFilter(QObject* parent = 0);

    bool eventFilter(QObject *, QEvent *e);

    ~MouseEventFilter();

signals:
    void mouseMoved(QPoint location);
};

#endif // MOUSEEVENTFILTER_H
