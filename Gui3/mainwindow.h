#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRectF>
#include <QPen>
#include <QPainter>
#include <QColor>
#include <QMouseEvent>

#include "random.h"
#include "iclipping.h"
#include "liangbarskyclipping.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent* e);

    void drawLines(const QList<QLineF>& lines, QColor c, int width);
    void drawRect();

    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    ~MainWindow();

private slots:

    void on_lineEdit_returnPressed();

    void on_pushButtonClip_clicked();

    void on_pushButtonSelect_clicked();

private:
    Ui::MainWindow *ui;

    IClipping* algorithm;
    QList<QLineF> lines;

    QList<QLineF> clipped;

    QRectF area;

    bool select;
    QPoint begin;
    QPoint end;
};

#endif // MAINWINDOW_H
