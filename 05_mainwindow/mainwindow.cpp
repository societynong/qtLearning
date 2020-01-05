#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,600);
    // Menu Bar
    QMenuBar *mBar = menuBar();
    QMenu *pFile = mBar->addMenu("文件");
    QAction *pNew = pFile->addAction("新建");
    connect(pNew,&QAction::triggered,
            []()
            {
                qDebug() << "新建" ;
            }
            );
    pFile->addSeparator();
    QAction *pOpen = pFile->addAction("打开");

    QMenu *pAbout = mBar->addMenu("关于");

    // Tool Bar
    QToolBar *pToolBar = addToolBar("toolBar");

    pToolBar->addAction(pNew);

    QPushButton *btn = new QPushButton(this);
    pToolBar->addWidget(btn);
    btn->setText("*_*");
    connect(btn,&QPushButton::clicked,[btn]()
    {
       btn->setText("ToT") ;
    });
    // Status Bar
    QStatusBar *pStatusBar = statusBar();
    QLabel *label = new QLabel(this);
    label->setText("普通文件");
    pStatusBar->addWidget(label);

    // Key Items
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    // Floating Window
    QDockWidget *dockWidget = new QDockWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea,dockWidget);
    QTextEdit *dockTextEdit = new QTextEdit();
    dockWidget->setWidget(dockTextEdit);
}

MainWindow::~MainWindow()
{

}
