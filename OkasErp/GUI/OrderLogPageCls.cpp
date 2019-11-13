#include "OrderLogPageCls.h"
#include "ui_OrderLogPageCls.h"

#include "OrderLogCls.h"
#include "Utility/UtilsCls.h"

OrderLogPageCls::OrderLogPageCls(QWidget *parent) : QMainWindow(parent), ui(new Ui::OrderLogPageCls)
{
    ui->setupUi(this);

    connect(ui->tableWidget->horizontalHeader(),SIGNAL(sectionClicked(int)), ui->tableWidget, SLOT(sortByColumn(int)));

    connect(ui->pushButtonReturn, SIGNAL(clicked()), this, SLOT(LoadProductTrackingPage()));
    connect(ui->pushButtonSave, SIGNAL(clicked()), this, SLOT(SaveChanges()));
    connect(ui->pushButtonDelete, SIGNAL(clicked()), this, SLOT(EraseOrderLogs()));
    FillTable();
}

OrderLogPageCls::~OrderLogPageCls()
{
    delete ui;
}

void OrderLogPageCls::FillTable(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    QString l_DateStr;
    QString l_TimeStr;
    int32_t l_intRow = 0;
    OrderCls l_Order;
    QDate l_Date;
    QTime l_Time;
    QString l_TypeStr;

    l_Order = PageCls::m_SelectedOrder;

    ui->tableWidget->m_CheckedRowsList.clear();
    m_DatabasePtr->GetOrderLogList(l_Order, m_OrderLogList);

    ui->tableWidget->setColumnCount(m_uchTABLE_COLUMN_COUNT);
    ui->tableWidget->setRowCount(m_OrderLogList.size());
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setRowCount(m_OrderLogList.size());

    foreach (OrderLogStc l_OrderLog, m_OrderLogList)
    {
        l_Date = l_OrderLog.m_Date;
        l_Time = l_OrderLog.m_Time;
        l_DateStr = UtilsCls::GetDateString(l_Date);
        l_TimeStr = UtilsCls::GetTimeString(l_Time);

        LogDateTypeEnum l_enmDateType = l_OrderLog.m_enmDateType;
        QString l_NotesStr = l_OrderLog.m_NotesStr;
        QString l_OperatorName = l_OrderLog.m_OperatorNameStr;
        QString l_ProcessedQuantity = QString::number(l_OrderLog.m_ulnProcessedQuantity);
        QString l_OperationStr = l_OrderLog.m_Operation.m_NameStr;
        int32_t l_intOrderLogID = l_OrderLog.m_intOrderLogID;
        int32_t l_intLineCount = l_NotesStr.count('\n') + 1;
        int32_t l_intRowHeight = ui->tableWidget->rowHeight(l_intRow);
        l_TypeStr = (l_enmDateType == LogDateType_Start) ? "Başlangıç" : "Bitiş";

        ui->tableWidget->setItem(l_intRow, m_uchORDER_ID_COLUMN             , new QTableWidgetItem(QString::number(l_OrderLog.m_ulnOrderID)));
        ui->tableWidget->setItem(l_intRow, m_uchRECEIVED_QUANTITY_COLUMN    , new QTableWidgetItem(QString::number(l_OrderLog.m_ulnReceivedQuantity)));
        ui->tableWidget->setItem(l_intRow, m_uchDATE_COLUMN                 , new QTableWidgetItem(l_DateStr));
        ui->tableWidget->setItem(l_intRow, m_uchTIME_COLUMN                 , new QTableWidgetItem(l_TimeStr));
        ui->tableWidget->setItem(l_intRow, m_uchNOTES_COLUMN                , new QTableWidgetItem(l_NotesStr));
        ui->tableWidget->setItem(l_intRow, m_uchOPERATOR_NAME_COLUMN        , new QTableWidgetItem(l_OperatorName));
        ui->tableWidget->setItem(l_intRow, m_uchPROCESSED_QUANTITY_COLUMN   , new QTableWidgetItem(l_ProcessedQuantity));
        ui->tableWidget->setItem(l_intRow, m_uchOPERATION_COLUMN            , new QTableWidgetItem(l_OperationStr));
        ui->tableWidget->setItem(l_intRow, m_uchDATE_TYPE_COLUMN            , new QTableWidgetItem(l_TypeStr));
        ui->tableWidget->setItem(l_intRow, m_uchORDER_LOG_ID_COLUMN         , new QTableWidgetItem(QString::number(l_intOrderLogID)));

        ui->tableWidget->setRowHeight(l_intRow, (l_intLineCount * l_intRowHeight));

        l_intRow++;
    }

    QStringList l_Headers;

    l_Headers << "ORDER ID"
              << "K.E\r\nMiktar"
              << "İşlenen\r\nMiktar"
              << "İşlem"
              << "Çalışan Adı"
              << "Tarih"
              << "Saat"
              << "Zaman"
              << "Notlar"
              << "Log ID"
              << " ";

    ui->tableWidget->setHorizontalHeaderLabels(l_Headers);
}

