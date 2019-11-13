#include "MainPageCls.h"
#include "ui_MainPageCls.h"

MainPageCls::MainPageCls(QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::MainPageCls)
{
    m_LoggerPtr->CreateTraceLog("MainPageCls::MainPageCls()", " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, "MainPageCls::MainPageCls()", "User is in Main Page");

    ui->setupUi(this);

    connect(ui->pushButtonLogOff,     SIGNAL(clicked()) , this, SLOT(LoadLoginPage()));
    connect(ui->pushButtonProduction, SIGNAL(clicked()) , this, SLOT(LoadProductionPage()));
    connect(ui->pushButtonSettings,   SIGNAL(clicked()) , this, SLOT(LoadSettingsPage()));
    connect(ui->pushButtonSales,      SIGNAL(clicked()) , this, SLOT(LoadSalesInformationPage()));
    connect(ui->pushButtonCustomer,   SIGNAL(clicked()) , this, SLOT(LoadCustomerProfilePage()));

    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");
}

void MainPageCls::LoadSalesInformationPage(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, "User Clicked to Sales Info Page");

    if (m_UserPtr->m_blnSalesAuth == true)
    {
        LoadPage(PageSelection_SalesInformationPage);

        delete this;
    }
    else
    {
        m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, "User has no privilege of Sales Info Page");
        m_LoggerPtr->DisplayInformation("Kullanıcı Yetkili Değil", this);
    }
}

MainPageCls::~MainPageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    delete ui;
}

void MainPageCls::LoadCustomerProfilePage(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, "User Clicked Customer Profile Page");

    if (m_UserPtr->m_blnCustomerAuth == true)
    {
        LoadPage(PageSelection_NewCustomerPage);
        delete this;
    }
    else
    {
        m_LoggerPtr->DisplayInformation("Kullanıcı Yetkili Değil", this);
        m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, "User has no privilege of Customer Profile Page");
    }

}

void MainPageCls::LoadProductionPage(void)
{
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, "User Clicked the Production Page");
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    LoadPage(PageSelection_ProductionPage);

    delete this;
}

void MainPageCls::LoadLoginPage(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, "User Returned to the Login Page");

    LoadPage(PageSelection_LoginPage);

    delete this;

}

void MainPageCls::LoadSettingsPage(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, "User Clicked the Settings Page");

    LoadPage(PageSelection_SettingsPage);

    delete this;
}

