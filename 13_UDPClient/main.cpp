#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w1(8888);
    Widget w2(9999);
    w1.show();
    w2.show();

    return a.exec();
}
