#ifndef PRODUCTTRACKINGPAGECLS_H
#define PRODUCTTRACKINGPAGECLS_H

#include <QMainWindow>
#include "CustomerCls.h"
#include "DataBaseCls.h"
#include <QList>
#include "Utility\ExcelHandlerCls.h"
#include "OrderCls.h"
#include "PageCls.h"
#include "RelationalModel.h"

#define BY_EXCEL 1
#define BY_ENTRY 2

namespace Ui
{
class ProductTrackingPageCls;
}


/*! \class ProductTrackingPageCls ProductTrackingPageCls.h
 *
 *  Docs for MyClassName
 */
class ProductTrackingPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    explicit ProductTrackingPageCls(QWidget * a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
    ~ProductTrackingPageCls();

private slots:
    void NextPressed();
    void PrevPressed();
/** @brief Holds true for negative values */
    void ReturnToThisPage();
    /** @brief Holds true for negative values */
    void ShowExcelCustomerSelectionDialog();
    /** @brief Holds true for negative values */
    void ShowManualCustomerSelectionDialog();
    /** @brief Holds true for negative values */
    void AddBarcodeNumber(void);
    /** @brief Holds true for negative values */
    void SearchOrderAndUpdateTable();
    /** @brief Holds true for negative values */
    void ReturnToCustomerSelectionPage();
    /** @brief Holds true for negative values */
    void LoadNewOrderPage();
    /** @brief Holds true for negative values */
    void CreateExcelReport();
    /** @brief Holds true for negative values */
    void EraseOrders(void);
    /** @brief Holds true for negative values */
    void OrderButtonClicked(QModelIndex a_Index);

    void PageEntered();

    void resizeEvent(QResizeEvent *event) override;

private:
    int32_t m_intPageNum;
    const int32_t m_intCount = 12;
    int32_t m_intMaxPage = 0;
/** @brief Holds true for negative values */
    Ui::ProductTrackingPageCls *ui;
/** @brief Holds true for negative values */
    QMainWindow * m_CustomerFormPtr;
    /** @brief Holds true for negative values */
    void FillProductTable(void);
    /** @brief Holds true for negative values */
    RelationalModel * m_Model;
    void GetOrderFromRow(int32_t a_Row, OrderCls &a_Order);
/** @brief Holds true for negative values */
    QComboBox * m_CustomerSelectionPtr;
/** @brief Holds true for negative values */
    int m_intEntryMethod;

    const uint8_t s_uchTABLE_COLUMN_COUNT = 18u;

    const uint8_t m_uchENTRY_DATE_COLUMN            = 0u;
    const uint8_t m_uchCUSTOMER_NAME_COLUMN         = 1u;
    const uint8_t m_uchPROJECT_NAME_COLUMN          = 2u;
    const uint8_t m_uchPRODUCT_NUMBER_COLUMN        = 3u;
    const uint8_t m_uchPO_NUMBER_COLUMN             = 4u;
    const uint8_t m_uchSOW_NUMBER_COLUMN            = 5u;
    const uint8_t m_uchRECEIVED_QUANTITY_COLUMN     = 6u;
    const uint8_t m_uchACCEPTED_QUANTITY_COLUMN     = 7u;
    const uint8_t m_uchREJECTED_QUANTITY_COLUMN     = 8u;
    const uint8_t m_uchGKR_NUMBER_COLUMN            = 9u;
    const uint8_t m_uchBARCODE_NUMBER_COLUMN        = 10u;
    const uint8_t m_uchURGENCY_COLUMN               = 11u;
    const uint8_t m_uchBRAND_DATE_COLUMN            = 12u;
    const uint8_t m_uchSOIR_COLUMN                  = 13u;
    const uint8_t m_uchSALE_DATE_COLUMN             = 14u;
    const uint8_t m_uchDISPATCH_NUMBER_COLUMN       = 15u;
    const uint8_t m_uchORDER_ID_COLUMN              = 16u;
    const uint8_t m_uchBUTTON_COLUMN                = 17u;
    const uint8_t m_uchCHECKBOX_COLUMN              = 18u;

    const uint8_t m_uchENTRY_DATE_COLUMN_WIDTH          = 75u;
    const uint8_t m_uchCUSTOMER_NAME_COLUMN_WIDTH       = 75u;
    const uint8_t m_uchPROJECT_NAME_COLUMN_WIDTH        = 120u;
    const uint8_t m_uchRECEIVED_QUANTITY_COLUMN_WIDTH   = 50u;
    const uint8_t m_uchACCEPTED_QUANTITY_COLUMN_WIDTH   = 50u;
    const uint8_t m_uchREJECTED_QUANTITY_COLUMN_WIDTH   = 50u;
    const uint8_t m_uchBARCODE_NUMBER_COLUMN_WIDTH      = 120u;
    const uint8_t m_uchURGENCY_COLUMN_WIDTH             = 50u;
    const uint8_t m_uchCHECKBOX_COLUMN_WIDTH            = 20u;
    const uint8_t m_uchBUTTON_COLUMN_WIDTH              = 70u;



    const uint16_t m_ushCUSTOMER_FORM_WIDTH     = 320;
    const uint16_t m_ushCUSTOMER_FORM_HEIGHT    = 240u;

    const uint16_t m_ushCUSTOMER_COMBO_POS_X = 50u;
    const uint16_t m_ushCUSTOMER_COMBO_POS_Y = 50u;

    const uint16_t m_ushBUTTON_POS_X = 200u;
    const uint16_t m_ushBUTTON_POS_Y = 50u;

};

#endif // PRODUCTTRACKINGPAGECLS_H
