#ifndef TABLEMODELCLS_H
#define TABLEMODELCLS_H

#include <QObject>
#include <QSqlTableModel>

class TableModelCls : public QSqlTableModel
{
    Q_OBJECT
public:
    TableModelCls(QObject *parent);

    Qt::ItemFlags flags(const QModelIndex & index) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex & index, const QVariant & value, int role) override;
    QList<int> getCheckedRowList(void);
    bool select() override;
    void SetAllChecked(void);
    void SetAllUnchecked(void);

    int m_CheckboxColumn;
    int m_PushButtonColumn;

Q_SIGNALS:
    void RowChecked(int Row, bool state);
private:

    Qt::CheckState m_CheckStateList[128];
    QList<int> m_CheckRowList;

};

#endif // TABLEMODELCLS_H
