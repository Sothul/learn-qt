#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_okButton_clicked()
{
    // Collect Information
    QString userPosition = ui->positionLineEdit->text();
    if (!userPosition.isEmpty()) {
        position = userPosition;

        if (ui->windowRadioButton->isChecked()) {
            favoriteOs = "Windows";
        }
        if (ui->macRadioButton->isChecked()) {
            favoriteOs = "Mac";
        }
        if (ui->linuxRadioButton->isChecked()) {
            favoriteOs = "Linux";
        }
    }

    // Accept the dialog
    accept();
}


void InfoDialog::on_cancelButton_clicked()
{
    // Reject the dialog
    reject();
}

QString InfoDialog::getFavoriteOs() const
{
    return favoriteOs;
}

QString InfoDialog::getPosition() const
{
    return position;
}



