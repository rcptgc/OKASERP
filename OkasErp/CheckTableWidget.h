#ifndef CHECKTABLEWIDGET_H
#define CHECKTABLEWIDGET_H

#include <QTableWidget>
#include <QList>
#include <OrderCls.h>
#include <QHeaderView>

/*! \class CheckTableWidget CheckTableWidget.h
 *
 *  Docs for MyClassName
 */
class CheckTableWidget : public QTableWidget
{
    Q_OBJECT

public:
/** @brief Holds true for negative values */
    CheckTableWidget(QWidget * a_ParentPtr = nullptr);
/** @brief Holds true for negative values */
    void setRowCount(int32_t a_RowCount);
/** @brief Holds true for negative values */
    void setColumnCount(int32_t a_ColumnCount);
/** @brief Holds true for negative values */
    void insertRows(int32_t a_RowCount);
/** @brief Holds true for negative values */
    void SetPushButton(bool a_blnIsSet);

/** @brief Holds true for negative values */
    QList<int32_t> m_CheckedRowsList;
/** @brief Holds true for negative values */
    QList<int32_t> m_EditedRowsList;

    void resizeEvent(QResizeEvent *ev)
    {
        Q_UNUSED(ev)
        QHeaderView * header = this->horizontalHeader();
        for (int i = 0; i < header->count();i++)
        {
            header->setSectionResizeMode(i , QHeaderView::ResizeToContents);
            int width = header->sectionSize(i);
            header->setSectionResizeMode(i, QHeaderView::Interactive);
            header->resizeSection(i, width);
        }
    }

protected slots:
/** @brief Holds true for negative values */
    void UpdateEditedList(QTableWidgetItem * a_ItemPtr);
/** @brief Holds true for negative values */
    void TableItemClicked(QTableWidgetItem * a_ItemPtr);


Q_SIGNALS:
    /** @brief Holds true for negative values */
    void RowChecked(bool a_blnIsChecked, int32_t a_intRowNumber);
    /** @brief Holds true for negative values */
    void ButtonClicked(int32_t a_intRowNumber);

private:
    const uint8_t m_uchCHECKBOX_COLUMN_WIDTH    = 25u;
    const uint8_t m_uchCHECKBOX_COLUMN_OFFSET   = 1U;
    const uint8_t m_uchBUTTON_COLUMN_OFFSET     = 2U;

    bool IsPushEnabled = false;
};

/*! \class OrderTableWidget CheckTableWidget.h
 *
 *  Docs for MyClassName
 */
class OrderTableWidget : public CheckTableWidget
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    QList<OrderCls> m_OrderList;
/** @brief Holds true for negative values */
    OrderTableWidget(QWidget * a_ParentPtr = nullptr)
    {
        this->setParent(a_ParentPtr);
        connect(this, SIGNAL(itemChanged(QTableWidgetItem *)), this, SLOT(UpdateEditedList(QTableWidgetItem *)));
        connect(this, SIGNAL(itemClicked(QTableWidgetItem *)), this, SLOT(TableItemClicked(QTableWidgetItem *)));
    }

    void resizeEvent(QResizeEvent *ev)
    {
        Q_UNUSED(ev)
        QHeaderView * header = this->horizontalHeader();
        for (int i = 0; i < header->count();i++)
        {
            header->setSectionResizeMode(i , QHeaderView::ResizeToContents);
            int width = header->sectionSize(i);
            header->setSectionResizeMode(i, QHeaderView::Interactive);
            header->resizeSection(i, width);
        }
    }
};

/*! \class OrderTableWidget CheckTableWidget.h
 *
 *  Docs for MyClassName
 */
class UserTableWidget : public CheckTableWidget
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    QList<UserStc> m_UserList;
/** @brief Holds true for negative values */
    UserTableWidget(QWidget * a_ParentPtr = nullptr)
    {
        this->setParent(a_ParentPtr);
        connect(this, SIGNAL(itemChanged(QTableWidgetItem *)), this, SLOT(UpdateEditedList(QTableWidgetItem *)));
        connect(this, SIGNAL(itemClicked(QTableWidgetItem *)), this, SLOT(TableItemClicked(QTableWidgetItem *)));
    }

    void resizeEvent(QResizeEvent *ev)
    {
        Q_UNUSED(ev)
        QHeaderView * header = this->horizontalHeader();
        for (int i = 0; i < header->count();i++)
        {
            header->setSectionResizeMode(i , QHeaderView::ResizeToContents);
            int width = header->sectionSize(i);
            header->setSectionResizeMode(i, QHeaderView::Interactive);
            header->resizeSection(i, width);
        }
    }
};

#endif // CHECKTABLEWIDGET_H
