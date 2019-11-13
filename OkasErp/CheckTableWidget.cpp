#include "CheckTableWidget.h"

#include <QPushButton>
#include <QDebug>

CheckTableWidget::CheckTableWidget(QWidget * a_ParentPtr)
{
    SetPushButton(true);
    this->setParent(a_ParentPtr);

    connect(this, SIGNAL(itemChanged(QTableWidgetItem *)), this, SLOT(UpdateEditedList(QTableWidgetItem *)));

    connect(this, SIGNAL(itemClicked(QTableWidgetItem *)), this, SLOT(TableItemClicked(QTableWidgetItem *)));
}

void CheckTableWidget::SetPushButton(bool a_IsSelected)
{
    this->IsPushEnabled = a_IsSelected;
}

void CheckTableWidget::TableItemClicked(QTableWidgetItem * a_ItemPtr)
{
    int32_t l_intButtonColumn = this->columnCount() - m_uchBUTTON_COLUMN_OFFSET;

    if (a_ItemPtr->checkState() == Qt::Checked)
    {
        if (m_CheckedRowsList.contains(a_ItemPtr->row()) == false)
        {
            m_CheckedRowsList.append(a_ItemPtr->row());
            emit RowChecked(true, a_ItemPtr->row());
        }
    }
    else
    {
        if (m_CheckedRowsList.contains(a_ItemPtr->row()))
        {
            int l_intCheckBoxIndex = m_CheckedRowsList.indexOf(a_ItemPtr->row());
            m_CheckedRowsList.removeAt(l_intCheckBoxIndex);
            emit RowChecked(false, a_ItemPtr->row());
        }
    }

    if (true == IsPushEnabled)
    {
        if (a_ItemPtr->column() == l_intButtonColumn)
        {
            emit ButtonClicked(a_ItemPtr->row());
        }
    }

}

void CheckTableWidget::UpdateEditedList(QTableWidgetItem * a_ItemPtr)
{

    if (a_ItemPtr->isSelected() == true)
    {
        if (m_EditedRowsList.indexOf(a_ItemPtr->row()) == -1)
        {
            m_EditedRowsList.append(a_ItemPtr->row());
        }
    }

    if (a_ItemPtr->checkState() == Qt::Checked)
    {
        if (m_CheckedRowsList.contains(a_ItemPtr->row()) == false)
        {
            m_CheckedRowsList.append(a_ItemPtr->row());
            emit RowChecked(true, a_ItemPtr->row());
        }
    }
    else
    {
        if (m_CheckedRowsList.contains(a_ItemPtr->row()))
        {
            int32_t l_intCheckBoxIndex = m_CheckedRowsList.indexOf(a_ItemPtr->row());
            m_CheckedRowsList.removeAt(l_intCheckBoxIndex);
            emit RowChecked(false, a_ItemPtr->row());
        }
    }
}

void CheckTableWidget::setRowCount(int32_t a_RowCount)
{
    QTableWidget::setRowCount(a_RowCount);

    int32_t l_intCheckboxColumn = columnCount() - m_uchCHECKBOX_COLUMN_OFFSET;

    int32_t l_intButtonColumn = this->columnCount() - m_uchBUTTON_COLUMN_OFFSET;

    for (int32_t l_intRowNumber = 0; l_intRowNumber < rowCount(); l_intRowNumber++)
    {
        QTableWidgetItem * l_CheckItemPtr = new QTableWidgetItem();

        l_CheckItemPtr->setCheckState(Qt::Unchecked);

        setItem(l_intRowNumber, l_intCheckboxColumn, l_CheckItemPtr);

        if (true == IsPushEnabled)
        {
            QTableWidgetItem * l_ButtonItemPtr = new QTableWidgetItem();

            l_ButtonItemPtr->setBackgroundColor(QColor(Qt::gray));
            l_ButtonItemPtr->setText("Göster");

            setItem(l_intRowNumber, l_intButtonColumn, l_ButtonItemPtr);
        }
    }
}

void CheckTableWidget::setColumnCount(int32_t a_ColumnCount)
{
    QTableWidget::setColumnCount(a_ColumnCount);

    int32_t l_intCheckboxColumn = this->columnCount() - m_uchCHECKBOX_COLUMN_OFFSET;

    QTableWidgetItem * l_ItemPtr = horizontalHeaderItem(this->columnCount() - 1);

    if (l_ItemPtr == nullptr)
    {
        l_ItemPtr = new QTableWidgetItem("");
    }

    setHorizontalHeaderItem(l_intCheckboxColumn, l_ItemPtr);

    setColumnWidth(l_intCheckboxColumn, m_uchCHECKBOX_COLUMN_WIDTH);

    insertColumn(this->columnCount());
}

void CheckTableWidget::insertRows(int32_t a_RowCount)
{
    int32_t l_intCheckboxColumn = this->columnCount() - m_uchCHECKBOX_COLUMN_OFFSET;

    for (int32_t l_intRowCounter = 0; l_intRowCounter < a_RowCount; l_intRowCounter++)
    {
        QTableWidget::insertRow(this->rowCount());

        QTableWidgetItem * l_CheckItemPtr = new QTableWidgetItem();

        l_CheckItemPtr->setCheckState(Qt::Unchecked);

        setItem(this->rowCount() - 1, l_intCheckboxColumn, l_CheckItemPtr);

    }
}
