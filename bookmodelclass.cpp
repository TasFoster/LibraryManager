#include "bookmodelclass.h"

BookModelClass::BookModelClass(QObject *parent) : QAbstractListModel(parent) {}

void BookModelClass::addBook(const Book &book){
    beginInsertRows(QModelIndex(), books.size(), books.size());
    books.push_back(book);
    endInsertRows();
}

int BookModelClass::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return books.size();
}

QVariant BookModelClass::data(const QModelIndex &index, int role) const{
    if (!index.isValid() || index.row() >= books.size())
        return {};

    const Book& b = books.at(index.row());

    if (role == Qt::DisplayRole) {
        return QString("%1 | %2 | %3 | %4").arg(b.title).arg(b.author).arg(b.year).arg(b.count);
    }
    else if (role == Qt::UserRole) {

    }
    return {};
}

bool BookModelClass::setData(const QModelIndex &index, const QVariant &value, int role){

    if(!index.isValid() || index.row() >= books.size()) return false;

    Book &book = books[index.row()];

    switch (role) {
    case TitleRole:
        book.title = value.toString();
        break;
    case AuthorRole:
        book.author = value.toString();
        break;
    case YearRole:
        book.year = value.toInt();
        break;
    case CountRole:
        book.count = value.toInt();
        break;
    default:
        return false;
        break;
    }

    emit dataChanged(index,index,{role});
    return true;
}

Qt::ItemFlags BookModelClass::flags(const QModelIndex &index) const {
    if (!index.isValid()) return Qt::NoItemFlags;

    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}


