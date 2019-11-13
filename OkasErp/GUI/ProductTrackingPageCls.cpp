#include "ProductTrackingPageCls.h"
#include "ui_ProductTrackingPageCls.h"

#include <QFileDialog>

#include "Utility\ExcelHandlerCls.h"
#include <QTableWidgetItem>
#include "Utility/ExcellOrderCls.h"
#include "PageCls.h"


ProductTrackingPageCls::ProductTrackingPageCls(QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::ProductTrackingPageCls)
{
    ui->setupUi(this);
    m_Model = new RelationalModel(ui->tableView);

    if (m_CustNameList.size() != 0)
    {
        m_intPageNum = 1;
        FillProductTable();
        connect(ui->pushButtonAddOrder,       SIGNAL(clicked()),            this, SLOT(ShowExcelCustomerSelectionDialog()));
        connect(ui->pushButtonAssignBarcode,  SIGNAL(clicked()),            this, SLOT(AddBarcodeNumber()));
        connect(ui->lineEditSearch,           SIGNAL(returnPressed()),      this, SLOT(SearchOrderAndUpdateTable()));
        connect(ui->pushButtonBack,           SIGNAL(clicked()),            this, SLOT(ReturnToCustomerSelectionPage()));
        connect(ui->pushButtonAddOrderScreen, SIGNAL(clicked()),            this, SLOT(ShowManualCustomerSelectionDialog()));
        connect(ui->pushButtonReportExcel,    SIGNAL(clicked()),            this, SLOT(CreateExcelReport()));
        connect(ui->pushButtonEraseSelected,  SIGNAL(clicked()),            this, SLOT(EraseOrders()));
        connect(ui->tableView,                SIGNAL(clicked(QModelIndex)), this, SLOT(OrderButtonClicked(QModelIndex )));
        connect(ui->pushButtonNext,           SIGNAL(clicked()),            this, SLOT(NextPressed()));
        connect(ui->pushButtonPrev,           SIGNAL(clicked()),            this, SLOT(PrevPressed()));
        connect(ui->lineEditPageNum,          SIGNAL(returnPressed()),            this, SLOT(PageEntered()));
        this->setWindowTitle("MARISOFT");

        ui->progressBar->setValue(0);
    }
}

void ProductTrackingPageCls::PageEntered()
{
    QString l_PageStr = ui->lineEditPageNum->text();

    int32_t l_intPageNum = l_PageStr.toInt();

    if (l_intPageNum > 0 && l_intPageNum <= m_intMaxPage)
    {
        m_intPageNum = l_intPageNum;
        FillProductTable();
    }
}

void ProductTrackingPageCls::OrderButtonClicked(QModelIndex a_Index)
{
    if (a_Index.column() == m_Model->m_PushButtonColumn)
    {
        GetOrderFromRow(a_Index.row(), m_SelectedOrder);
        LoadPage(PageSelection_OrderLogPage);
        this->hide();
    }
}

void ProductTrackingPageCls::AddBarcodeNumber(void)
{
    foreach (QString l_CustNameStr, m_CustNameList)
    {
        m_DatabasePtr->UpdateBarcodes(l_CustNameStr);
    }

    FillProductTable();
}

void ProductTrackingPageCls::EraseOrders(void)
{
    QList<int> RowList;

    RowList = m_Model->getCheckedRowList();

    foreach (int Row, RowList)
    {
        m_Model->removeRows(Row, 1);

        if( m_Model->submitAll() )
        {
            m_Model->database().commit();
        }
        else
        {
            m_Model->database().rollback();
        }
    }

    FillProductTable();
}

void ProductTrackingPageCls::GetOrderFromRow(int32_t a_Row, OrderCls &a_Order)
{
    a_Order.m_BarcodeNumStr = m_Model->record(a_Row).value(m_uchBARCODE_NUMBER_COLUMN).toString();
    a_Order.m_BrandDateStr  = m_Model->record(a_Row).value(m_uchBRAND_DATE_COLUMN).toString();
    a_Order.m_EntryDateStr  = m_Model->record(a_Row).value(m_uchENTRY_DATE_COLUMN).toString();
    a_Order.m_GKRNumStr     = m_Model->record(a_Row).value(m_uchGKR_NUMBER_COLUMN).toString();
    a_Order.m_DispatchStr   = m_Model->record(a_Row).value(m_uchDISPATCH_NUMBER_COLUMN).toString();
    a_Order.m_PONumStr      = m_Model->record(a_Row).value(m_uchPO_NUMBER_COLUMN).toString();
    a_Order.m_PartNumStr    = m_Model->record(a_Row).value(m_uchPRODUCT_NUMBER_COLUMN).toString();
    a_Order.m_ProjectStr    = m_Model->record(a_Row).value(m_uchPROJECT_NAME_COLUMN).toString();
    a_Order.m_SaleDateStr   = m_Model->record(a_Row).value(m_uchSALE_DATE_COLUMN).toString();
    a_Order.m_SoirStr       = m_Model->record(a_Row).value(m_uchSOIR_COLUMN).toString();
    a_Order.m_SOWNumStr     = m_Model->record(a_Row).value(m_uchSOW_NUMBER_COLUMN).toString();
    a_Order.m_ulnAcptdQty   = m_Model->record(a_Row).value(m_uchACCEPTED_QUANTITY_COLUMN).toUInt();
    a_Order.m_ulnRcvdQty    = m_Model->record(a_Row).value(m_uchRECEIVED_QUANTITY_COLUMN).toUInt();
    a_Order.m_ulnRejctdQty  = m_Model->record(a_Row).value(m_uchREJECTED_QUANTITY_COLUMN).toUInt();
    a_Order.m_UrgencyStr    = m_Model->record(a_Row).value(m_uchURGENCY_COLUMN).toString();
    a_Order.m_CustNameStr   = m_Model->record(a_Row).value(0).toString();
    a_Order.m_ulnID         = m_Model->record(a_Row).value(1).toUInt();
}

