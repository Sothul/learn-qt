#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString path = "/home/james";

    // Dir Model
    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
    dirModel->setRootPath(path);
    ui->treeView->setModel(dirModel);

    // File Model
    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    fileModel->setRootPath(path); // Required for model to load file system info
    ui->listView->setModel(fileModel);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_treeView_clicked(const QModelIndex &index)
{
    QString path = dirModel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(fileModel->setRootPath(path));

}

