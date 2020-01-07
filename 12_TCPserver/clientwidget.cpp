#include "clientwidget.h"
#include "ui_clientwidget.h"

#include <QTime>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    ptcpSocket = new QTcpSocket(this);
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_buttonConnect_clicked()
{
    QString ip = ui->editIP->text();
    quint16 port = quint16(ui->editPort->text().toUInt());
    ptcpSocket->connectToHost(ip,port);
    connect(ptcpSocket,&QTcpSocket::readyRead,[=](){
        QByteArray qba = ptcpSocket->readAll();
        ui->editSystem->append(QString("%1:").arg(QDateTime::currentDateTime().time().toString("hh:mm:ss")));
        ui->editSystem->append(QString("%1").arg(QString(qba)));
    });
    connect(ptcpSocket,&QTcpSocket::disconnected,[=]() {
        ui->editSystem->append(QString("%1:").arg(QDateTime::currentDateTime().time().toString("hh:mm:ss")));
        ui->editSystem->append(QString("[%1:%2]:断开连接").arg(ip).arg(port));
    });

}

void ClientWidget::on_buttonSubmit_clicked()
{
    if(!ptcpSocket)
        return;
    QString text = ui->editInput->toPlainText();
    ptcpSocket->write(text.toUtf8().data());
    ui->editInput->clear();


}

void ClientWidget::on_buttonClear_clicked()
{
    if(!ptcpSocket)
        return;
    ptcpSocket->close();

}
