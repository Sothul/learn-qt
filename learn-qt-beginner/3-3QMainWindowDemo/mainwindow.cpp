#include "mainwindow.h"
#include <QPushButton>
#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Add Central Widget
    QPushButton * button = new QPushButton("Hello", this);
    setCentralWidget(button);

    // Declare Quit Action
    QAction * quitAction = new QAction("Quit");
    connect(quitAction, &QAction::triggered, [=](){
        QApplication::quit();
    });

    // Add Menus
    QMenu * fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    // Add Status Bar message
    statusBar()->showMessage("Uploading file....", 3000);
//    statusBar()->clearMessage();
}

MainWindow::~MainWindow()
{
}

QSize MainWindow::sizeHint() const
{
    return QSize(800, 500);
}

