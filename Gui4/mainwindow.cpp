#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *e) {
    drawPoints(line, Qt::red);
    drawPoints(points, Qt::black);
//    drawTangents(points, Qt::blue);
}

void MainWindow::drawPoints(const QVector<QPointF>& pts, QColor c) {
    QPoint disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
    QPainter painter(this);
    QPen pen(c);
    pen.setWidth(2);
    painter.setPen(pen);
    foreach (QPointF p, pts) {
        painter.drawPoint(p + disp);
    }
}

void MainWindow::drawTangents(const QVector<QPointF> &pts, QColor c) {
    QPoint disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
    QPainter painter(this);
    QPen pen(c);
    pen.setWidth(2);
    painter.setPen(pen);
    for (int i = 1; i < pts.size(); i++) {
        painter.drawLine(pts[i] + disp, pts[i - 1] + disp);
    }
}

void MainWindow::mousePressEvent(QMouseEvent* e) {
//    qDebug() << e->pos();
    QPoint disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
    points.push_back(e->pos() - disp);
    repaint();
}

void MainWindow::mouseMoveEvent(QMouseEvent* e) {

}

void MainWindow::mouseReleaseEvent(QMouseEvent* e) {

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonBuild_clicked()
{
    line.clear();
    bezierCurve = new BezierCurve(points);
    int stepCount = 1000;
    qreal step = 1.0 / stepCount;
    for (int i = 0; i < stepCount; i++) {
        line.push_back(bezierCurve->at(step * i));
    }
    repaint();
}

void MainWindow::on_pushButtonClear_clicked()
{
    line.clear();
    points.clear();
    repaint();
}
