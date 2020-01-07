#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_openButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"Open File","../","Text (*.txt *.cpp)");

    if(filePath.isEmpty())
        return;

    QFile file(filePath);
    QFileInfo qfi(file);
    qDebug() << QString("File Name:%1, File Size:%2, File Type:%3").arg(qfi.baseName()).arg(qfi.size()).arg(qfi.suffix());
    if(!file.open(QIODevice::ReadOnly))
        return;
    QByteArray qba = file.readAll();

    ui->textEdit->setText(qba);
    file.close();

}

void Widget::on_saveButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this,"Save File","../","Text (*.txt)");

    if(filePath.isEmpty())
        return;
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly))
        return;

    QByteArray qba = ui->textEdit->toPlainText().toUtf8();
    file.write(qba);

    file.close();
}
