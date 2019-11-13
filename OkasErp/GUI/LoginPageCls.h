#ifndef LOGINPAGECLS_H
#define LOGINPAGECLS_H

#include <QMainWindow>
#include "UserCls.h"
#include "PageCls.h"

namespace Ui
{
    class LoginPageCls;
}

/*! \class LoginPageCls LoginPageCls.h
 *
 *  Docs for MyClassName
 */
class LoginPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

    public:
    /** @brief Holds true for negative values */
        explicit LoginPageCls(QWidget *a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
        ~LoginPageCls();

    private slots:
    /** @brief Holds true for negative values */
        void Login(void);
        /** @brief Holds true for negative values */
        void LoadPasswordReminderPage(void);

    private:
/** @brief Holds true for negative values */
        Ui::LoginPageCls * ui;
/** @brief Holds true for negative values */
        UserStc m_User;
/** @brief Holds true for negative values */
        void ReadConfigurationAndConnect(QString a_ConfigurationFileStr);
        /** @brief Holds true for negative values */
        bool CheckUserNameAndPassword(QString a_UserNameStr, QString a_PasswordStr);
        /** @brief Holds true for negative values */
        void GetUserPrivileges(QString a_UserNameStr, QString a_PasswordStr);
        /** @brief Holds true for negative values */
        void LoadMainPage();

};

#endif // LOGINPAGECLS_H
