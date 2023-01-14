#include "infodialog.h"
#include "ui_infodialog.h"
#include <QDebug>

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton = ui->buttonBox->standardButton(button);

    if (stdButton == QDialogButtonBox::Ok) {
        accept();
        qDebug() << "Ok Button clicked";
    }
    if (stdButton == QDialogButtonBox::Save) {
        qDebug() << "Save Button clicked";
    }
    if (stdButton == QDialogButtonBox::SaveAll) {
        qDebug() << "SaveAll Button clicked";
    }
    if (stdButton == QDialogButtonBox::Open) {
        qDebug() << "Open Button clicked";
    }
    if (stdButton == QDialogButtonBox::Cancel) {
        qDebug() << "Cancel Button clicked";
        reject();
    }
    if (stdButton == QDialogButtonBox::YesToAll) {
        qDebug() << "YesToAll Button clicked";
    }
}

