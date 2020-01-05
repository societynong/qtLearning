#ifndef WIDGET_H
#define WIDGET_H

#include "subwidget.h"

#include <QPushButton>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void mySlot();
    void changeWindow();
    void subChangeWindow();
private:
    QPushButton btn1;
    QPushButton *btn2;
    QPushButton btn3;
    SubWidget sw;
};

#endif // WIDGET_H
