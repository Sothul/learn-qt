#include "widget.h"
#include "ui_widget.h"
#include <QColorDialog>
#include <QSettings>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    for (int i = 0; i < 9; i++) {
        colorList.append(Qt::black);
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_oneButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0], this, "Choose Background Color");

    if (color.isValid()) {
        // Save the color in the list in memory
        colorList[0] = color;

        // Set background color to the button
        QString css = QString("background-color : %1").arg(color.name());
        ui->oneButton->setStyleSheet(css);
    }
}


void Widget::on_twoButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[1], this, "Choose Background Color");

    if (color.isValid()) {
        // Save the color in the list in memory
        colorList[1] = color;

        // Set background color to the button
        QString css = QString("background-color : %1").arg(color.name());
        ui->twoButton->setStyleSheet(css);
    }
}


void Widget::on_threeButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[2], this, "Choose Background Color");

    if (color.isValid()) {
        // Save the color in the list in memory
        colorList[2] = color;

        // Set background color to the button
        QString css = QString("background-color : %1").arg(color.name());
        ui->threeButton->setStyleSheet(css);
    }
}


void Widget::on_fourButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[3], this, "Choose Background Color");

    if (color.isValid()) {
        // Save the color in the list in memory
        colorList[3] = color;

        // Set background color to the button
        QString css = QString("background-color : %1").arg(color.name());
        ui->fourButton->setStyleSheet(css);
    }
}


void Widget::on_fiveButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[4], this, "Choose Background Color");

    if (color.isValid()) {
        // Save the color in the list in memory
        colorList[4] = color;

        // Set background color to the button
        QString css = QString("background-color : %1").arg(color.name());
        ui->fiveButton->setStyleSheet(css);
    }
}


void Widget::on_sixButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[5], this, "Choose Background Color");

    if (color.isValid()) {
        // Save the color in the list in memory
        colorList[5] = color;

        // Set background color to the button
        QString css = QString("background-color : %1").arg(color.name());
        ui->sixButton->setStyleSheet(css);
    }
}


void Widget::on_sevenButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[6], this, "Choose Background Color");

    if (color.isValid()) {
        // Save the color in the list in memory
        colorList[6] = color;

        // Set background color to the button
        QString css = QString("background-color : %1").arg(color.name());
        ui->sevenButton->setStyleSheet(css);
    }
}


void Widget::on_eightButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[7], this, "Choose Background Color");

    if (color.isValid()) {
        // Save the color in the list in memory
        colorList[7] = color;

        // Set background color to the button
        QString css = QString("background-color : %1").arg(color.name());
        ui->eightButton->setStyleSheet(css);
    }
}


void Widget::on_nineButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[8], this, "Choose Background Color");

    if (color.isValid()) {
        // Save the color in the list in memory
        colorList[8] = color;

        // Set background color to the button
        QString css = QString("background-color : %1").arg(color.name());
        ui->nineButton->setStyleSheet(css);
    }
}


void Widget::on_loadColorButton_clicked()
{
    setLoadColor("oneButton", 0, ui->oneButton);
    setLoadColor("twoButton", 1, ui->twoButton);
    setLoadColor("threeButton", 2, ui->threeButton);
    setLoadColor("fourButton", 3, ui->fourButton);
    setLoadColor("fiveButton", 4, ui->fiveButton);
    setLoadColor("sixButton", 5, ui->sixButton);
    setLoadColor("sevenButton", 6, ui->sevenButton);
    setLoadColor("eightButton", 7, ui->eightButton);
    setLoadColor("nineButton", 8, ui->nineButton);
}


void Widget::on_saveColorButton_clicked()
{
    saveColor("oneButton", colorList[0]);
    saveColor("twoButton", colorList[1]);
    saveColor("threeButton", colorList[2]);
    saveColor("fourButton", colorList[3]);
    saveColor("fiveButton", colorList[4]);
    saveColor("sixButton", colorList[5]);
    saveColor("sevenButton", colorList[6]);
    saveColor("eightButton", colorList[7]);
    saveColor("nineButton", colorList[8]);
}

void Widget::saveColor(QString key, QColor color)
{
    int red = color.red();
    int green = color.green();
    int blue = color.blue();

    QSettings settings("Blikoon", "SettingsDemo");

    settings.beginGroup("ButtonColor");
    settings.setValue(key + "r", red);
    settings.setValue(key + "g", green);
    settings.setValue(key + "b", blue);
    settings.endGroup();
}

QColor Widget::loadColor(QString key)
{
    int red;
    int green;
    int blue;

    QSettings settings("Blikoon", "SettingsDemo");

    settings.beginGroup("ButtonColor");

    red = settings.value(key + "r", QVariant(0)).toInt();
    green = settings.value(key + "g", QVariant(0)).toInt();
    blue = settings.value(key + "b", QVariant(0)).toInt();

    settings.endGroup();

    return QColor(red, green, blue);
}

void Widget::setLoadColor(QString key, int index, QPushButton * button)
{
    QColor color = loadColor(key);
    colorList[index] = color;

    // Set background color to the button
    QString css = QString("background-color : %1").arg(color.name());
    button->setStyleSheet(css);
}

