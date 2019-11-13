#include "CustomerSelectionPageCls.h"
#include "ui_CustomerSelectionPage.h"

static const uint8_t s_uchCUSTOMER_NAME_COLUMN  = 0U;
static const uint8_t s_uchCHECKBOX_COLUMN       = 1U;
static const uint8_t s_uchCUSTOMER_NAME_COLUMN_WIDTH = 150U;
static const uint8_t s_uchCHECKBOX_COLUMN_WIDTH = 5U;

CustomerSelectionPageCls::CustomerSelectionPageCls(QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::CustomerSelectionPage)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    ui->setupUi(this);

    m_Model = new RModel(ui->tableView);
    connect(m_Model,                    SIGNAL(RowChecked(int, bool)),      this, SLOT(RowCheckHandle(int, bool)));
    connect(ui->lineEditSearch,         SIGNAL(returnPressed()),            this, SLOT(SearchAndFilterTableview()));
    connect(ui->pushButtonSelectAll,    SIGNAL(clicked()),                  this, SLOT(SelectAllClicked()));
    connect(ui->pushButtonClearAll,     SIGNAL(clicked()),                  this, SLOT(ClearAllClicked()));
    connect(ui->pushButtonCustomerName, SIGNAL(clicked()),                  this, SLOT(LoadProductTrackingPage()));
    connect(ui->pushButtonReturn,       SIGNAL(clicked()),                  this, SLOT(LoadMainPage()));

    FillCustomerTable();

    ui->tableView->setColumnWidth(s_uchCUSTOMER_NAME_COLUMN, s_uchCUSTOMER_NAME_COLUMN_WIDTH);
    ui->tableView->setColumnWidth(s_uchCHECKBOX_COLUMN, s_uchCHECKBOX_COLUMN_WIDTH);

    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");
}

void CustomerSelectionPageCls::resizeEvent(QResizeEvent *event)
{
    ui->tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeMode::ResizeToContents);
    QMainWindow::resizeEvent(event);
}

void CustomerSelectionPageCls::RowCheckHandle(int a_Row, bool a_State)
{
    Q_UNUSED(a_Row)
    Q_UNUSED(a_State)

    QModelIndex idx;
    QString CustomerName;
    QList<int> RowList;

    RowList = m_Model->getCheckedRowList();

    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    if (RowList.size() > 1)
    {
        ui->pushButtonCustomerName->setText("SEÇİLENLERİ GÖSTER");
    }
    else if (RowList.size()  == 1)
    {
        idx = m_Model->index(RowList[0], s_uchCUSTOMER_NAME_COLUMN);
        CustomerName = m_Model->data(idx, Qt::DisplayRole).toString();

        ui->pushButtonCustomerName->setText(CustomerName);
    }
    else if (RowList.size() == 0)
    {
        ui->pushButtonCustomerName->setText("");
    }
}

void CustomerSelectionPageCls::FillCustomerTable(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    QString l_QueryStr = QString("SELECT CustomerName AS `Müşteri Adı` FROM customers");
    m_Model->SetQuery(l_QueryStr);

    ui->tableView->setModel(m_Model);

    m_Model->setHeaderData(1, Qt::Horizontal, " ");

    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

void CustomerSelectionPageCls::SearchAndFilterTableview()
{
    QString l_CustomerNameStr = ui->lineEditSearch->text();
    m_Model->clear();
    QString l_QueryStr = QString("SELECT CustomerName AS `Müşteri Adı` FROM customers WHERE CustomerName = '%1'").arg(l_CustomerNameStr);
    m_Model->SetQuery(l_QueryStr);

    ui->tableView->setModel(m_Model);
}

void CustomerSelectionPageCls::LoadProductTrackingPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    QList<int> RowList;
    QModelIndex idx;
    RowList = m_Model->getCheckedRowList();

    if (RowList.size() > 0)
    {
        m_CustNameList.clear();
        foreach (int row, RowList)
        {
            idx = m_Model->index(row, s_uchCUSTOMER_NAME_COLUMN);
            m_CustNameList.append(m_Model->data(idx, Qt::DisplayRole).toString());
        }
        LoadPage(PageSelection_ProductTrackingPage);
        delete this;
    }

}

void CustomerSelectionPageCls::SelectAllClicked()
{
    m_Model->SetAllChecked();
}

void CustomerSelectionPageCls::ClearAllClicked()
{
    m_Model->SetAllUnchecked();
}

void CustomerSelectionPageCls::LoadMainPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_ProductionPage);

    delete this;

}

CustomerSelectionPageCls::~CustomerSelectionPageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    delete ui;
}
