#include "EditUserPageCls.h"
#include "ui_EditUserPageCls.h"

static const uint8_t s_uchTABLE_COLUMN_COUNT = 8u;

static const uint8_t s_uchUSERNAME_COLUMN                 = 0u;
static const uint8_t s_uchEMAIL_COLUMN                    = 1u;
static const uint8_t s_uchPASSWORD_COLUMN                 = 2u;
static const uint8_t s_uchPRODUCT_TRACK_PRIV_COLUMN       = 3u;
static const uint8_t s_uchBRANDING_PRIV_COLUMN            = 4u;
static const uint8_t s_uchCUSTOMER_PROFILE_PRIV_COLUMN    = 5u;
static const uint8_t s_uchUSER_PROFILE_PRIV_COLUMN        = 6u;
static const uint8_t s_uchSALES_INFO_PRIV_COLUMN          = 7u;

EditUserPageCls::EditUserPageCls(QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::EditUserPageCls)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    ui->setupUi(this);

    m_DatabasePtr->GetUserList(ui->tableWidget->m_UserList);

    FillTable(ui->tableWidget->m_UserList);

    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");

    connect(ui->pushButtonReturn,   SIGNAL(clicked()),              this, SLOT(LoadSettingsPage()));
    connect(ui->pushButtonSave,     SIGNAL(clicked()),              this, SLOT(SaveChanges()));
    connect(ui->pushButtonErase,    SIGNAL(clicked()),              this, SLOT(EraseSelected()));
}

EditUserPageCls::~EditUserPageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    delete ui;
}

void EditUserPageCls::FillTable(QList<UserStc> a_UserList)
{
    int32_t l_intRow = 0;

    QTableWidgetItem * l_UserItemPtr;

    ui->tableWidget->clear();

    ui->tableWidget->setColumnCount(s_uchTABLE_COLUMN_COUNT + 1);
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->insertRows(a_UserList.size());

    foreach (UserStc l_User, a_UserList)
    {
        l_UserItemPtr = new QTableWidgetItem(QString::number(static_cast<int>(l_User.m_blnBrandingAuth)));
        ui->tableWidget->setItem(l_intRow, s_uchBRANDING_PRIV_COLUMN, l_UserItemPtr);

        l_UserItemPtr = new QTableWidgetItem(QString::number(static_cast<int>(l_User.m_blnCustomerAuth)));
        ui->tableWidget->setItem(l_intRow, s_uchCUSTOMER_PROFILE_PRIV_COLUMN, l_UserItemPtr);

        l_UserItemPtr = new QTableWidgetItem(l_User.m_EmailStr);
        ui->tableWidget->setItem(l_intRow, s_uchEMAIL_COLUMN, l_UserItemPtr);

        l_UserItemPtr = new QTableWidgetItem(l_User.m_PasswordStr);
        ui->tableWidget->setItem(l_intRow, s_uchPASSWORD_COLUMN, l_UserItemPtr);

        l_UserItemPtr = new QTableWidgetItem(QString::number(static_cast<int>(l_User.m_blnProductTrackingAuth)));
        ui->tableWidget->setItem(l_intRow, s_uchPRODUCT_TRACK_PRIV_COLUMN, l_UserItemPtr);

        l_UserItemPtr = new QTableWidgetItem(QString::number(static_cast<int>(l_User.m_blnSalesAuth)));
        ui->tableWidget->setItem(l_intRow, s_uchSALES_INFO_PRIV_COLUMN, l_UserItemPtr);

        l_UserItemPtr = new QTableWidgetItem(l_User.m_UserNameStr);
        ui->tableWidget->setItem(l_intRow, s_uchUSERNAME_COLUMN, l_UserItemPtr);

        l_UserItemPtr = new QTableWidgetItem(QString::number(static_cast<int>(l_User.m_blnUserAuth)));
        ui->tableWidget->setItem(l_intRow, s_uchUSER_PROFILE_PRIV_COLUMN, l_UserItemPtr);

        l_intRow++;
    }
    QStringList l_Headers;

    l_Headers << "Kullanıcı Adı"
              << "E-Mail"
              << "Şifre"
              << "Ürün Takip\r\nYetkisi"
              << "Markalama\r\nYetkisi"
              << "Müşteri Profili\r\nYetkisi"
              << "Kullanıcı Profili\r\nYetkisi"
              << "Satış Bilgisi\r\nYetkisi";

    ui->tableWidget->setHorizontalHeaderLabels(l_Headers);

}

