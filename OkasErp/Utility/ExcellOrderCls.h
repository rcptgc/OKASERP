#ifndef EXCELLORDERCLS_H
#define EXCELLORDERCLS_H
#include <QList>
#include <OrderCls.h>
#include <CustomerCls.h>
#include "ExcelHandlerCls.h"
#include "Utility/LoggerCls.h"
#include <QProgressBar>

/*! \class ExcellOrderCls ExcellOrderCls.h
 *
 *  Docs for MyClassName
 */
class ExcellOrderCls
{
public:
    /** @brief Holds true for negative values */
    ExcellOrderCls();
/** @brief Holds true for negative values */
    ExcelHandlerCls * m_ExcelHandlerPtr;
/** @brief Holds true for negative values */
    void GetOrderInformation(QString a_CustomerNameStr, QString a_FileNameStr, QList<OrderCls> &a_OrderList, QProgressBar * a_ProgressBarPtr);
/** @brief Holds true for negative values */
    LoggerCls * a_LoggerPtr;
private :
    const int32_t m_intEXCEL_ENTRY_DATE_COLUMN           = 1;
    const int32_t m_intEXCEL_DISPATCH_NO_COLUMN          = 2;
    const int32_t m_intEXCEL_PROJECT_NAME_COLUMN         = 3;
    const int32_t m_intEXCEL_PART_NUMBER_COLUMN          = 4;
    const int32_t m_intEXCEL_PO_NAME_COLUMN              = 5;
    const int32_t m_intEXCEL_SOW_NAME_COLUMN             = 6;
    const int32_t m_intEXCEL_RECEIVED_QUANTITY_COLUMN    = 7;
    const int32_t m_intEXCEL_ACCEPTED_QUANTITY_COLUMN    = 8;
    const int32_t m_intEXCEL_REJECTED_QUANTITY_COLUMN    = 9;
    const int32_t m_intEXCEL_COMPANY_SOW_COLUMN          = 10;
    const int32_t m_intEXCEL_BARCODE_NUMBER_COLUMN       = 11;
    const int32_t m_intEXCEL_URGENCY_COLUMN              = 12;
    const int32_t m_intEXCEL_BRAND_DATE_COLUMN           = 13;
    const int32_t m_intEXCEL_SOIR_COLUMN                 = 14;

    const int32_t m_intPROGRESS_DONE_VALUE          = 100;
    const int32_t m_intPROGRESS_FILE_STARTED_VALUE  = 40;
    const int32_t m_intPROGRESS_FILE_OPENED_VALUE   = 50;
};

#endif // EXCELLORDERCLS_H
