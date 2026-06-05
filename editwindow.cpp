#include "editwindow.h"
#include "ui_editwindow.h"
#include <iostream>
EditWindow::EditWindow(BookModelClass *model, const QModelIndex &index, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditWindow)
{
    ui->setupUi(this);
    this->model = model;
    this->index = index;
    Book book = model->data(this->index, Qt::UserRole).value<Book>();
    ui->TitleEdit->setText(book.title);
    ui->AuthorEdit->setText(book.author);
    ui->YearsEdit->setText(QtPrivate::convertToQString(std::to_string( book.year)));
    ui->CountEdit->setText(QtPrivate::convertToQString(std::to_string( book.count)));
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_Return_clicked()
{
    const Book &book = model->data(this->index, Qt::UserRole).value<Book>();
    model->setData(this->index,model->data(this->index, Qt::UserRole).value<Book>().count + 1, CountRole);
    ui->CountEdit->setText(QtPrivate::convertToQString(std::to_string( book.count)));
}


void EditWindow::on_Get_clicked()
{
    const Book &book = model->data(this->index, Qt::UserRole).value<Book>();
    if(book.count > 0){
        model->setData(this->index,book.count - 1, CountRole);
    }
    ui->CountEdit->setText(QtPrivate::convertToQString(std::to_string(book.count)));
}


void EditWindow::on_Edit_clicked()
{

}

