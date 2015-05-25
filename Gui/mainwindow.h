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
    void paintEvent(QPaintEvent *);
    void drawPoints(const std::vector<Point*>& points, QColor c);
    void drawRectangle(Rectangle r, QColor c);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    ~MainWindow();

private:
    void search();

private:
    Ui::MainWindow *ui;

    int pointsAmount;

    std::vector<Point*> points;
    std::vector<Point*> found;
    std::vector<Point*> prevFound;

    IRangeSearch* algorithm;
    Rectangle field;

    QRect repaintField;

    QPoint previousClick;

    QPoint beginSelect;
    QPoint endSelect;

    QPoint beginMove;
    QPoint endMove;
    QPoint pos;
    QColor color;
    bool paintRect;
    QPoint disp;

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
