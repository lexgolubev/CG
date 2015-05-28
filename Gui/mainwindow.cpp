#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    algorithm(nullptr),
    rectangleSelected(false),
    paintAllPoints(false),
    paintRect(true),
    disp(0, 0)
{
    ui->setupUi(this);

    algorithm = new QuadTreeRangeSearch();
    algorithm->init(points);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    drawRectangle(field, Qt::red);
    drawPoints(found, color);
    if (paintAllPoints) {
        disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
        drawPoints(points, Qt::black);
    }
}

void MainWindow::drawPoints(const QVector<QPointF>& points, QColor c) {
    QPainter painter(this);
    QPen pen(c);
    pen.setWidth(2);
    painter.setPen(pen);
    foreach (QPointF p, points) {
        painter.drawPoint(p.x() + disp.x(), p.y() + disp.y());
    }
}

void MainWindow::drawRectangle(QRectF r, QColor c)
{
    if (paintRect) {
        QPainter painter(this);
        QPen pen;
        pen.setColor(c);
        pen.setWidth(5);
        painter.setPen(pen);
        painter.drawRect(r.translated(disp));
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if (!rectangleSelected) {
        disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
        beginSelect = e->pos() - disp;
    } else {
        beginMove = e->pos();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if (!rectangleSelected) {
        endSelect = e->pos() - disp;
        field = QRectF(beginSelect, endSelect);
        rectangleSelected = true;
        search();
        repaint();
    } else {
        endMove = e->pos();
        search();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e) {
    if (!rectangleSelected) {
        endSelect = e->pos() - disp;
        field = QRectF(beginSelect, endSelect);
    } else {
        endMove = e->pos();
        field.translate(endMove - beginMove);
    }
    search();

}

void MainWindow::search() {
    if (algorithm != nullptr) {
        algorithm->search(field, found);

        color = Qt::red;
        paintRect = true;
        repaint();

        beginMove = endMove;
    }
}

void MainWindow::on_radioButtonQuadTree_clicked()
{
    delete algorithm;
    algorithm = nullptr;
    algorithm = new QuadTreeRangeSearch();
    algorithm->init(points);
}

void MainWindow::on_radioButtonLinear_clicked()
{
    delete algorithm;
    algorithm = nullptr;
    algorithm = new LinearRangeSearch();
    algorithm->init(points);
}

void MainWindow::on_pushButtonInit_clicked()
{
    Random random;
    pointsAmount = ui->lineEditPoints->text().toInt();
    points = random.qpoints_vector(pointsAmount);
    algorithm->init(points);
    found.clear();
    paintAllPoints = true;
    repaint();
}

void MainWindow::on_toolButton_clicked()
{
    found.clear();
    rectangleSelected = false;
    field = QRectF();
    paintAllPoints = true;
    repaint();
    paintAllPoints = false;
}

void MainWindow::on_lineEditPoints_returnPressed()
{
    Random random;
    pointsAmount = ui->lineEditPoints->text().toInt();
    points = random.qpoints_vector(pointsAmount);
    algorithm->init(points);
    on_toolButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}
