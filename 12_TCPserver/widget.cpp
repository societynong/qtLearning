#include "widget.h"
#include "ui_widget.h"
#include <QTime>
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
        quint16 port = ptcpSocket->peerPort();
        ui->editSystem->append(QString("%1:").arg(QDateTime::currentDateTime().time().toString("hh:mm:ss")));
        ui->editSystem->append(QString("[%1:%2]:成功连接").arg(ip).arg(port));

        connect(ptcpSocket,&QTcpSocket::readyRead,[=]()
        {
            QByteArray qba = ptcpSocket->readAll();
            ui->editSystem->append(QString("%1:").arg(QDateTime::currentDateTime().time().toString("hh:mm:ss")));
            ui->editSystem->append(QString("%1").arg(QString(qba)));
        });

        connect(ptcpSocket,&QTcpSocket::disconnected,[=]() {
            ui->editSystem->append(QString("%1:").arg(QDateTime::currentDateTime().time().toString("hh:mm:ss")));
            ui->editSystem->append(QString("[%1:%2]:断开连接").arg(ip).arg(port));
        });

    });



}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_buttonSubmit_clicked()
{
    QString text = ui->editInput->toPlainText();

    ptcpSocket->write(text.toUtf8().data());

    ui->editInput->clear();

}

void Widget::on_buttonClear_clicked()
{
    if(!ptcpSocket)
        return;
    ptcpSocket->disconnectFromHost();
    ptcpSocket->close();
//    ui->editSystem->clear();
}
