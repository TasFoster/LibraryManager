#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "Book.h"
#include "bookmodelclass.h"
namespace Ui {
class AddWindow;
}

class AddWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit AddWindow(BookModelClass *model, QWidget *parent = nullptr);
    ~AddWindow();

private slots:
    void on_Add_clicked();

private:
    Ui::AddWindow *ui;
    BookModelClass *model;
};

#endif // ADDWINDOW_H
