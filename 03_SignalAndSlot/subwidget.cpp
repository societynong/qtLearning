#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("DiDi");
    resize(800,600);
    btn1.setParent(this);
    btn1.setText("Switch");
    btn1.show();

    connect(&btn1,&QPushButton::released, this, &SubWidget::changeWindow);
}

void SubWidget::sendSlot()
{
    emit mySwitch();
    emit mySignal(111,"木哈哈哈");
}

void SubWidget::changeWindow()
{
    sendSlot();
}
