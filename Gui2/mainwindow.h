#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointF>
#include <QColor>
#include <QPainter>
#include <QPen>

#include "ihull.h"
#include "grahamhull.h"
#include "random.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void paintEvent(QPaintEvent* e);

    void drawPoints(const QList<QPointF>& points, QColor c);

    void drawHull(QColor c);

    ~MainWindow();

private slots:
    void on_lineEditPoints_returnPressed();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    IHull* algorithm;

    QList<QPointF> points;
    QList<QPointF> hull;
};

#endif // MAINWINDOW_H