void EditUserPageCls::LoadSettingsPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_SettingsPage);

    delete this;
}

void EditUserPageCls::EraseSelected()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    QList<UserStc> l_DeletedUsersList;

    foreach (const int32_t &l_intRow, ui->tableWidget->m_CheckedRowsList)
    {
        l_DeletedUsersList.append(ui->tableWidget->m_UserList[l_intRow]);
    }

    int32_t l_intUserCtr = 0;
    uint32_t l_ulnID;
    foreach (const int32_t &l_intRow, ui->tableWidget->m_CheckedRowsList)
    {
        UserStc l_User;
        GetUserFromRow(l_intRow, l_User);

        l_ulnID = l_DeletedUsersList[l_intUserCtr].m_ulnID;
        l_User.m_ulnID = l_ulnID;
        m_DatabasePtr->RemoveUser(l_User);
        l_intUserCtr++;
    }

    m_DatabasePtr->GetUserList(ui->tableWidget->m_UserList);
    FillTable(ui->tableWidget->m_UserList);
}

void EditUserPageCls::SaveChanges()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    uint32_t l_ulnID;

    foreach (int32_t l_Row, ui->tableWidget->m_EditedRowsList)
    {
        UserStc l_User;

        GetUserFromRow(l_Row, l_User);

        l_ulnID = ui->tableWidget->m_UserList[l_Row].m_ulnID;

        l_User.m_ulnID = l_ulnID;

        m_DatabasePtr->UpdateUser(l_User);
    }

    m_LoggerPtr->DisplayInformation("Kaydedildi!", this);
}

void EditUserPageCls::GetUserFromRow(int32_t a_Row, UserStc &a_User)
{
    bool l_blnBrandingAuth      = static_cast<bool>(ui->tableWidget->item(a_Row, s_uchBRANDING_PRIV_COLUMN)->text().toInt());
    bool l_blnCustomerAuth      = static_cast<bool>(ui->tableWidget->item(a_Row, s_uchCUSTOMER_PROFILE_PRIV_COLUMN)->text().toInt());
    bool l_blnProductTrackAuth  = static_cast<bool>(ui->tableWidget->item(a_Row, s_uchPRODUCT_TRACK_PRIV_COLUMN)->text().toInt());
    bool l_blnSalesAuth         = static_cast<bool>(ui->tableWidget->item(a_Row, s_uchSALES_INFO_PRIV_COLUMN)->text().toInt());
    bool l_blnUserAuth          = static_cast<bool>(ui->tableWidget->item(a_Row, s_uchUSER_PROFILE_PRIV_COLUMN)->text().toInt());

    QString l_EmailStr      = ui->tableWidget->item(a_Row, s_uchEMAIL_COLUMN)->text();
    QString l_PasswordStr   = ui->tableWidget->item(a_Row, s_uchPASSWORD_COLUMN)->text();
    QString l_UserNameStr   = ui->tableWidget->item(a_Row, s_uchUSERNAME_COLUMN)->text();

    a_User.m_blnBrandingAuth = l_blnBrandingAuth;
    a_User.m_blnCustomerAuth = l_blnCustomerAuth;
    a_User.m_EmailStr = l_EmailStr;
    a_User.m_PasswordStr = l_PasswordStr;
    a_User.m_blnProductTrackingAuth = l_blnProductTrackAuth;
    a_User.m_blnSalesAuth = l_blnSalesAuth;
    a_User.m_UserNameStr = l_UserNameStr;
    a_User.m_blnUserAuth = l_blnUserAuth;
}
