#include "TableModelCls.h"



TableModelCls::TableModelCls(QObject *parent): QSqlTableModel(parent)
{

}

Qt::ItemFlags TableModelCls::flags(const QModelIndex & index) const
{
    static bool IsFirst = true;

    if (IsFirst)
    {
        IsFirst = false;
    }

    if (index.column() == m_CheckboxColumn)
    {
        return QSqlTableModel::flags(index) | Qt::ItemIsUserCheckable;
    }

    return QSqlTableModel::flags(index) | Qt::ItemIsEditable;
}

QVariant TableModelCls::data(const QModelIndex &index, int role) const
{
    if (role == Qt::CheckStateRole)
    {
        if (index.column() == m_CheckboxColumn)
        {
            return m_CheckStateList[index.row()];
        }
    }

    if (role == Qt::DisplayRole && index.column() == m_PushButtonColumn)
    {
        return QString("Göster");
    }

    return QSqlTableModel::data(index, role);
}

bool TableModelCls::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::CheckStateRole && index.column() == m_CheckboxColumn)
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
    return QSqlTableModel::setData(index, value, role);
}

bool TableModelCls::select()
{
    bool blnReturn;
    blnReturn = QSqlTableModel::select();

    insertColumn(columnCount());
    m_CheckboxColumn = columnCount() - 1;

    insertColumn(columnCount());
    m_PushButtonColumn = columnCount() - 1;

    for (int i = 0; i < this->rowCount(); i++)
    {
        m_CheckStateList[i] = Qt::Unchecked;
    }

    return blnReturn;
}

void TableModelCls::SetAllChecked(void)
{
    for (int i = 0; i < this->rowCount(); i++)
    {
        setData(index(i, m_CheckboxColumn), Qt::Checked, Qt::CheckStateRole);
    }
}

void TableModelCls::SetAllUnchecked(void)
{
    for (int i = 0; i < this->rowCount(); i++)
    {
        setData(index(i, m_CheckboxColumn), Qt::Unchecked, Qt::CheckStateRole);
    }
}

QList<int> TableModelCls::getCheckedRowList(void)
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
