#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    algorithm = new GrahamHull();
}

void MainWindow::paintEvent(QPaintEvent *e) {
    drawPoints(points, Qt::black);
    drawHull(Qt::red);
}

void MainWindow::drawPoints(const QList<QPointF>& points, QColor c) {
    QPoint disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
    QPainter painter(this);
    QPen pen(c);
    pen.setWidth(2);
    painter.setPen(pen);
    foreach (QPointF p, points) {
        painter.drawPoint(p.x() + disp.x(), p.y() + disp.y());
    }
}

void MainWindow::drawHull(QColor c) {
    if (hull.size() <= 0) {
        return;
    }
    QPoint disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
    QPainter painter(this);
    painter.setPen(QPen(c));
    QPointF first = hull[0];
    QPointF last = hull[0];
    foreach (QPointF p, hull) {
        painter.drawLine(last + disp, p + disp);
        last = p;
    }
    painter.drawLine(last + disp, first + disp);
}

void MainWindow::on_lineEditPoints_returnPressed()
{
    Random random;
    points = random.qpoints(ui->lineEditPoints->text().toInt());
    hull = algorithm->build(points);
    repaint();
}

void MainWindow::on_pushButton_clicked()
{
    Random random;
    points = random.qpoints(ui->lineEditPoints->text().toInt());
    hull = algorithm->build(points);
    repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}
