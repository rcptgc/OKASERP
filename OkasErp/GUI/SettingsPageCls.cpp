#include "SettingsPageCls.h"
#include "ui_SettingsPageCls.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QFileDialog>
#include <DataBaseCls.h>

SettingsPageCls::SettingsPageCls(QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::SettingsPageCls)
{
    ui->setupUi(this);

    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    ReadConfigurationFromFile("conf_test.json");

    connect(ui->pushButtonNewUser,      SIGNAL(clicked()), this, SLOT(LoadNewUserPage()));
    connect(ui->pushButtonEditUser,     SIGNAL(clicked()), this, SLOT(LoadEditUserPage()));
    connect(ui->pushButtonSave,         SIGNAL(clicked()), this, SLOT(SaveConfiguration()));
    connect(ui->pushButtonSelectFolder, SIGNAL(clicked()), this, SLOT(SelectAndSaveImagesPath()));
    connect(ui->pushButtonReturn,       SIGNAL(clicked()), this, SLOT(LoadMainPage()));

    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");
}

void SettingsPageCls::ReadConfigurationFromFile(QString a_FileNameStr)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    QString l_IpAddressStr;
    QString l_ImagesPathStr;
    QString l_EmailStr;
    QString l_PasswordStr;
    QString l_SmtpServerNameStr;


    QFile l_File;
    l_File.setFileName(a_FileNameStr);
    l_File.open(QFile::ReadOnly | QFile::Text);

    QJsonDocument l_JsonDocument = QJsonDocument::fromJson(l_File.readAll());

    QJsonObject l_Json = l_JsonDocument.object();

    l_IpAddressStr      = l_Json["ipAddress"].toString();
    l_ImagesPathStr     = l_Json["ServerPath"].toString();
    l_EmailStr          = l_Json["EmailAddress"].toString();
    l_PasswordStr       = l_Json["Password"].toString();
    l_SmtpServerNameStr = l_Json["SmtpServer"].toString();

    ui->FilePathLineEdit->setText(l_ImagesPathStr);
    ui->ServerIpLineEdit->setText(l_IpAddressStr);
    ui->lineEditEmailAddr->setText(l_EmailStr);
    ui->lineEditPassword->setText(l_PasswordStr);
    ui->linEditSmtpServer->setText(l_SmtpServerNameStr);

    l_File.close();
}

void SettingsPageCls::LoadNewUserPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    if (m_UserPtr->m_blnUserAuth == true)
    {
        LoadPage(PageSelection_NewUserPage);
        delete this;
    }
    else
    {
        m_LoggerPtr->CreateErrorLog(Q_FUNC_INFO, "Kullanıcı Yetkili Değil", true);
    }

}

void SettingsPageCls::LoadEditUserPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    if (m_UserPtr->m_blnUserAuth == true)
    {
        LoadPage(PageSelection_EditUserPage);
        delete this;
    }
    else
    {
        m_LoggerPtr->CreateErrorLog(Q_FUNC_INFO, "Kullanıcı Yetkili Değil", true);
    }

}

SettingsPageCls::~SettingsPageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    delete ui;
}

void SettingsPageCls::LoadMainPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_MainPage);

    delete this;
}

void SettingsPageCls::SelectAndSaveImagesPath()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    QJsonObject l_Json;
    QJsonDocument l_JsonDoc;
    QFile l_File;

    QString l_DirectoryStr = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    l_Json["ipAddress"]     = ui->ServerIpLineEdit->text();
    l_Json["ServerPath"]    = l_DirectoryStr;
    l_Json["EmailAddress"]  = ui->lineEditEmailAddr->text();
    l_Json["Password"]      = ui->lineEditPassword->text();
    l_Json["SmtpServer"]    = ui->linEditSmtpServer->text();
    ui->FilePathLineEdit->setText(l_DirectoryStr);

    l_JsonDoc.setObject(l_Json);

    l_File.setFileName("conf_test.json");
    l_File.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    l_File.write(l_JsonDoc.toJson());
    l_File.close();

    DataBaseCls * l_DataBasePtr = DataBaseCls::instance();

    l_DataBasePtr->SetIpAddress(l_Json["ipAddress"].toString());
    l_DataBasePtr->SetImagesPath(l_Json["ServerPath"].toString());

    l_DataBasePtr->Initialize( "root", 3306, "testdb");
    l_DataBasePtr->Connect();
}

void SettingsPageCls::SaveConfiguration()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    QJsonObject l_Json;
    QJsonDocument l_JsonDocument;
    QFile l_File;

    l_Json["ipAddress"]     = ui->ServerIpLineEdit->text();
    l_Json["ServerPath"]    = ui->FilePathLineEdit->text();
    l_Json["EmailAddress"]  = ui->lineEditEmailAddr->text();
    l_Json["Password"]      = ui->lineEditPassword->text();
    l_Json["SmtpServer"]    = ui->linEditSmtpServer->text();

    l_JsonDocument.setObject(l_Json);

    l_File.setFileName("conf_test.json");
    l_File.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    l_File.write(l_JsonDocument.toJson());
    l_File.close();

    DataBaseCls * l_DatabasePtr = DataBaseCls::instance();
    l_DatabasePtr->SetIpAddress(l_Json["ipAddress"].toString());
    l_DatabasePtr->SetImagesPath(l_Json["ServerPath"].toString());

    l_DatabasePtr->Initialize( "root", 3306, "erpokasdb");
    l_DatabasePtr->Connect();

    m_LoggerPtr->DisplayInformation("Kaydedildi!", this);
}
