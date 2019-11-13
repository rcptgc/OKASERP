#ifndef RMODEL_H
#define RMODEL_H

#include <QSqlQueryModel>

class RModel : public QSqlQueryModel
{
    Q_OBJECT
public :
    RModel(QObject *parent);

    void SetQuery(const QString &query, const QSqlDatabase &db = QSqlDatabase());
    Qt::ItemFlags flags(const QModelIndex & index) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex & index, const QVariant & value, int role) override;
    QList<int> getCheckedRowList(void);

    void SetAllChecked(void);
    void SetAllUnchecked(void);
Q_SIGNALS:
    void RowChecked(int Row, bool state);
private:
    Qt::CheckState m_CheckStateList[128];
    QList<int> m_CheckRowList;
};

#endif // RMODEL_H
