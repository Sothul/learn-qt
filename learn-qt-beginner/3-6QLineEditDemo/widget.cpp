#include "widget.h"
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // First Name
    QLabel * firstNameLabel = new QLabel("First Name:", this);
    firstNameLabel->setMinimumSize(70, 50);
    firstNameLabel->move(10, 10);

    QLineEdit * firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200, 50);
    firstNameLineEdit->move(100, 10);

    // Last Name
    QLabel * lastNameLabel = new QLabel("Last Name:", this);
    lastNameLabel->setMinimumSize(70, 50);
    lastNameLabel->move(10, 70);

    QLineEdit * lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200, 50);
    lastNameLineEdit->move(100, 70);

    // City
    QLabel * cityLabel = new QLabel("City:", this);
    cityLabel->setMinimumSize(70, 50);
    cityLabel->move(10, 130);

    QLineEdit * cityLineEdit = new QLineEdit(this);
    cityLineEdit->setMinimumSize(200, 50);
    cityLineEdit->move(100, 130);

    // Grab Data Button
    QFont buttonFont("Times", 20, QFont::Bold);
    QPushButton * button = new QPushButton("Grab Data", this);
    button->setFont(buttonFont);
    button->move(80, 190);

    connect(button, &QPushButton::clicked, [=](){
        QString firstName = firstNameLineEdit->text();
        QString lastName = lastNameLineEdit->text();
        QString city = cityLineEdit->text();

        if (!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty()) {
            qDebug() << "First Name : " << firstName;
            qDebug() << "Last Name : " << lastName;
            qDebug() << "City : " << city;
        } else {
            qDebug() << "One field is empty";
        }
    });

    // Respond to signal from QLineEdits
    /*
    // cursorPositionChanged
    connect(firstNameLineEdit, &QLineEdit::cursorPositionChanged, [=](){
       qDebug() << "The current cursor position is: " << firstNameLineEdit->cursorPosition();
    });


    // editingFinished: emitted when user clicks enter or when line edit looses focus
    connect(firstNameLineEdit, &QLineEdit::editingFinished, [=](){
       qDebug() << "Editing finished : ";
    });

    // returnPressed
    connect(firstNameLineEdit, &QLineEdit::returnPressed, [=](){
       qDebug() << "Return Pressed";
    });

    // selectionChanged
    connect(firstNameLineEdit, &QLineEdit::selectionChanged, [=](){
       qDebug() << "Selection Changed";
    });

    // textChanged
    connect(firstNameLineEdit, &QLineEdit::textChanged, [=](){
       qDebug() << "Text Changed to: " << firstNameLineEdit->text();
    });
        */
    // textEdited
    connect(firstNameLineEdit, &QLineEdit::textEdited, [=](){
       qDebug() << "Text Edited to: " << firstNameLineEdit->text();
    });

    // Change text in QLineEdit programmatically
//    lastNameLineEdit->setText("Say your last name");

    // Hint Text
    firstNameLineEdit->setPlaceholderText("First Name");
    lastNameLineEdit->setPlaceholderText("Last Name");
    cityLineEdit->setPlaceholderText("City");

}

Widget::~Widget()
{
}