void ProductTrackingPageCls::LoadNewOrderPage()
{
    LoadPage(PageSelection_CreateOrderPage);
    this->hide();
}

void ProductTrackingPageCls::FillProductTable(void)
{
    m_Model->setTable("orders");

    QSqlQueryModel l_QueryModel;

    QString l_QueryStr("SELECT customers.CustomerID, COUNT(OrderID) FROM orders "
                       "JOIN customers ON customers.CustomerID = orders.CustomerID "
                       "WHERE ");

    QString l_FilterStr;
    for (int32_t intCustCtr = 0; intCustCtr < PageCls::m_CustNameList.size(); intCustCtr++)
    {
        l_FilterStr.append("CustomerName = ");
        l_FilterStr.append("'" + PageCls::m_CustNameList.at(intCustCtr) + "'");

        if (intCustCtr != (PageCls::m_CustNameList.size() - 1))
        {
           l_FilterStr.append(" OR ");
        }
    }

    l_QueryStr.append(l_FilterStr);
    l_QueryStr.replace("CustomerName", "customers.CustomerName");

    l_QueryModel.setQuery(l_QueryStr);
    qDebug() << l_QueryStr;

    if (l_QueryModel.lastError().isValid())
    {
        qDebug() << l_QueryModel.lastError();
    }

    qDebug() << "Total Count = " << l_QueryModel.record(0).value(1).toString();

    int l_OrderCount = l_QueryModel.record(0).value(1).toInt();
    m_intMaxPage = l_OrderCount / m_intCount;

    if (l_OrderCount % m_intCount != 0)
    {
        m_intMaxPage++;
    }

    m_Model->setRelation(0, QSqlRelation("customers", "CustomerID", "CustomerName"));
    m_Model->setFilter(l_FilterStr);
    m_Model->SetLimit(m_intCount);
    m_Model->SetOffset((m_intPageNum - 1) * m_intCount);
    m_Model->select();


    if (m_Model->lastError().isValid())
    {
        qDebug() << m_Model->lastError();
    }

    QStringList Headers;
    Headers << "Müşteri Adı" << "ID" << "Giriş Tarihi" << "Proje" << "Parça No" << "Sipariş No" << "İş Emri" << "Gön.\r\nAdet"
            << "K.E.\r\nAdet" << "Ret\r\nAdet" << "GKR No" << "Barkod No" << "Acil" << "Mark Tarihi" << "Soir" << "Satış Tarihi"
            << "İrsaliye No";

    int Column = 0;
    foreach (QString header, Headers)
    {
       m_Model->setHeaderData(Column, Qt::Horizontal, header);
       Column++;
    }

    ui->tableView->setModel(m_Model);
    ui->tableView->hideColumn(1);
    ui->tableView->hideColumn(16);

    m_Model->setHeaderData(18, Qt::Horizontal, " ");
    m_Model->setHeaderData(19, Qt::Horizontal, " ");

    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->lineEditPageNum->setText(QString::number(m_intPageNum));
}

void ProductTrackingPageCls::resizeEvent(QResizeEvent *event)
{
    ui->tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeMode::ResizeToContents);
    QMainWindow::resizeEvent(event);
}

void ProductTrackingPageCls::CreateExcelReport()
{
    QTemporaryFile l_TempFile;
    l_TempFile.open();

    QString l_TempFilePath = l_TempFile.fileName();

    l_TempFile.close();

    l_TempFilePath += ".xls";

    QFile l_TemplateFile(":/new/prefix1/ReportTemplate2.xlsx");
    l_TemplateFile.copy(QDir::toNativeSeparators(l_TempFilePath));
    ExcelHandlerCls l_ExcelHandler(l_TempFilePath);
    l_ExcelHandler.CreateReport(*m_Model);
}

