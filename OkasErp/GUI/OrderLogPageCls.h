#ifndef ORDERLOGPAGECLS_H
#define ORDERLOGPAGECLS_H

#include <QMainWindow>
#include "PageCls.h"
namespace Ui {
class OrderLogPageCls;
}

class OrderLogPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    explicit OrderLogPageCls(QWidget *parent = 0);
    ~OrderLogPageCls();

private:
    Ui::OrderLogPageCls *ui;
    QList<OrderLogStc> m_OrderLogList;
    void FillTable();

    const uint8_t m_uchTABLE_COLUMN_COUNT = 10U;
    const uint8_t m_uchORDER_ID_COLUMN = 0U;
    const uint8_t m_uchRECEIVED_QUANTITY_COLUMN = 1U;
    const uint8_t m_uchDATE_COLUMN = 5U;
    const uint8_t m_uchTIME_COLUMN = 6U;
    const uint8_t m_uchNOTES_COLUMN = 8U;
    const uint8_t m_uchOPERATOR_NAME_COLUMN = 4U;
    const uint8_t m_uchPROCESSED_QUANTITY_COLUMN = 2U;
    const uint8_t m_uchOPERATION_COLUMN = 3U;
    const uint8_t m_uchDATE_TYPE_COLUMN = 7U;
    const uint8_t m_uchORDER_LOG_ID_COLUMN = 9U;

    void GetOrderLogFromRow(int32_t a_Row, OrderLogStc &a_OrderLog);

private slots:
    void LoadProductTrackingPage();
    void SaveChanges();
    void EraseOrderLogs(void);

};

#endif // ORDERLOGPAGECLS_H
