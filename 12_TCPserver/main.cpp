#include "widget.h"
#include "clientwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    ClientWidget client;
    client.show();
    return a.exec();
}