void ProductTrackingPageCls::SearchOrderAndUpdateTable()
{
    QString l_SearchedTextStr = ui->lineEditSearch->text();

    if (false == l_SearchedTextStr.isEmpty())
    {
        QString l_FilterStr = QString("BarcodeNum = '%1' OR GKRNum = '%1' OR PONum = '%1' OR PartNum = '%1' OR "
                                      "Project = '%1' OR Soir = '%1' OR SOWNum = '%1' OR Urgency = '%1' OR "
                                      "CustomerName = '%1' OR DispNum = '%1'"
                                     ).arg(l_SearchedTextStr);
        m_Model->setTable("orders");

        m_Model->setRelation(0, QSqlRelation("customers", "CustomerID", "CustomerName"));
        m_Model->setFilter(l_FilterStr);
        m_Model->select();

        if (m_Model->lastError().isValid())
        {
            qDebug() << m_Model->lastError();
        }

        QStringList Headers;
        Headers << "Müşteri Adı" << "ID" << "Giriş Tarihi" << "Proje" << "Parça No" << "Sipariş No" << "İş Emri" << "Gön.\r\nAdet"
                << "K.E.\r\nAdet" << "Ret\r\nAdet" << "GKR No" << "Barkod No" << "Acil" << "Mark Tarihi" << "Soir" << "Satış Tarihi"
                << "İrsaliye No";
        int Column = 0;
        foreach (QString header, Headers)
        {
           m_Model->setHeaderData(Column, Qt::Horizontal, header);
           Column++;
        }

        ui->tableView->setModel(m_Model);

        ui->tableView->hideColumn(1);
        ui->tableView->hideColumn(16);
    }
    else
    {
        FillProductTable();
    }
}

void ProductTrackingPageCls::ReturnToCustomerSelectionPage()
{
    LoadPage(PageSelection_CustomerSelectionPage);
    delete this;
}

void ProductTrackingPageCls::ShowExcelCustomerSelectionDialog()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    m_intEntryMethod = BY_EXCEL;
    m_CustomerFormPtr = new QMainWindow(this);

    m_CustomerFormPtr->resize(320, 240);

    m_CustomerSelectionPtr = new QComboBox(m_CustomerFormPtr);

    QPushButton * l_ButtonPtr = new QPushButton(m_CustomerFormPtr);

    m_CustomerSelectionPtr->move(50, 50);
    l_ButtonPtr->move(200, 50);

    foreach (QString CustNameStr, PageCls::m_CustNameList)
    {
        m_CustomerSelectionPtr->addItem(CustNameStr);
    }

    connect(l_ButtonPtr, SIGNAL(clicked()), this, SLOT(ReturnToThisPage())) ;

    l_ButtonPtr->setText("TAMAM");

    this->hide();

    m_CustomerFormPtr->show();
}

void ProductTrackingPageCls::ShowManualCustomerSelectionDialog()
{
    m_intEntryMethod = BY_ENTRY;
    m_CustomerFormPtr = new QMainWindow(this);

    m_CustomerFormPtr->resize(m_ushCUSTOMER_FORM_WIDTH, m_ushCUSTOMER_FORM_HEIGHT);
    m_CustomerSelectionPtr = new QComboBox(m_CustomerFormPtr);
    QPushButton * l_ButtonPtr = new QPushButton(m_CustomerFormPtr);

    m_CustomerSelectionPtr->move(m_ushCUSTOMER_COMBO_POS_X, m_ushCUSTOMER_COMBO_POS_Y);
    l_ButtonPtr->move(m_ushBUTTON_POS_X, m_ushBUTTON_POS_Y);

    foreach (QString CustNameStr, PageCls::m_CustNameList)
    {
        m_CustomerSelectionPtr->addItem(CustNameStr);
    }
    connect(l_ButtonPtr, SIGNAL(clicked()), this, SLOT(ReturnToThisPage())) ;
    l_ButtonPtr->setText("TAMAM");
    this->hide();
    m_CustomerFormPtr->show();

}

void ProductTrackingPageCls::NextPressed()
{
    if (m_intPageNum < m_intMaxPage)
    {
        m_intPageNum++;
        FillProductTable();
    }
}

void ProductTrackingPageCls::PrevPressed()
{
    if (m_intPageNum > 1)
    {
        m_intPageNum--;
    }
    FillProductTable();
}

void ProductTrackingPageCls::ReturnToThisPage()
{
    QString l_SelectedCustomerStr;
    l_SelectedCustomerStr = m_CustomerSelectionPtr->currentText();

    if (m_intEntryMethod == BY_EXCEL)
    {
        this->show();
        m_CustomerFormPtr->hide();
        QString l_FileNameStr = QFileDialog::getOpenFileName(this, tr("Open Excel"), "/home", tr("Excel Files (*.xls *.xlsx)"));
        QList<OrderCls> l_NewOrdersList;
        ExcellOrderCls l_ExcelOrderHandler;

        if (l_FileNameStr.isEmpty() == false)
        {
            l_ExcelOrderHandler.GetOrderInformation(l_SelectedCustomerStr, l_FileNameStr, l_NewOrdersList, ui->progressBar);
        }
        foreach (OrderCls l_Order, l_NewOrdersList)
        {
            m_DatabasePtr->AddOrder(l_Order);
        }
        FillProductTable();
        ui->progressBar->setValue(0u);
    }
    else
    {
        m_CustomerFormPtr->hide();

        LoadPage(PageSelection_CreateOrderPage, l_SelectedCustomerStr);

        this->hide();
    }

}

ProductTrackingPageCls::~ProductTrackingPageCls()
{
    delete ui;
}
