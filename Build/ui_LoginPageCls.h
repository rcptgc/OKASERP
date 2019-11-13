/********************************************************************************
** Form generated from reading UI file 'LoginPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGECLS_H
#define UI_LOGINPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButtonLogin;
    QLineEdit *lineEditUserName;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEditPassword;
    QFrame *frame;
    QLabel *ForgottenPasswordLink;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginPageCls)
    {
        if (LoginPageCls->objectName().isEmpty())
            LoginPageCls->setObjectName(QStringLiteral("LoginPageCls"));
        LoginPageCls->resize(800, 600);
        LoginPageCls->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(LoginPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(120, 140, 591, 231));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        pushButtonLogin = new QPushButton(groupBox);
        pushButtonLogin->setObjectName(QStringLiteral("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(130, 140, 191, 41));
        pushButtonLogin->setFont(font);
        lineEditUserName = new QLineEdit(groupBox);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));
        lineEditUserName->setGeometry(QRect(130, 20, 191, 41));
        lineEditUserName->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 71, 41));
        label_2->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 91, 41));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral(""));
        lineEditPassword = new QLineEdit(groupBox);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(130, 70, 191, 41));
        lineEditPassword->setFont(font);
        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(360, 20, 211, 161));
        frame->setFont(font);
        frame->setStyleSheet(QStringLiteral("image: url(:/new/prefix1/images/MARISOFT.PNG);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        ForgottenPasswordLink = new QLabel(groupBox);
        ForgottenPasswordLink->setObjectName(QStringLiteral("ForgottenPasswordLink"));
        ForgottenPasswordLink->setGeometry(QRect(160, 190, 141, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setUnderline(true);
        ForgottenPasswordLink->setFont(font1);
        ForgottenPasswordLink->setFocusPolicy(Qt::ClickFocus);
        ForgottenPasswordLink->setStyleSheet(QStringLiteral(""));
        ForgottenPasswordLink->setTextFormat(Qt::RichText);
        ForgottenPasswordLink->setOpenExternalLinks(false);
        ForgottenPasswordLink->setTextInteractionFlags(Qt::TextBrowserInteraction);
        LoginPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        LoginPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        LoginPageCls->setStatusBar(statusbar);
        QWidget::setTabOrder(lineEditUserName, lineEditPassword);
        QWidget::setTabOrder(lineEditPassword, pushButtonLogin);

        retranslateUi(LoginPageCls);

        QMetaObject::connectSlotsByName(LoginPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *LoginPageCls)
    {
        LoginPageCls->setWindowTitle(QApplication::translate("LoginPageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pushButtonLogin->setText(QApplication::translate("LoginPageCls", "G\304\260R\304\260\305\236", nullptr));
        label_2->setText(QApplication::translate("LoginPageCls", "\305\236\304\260FRE", nullptr));
        label->setText(QApplication::translate("LoginPageCls", "KULLANICI ADI", nullptr));
        ForgottenPasswordLink->setText(QApplication::translate("LoginPageCls", "<html><head/><body><pre style=\" margin-top:0px; margin-bottom:15px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:#eff0f1;\"><span style=\" font-family:'Courier New'; background-color:#eff0f1;\">\305\236ifremi unuttum</span></pre></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPageCls: public Ui_LoginPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGECLS_H
