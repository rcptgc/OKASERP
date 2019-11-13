#include "ProductionPageCls.h"
#include "ui_ProductionPageCls.h"

ProductionPageCls::ProductionPageCls(QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::ProductionPageCls)
{
    ui->setupUi(this);

    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    connect(ui->pushButtonPartTrack,    SIGNAL(clicked()), this, SLOT(LoadProductTrackPage()));
    connect(ui->pushButtonBranding,     SIGNAL(clicked()), this, SLOT(LoadBrandingPage()));
    connect(ui->pushButtonReturn,       SIGNAL(clicked()), this, SLOT(LoadMainPage()));
    connect(ui->pushButtonProdEntry,    SIGNAL(clicked()), this, SLOT(LoadProductionEntryPage()));

    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");
}

void ProductionPageCls::LoadProductTrackPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    if (m_UserPtr->m_blnProductTrackingAuth == true)
    {
        LoadPage(PageSelection_CustomerSelectionPage);
        this->hide();
    }
    else
    {
        m_LoggerPtr->CreateErrorLog(Q_FUNC_INFO, "Kullanıcı Yetkili Değil", true);
    }

}

void ProductionPageCls::LoadBrandingPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    if (m_UserPtr->m_blnBrandingAuth == true)
    {
        LoadPage(PageSelection_BrandingPage);
        this->hide();
    }
    else
    {
        m_LoggerPtr->CreateErrorLog(Q_FUNC_INFO, "Kullanıcı Yetkili Değil", true);
    }

}

void ProductionPageCls::LoadMainPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_MainPage);

    this->hide();
}

void ProductionPageCls::LoadProductionEntryPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_ProductionEntryPage);

    this->hide();
}

ProductionPageCls::~ProductionPageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    this->hide();
}

