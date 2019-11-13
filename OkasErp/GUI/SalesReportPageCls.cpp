#include "SalesReportPageCls.h"
#include "ui_SalesReportPageCls.h"
#include "Utility\ExcelHandlerCls.h"
#include "Utility/UtilsCls.h"
#include <QFileDialog>
#include "CustomerCls.h"

SalesReportPageCls::SalesReportPageCls(QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::SalesReportPageCls)
{
    ui->setupUi(this);

    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    ui->dateEditStartDate->setDate(QDate::currentDate());
    ui->dateEditEndDate->setDate(QDate::currentDate());

    this->setWindowTitle("MARISOFT");

    connect(ui->pushButtonShowSelected,   SIGNAL(clicked()), this, SLOT(ShowSelectedSales()));
    connect(ui->pushButtonSelectedReport, SIGNAL(clicked()), this, SLOT(CreateReportFromTable()));
    connect(ui->pushButtonReturn,         SIGNAL(clicked()), this, SLOT(LoadSalesMainPage()));

}

SalesReportPageCls::~SalesReportPageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    delete ui;
}

void SalesReportPageCls::CreateReportFromTable()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    QTemporaryFile l_TempFile;
    l_TempFile.open();

    QString l_TempFilePathStr = l_TempFile.fileName();

    l_TempFile.close();

    l_TempFilePathStr += ".xls";

    QFile l_TemplateFile(":/new/prefix1/ReportTemplate.xlsx");
    l_TemplateFile.copy(QDir::toNativeSeparators(l_TempFilePathStr));

    ExcelHandlerCls l_ExcelHandler(l_TempFilePathStr);

    int32_t l_intRowToWrite = m_uchEXCEL_FIRST_ROW;

    foreach (OrderCls Order, m_SaleOrderList)
    {
        l_ExcelHandler.SetCellValue(l_intRowToWrite, m_uchEXCEL_PRODUCT_NUMBER_COLUMN,      Order.m_PartNumStr);
        l_ExcelHandler.SetCellValue(l_intRowToWrite, m_uchEXCEL_PO_NUMBER_COLUMN,           Order.m_PONumStr);
        l_ExcelHandler.SetCellValue(l_intRowToWrite, m_uchEXCEL_SOW_NUMBER_COLUMN,          Order.m_SOWNumStr);
        l_ExcelHandler.SetCellValue(l_intRowToWrite, m_uchEXCEL_ACCEPTED_QUANTITY_COLUMN,   QString::number(Order.m_ulnAcptdQty));
        l_ExcelHandler.SetCellValue(l_intRowToWrite, m_uchEXCEL_INTERNAL_SOW_NUMBER_COLUMN, Order.m_GKRNumStr);
        l_ExcelHandler.SetCellValue(l_intRowToWrite, m_uchEXCEL_SALE_DATE_COLUMN,           Order.m_SaleDateStr);
        l_ExcelHandler.SetCellValue(l_intRowToWrite, m_uchEXCEL_COST_COLUMN,                Order.m_CostStr);
        l_intRowToWrite++;
    }

    QString l_FileStr = "Sales_Report.xlsx";
    QString l_PathStr = QFileDialog::getExistingDirectory(this);

    l_ExcelHandler.SaveAs(l_PathStr + "/" + l_FileStr);
    l_ExcelHandler.CloseFile();
}

void SalesReportPageCls::ShowSelectedSales()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    QString l_SelectedCustomerNameStr = ui->lineEditCustomerName->text();

    QDate l_StartDate = ui->dateEditStartDate->date();
    QString l_StartDateStr = UtilsCls::GetDateString(l_StartDate);

    QDate l_EndDate = ui->dateEditEndDate->date();
    QString l_EndDateStr = UtilsCls::GetDateString(l_EndDate);

    m_SaleOrderList.clear();

    CustomerCls l_Customer;

    if (m_DatabasePtr->GetCustomer(l_Customer, l_SelectedCustomerNameStr) == true)
    {
        m_DatabasePtr->GetOrderList(l_SelectedCustomerNameStr, l_StartDateStr, l_EndDateStr, m_SaleOrderList);
    }
    else
    {
        m_DatabasePtr->GetOrderList(l_StartDateStr, l_EndDateStr, m_SaleOrderList);
    }

    FillSalesTable(m_SaleOrderList);
}

