#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *pMenuBar = menuBar();
    QMenu *pMenu = pMenuBar->addMenu("Dialog");
    QAction *p1 = pMenu->addAction("modeled diag");
    QAction *p2 = pMenu->addAction("unmodeled diag");
    QAction *p3 = pMenu->addAction("about");
    QAction *p4 = pMenu->addAction("qabout");
    QAction *p5 = pMenu->addAction("file diag");
    connect(p1,&QAction::triggered,[=]()
    {
        QDialog dlg;
        dlg.exec();
    });

    connect(p2,&QAction::triggered,[=]()
    {
        QDialog *pDlg = new QDialog(this);
        pDlg->show();

    });

    connect(p3,&QAction::triggered,[this]()
    {
       QMessageBox::about(this,"about","xxx") ;
    });

    connect(p4,&QAction::triggered,[this]()
    {
       int ret = QMessageBox::question(this,"Question","R U O K?");
       switch (ret) {
       case QMessageBox::Yes:
           qDebug() << "Yes";
           break;
       case QMessageBox::No:
           qDebug() << "No";
           break;
       }
    });

    connect(p5, &QAction::triggered,[this]()
    {
        QString path = QFileDialog::getOpenFileName(this,"open","../",
                                                    "source(*.cpp *.h);;text(*.txt);;all(*.*)");
        qDebug() << path;
    });

}

MainWindow::~MainWindow()
{

}
