#include "widget.h"
#include "ui_widget.h"

#include <QMouseEvent>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    margin = 30;
    m = 5;
    n = 5;
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{


    int dy = (height() - 2 * margin) / m;
    int dx = (width() - 2 * margin) / n;



    QPainter p;
    p.begin(this);

    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::blue);
    p.setPen(pen);

    for(int x = margin,y = margin ; y < height() ; y += dy)
        p.drawLine(x,y,x + dx * n,y);

    for(int x = margin,y = margin ; x < width() ; x += dx)
        p.drawLine(x,y,x,y + dy * m);

    int nx = (clickX - margin) / dx;
    int ny = (clickY - margin) / dy;

    if(clickX >= margin && clickY >= margin && nx >= 0 && nx < n && ny >= 0 && ny < m)
        p.drawEllipse(QPoint(margin + dx / 2 + dx * nx,margin + dy / 2 + dy * ny),10,10);
    p.end();
}

void Widget::mouseReleaseEvent(QMouseEvent *me)
{
    clickX = me->x();
    clickY = me->y();
    update();
}
