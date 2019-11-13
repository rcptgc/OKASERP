#include "ExcellOrderCls.h"


ExcellOrderCls::ExcellOrderCls()
{
    a_LoggerPtr = LoggerCls::instance();
    a_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
}

void ExcellOrderCls::GetOrderInformation(QString a_CustomerNameStr, QString a_FileNameStr, QList<OrderCls> &a_OrderList, QProgressBar * a_ProgressBarPtr)
{

    a_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    if (false == a_CustomerNameStr.isEmpty())
    {
        a_ProgressBarPtr->setMaximum(m_intPROGRESS_DONE_VALUE);

        a_ProgressBarPtr->setValue(m_intPROGRESS_FILE_STARTED_VALUE);

        QVariant l_CellValue;
        m_ExcelHandlerPtr = new ExcelHandlerCls(a_FileNameStr);


        a_ProgressBarPtr->setValue(m_intPROGRESS_FILE_OPENED_VALUE);

        int l_intRowsCount = m_ExcelHandlerPtr->GetRowCount();
        int l_intRowsStart = m_ExcelHandlerPtr->GetRowsStart();

        for (int32_t l_intRowCounter = (l_intRowsStart + 1); l_intRowCounter <= l_intRowsCount; l_intRowCounter++)
        {

            a_ProgressBarPtr->setValue(m_intPROGRESS_FILE_OPENED_VALUE + (m_intPROGRESS_FILE_OPENED_VALUE * l_intRowCounter) / l_intRowsCount);

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_ENTRY_DATE_COLUMN);
            QString l_DateStr = l_CellValue.toString();
            QStringList l_StrList = l_DateStr.split(".");

            OrderCls * l_NewOrderPtr = new OrderCls();
            QString l_EntryDateStr = l_StrList.at(2) + "-" + l_StrList.at(1) + "-" + l_StrList.at(0);

            l_NewOrderPtr->m_EntryDateStr = l_EntryDateStr;

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_PROJECT_NAME_COLUMN);
            l_NewOrderPtr->m_ProjectStr = l_CellValue.toString();

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_DISPATCH_NO_COLUMN);
            l_NewOrderPtr->m_DispatchStr = l_CellValue.toString();

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_PART_NUMBER_COLUMN);
            l_NewOrderPtr->m_PartNumStr = l_CellValue.toString();

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_PO_NAME_COLUMN);
            l_NewOrderPtr->m_PONumStr = (l_CellValue.toString());

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_SOW_NAME_COLUMN);
            l_NewOrderPtr->m_SOWNumStr = l_CellValue.toString();

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_RECEIVED_QUANTITY_COLUMN);
            l_NewOrderPtr->m_ulnRcvdQty = l_CellValue.toUInt();

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_ACCEPTED_QUANTITY_COLUMN);
            l_NewOrderPtr->m_ulnAcptdQty = l_CellValue.toUInt();

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_REJECTED_QUANTITY_COLUMN);
            l_NewOrderPtr->m_ulnRejctdQty = l_CellValue.toUInt();

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_COMPANY_SOW_COLUMN);
            l_NewOrderPtr->m_GKRNumStr = l_CellValue.toString();

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_BARCODE_NUMBER_COLUMN);
            l_NewOrderPtr->m_BarcodeNumStr = l_CellValue.toString();

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_URGENCY_COLUMN);
            l_NewOrderPtr->m_UrgencyStr = l_CellValue.toString();

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_BRAND_DATE_COLUMN);
            l_NewOrderPtr->m_BrandDateStr = l_CellValue.toString();

            l_CellValue = m_ExcelHandlerPtr->GetCellValue(l_intRowCounter, m_intEXCEL_SOIR_COLUMN);
            l_NewOrderPtr->m_SoirStr = l_CellValue.toString();

            l_NewOrderPtr->m_CustNameStr = a_CustomerNameStr;

            a_OrderList.append(*l_NewOrderPtr);
        }
    }
}
