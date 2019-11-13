#include "BrandingPageCls.h"
#include "ui_BrandingPageCls.h"
#include "ProductImagePageCls.h"
#include "Utility/UtilsCls.h"


BrandingPageCls::BrandingPageCls(QString a_BarcodeStr, QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::BrandingPageCls)
{
    ui->setupUi(this);

    m_PageData.CurrentDate = QDate::currentDate();
    m_PageData.BrandDateStr = UtilsCls::GetDateString(m_PageData.CurrentDate);

    ui->lineEditBarcode->setText(a_BarcodeStr);

    FillForm();

    connect(ui->lineEditBarcode,         SIGNAL(returnPressed()),  this, SLOT(LoadProductImagePage()));
    connect(ui->pushButtonReturn,        SIGNAL(clicked()),        this, SLOT(LoadProductionPage()));
    connect(ui->pushButtonSaveBrandDate, SIGNAL(clicked()),        this, SLOT(SaveBrandDate()));

    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");
}

void BrandingPageCls::SaveBrandDate(void)
{
    m_PageData.BarcodeNumberStr = ui->lineEditBarcode->text();

    bool l_blnIsFound = m_DatabasePtr->GetOrder(m_PageData.Order, m_PageData.BarcodeNumberStr);

    if (true == l_blnIsFound)
    {
        m_PageData.Order.m_BrandDateStr = m_PageData.BrandDateStr;
        m_DatabasePtr->UpdateOrder(m_PageData.Order);
        m_LoggerPtr->DisplayInformation("Markalama Tarihi Kaydedildi", this);
    }
    else
    {
        m_LoggerPtr->DisplayInformation("Barkod Bulunamadı!", this);
    }
}

void BrandingPageCls::FillForm(void)
{
    m_PageData.BarcodeNumberStr = ui->lineEditBarcode->text();

    bool l_blnIsFound = m_DatabasePtr->GetOrder(m_PageData.Order, m_PageData.BarcodeNumberStr);

    if (true == l_blnIsFound)
    {
        ui->lineEditPartNumber->setText(m_PageData.Order.m_PartNumStr);
        ui->lineEditSowNumber->setText(m_PageData.Order.m_SOWNumStr);
        ui->lineEditMainCustomer->setText(m_PageData.Order.m_CustNameStr);
        ui->lineEditSoir->setText(m_PageData.Order.m_SoirStr);
        ui->lineEditDate->setText(m_PageData.BrandDateStr);
    }
}

void BrandingPageCls::LoadProductImagePage(void)
{
    m_PageData.BarcodeNumberStr = ui->lineEditBarcode->text();
    LoadPage(PageSelection_ProductImagePage, nullptr, m_PageData.BarcodeNumberStr);
    this->hide();
}

void BrandingPageCls::LoadProductionPage(void)
{
    LoadPage(PageSelection_ProductionPage);
    delete this;
}

BrandingPageCls::~BrandingPageCls()
{
    delete ui;
}
