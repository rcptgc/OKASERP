#include "SalesEntryPageCls.h"
#include "ui_SalesEntryPageCls.h"
#include "Utility/UtilsCls.h"

SalesEntryPageCls::SalesEntryPageCls(QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::SalesEntryPageCls)
{
    ui->setupUi(this);

    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    m_blnBarcodeReadStarted = false;
    ui->centralwidget->setFocus();

    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");

    connect(ui->lineEdit,              SIGNAL(returnPressed()), this, SLOT(AddSaleToTable()));
    connect(ui->pushButtonBarcodeRead, SIGNAL(clicked()),       this, SLOT(StartBarcodeReading()));
    connect(ui->pushButtonReturn,      SIGNAL(clicked()),       this, SLOT(LoadSalesMainPage()));
    connect(ui->pushButtonAssignDate,  SIGNAL(clicked()),       this, SLOT(AssignDate()));
    connect(ui->pushButtonSave,        SIGNAL(clicked()),       this, SLOT(SaveSalesInTable()));
}

SalesEntryPageCls::~SalesEntryPageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    delete ui;
}

void SalesEntryPageCls::AddSaleToTable()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    if (m_blnBarcodeReadStarted == true)
    {
        QString l_BarcodeStr;

        l_BarcodeStr = ui->lineEdit->text();

        OrderCls l_Order;

        if (m_DatabasePtr->GetOrder(l_Order, l_BarcodeStr) == true)
        {
            ui->tableWidget->setColumnCount(m_uchTABLE_COLUMN_COUNT);
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);

            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, m_uchBARCODE_COLUMN,      new QTableWidgetItem(l_Order.m_BarcodeNumStr));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, m_uchSOW_NUMBER_COLUMN,   new QTableWidgetItem(l_Order.m_SOWNumStr));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, m_uchSALE_DATE_COLUMN,    new QTableWidgetItem(l_Order.m_SaleDateStr));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, m_uchCOST_COLUMN,         new QTableWidgetItem(l_Order.m_CostStr));

            ui->tableWidget->setHorizontalHeaderItem(m_uchBARCODE_COLUMN,       new QTableWidgetItem("Barkod No"));
            ui->tableWidget->setHorizontalHeaderItem(m_uchSOW_NUMBER_COLUMN,    new QTableWidgetItem("İş Emri"));
            ui->tableWidget->setHorizontalHeaderItem(m_uchSALE_DATE_COLUMN,     new QTableWidgetItem("Satış Tarihi"));
            ui->tableWidget->setHorizontalHeaderItem(m_uchCOST_COLUMN,          new QTableWidgetItem("Fiyat"));
        }
    }
    else
    {
        ui->lineEdit->clear();
    }
}

void SalesEntryPageCls::StartBarcodeReading()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    m_blnBarcodeReadStarted = true;
    ui->lineEdit->setFocus();
}

void SalesEntryPageCls::AssignDate()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    OrderCls l_Order;

    for (int32_t l_intRowCtr = 0; l_intRowCtr < ui->tableWidget->rowCount(); l_intRowCtr++)
    {
        if (m_DatabasePtr->GetOrder(l_Order, ui->tableWidget->item(l_intRowCtr, m_uchBARCODE_COLUMN)->data(0).toString()) == true)
        {
            QDate l_CurrDate = QDate::currentDate();
            QString l_DateStr = UtilsCls::GetDateString(l_CurrDate);
            QTableWidgetItem * l_Item3Ptr = new QTableWidgetItem(l_DateStr);
            ui->tableWidget->setItem(l_intRowCtr, 2, l_Item3Ptr);
        }
    }
}

void SalesEntryPageCls::SaveSalesInTable()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    for (int32_t l_intRowCtr = 0; l_intRowCtr < ui->tableWidget->rowCount(); l_intRowCtr++)
    {
        OrderCls l_Order;

        if (m_DatabasePtr->GetOrder(l_Order, ui->tableWidget->item(l_intRowCtr, m_uchBARCODE_COLUMN)->data(0).toString()) == true)
        {
            l_Order.m_SaleDateStr = UtilsCls::GetDateString(QDate::currentDate());
            l_Order.m_CostStr = ui->tableWidget->item(l_intRowCtr, m_uchCOST_COLUMN)->data(0).toString();
            m_DatabasePtr->UpdateOrderSaleDate(l_Order);
        }
    }
}

void SalesEntryPageCls::LoadSalesMainPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_SalesInformationPage);

    delete this;

}
