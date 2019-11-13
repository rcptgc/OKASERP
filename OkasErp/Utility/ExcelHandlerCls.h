#ifndef EXCELHANDLERCLS_H
#define EXCELHANDLERCLS_H
#include <QVariant>
#include <QAxObject>
#include <QAxWidget>
#include <QFile>
#include <QDebug>
#include <QPrinterInfo>
#include "LoggerCls.h"
#include <QSqlTableModel>
#include <QSqlRecord>

/*! \class ExcelHandlerCls ExcelHandlerCls.h
 *
 *  Docs for MyClassName
 */
class ExcelHandlerCls
{
public:
    /** @brief Holds true for negative values */
    ExcelHandlerCls(QString a_FilePathStr);
/** @brief Holds true for negative values */
    bool SetCellValue(int32_t a_intRow, int32_t a_intColumn, QVariant a_Value);
    /** @brief Holds true for negative values */
    QVariant GetCellValue(int32_t a_intRow, int32_t a_intColumn);
/** @brief Holds true for negative values */
    bool AccessFile();
    /** @brief Holds true for negative values */
    bool SaveFile();
    /** @brief Holds true for negative values */
    bool CloseFile();
    /** @brief Holds true for negative values */
    bool PrintFile();
    /** @brief Holds true for negative values */
    void SaveAs(QString a_SavefilenameStr);

    int GetRowCount(void);
    int GetRowsStart() const;
    void CreateReport(QSqlTableModel &l_Model);

private:

    /** @brief Holds true for negative values */
    int m_intRowsStart;
    /** @brief Holds true for negative values */
    int m_intRowsCount;
    /** @brief Holds true for negative values */
    int m_intColumnsStart;
    /** @brief Holds true for negative values */
    int m_intColumnsCount;

    /** @brief Holds true for negative values */
    QAxObject * m_ExcelAppPtr;
/** @brief Holds true for negative values */
    QAxObject * m_WorkBooksPtr;
/** @brief Holds true for negative values */
    QAxObject * m_WorkbookPtr;
/** @brief Holds true for negative values */
    QAxObject * m_WorksheetPtr;
/** @brief Holds true for negative values */
    QAxObject * m_UsedRangePtr;
/** @brief Holds true for negative values */
    QAxObject * m_RowsPtr;
/** @brief Holds true for negative values */
    QAxObject * m_ColumnsPtr;
/** @brief Holds true for negative values */
    LoggerCls * m_LoggerPtr;

    const uint8_t m_uchEXCEL_ENTRY_DATE_COLUMN           = 1u;
    const uint8_t m_uchEXCEL_CUSTOMER_NAME_COLUMN        = 2u;
    const uint8_t m_uchEXCEL_DISPATCH_NUMBER_COLUMN      = 3u;
    const uint8_t m_uchEXCEL_PROJECT_NAME_COLUMN         = 4u;
    const uint8_t m_uchEXCEL_PRODUCT_NUMBER_COLUMN       = 5u;
    const uint8_t m_uchEXCEL_PO_NUMBER_COLUMN            = 6u;
    const uint8_t m_uchEXCEL_SOW_NUMBER_COLUMN           = 7u;
    const uint8_t m_uchEXCEL_RECEIVED_QUANTITY_COLUMN    = 8u;
    const uint8_t m_uchEXCEL_ACCEPTED_QUANTITY_COLUMN    = 9u;
    const uint8_t m_uchEXCEL_REJECTED_QUANTITY_COLUMN    = 10u;
    const uint8_t m_uchEXCEL_INTERNAL_SOW_NUMBER_COLUMN  = 11u;
    const uint8_t m_uchEXCEL_BARCODE_NUMBER_COLUMN       = 12u;
    const uint8_t m_uchEXCEL_URGENCY_COLUMN              = 13u;
    const uint8_t m_uchEXCEL_BRAND_DATE_COLUMN           = 14u;
    const uint8_t m_uchEXCEL_SOIR_COLUMN                 = 15u;
    const uint8_t m_uchEXCEL_SALE_DATE_COLUMN            = 16u;

    const uint8_t m_uchCUSTOMER_NAME_COLUMN         = 0u;
    const uint8_t m_uchORDER_ID_COLUMN              = 1U;
    const uint8_t m_uchENTRY_DATE_COLUMN            = 2u;
    const uint8_t m_uchPROJECT_NAME_COLUMN          = 3u;
    const uint8_t m_uchPRODUCT_NUMBER_COLUMN        = 4u;
    const uint8_t m_uchPO_NUMBER_COLUMN             = 5u;
    const uint8_t m_uchSOW_NUMBER_COLUMN            = 6u;
    const uint8_t m_uchRECEIVED_QUANTITY_COLUMN     = 7u;
    const uint8_t m_uchACCEPTED_QUANTITY_COLUMN     = 8u;
    const uint8_t m_uchREJECTED_QUANTITY_COLUMN     = 9u;
    const uint8_t m_uchGKR_NUMBER_COLUMN            = 10u;
    const uint8_t m_uchBARCODE_NUMBER_COLUMN        = 11u;
    const uint8_t m_uchURGENCY_COLUMN               = 12u;
    const uint8_t m_uchBRAND_DATE_COLUMN            = 13u;
    const uint8_t m_uchSOIR_COLUMN                  = 14u;
    const uint8_t m_uchSALE_DATE_COLUMN             = 15u;
    const uint8_t m_uchDISPATCH_NUMBER_COLUMN       = 16u;
    const uint8_t m_uchCOST_COLUMN                  = 17u;
};

#endif // EXCELHANDLERCLS_H
