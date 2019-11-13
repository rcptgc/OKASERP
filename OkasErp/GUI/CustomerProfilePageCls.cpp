#include "CustomerProfilePageCls.h"
#include "ui_CustomerProfilePageCls.h"

CustomerProfilePageCls::CustomerProfilePageCls(QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::CustomerProfilePageCls)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    ui->setupUi(this);
    ui->comboBoxDateTimeType->addItem("GG.AA.YYYY");
    ui->comboBoxDateTimeType->addItem("AA.GG.YYYY");
    ui->lineEditBarcodePrefix->setText("");
    ui->lineEditCustomerName->setText("");
    ui->lineEditSowPrefix->setText("");
    ui->checkBox->setChecked(false);
    connect(ui->pushButtonReturn,       SIGNAL(clicked()),          this, SLOT(LoadMainPage()));
    connect(ui->pushButtonAddCustomer,  SIGNAL(clicked()),          this, SLOT(AddNewCustomer()));
    connect(ui->pushButtonEditCustomer, SIGNAL(clicked()),          this, SLOT(UpdateCustomer()));
    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");
}

void CustomerProfilePageCls::FillForm(CustomerCls &a_Customer)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    ui->lineEditCustomerName->setText(a_Customer.m_CustomerNameStr);
    ui->lineEditBarcodePrefix->setText(a_Customer.m_BarcodePrefixStr);
    ui->lineEditSowPrefix->setText(a_Customer.m_GKRPrefixStr);
    ui->checkBox->setChecked(a_Customer.m_blnIsSoirUsed);
    ui->comboBoxDateTimeType->setCurrentIndex(static_cast<int>(a_Customer.m_enmDateTimeType));
}

void CustomerProfilePageCls::ClearForm(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    ui->lineEditCustomerName->setText("");
    ui->lineEditBarcodePrefix->setText("");
    ui->lineEditSowPrefix->setText("");
    ui->checkBox->setChecked(false);
    ui->comboBoxDateTimeType->setCurrentIndex(0);
}

void CustomerProfilePageCls::LoadMainPage(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    LoadPage(PageSelection_MainPage);
    delete this;
}

void CustomerProfilePageCls::AddNewCustomer(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_CustomerNameStr = ui->lineEditCustomerName->text();

    if ( (ui->lineEditBarcodePrefix->text().isEmpty() == false) &&
         (ui->lineEditCustomerName->text().isEmpty() == false) &&
         (ui->lineEditSowPrefix->text().isEmpty() == false) )
    {
        if (m_DatabasePtr->GetCustomer(m_Customer, m_CustomerNameStr) == true)
        {
            m_LoggerPtr->DisplayInformation("Müşteri Kaydı Mevcut!", this);
        }
        else
        {
            m_BarcodePrefixStr      = ui->lineEditBarcodePrefix->text();
            m_enmDateTimeType       = ((ui->comboBoxDateTimeType->currentIndex() == 0) ? DateTimeType_DayMonth : DateTimeType_MonthDay);
            m_blnIsSoirUsed         = (ui->checkBox->isChecked());
            m_SowPrefixStr          = ui->lineEditSowPrefix->text();
            m_Customer.m_CustomerNameStr = m_CustomerNameStr;;
            m_Customer.m_BarcodePrefixStr = m_BarcodePrefixStr;
            m_Customer.m_enmDateTimeType = m_enmDateTimeType;
            m_Customer.m_blnIsSoirUsed = m_blnIsSoirUsed;
            m_Customer.m_GKRPrefixStr = m_SowPrefixStr;
            m_DatabasePtr->AddCustomer(m_Customer);
            m_LoggerPtr->DisplayInformation("Müşteri Kaydedildi", this);
        }
    }
    else
    {
        m_LoggerPtr->DisplayInformation("Alanlar Boş Olamaz!", this);
    }
}

void CustomerProfilePageCls::UpdateCustomer(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    LoadPage(PageSelection_CustomerEditPage);
    delete this;
}

CustomerProfilePageCls::~CustomerProfilePageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    delete ui;
}
