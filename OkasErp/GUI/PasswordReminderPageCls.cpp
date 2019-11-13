#include "PasswordReminderPageCls.h"
#include "ui_PasswordReminderPageCls.h"
#include "Utility/smtp.h"


PasswordReminderPageCls::PasswordReminderPageCls(QWidget *parent) : QMainWindow(parent), ui(new Ui::PasswordReminderPageCls)
{
    ui->setupUi(this);

    connect(ui->pushButtonReturn, SIGNAL(clicked()), this, SLOT(ReturnToLoginPage()));

    connect(ui->pushButtonSendCredentals, SIGNAL(clicked()), this, SLOT(SendEmail()));

    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");
}

void PasswordReminderPageCls::ReturnToLoginPage(void)
{
    LoadPage(PageSelection_LoginPage);

    delete this;
}

void PasswordReminderPageCls::SendEmail(void)
{
    QString l_ReceiverMailStr = ui->lineEdit->text();
    QString l_PasswordStr;
    QString l_UserNameStr;
    bool l_blnIsFound = m_DatabasePtr->GetUserPassword(l_ReceiverMailStr, l_UserNameStr, l_PasswordStr);

    if (l_blnIsFound == true)
    {
        ReadConfigurationFromFile("conf_test.json");

        Smtp * smtp = new Smtp(m_EmailStr, m_PasswordStr, m_SmtpServerNameStr, 465);
        const QString MailText = QString("Kullanici Adi = %1  Sifre = %2").arg(l_UserNameStr).arg(l_UserNameStr);

        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        smtp->sendMail(m_EmailStr, l_ReceiverMailStr, "Şifre Hatırlatma", MailText);
    }
    else
    {
        m_LoggerPtr->DisplayInformation("Kullanıcı Mevcut Değil!", this);
    }

}

void PasswordReminderPageCls::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

PasswordReminderPageCls::~PasswordReminderPageCls()
{
    delete ui;
}

void PasswordReminderPageCls::ReadConfigurationFromFile(QString a_FileNameStr)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    QFile l_File;
    l_File.setFileName(a_FileNameStr);
    l_File.open(QFile::ReadOnly | QFile::Text);

    QJsonDocument l_JsonDocument = QJsonDocument::fromJson(l_File.readAll());

    QJsonObject l_Json = l_JsonDocument.object();

    m_EmailStr          = l_Json["EmailAddress"].toString();
    m_PasswordStr       = l_Json["Password"].toString();
    m_SmtpServerNameStr = l_Json["SmtpServer"].toString();

    l_File.close();
}
