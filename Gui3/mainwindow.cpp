#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    algorithm = new LiangBarskyClipping();

//    area = QRectF(100, 100, 200, 200);
}

void MainWindow::paintEvent(QPaintEvent *e) {
    drawLines(lines, Qt::black, 1);
//    if (select) {
        drawLines(clipped, Qt::red, 3);
//    }
    drawRect();
}

void MainWindow::drawLines(const QList<QLineF>& lines, QColor c, int width) {
    if (lines.size() <= 0) {
        return;
    }
    QPoint disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
    QPainter painter(this);
    QPen pen(c);
    pen.setWidth(width);
    painter.setPen(pen);
    foreach (QLineF line, lines) {
        painter.drawLine(line.translated(disp));
    }
}

void MainWindow::drawRect() {
    QPoint disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
    QPainter painter(this);
    QPen pen(Qt::red);
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawRect(area.translated(disp));
}

void MainWindow::on_lineEdit_returnPressed()
{
    Random random;
    lines = random.qlines(ui->lineEdit->text().toInt());
    clipped = algorithm->clip(area, lines);
    repaint();
}

void MainWindow::mousePressEvent(QMouseEvent *e) {
    if (!select) {
        QPoint disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
        begin = e->pos() - disp;
        on_pushButtonSelect_clicked();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e) {
    if (!select) {
        QPoint disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
        end = e->pos() - disp;
        area = QRectF(begin, end);
//        select = true;
        repaint();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e) {
    if (!select) {
        QPoint disp = ui->widget->parentWidget()->mapToParent(ui->widget->mapToParent(QPoint(0, 0)));
        end = e->pos() - disp;
        area = QRectF(begin, end);
//        select = true;
        on_pushButtonClip_clicked();
        repaint();
    }
}

void MainWindow::on_pushButtonClip_clicked()
{
//    Random random;
//    lines = random.qlines(ui->lineEdit->text().toInt());
    clipped = algorithm->clip(area, lines);
    repaint();
}

void MainWindow::on_pushButtonSelect_clicked()
{
    select = false;
    area = QRectF();
    clipped.clear();
    repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}
