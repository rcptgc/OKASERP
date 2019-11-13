#include "LoginPageCls.h"
#include "ui_LoginPageCls.h"
#include "DataBaseCls.h"
#include "UserCls.h"
#include "Utility\LoggerCls.h"

DatabaseAccessCls * DatabaseAccessCls::s_instance = nullptr;
LoggerCls * LoggerCls::s_instance = nullptr;


LoginPageCls::LoginPageCls(QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::LoginPageCls)
{
    ui->setupUi(this);

    PageCls::SetLogger(LoggerCls::instance());

    m_DatabasePtr = DatabaseAccessCls::instance();
    QString PathStr;
    m_DatabasePtr->GetImagesPath(PathStr);
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    ui->lineEditUserName->setText("");
    ui->lineEditPassword->setText("");

    ui->lineEditPassword->setEchoMode(QLineEdit::Password);

    connect(ui->pushButtonLogin,        SIGNAL(clicked()),              this, SLOT(Login()));
    connect(ui->lineEditPassword,       SIGNAL(returnPressed()),        this, SLOT(Login()));
    connect(ui->ForgottenPasswordLink,  SIGNAL(linkActivated(QString)), this, SLOT(LoadPasswordReminderPage()));

    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");

    ui->ForgottenPasswordLink->setText("<a href=\"sdfsdf\">Şifremi Unuttum</a>");
    ui->ForgottenPasswordLink->setTextInteractionFlags(Qt::TextBrowserInteraction);

    ui->lineEditPassword->setText("admin");
    ui->lineEditUserName->setText("admin");
}

void LoginPageCls::LoadPasswordReminderPage(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    LoadPage(PageSelection_PasswordReminderPage);

    this->hide();
}

bool LoginPageCls::CheckUserNameAndPassword(QString a_UserNameStr, QString a_PasswordStr)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    bool l_blnSuccess = false;

    l_blnSuccess = m_DatabasePtr->GetUser(m_User, a_UserNameStr);

    if (l_blnSuccess)
    {
        if (QString::compare(m_User.m_PasswordStr, a_PasswordStr) == 0)
        {
            m_LoggerPtr->CreateUserLog(&m_User, Q_FUNC_INFO, "Logged in");
            l_blnSuccess = true;
        }
        else
        {
            m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO ,
                                   "Incorrect Credentals: User Name = " + m_User.m_UserNameStr +
                                   "Password = " + m_User.m_PasswordStr);
            l_blnSuccess = false;
        }
    }

    return l_blnSuccess;
}

void LoginPageCls::LoadMainPage(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    LoadPage(PageSelection_MainPage);

    this->hide();
}

LoginPageCls::~LoginPageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    delete ui;
}

void LoginPageCls::Login()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    QString l_UserNameStr = ui->lineEditUserName->text();
    QString l_PassWordStr = ui->lineEditPassword->text();

    if (l_UserNameStr.isEmpty() == false && l_PassWordStr.isEmpty() == false)
    {
        if (CheckUserNameAndPassword(l_UserNameStr, l_PassWordStr) == true)
        {
            PageCls::SetUser(&m_User);
            LoadMainPage();
        }
        else
        {
            m_LoggerPtr->DisplayInformation("Kullanıcı Bilgileri Hatalı!", this);
            m_LoggerPtr->CreateErrorLog(Q_FUNC_INFO,
                                   "Incorrect Credentals: User Name = " + m_User.m_UserNameStr +
                                   "Password = " + m_User.m_PasswordStr, false);
        }
    }
    else
    {
        m_LoggerPtr->DisplayInformation("Kullanıcı Adı ve Şifresi Boş Olamaz!", this);
    }

}
