#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    algorithm(nullptr),
    previousClick(-1, -1),
    rectangleSelected(false),
    paintRect(true),
    disp(0, 0),
    paintAllPoints(false)
{
    ui->setupUi(this);

    algorithm = new QuadTreeRangeSearch();
    algorithm->init(points);

//    MouseEventFilter* filter = new MouseEventFilter(this);
//    ui->centralWidget->installEventFilter(filter);
//    connect(filter, SIGNAL(mouseMoved(QPoint)), this, SLOT(onMouseMoved(QPoint)));
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    drawRectangle(field, Qt::red);
    if (paintAllPoints) {
        disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
        drawPoints(points, Qt::black);
    } //else {
//        disp = QPoint(0, 0);
        drawPoints(found, color);
    //}
}

void MainWindow::drawPoints(const std::vector<Point *>& points, QColor c) {
//    printf("count: %lf\n", points.size());
    QPainter painter(this);
    QPen pen(c);
    pen.setWidth(2);
    painter.setPen(pen);
    for (auto it = points.begin(); it != points.end(); ++it) {
        Point* p = *it;
        painter.drawPoint(p->x() + disp.x(), p->y() + disp.y());
    }
}

void MainWindow::drawRectangle(Rectangle r, QColor c)
{
    if (paintRect) {
        QPainter painter(this);
        QPen pen;
        pen.setColor(c);
        pen.setWidth(5);
        painter.setPen(pen);
        painter.drawLine(r.left() + disp.x(), r.top() + disp.y(), r.right() + disp.x(), r.top() + disp.y());//top line
        painter.drawLine(r.right() + disp.x(), r.top() + disp.y(), r.right() + disp.x(), r.bottom() + disp.y());//right line
        painter.drawLine(r.right() + disp.x(), r.bottom() + disp.y(), r.left() + disp.x(), r.bottom() + disp.y());//left line
        painter.drawLine(r.left() + disp.x(), r.bottom() + disp.y(), r.left() + disp.x(), r.top() + disp.y());//left line
    //    qDebug() << r.left() << r.top() << r.right() << r.bottom();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "press";
    if (!rectangleSelected) {
        disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
        beginSelect = e->pos() - disp;
    } else {
        beginMove = e->pos();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    qDebug() << "release";
    if (!rectangleSelected) {
        endSelect = e->pos() - disp;
        field = Rectangle(std::max(beginSelect.y(), endSelect.y()),
                          std::max(beginSelect.x(), endSelect.x()),
                          std::min(beginSelect.y(), endSelect.y()),
                          std::min(beginSelect.x(), endSelect.x()));
        rectangleSelected = true;
        search();
        repaintField = QRect(field.left(), field.bottom(), field.right() - field.left() + 1, field.top() - field.bottom() + 1);
        repaint(repaintField);
    } else {
        endMove = e->pos();
        search();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e) {
    qDebug() << "move";
    if (!rectangleSelected) {
        endSelect = e->pos() - disp;
        field = Rectangle(std::max(beginSelect.y(), endSelect.y()),
                          std::max(beginSelect.x(), endSelect.x()),
                          std::min(beginSelect.y(), endSelect.y()),
                          std::min(beginSelect.x(), endSelect.x()));
        repaintField = QRect(field.left(), field.bottom(), field.right() - field.left() + 1, field.top() - field.bottom() + 1);
//        paintAllPoints = true;
//        repaint(repaintField);
//        paintAllPoints = false;
    } else {
        endMove = e->pos();
    }
    search();

}

void MainWindow::search() {
    if (algorithm != nullptr) {
        found = algorithm->search(field);

        color = Qt::black;
        paintRect = false;
//        repaint(repaintField);
//        repaint();

        field = field + Point(endMove.x() - beginMove.x(), endMove.y() - beginMove.y());

        color = Qt::red;
        paintRect = true;
        repaintField.translate(endMove.x() - beginMove.x(), endMove.y() - beginMove.y());
//        repaint(repaintField);
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
    points = random.points(pointsAmount);
    algorithm->init(points);
    found.clear();
//    selected = false;
    paintAllPoints = true;
    repaint();
//    paintAllPoints = false;
}

void MainWindow::on_toolButton_clicked()
{
//    start = false;
    rectangleSelected = false;
    field = Rectangle();
//    repaint(repaintField);
    paintAllPoints = true;
    repaint();
    paintAllPoints = false;
}

void MainWindow::on_lineEditPoints_returnPressed()
{
    Random random;
    pointsAmount = ui->lineEditPoints->text().toInt();
    points = random.points(pointsAmount);
    algorithm->init(points);
    found.clear();
//    selected = false;
    on_toolButton_clicked();
    paintAllPoints = true;
    repaint();
    paintAllPoints = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}
