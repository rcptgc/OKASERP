#include "RelationalModel.h"
#include <QDebug>

RelationalModel::RelationalModel(QObject *parent): QSqlRelationalTableModel(parent)
{
    m_intLimit = 0;
    m_intOffset = 0;
}

void RelationalModel::SetLimit(int32_t a_intLimit)
{
    m_intLimit = a_intLimit;
}

void RelationalModel::SetOffset(int32_t a_intOffset)
{
    m_intOffset = a_intOffset;
}

QString RelationalModel::selectStatement() const
{
    QString query = QSqlRelationalTableModel::selectStatement();

    if(m_intLimit > 0)
    {
        query += QString(" LIMIT %1").arg(m_intLimit);
    }

    if (m_intOffset > 0)
    {
        query += QString(" OFFSET %1").arg(m_intOffset);
    }

    return query;
}

Qt::ItemFlags RelationalModel::flags(const QModelIndex & index) const
{
    static bool IsFirst = true;

    if (IsFirst)
    {
        IsFirst = false;
    }

    if (index.column() == m_CheckboxColumn)
    {
        return QSqlRelationalTableModel::flags(index) | Qt::ItemIsUserCheckable;
    }

    return QSqlRelationalTableModel::flags(index) | Qt::ItemIsEditable;
}

QVariant RelationalModel::data(const QModelIndex &index, int role) const
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

    return QSqlRelationalTableModel::data(index, role);
}

bool RelationalModel::setData(const QModelIndex & index, const QVariant & value, int role)
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
    return QSqlRelationalTableModel::setData(index, value, role);
}

bool RelationalModel::select()
{
    bool blnReturn;
    blnReturn = QSqlRelationalTableModel::select();

    insertColumn(columnCount());
    m_CheckboxColumn = columnCount() - 1;

    insertColumn(columnCount());
    m_PushButtonColumn = columnCount() - 1;

    for (int i = 0; i < this->rowCount(); i++)
    {
        m_CheckStateList[i] = Qt::Unchecked;
    }

    qDebug() << "ST : " << this->selectStatement();

    return blnReturn;
}

void RelationalModel::SetAllChecked(void)
{
    for (int i = 0; i < this->rowCount(); i++)
    {
        setData(index(i, m_CheckboxColumn), Qt::Checked, Qt::CheckStateRole);
    }
}

void RelationalModel::SetAllUnchecked(void)
{
    for (int i = 0; i < this->rowCount(); i++)
    {
        setData(index(i, m_CheckboxColumn), Qt::Unchecked, Qt::CheckStateRole);
    }
}

QList<int> RelationalModel::getCheckedRowList(void)
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
