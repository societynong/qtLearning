#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ptcpServer = new QTcpServer(this);
    ptcpServer->listen(QHostAddress::Any,8899);
    connect(ptcpServer,&QTcpServer::newConnection,[=]()
    {
        ptcpSocket = ptcpServer->nextPendingConnection();

        QString ip = ptcpSocket->peerAddress().toString();
        qint16 port = ptcpSocket->peerPort();

        ui->editSystem->setText(QString("[%1:%2]:成功连接").arg(ip).arg(port));

    });
}

Widget::~Widget()
{
    delete ui;
}

