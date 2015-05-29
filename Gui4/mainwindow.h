#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QVector>
#include <QPointF>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QDebug>
#include "beziercurve.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void paintEvent(QPaintEvent* e);

    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);

    void drawPoints(const QVector<QPointF>& pts, QColor c);
    void drawTangents(const QVector<QPointF>& pts, QColor c);

    ~MainWindow();

private slots:
    void on_pushButtonBuild_clicked();

    void on_pushButtonClear_clicked();

private:
    Ui::MainWindow *ui;

    QVector<QPointF> points;

    BezierCurve* bezierCurve;

    QVector<QPointF> line;
};

#endif // MAINWINDOW_H
