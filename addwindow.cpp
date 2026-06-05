#include "addwindow.h"
#include "ui_addwindow.h"

AddWindow::AddWindow(BookModelClass *model,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddWindow)
{
    ui->setupUi(this);
    this->model = model;
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::on_Add_clicked()
{
    Book book;
    book.title = ui->LineEdit_title->text();
    book.author = ui->LineEdit_author->text();
    book.year = ui->LineEdit_year->text().toInt();
    book.count = ui->LineEdit_count->text().toInt();
    model->addBook(book);
    this->close();
}