void OrderLogPageCls::LoadProductTrackingPage()
{
    LoadPage(PageSelection_ProductTrackingPage);
    delete this;
}

void OrderLogPageCls::GetOrderLogFromRow(int32_t a_Row, OrderLogStc &a_OrderLog)
{
    uint32_t l_ulnOrderID           = ui->tableWidget->item(a_Row, m_uchORDER_ID_COLUMN)->text().toUInt();
    uint32_t l_ulnReceivedQuantity  = ui->tableWidget->item(a_Row, m_uchRECEIVED_QUANTITY_COLUMN)->text().toUInt();
    uint32_t l_ulnProcessedQuantity = ui->tableWidget->item(a_Row, m_uchPROCESSED_QUANTITY_COLUMN)->text().toUInt();
    QString l_OperationStr          = ui->tableWidget->item(a_Row, m_uchOPERATION_COLUMN)->text();
    QString l_OperatorNameStr       = ui->tableWidget->item(a_Row, m_uchOPERATOR_NAME_COLUMN)->text();
    QString l_DateStr               = ui->tableWidget->item(a_Row, m_uchDATE_COLUMN)->text();
    QString l_DateTypeStr           = ui->tableWidget->item(a_Row, m_uchDATE_TYPE_COLUMN)->text();
    int32_t l_intOrderLogID         = ui->tableWidget->item(a_Row, m_uchORDER_LOG_ID_COLUMN)->text().toInt();

    OperationStc l_Operation;
    l_Operation.m_NameStr = l_OperationStr;
    l_Operation.m_ulnID = (a_OrderLog.m_OperationMap.key(l_OperationStr) + 1);

    QDate l_Date = QDate::fromString(l_DateStr,"yyyy-M-d");

    QString l_TimeStr = ui->tableWidget->item(a_Row, m_uchTIME_COLUMN)->text();
    QTime l_Time = QTime::fromString(l_TimeStr, "hh:mm:ss");

    QString l_NotesStr = ui->tableWidget->item(a_Row, m_uchNOTES_COLUMN)->text();

    LogDateTypeEnum l_enmType;
    if (QString::compare("Başlangıç", l_DateTypeStr) == 0)
    {
        l_enmType = LogDateType_Start;
    }
    else
    {
        l_enmType = LogDateType_Finish;
    }

    a_OrderLog.m_intOrderLogID = l_intOrderLogID;
    a_OrderLog.m_Date = l_Date;
    a_OrderLog.m_Time = l_Time;
    a_OrderLog.m_NotesStr = l_NotesStr;
    a_OrderLog.m_Operation = l_Operation;
    a_OrderLog.m_OperatorNameStr = l_OperatorNameStr;
    a_OrderLog.m_ulnOrderID = l_ulnOrderID;
    a_OrderLog.m_ulnProcessedQuantity = l_ulnProcessedQuantity;
    a_OrderLog.m_ulnReceivedQuantity = l_ulnReceivedQuantity;
    a_OrderLog.m_enmDateType = l_enmType;
}

void OrderLogPageCls::SaveChanges()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    foreach (const int32_t &l_intRow, ui->tableWidget->m_EditedRowsList)
    {
        OrderLogStc l_OrderLog;
        GetOrderLogFromRow(l_intRow, l_OrderLog);
        m_DatabasePtr->UpdateOrderLog(l_OrderLog);
    }

    m_LoggerPtr->DisplayInformation("Kaydedildi!", this);
}

void OrderLogPageCls::EraseOrderLogs(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    QList<OrderLogStc> l_DeletedOrdersList;

    foreach (const int32_t &l_intRow, ui->tableWidget->m_CheckedRowsList)
    {
        l_DeletedOrdersList.append(m_OrderLogList[l_intRow]);
    }

    foreach (OrderLogStc l_OrderLog, l_DeletedOrdersList)
    {
        m_DatabasePtr->RemoveOrderLog(l_OrderLog.m_intOrderLogID);
    }

    FillTable();
}
