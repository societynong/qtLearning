#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(1024,768);
    this->setWindowTitle("Boss");
    btn1.setParent(this);
    btn1.setText("^-^");
    btn1.move(100,100);
    btn1.show();
    /* &btn1:信号发出者
     * &QPushButton::pressed:发出的信号
     * this:信号处理者
     * &Widget::close:信号处理函数
     * */
    connect(&btn1, &QPushButton::pressed,this, &Widget::close);

    /* 自定义槽
     * 可以为任意成员函数，可以为普通函数，静态函数。
     * 需要和信号一致，参数以及返回值需要一致，由于信号没有返回值，所以槽函数也没有返回值。
     */
    btn2 = new QPushButton(this);
    btn2->show();
    connect(btn2, &QPushButton::released, &btn1, &QPushButton::hide);

    btn3.setParent(this);
    btn3.setText("Switch");
    btn3.move(50,50);
    btn3.show();
    connect(&btn3, &QPushButton::released, this, &Widget::changeWindow);
    connect(&sw, &SubWidget::mySwitch, this, &Widget::subChangeWindow);
    void (SubWidget::*pSigPara)(int, QString) = &SubWidget::mySignal;
    connect(&sw, pSigPara, this, &Widget::dealSlot);
//    sw.show();
}

Widget::~Widget()
{

}

void Widget::mySlot()
{
    btn2->setText("1");
}

void Widget::changeWindow()
{
    sw.show();
    hide();
}

void Widget::subChangeWindow()
{
    sw.hide();
    show();
}

void Widget::dealSlot(int i, QString str)
{
    qDebug() << i << " " << str;
}
