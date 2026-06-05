#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bookmodelclass.h"
#include "addwindow.h"
#include "editwindow.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(BookModelClass *model, QWidget *parent = nullptr);
    ~MainWindow();
    BookModelClass *model;
private slots:
    void on_AddBook_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
