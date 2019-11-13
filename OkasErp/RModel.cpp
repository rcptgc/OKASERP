#include "RModel.h"

RModel::RModel(QObject *parent):QSqlQueryModel(parent)
{
    for (int i = 0; i < 128; i++)
    {
        m_CheckStateList[i] = Qt::Unchecked;
    }
}

void RModel::SetQuery(const QString &query, const QSqlDatabase &db)
{
    Q_UNUSED(db)
    setQuery(query);
    insertColumn(columnCount());
    for (int i = 0; i < this->rowCount(); i++)
    {
        m_CheckStateList[i] = Qt::Unchecked;
    }
}

Qt::ItemFlags RModel::flags(const QModelIndex & index) const
{
    static bool IsFirst = true;

    if (IsFirst)
    {
        IsFirst = false;
    }

    if (index.column() == this->columnCount() - 1)
    {
        return QSqlQueryModel::flags(index) | Qt::ItemIsUserCheckable;
    }

    return QSqlQueryModel::flags(index) | Qt::ItemIsEditable;
}

QVariant RModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::CheckStateRole)
    {
        if (index.column() == this->columnCount() - 1)
        {
            return m_CheckStateList[index.row()];
        }
    }

    return QSqlQueryModel::data(index, role);
}

bool RModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::CheckStateRole && index.column() == this->columnCount() - 1)
    {
        if (value == Qt::Checked)
        {
            m_CheckStateList[index.row()] = Qt::Checked;
            emit RowChecked(index.row(), true);
            QModelIndex topLeft = index;
            QModelIndex bottomRight = index;
            emit dataChanged(topLeft, bottomRight);
            return true;
        }
        else if (value == Qt::Unchecked)
        {
            m_CheckStateList[index.row()] = Qt::Unchecked;
            emit RowChecked(index.row(), false);
            QModelIndex topLeft = index;
            QModelIndex bottomRight = index;
            emit dataChanged(topLeft, bottomRight);
            return true;
        }
    }


    QModelIndex topLeft = index;
    QModelIndex bottomRight = index;
    emit dataChanged(topLeft, bottomRight);
    return QSqlQueryModel::setData(index, value, role);
}

void RModel::SetAllChecked(void)
{
    for (int i = 0; i < this->rowCount(); i++)
    {
        setData(index(i, columnCount() - 1), Qt::Checked, Qt::CheckStateRole);
    }
}

void RModel::SetAllUnchecked(void)
{
    for (int i = 0; i < this->rowCount(); i++)
    {
        setData(index(i, columnCount() - 1), Qt::Unchecked, Qt::CheckStateRole);
    }
}

QList<int> RModel::getCheckedRowList(void)
{
    m_CheckRowList.clear();
    for (int i = 0; i < 128; i++)
    {
        if (m_CheckStateList[i] == Qt::Checked)
        {
            m_CheckRowList.append(i);
        }
    }
    return m_CheckRowList;
}
