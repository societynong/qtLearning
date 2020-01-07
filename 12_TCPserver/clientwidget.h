#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void on_buttonConnect_clicked();

    void on_buttonSubmit_clicked();

    void on_buttonClear_clicked();

private:
    Ui::ClientWidget *ui;
    QTcpSocket *ptcpSocket;
};

#endif // CLIENTWIDGET_H
