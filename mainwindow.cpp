#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(BookModelClass *model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->model = model;
    ui->listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddBook_clicked()
{
    AddWindow *add = new AddWindow(model, this);
    add->show();
}


void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    EditWindow *edit = new EditWindow(model,index,this);
    edit->show();

}

