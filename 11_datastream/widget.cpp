#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    readData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeData()
{
    QString path = "../xxx.txt";
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly))
        return;

    QDataStream qds(&file);

    qds << QString("123");

    file.close();
}

void Widget::readData()
{
    QString path = "../xxx.txt";
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly))
        return;

    QDataStream qds(&file);

    QString str;
    qds >> str;

    qDebug() << str;

    file.close();
}

