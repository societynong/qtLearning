#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void sendSlot();
signals:
    void mySwitch();
public slots:
    void changeWindow();
private:
    QPushButton btn1;
};

#endif // SUBWIDGET_H
