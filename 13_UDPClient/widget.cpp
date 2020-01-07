#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::Widget(quint16 port):ui(new Ui::Widget)
{
    ui->setupUi(this);
    pudpSocketReceiver = new QUdpSocket(this);
    pudpSocketSender = new QUdpSocket(this);
    pudpSocketReceiver->bind(QHostAddress("127.0.0.1"),port);
    connect(pudpSocketReceiver,&QUdpSocket::readyRead,[=](){
        char buf[1024];
        QHostAddress peerAddr;
        quint16 peerPort;
        quint16 len = pudpSocketReceiver->readDatagram(buf,sizeof(buf),&peerAddr,&peerPort);
        if(len <= 0)
            return;
        QString str = QString("[%1:%2]:%3").arg(peerAddr.toString()).arg(peerPort).arg(buf);
        ui->editRead->append(str);

    });

    setWindowTitle(QString::number(port));


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonSend_clicked()
{
    QString ip = ui->lineIP->text();
    quint16 port = quint16(ui->linePort->text().toUInt());
    if(port < 1024 || port > 65535)
        return;
//    pudpSocketSender->bind(QHostAddress(ip),port);

    QString contents = ui->editWrite->toPlainText();
//    pudpSocketSender->write(contents.toUtf8().data());
    pudpSocketSender->writeDatagram(contents.toUtf8(),QHostAddress(ip),port);
}
