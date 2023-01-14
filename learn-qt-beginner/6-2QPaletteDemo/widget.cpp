#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    // Retrieve the palette for the label
    QPalette palette = ui->label->palette();
    ui->label->setAutoFillBackground(true);

    // Modify the palette
    palette.setColor(QPalette::Window, Qt::green);
    palette.setColor(QPalette::WindowText, Qt::red);

    // Reset the palette to the Widget
    ui->label->setPalette(palette);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_activeButton_clicked()
{
    QPalette::ColorGroup activeButtonColorGroup = ui->activeButton->palette().currentColorGroup();
    QPalette::ColorGroup disableButtonColorGroup = ui->disableButton->palette().currentColorGroup();

    qDebug() << "Active button color group: " << activeButtonColorGroup;
    qDebug() << "Disabled button color group: " << disableButtonColorGroup;
}



