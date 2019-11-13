#include "NewUserPageCls.h"
#include "ui_NewUserPageCls.h"

NewUserPageCls::NewUserPageCls(QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::NewUserPageCls)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    ui->setupUi(this);

    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");

    connect(ui->pushButtonSave,     SIGNAL(clicked()) , this, SLOT(CreateUser()));
    connect(ui->pushButtonReturn,   SIGNAL(clicked()) , this, SLOT(LoadSettingsPage()));

}

NewUserPageCls::~NewUserPageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    delete ui;
}

void NewUserPageCls::CreateUser()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    QString l_NameStr           = ui->lineEditName->text();
    QString l_SurnameStr        = ui->lineEditSurName->text();
    QString l_UserNameStr       = ui->lineEditUserName->text();
    QString l_MailAddressStr    = ui->lineEditEmail->text();
    QString l_PasswordStr       = ui->lineEditPassword->text();

    if (l_NameStr.isEmpty() == false &&
        l_SurnameStr.isEmpty() == false &&
        l_UserNameStr.isEmpty() == false &&
        l_MailAddressStr.isEmpty() == false &&
        l_PasswordStr.isEmpty() == false)
    {
        UserStc l_User;
        bool l_blnBrandingAuth          = ui->checkBoxBrandingPriv->isChecked();
        bool l_blnCustomerAuth          = ui->checkBox_CustPriv->isChecked();
        bool l_blnProductTrackingAuth   = ui->checkBox_ProdPriv->isChecked();
        bool l_blnUserAuth              = ui->checkBox_UserPriv->isChecked();
        bool l_blnSaleAuth              = ui->checkBox_SalePriv->isChecked();

        QString l_EmailStr      = ui->lineEditEmail->text();
        QString l_PasswordStr   = ui->lineEditPassword->text();
        QString l_UserNameStr   = ui->lineEditUserName->text();

        l_User.m_UserNameStr = l_UserNameStr;

        l_User.m_blnBrandingAuth = l_blnBrandingAuth;
        l_User.m_blnCustomerAuth = l_blnCustomerAuth;
        l_User.m_EmailStr = l_EmailStr;
        l_User.m_PasswordStr = l_PasswordStr;
        l_User.m_blnProductTrackingAuth = l_blnProductTrackingAuth;
        l_User.m_blnSalesAuth = l_blnSaleAuth;
        l_User.m_UserNameStr = l_UserNameStr;
        l_User.m_blnUserAuth = l_blnUserAuth;

        m_DatabasePtr->AddUser(l_User);

        m_LoggerPtr->DisplayInformation("Kullanıcı Kaydedildi", this);

    }
    else
    {
        m_LoggerPtr->DisplayInformation("Alanlar Boş Olamaz", this);
    }
}

void NewUserPageCls::LoadSettingsPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_SettingsPage);
    delete this;
}
