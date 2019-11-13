#include "ExcelHandlerCls.h"
#include <QFileDialog>

ExcelHandlerCls::ExcelHandlerCls(QString a_FilePathStr)
{
    m_LoggerPtr = LoggerCls::instance();
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    m_ExcelAppPtr = new QAxObject("Excel.Application", nullptr);
    m_ExcelAppPtr->setProperty("Visible", false);

    m_WorkBooksPtr = m_ExcelAppPtr->querySubObject("WorkBooks");
    m_WorkBooksPtr->dynamicCall("Open (const QString&)", a_FilePathStr);

    m_WorkbookPtr   = m_ExcelAppPtr->querySubObject("ActiveWorkBook");
    m_WorksheetPtr  = m_WorkbookPtr->querySubObject("Worksheets(int)", 1);
    m_UsedRangePtr  = m_WorksheetPtr->querySubObject("UsedRange");
    m_RowsPtr       = m_UsedRangePtr->querySubObject("Rows");
    m_ColumnsPtr    = m_UsedRangePtr->querySubObject("Columns");

    m_intRowsStart      = m_UsedRangePtr->property("Row").toInt();
    m_intRowsCount      = m_RowsPtr->property("Count").toInt();
    m_intColumnsStart   = m_UsedRangePtr->property("Column").toInt();
    m_intColumnsCount   = m_ColumnsPtr->property("Count").toInt();

}

int ExcelHandlerCls::GetRowCount(void)
{
    return m_intRowsCount;
}

int ExcelHandlerCls::GetRowsStart() const
{
    return m_intRowsStart;
}

bool ExcelHandlerCls::SetCellValue(int32_t a_intRow, int32_t a_intColumn, QVariant a_Value)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    QAxObject * l_CellPtr;

    l_CellPtr = m_ExcelAppPtr->querySubObject("Cells(Int, Int)", a_intRow, a_intColumn);
    l_CellPtr->setProperty("Value", a_Value.toString());

    QVariant val = l_CellPtr->dynamicCall("value");
    return true;
}

QVariant ExcelHandlerCls::GetCellValue(int32_t a_intRow, int32_t a_intColumn)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    QAxObject * l_CellPtr;

    l_CellPtr = m_ExcelAppPtr->querySubObject("Cells(Int, Int)", a_intRow, a_intColumn );

    QVariant l_CellValue = l_CellPtr->dynamicCall("value");

    return l_CellValue;
}

bool ExcelHandlerCls::AccessFile()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    return true;
}

bool ExcelHandlerCls::SaveFile()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_WorkbookPtr->dynamicCall("Save()");

    return true;
}

bool ExcelHandlerCls::CloseFile()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    m_WorkbookPtr->dynamicCall("Close()");
    m_ExcelAppPtr->dynamicCall("Quit()");

    delete m_WorkbookPtr;
    delete m_ExcelAppPtr;
    return true;
}

void ExcelHandlerCls::SaveAs(QString a_SavefilenameStr)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    SaveFile();
    QVariant l_Param;
    l_Param = static_cast<QVariant>(a_SavefilenameStr);
    m_WorkbookPtr->dynamicCall("SaveCopyAs  (QVariant)", l_Param);
}

void ExcelHandlerCls::CreateReport(QSqlTableModel &l_Model)
{

    int32_t l_intRowToWrite = 2;

    for (int RowCtr = 0; RowCtr < l_Model.rowCount(); RowCtr++)
    {
        SetCellValue(l_intRowToWrite, m_uchEXCEL_ENTRY_DATE_COLUMN,          l_Model.record(RowCtr).value(m_uchENTRY_DATE_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_CUSTOMER_NAME_COLUMN,       l_Model.record(RowCtr).value(m_uchCUSTOMER_NAME_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_DISPATCH_NUMBER_COLUMN,     l_Model.record(RowCtr).value(m_uchDISPATCH_NUMBER_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_PROJECT_NAME_COLUMN,        l_Model.record(RowCtr).value(m_uchPROJECT_NAME_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_PRODUCT_NUMBER_COLUMN,      l_Model.record(RowCtr).value(m_uchPRODUCT_NUMBER_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_PO_NUMBER_COLUMN,           l_Model.record(RowCtr).value(m_uchEXCEL_PO_NUMBER_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_SOW_NUMBER_COLUMN,          l_Model.record(RowCtr).value(m_uchSOW_NUMBER_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_RECEIVED_QUANTITY_COLUMN,   l_Model.record(RowCtr).value(m_uchRECEIVED_QUANTITY_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_ACCEPTED_QUANTITY_COLUMN,   l_Model.record(RowCtr).value(m_uchACCEPTED_QUANTITY_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_REJECTED_QUANTITY_COLUMN,   l_Model.record(RowCtr).value(m_uchREJECTED_QUANTITY_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_INTERNAL_SOW_NUMBER_COLUMN, l_Model.record(RowCtr).value(m_uchGKR_NUMBER_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_BARCODE_NUMBER_COLUMN,      l_Model.record(RowCtr).value(m_uchBARCODE_NUMBER_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_URGENCY_COLUMN,             l_Model.record(RowCtr).value(m_uchURGENCY_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_BRAND_DATE_COLUMN,          l_Model.record(RowCtr).value(m_uchBRAND_DATE_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_SOIR_COLUMN,                l_Model.record(RowCtr).value(m_uchSOIR_COLUMN).toString());
        SetCellValue(l_intRowToWrite, m_uchEXCEL_SALE_DATE_COLUMN,           l_Model.record(RowCtr).value(m_uchSALE_DATE_COLUMN).toString());

        l_intRowToWrite++;
    }

    QString l_FileStr = "Production_Report.xlsx";
    QString l_PathStr = QFileDialog::getExistingDirectory();

    SaveAs(l_PathStr + "/" + l_FileStr);
    CloseFile();
}

