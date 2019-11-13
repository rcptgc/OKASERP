#ifndef SALESREPORTPAGECLS_H
#define SALESREPORTPAGECLS_H

#include <QMainWindow>
#include "PageCls.h"
#include "OrderCls.h"
#include "CustomerCls.h"

namespace Ui {
class SalesReportPageCls;
}

/*! \class SalesReportPageCls SalesReportPageCls.h
 *
 *  Docs for MyClassName
 */
class SalesReportPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    explicit SalesReportPageCls(QWidget * a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
    ~SalesReportPageCls();

private slots:
/** @brief Holds true for negative values */
    void CreateReportFromTable();
/** @brief Holds true for negative values */
    void ShowSelectedSales();
/** @brief Holds true for negative values */
    void LoadSalesMainPage();
/** @brief Holds true for negative values */
    void FillSalesTable(QList<OrderCls> a_OrderList);

private:
/** @brief Holds true for negative values */
    QList<OrderCls> m_SaleOrderList;
/** @brief Holds true for negative values */
    Ui::SalesReportPageCls * ui;


    const uint8_t m_uchTABLE_COLUMN_COUNT = 17u;

    const uint8_t m_uchENTRY_DATE_COLUMN           = 0u;
    const uint8_t m_uchCUSTOMER_NAME_COLUMN        = 1u;
    const uint8_t m_uchPROJECT_NAME_COLUMN         = 2u;
    const uint8_t m_uchPRODUCT_NUMBER_COLUMN       = 3u;
    const uint8_t m_uchPO_NUMBER_COLUMN            = 4u;
    const uint8_t m_uchSOW_NUMBER_COLUMN           = 5u;
    const uint8_t m_uchRECEIVED_QUANTITY_COLUMN    = 6u;
    const uint8_t m_uchACCEPTED_QUANTITY_COLUMN    = 7u;
    const uint8_t m_uchREJECTED_QUANTITY_COLUMN    = 8u;
    const uint8_t m_uchINTERNAL_SOW_NUMBER_COLUMN  = 9u;
    const uint8_t m_uchBARCODE_NUMBER_COLUMN       = 10u;
    const uint8_t m_uchURGENCY_COLUMN              = 11u;
    const uint8_t m_uchBRAND_DATE_COLUMN           = 12u;
    const uint8_t m_uchSOIR_COLUMN                 = 13u;
    const uint8_t m_uchSALE_DATE_COLUMN            = 14u;
    const uint8_t m_uchPRICE_COLUMN                = 15u;
    const uint8_t m_uchDISPATCH_NUMBER_COLUMN      = 16u;

    const uint8_t m_uchENTRY_DATE_COLUMN_WIDTH          = 75u;
    const uint8_t m_uchCUSTOMER_NAME_COLUMN_WIDTH       = 75u;
    const uint8_t m_uchPROJECT_NAME_COLUMN_WIDTH        = 120u;
    const uint8_t m_uchRECEIVED_QUANTITY_COLUMN_WIDTH   = 50u;
    const uint8_t m_uchACCEPTED_QUANTITY_COLUMN_WIDTH   = 50u;
    const uint8_t m_uchREJECTED_QUANTITY_COLUMN_WIDTH   = 50u;
    const uint8_t m_uchBARCODE_NUMBER_COLUMN_WIDTH      = 120u;
    const uint8_t m_uchURGENCY_COLUMN_WIDTH             = 50u;
    const uint8_t m_uchSALE_DATE_COLUMN_WIDTH           = 75u;
    const uint8_t m_uchDISPATCH_NUMBER_COLUMN_WIDTH     = 75u;

    const uint8_t m_uchEXCEL_FIRST_ROW  = 2u;

    const uint8_t m_uchEXCEL_PRODUCT_NUMBER_COLUMN      = 1u;
    const uint8_t m_uchEXCEL_PO_NUMBER_COLUMN           = 2u;
    const uint8_t m_uchEXCEL_SOW_NUMBER_COLUMN          = 3u;
    const uint8_t m_uchEXCEL_ACCEPTED_QUANTITY_COLUMN   = 4u;
    const uint8_t m_uchEXCEL_INTERNAL_SOW_NUMBER_COLUMN = 5u;
    const uint8_t m_uchEXCEL_COST_COLUMN                = 6u;
    const uint8_t m_uchEXCEL_SALE_DATE_COLUMN           = 7u;
};

#endif // SALESREPORTPAGECLS_H
