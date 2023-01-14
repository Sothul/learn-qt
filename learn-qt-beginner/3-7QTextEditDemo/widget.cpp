#include "widget.h"
#include <QPushButton>
#include <QDebug>
#include <QTextEdit>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    setFixedSize(400, 400);
}

Widget::~Widget()
{
}

void Widget::setupUI()
{
    QFont labelFont("Times", 15, QFont::Bold);
    QLabel * mLabel = new QLabel("This is my text", this);
    mLabel->setFont(labelFont);
    mLabel->move(100, 25);

    QTextEdit * textEdit = new QTextEdit(this);
    textEdit->move(70, 55);

    /*
    // textChanged
    connect(textEdit, &QTextEdit::textChanged, [=](){
       qDebug() << "Text Changed";
    });
    */

    // Cut, Copy and Paste Button
    QPushButton * copyButton = new QPushButton("Copy", this);
    copyButton->setMinimumSize(50, 25);
    copyButton->move(10, 250);
    connect(copyButton, &QPushButton::clicked, [=](){
        textEdit->copy();
    });

    QPushButton * cutButton = new QPushButton("Cut", this);
    cutButton->setMinimumSize(50, 25);
    cutButton->move(110, 250);
    connect(cutButton, &QPushButton::clicked, [=](){
        textEdit->cut();
    });

    QPushButton * pasteButton = new QPushButton("Paste", this);
    pasteButton->setMinimumSize(50, 25);
    pasteButton->move(210, 250);
    connect(pasteButton, &QPushButton::clicked, [=](){
        textEdit->paste();
    });

    // Undo and Redo
    QPushButton * undoButton = new QPushButton("Undo", this);
    undoButton->setMinimumSize(50, 25);
    undoButton->move(10, 280);
    connect(undoButton, &QPushButton::clicked, [=](){
        textEdit->undo();
    });

    QPushButton * redoButton = new QPushButton("Redo", this);
    redoButton->setMinimumSize(50, 25);
    redoButton->move(110, 280);
    connect(redoButton, &QPushButton::clicked, [=](){
        textEdit->redo();
    });

    // Set Text and html to text edit
    QPushButton * plainTextButton = new QPushButton("Plain Text", this);
    plainTextButton->setMinimumSize(100, 25);
    plainTextButton->move(10, 310);
    connect(plainTextButton, &QPushButton::clicked, [=](){
        textEdit->setPlainText("Sed ut perspiciatis unde omnis iste natus error sit voluptatem");
    });

    QPushButton * htmlButton = new QPushButton("HTML", this);
    htmlButton->setMinimumSize(100, 25);
    htmlButton->move(120, 310);
    connect(htmlButton, &QPushButton::clicked, [=](){
        textEdit->setHtml("<h2>Kigali Districts</h2><p>The city of Kigali has three districts : </br> "
                          "<ul> <li>Gasabo</li> <li>Nyarugenge</li> <li>Kicukiro</li></u></p>");
    });

    // Grab text and html
    QPushButton * grabTextButton = new QPushButton("Grab Text", this);
    grabTextButton->setMinimumSize(100, 25);
    grabTextButton->move(10, 340);
    connect(grabTextButton, &QPushButton::clicked, [=](){
       qDebug() << "The plain text inside the text edit is: " << textEdit->toPlainText();
    });

    QPushButton * grabHtmlButton = new QPushButton("Grab HTML", this);
    grabHtmlButton->setMinimumSize(100, 25);
    grabHtmlButton->move(120, 340);
    connect(grabHtmlButton, &QPushButton::clicked, [=](){
       qDebug() << "The html text inside the text edit is: " << textEdit->toHtml();
    });
}

