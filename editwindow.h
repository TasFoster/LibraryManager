#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QAbstractItemModel>
#include <QPersistentModelIndex>
#include "bookmodelclass.h"


namespace Ui {
class EditWindow;
}

class EditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditWindow(BookModelClass *model, const QModelIndex &index, QWidget *parent = nullptr);
    ~EditWindow();

private slots:
    void on_Return_clicked();

    void on_Get_clicked();

    void on_Edit_clicked();

private:
    Ui::EditWindow *ui;
    BookModelClass *model;
    QPersistentModelIndex index;
};

#endif // EDITWINDOW_H
