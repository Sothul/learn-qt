#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QGridLayout * layout = new QGridLayout(this);

    QGridLayout * layout = new QGridLayout();

    // First Row
    layout->addWidget(ui->Button1, 0, 0);
    layout->addWidget(ui->Button2, 0, 1);
    layout->addWidget(ui->Button3, 0, 2);

    // Second Row
    layout->addWidget(ui->Button4, 1, 0);
    layout->addWidget(ui->Button5, 1, 1);
    layout->addWidget(ui->Button6, 1, 2);

    // Third Row
    layout->addWidget(ui->Button7, 2, 0);
    layout->addWidget(ui->Button8, 2, 1);
    layout->addWidget(ui->Button9, 2, 2);

    setLayout(layout);

}

Widget::~Widget()
{
    delete ui;
}

