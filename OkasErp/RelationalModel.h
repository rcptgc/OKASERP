#ifndef RELATIONALMODEL_H
#define RELATIONALMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>

class RelationalModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    RelationalModel(QObject *parent);

    Qt::ItemFlags flags(const QModelIndex & index) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex & index, const QVariant & value, int role) override;
    void SetLimit(int32_t a_intLimit);
    void SetOffset(int32_t a_intOffset);
    QList<int> getCheckedRowList(void);
    bool select() override;
    void SetAllChecked(void);
    void SetAllUnchecked(void);
    QString selectStatement() const override;
    int m_CheckboxColumn;
    int m_PushButtonColumn;

Q_SIGNALS:
    void RowChecked(int Row, bool state);
private:
    int32_t m_intLimit;
    int32_t m_intOffset;
    Qt::CheckState m_CheckStateList[128];
    QList<int> m_CheckRowList;

};


#endif // RELATIONALMODEL_H
