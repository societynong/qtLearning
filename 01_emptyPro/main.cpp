#include <QApplication>

#include <QPushButton>
#include <QWidget>


int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    QWidget w;
    w.show();


    QPushButton btn(&w);
    btn.setText("Click Me");
    btn.move((w.width() - btn.width()) / 2,(w.height() - btn.height()) / 2);
    btn.show();
    app.exec();
    return 0;
}




