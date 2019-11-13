#include "SalesInformationSelectionPageCls.h"
#include "ui_SalesInformationSelectionPageCls.h"

SalesInformationSelectionPageCls::SalesInformationSelectionPageCls(QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::SalesInformationSelectionPageCls)
{
    ui->setupUi(this);

    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    connect(ui->pushButtonSalesEntry,  SIGNAL(clicked()),  this, SLOT(LoadSalesEntryPage()));
    connect(ui->pushButtonSalesReport, SIGNAL(clicked()),  this, SLOT(LoadSalesReportPage()));
    connect(ui->pushButtonReturn,      SIGNAL(clicked()),  this, SLOT(LoadMainPage()));

    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");
}

SalesInformationSelectionPageCls::~SalesInformationSelectionPageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    delete ui;
}

void SalesInformationSelectionPageCls::LoadSalesEntryPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_SalesEntryPage);

    delete this;
}

void SalesInformationSelectionPageCls::LoadSalesReportPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_SalesReportPage);

    delete this;
}

void SalesInformationSelectionPageCls::LoadMainPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_MainPage);
    delete this;
}
