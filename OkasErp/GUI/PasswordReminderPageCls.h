#ifndef PASSWORDREMINDERPAGECLS_H
#define PASSWORDREMINDERPAGECLS_H

#include <QMainWindow>
#include "PageCls.h"
namespace Ui {
class PasswordReminderPageCls;
}

class PasswordReminderPageCls : public QMainWindow, PageCls
{
    Q_OBJECT

public:
    explicit PasswordReminderPageCls(QWidget *parent = 0);
    ~PasswordReminderPageCls();

private:
    Ui::PasswordReminderPageCls *ui;
    void ReadConfigurationFromFile(QString a_FileNameStr);

    QString m_EmailStr;
    QString m_PasswordStr;
    QString m_SmtpServerNameStr;
private slots:
    void ReturnToLoginPage();
    void SendEmail();

    void mailSent(QString status);
};

#endif // PASSWORDREMINDERPAGECLS_H
