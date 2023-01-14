#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup * buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->windowCheckBox);
    buttonGroup->addButton(ui->macOSCheckBox);
    buttonGroup->addButton(ui->linuxCheckBox);

    buttonGroup->setExclusive(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_windowCheckBox_toggled(bool checked)
{
    if (checked) {
        qDebug() << "Window checkBox is checked";
    } else {
        qDebug() << "Windows checkBox is unchecked";
    }
}


void Widget::on_beerCheckBox_toggled(bool checked)
{
    if (checked) {
        qDebug() << "Beer checkBox is checked";
    } else {
        qDebug() << "Beer checkBox is unchecked";
    }
}


void Widget::on_aRadioButton_toggled(bool checked)
{
    if (checked) {
        qDebug() << "A Radio Button is checked";
    } else {
        qDebug() << "A Radio Button is unchecked";
    }
}


void Widget::on_grabDataButton_clicked()
{
    if (ui->windowCheckBox->isChecked()) {
        qDebug() << "Window checkBox is checked";
    } else {
        qDebug() << "Windows checkBox is unchecked";
    }
}


void Widget::on_setStateButton_clicked()
{
    // An Exclusive Check Box
    if (ui->windowCheckBox->isChecked()) {
        ui->windowCheckBox->setChecked(false);
    } else {
        ui->windowCheckBox->setChecked(true);
    }

    // Non-Exclusive Check Box
    if (ui->beerCheckBox->isChecked()) {
        ui->beerCheckBox->setChecked(false);
    } else {
        ui->beerCheckBox->setChecked(true);
    }
}

