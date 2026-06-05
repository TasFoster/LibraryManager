#ifndef BOOKMODELCLASS_H
#define BOOKMODELCLASS_H
#define TitleRole 1
#define AuthorRole 2
#define YearRole 3
#define CountRole 4
#include "Book.h"
#include <QAbstractItemModel>
#include <QListView>
class BookModelClass : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit BookModelClass(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    void addBook(const Book &book);
    void removeBook(int id);
private:
    QList<Book> books;
};

#endif // BOOKMODELCLASS_H