void SalesReportPageCls::FillSalesTable(QList<OrderCls> a_OrderList)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    int32_t l_intRow = 0;

    ui->tableWidget->clear();

    ui->tableWidget->setColumnCount(m_uchTABLE_COLUMN_COUNT);
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->insertRows(a_OrderList.size());

    foreach (OrderCls l_Order, a_OrderList)
    {
        ui->tableWidget->setItem(l_intRow, m_uchBARCODE_NUMBER_COLUMN,      new QTableWidgetItem(l_Order.m_BarcodeNumStr));
        ui->tableWidget->setItem(l_intRow, m_uchCUSTOMER_NAME_COLUMN,       new QTableWidgetItem(l_Order.m_CustNameStr));
        ui->tableWidget->setItem(l_intRow, m_uchBRAND_DATE_COLUMN,          new QTableWidgetItem(l_Order.m_BrandDateStr));
        ui->tableWidget->setItem(l_intRow, m_uchENTRY_DATE_COLUMN,          new QTableWidgetItem(l_Order.m_EntryDateStr));
        ui->tableWidget->setItem(l_intRow, m_uchINTERNAL_SOW_NUMBER_COLUMN, new QTableWidgetItem(l_Order.m_GKRNumStr));
        ui->tableWidget->setItem(l_intRow, m_uchPO_NUMBER_COLUMN,           new QTableWidgetItem(l_Order.m_PONumStr));
        ui->tableWidget->setItem(l_intRow, m_uchPRODUCT_NUMBER_COLUMN,      new QTableWidgetItem(l_Order.m_PartNumStr));
        ui->tableWidget->setItem(l_intRow, m_uchPROJECT_NAME_COLUMN,        new QTableWidgetItem(l_Order.m_ProjectStr));
        ui->tableWidget->setItem(l_intRow, m_uchSALE_DATE_COLUMN,           new QTableWidgetItem(l_Order.m_SaleDateStr));
        ui->tableWidget->setItem(l_intRow, m_uchSOIR_COLUMN,                new QTableWidgetItem(l_Order.m_SoirStr));
        ui->tableWidget->setItem(l_intRow, m_uchSOW_NUMBER_COLUMN,          new QTableWidgetItem(l_Order.m_SOWNumStr));
        ui->tableWidget->setItem(l_intRow, m_uchACCEPTED_QUANTITY_COLUMN,   new QTableWidgetItem(QString::number(l_Order.m_ulnAcptdQty)));
        ui->tableWidget->setItem(l_intRow, m_uchRECEIVED_QUANTITY_COLUMN,   new QTableWidgetItem(QString::number(l_Order.m_ulnRcvdQty)));
        ui->tableWidget->setItem(l_intRow, m_uchREJECTED_QUANTITY_COLUMN,   new QTableWidgetItem(QString::number(l_Order.m_ulnRejctdQty)));
        ui->tableWidget->setItem(l_intRow, m_uchURGENCY_COLUMN,             new QTableWidgetItem(l_Order.m_UrgencyStr));
        ui->tableWidget->setItem(l_intRow, m_uchPRICE_COLUMN,               new QTableWidgetItem(l_Order.m_CostStr));
        ui->tableWidget->setItem(l_intRow, m_uchDISPATCH_NUMBER_COLUMN,     new QTableWidgetItem(l_Order.m_DispatchStr));

        l_intRow++;
    }
    QStringList l_Headers;

    l_Headers << "Giriş Tarihi"
              << "Müşteri Adı"
              << "Proje Adı"
              << "Parça No"
              << "Sipariş No"
              << "İş Emri"
              << "Gön.\r\nAdet"
              << "K.E.\r\nAdet"
              << "Ret\r\nAdet"
              << "GKR No"
              << "Barkod No"
              << "Acil"
              << "Markalama\r\nTarihi"
              << "Soir"
              << "Satış\r\nTarihi"
              << "Fiyat"
              << "İrsaliye\r\nNo";

    ui->tableWidget->setHorizontalHeaderLabels(l_Headers);

}

void SalesReportPageCls::LoadSalesMainPage()
{
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    LoadPage(PageSelection_SalesInformationPage);

    delete this;
}
