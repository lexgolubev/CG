#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QRect>
#include <QDebug>
#include <QRectF>
#include <QPen>
#include "random.h"
#include "rectangle.h"
#include "quadtreerangesearch.h"
#include "linearrangesearch.h"
#include "mouseeventfilter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void drawPoints(const QVector<QPointF>& points, QColor c);
    void drawRectangle(QRectF r, QColor c);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);

    ~MainWindow();

private:
    void search();

private:
    Ui::MainWindow *ui;

    int pointsAmount;

    QVector<QPointF> points;
    QVector<QPointF> found;

    IRangeSearch* algorithm;
    QRectF field;

    QPoint beginSelect;
    QPoint endSelect;

    QPoint beginMove;
    QPoint endMove;

    QColor color;
    QPoint disp;

    bool paintRect;
    bool rectangleSelected;
    bool paintAllPoints;

private slots:
    void on_radioButtonQuadTree_clicked();
    void on_radioButtonLinear_clicked();
    void on_pushButtonInit_clicked();
    void on_toolButton_clicked();
    void on_lineEditPoints_returnPressed();
};

#endif // MAINWINDOW_H
