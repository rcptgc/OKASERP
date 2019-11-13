/********************************************************************************
** Form generated from reading UI file 'SettingsPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSPAGECLS_H
#define UI_SETTINGSPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsPageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButtonSave;
    QLineEdit *ServerIpLineEdit;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *FilePathLineEdit;
    QPushButton *pushButtonSelectFolder;
    QLineEdit *lineEditEmailAddr;
    QLabel *label_3;
    QLineEdit *lineEditPassword;
    QLabel *label_4;
    QLineEdit *linEditSmtpServer;
    QLabel *label_5;
    QPushButton *pushButtonReturn;
    QGroupBox *groupBox_2;
    QPushButton *pushButtonNewUser;
    QPushButton *pushButtonEditUser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SettingsPageCls)
    {
        if (SettingsPageCls->objectName().isEmpty())
            SettingsPageCls->setObjectName(QStringLiteral("SettingsPageCls"));
        SettingsPageCls->resize(791, 509);
        SettingsPageCls->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(SettingsPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(270, 10, 501, 371));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        pushButtonSave = new QPushButton(groupBox);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(160, 320, 191, 41));
        pushButtonSave->setFont(font);
        ServerIpLineEdit = new QLineEdit(groupBox);
        ServerIpLineEdit->setObjectName(QStringLiteral("ServerIpLineEdit"));
        ServerIpLineEdit->setGeometry(QRect(160, 20, 191, 41));
        ServerIpLineEdit->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 131, 41));
        label_2->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 101, 41));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral(""));
        FilePathLineEdit = new QLineEdit(groupBox);
        FilePathLineEdit->setObjectName(QStringLiteral("FilePathLineEdit"));
        FilePathLineEdit->setGeometry(QRect(160, 80, 191, 41));
        FilePathLineEdit->setFont(font);
        pushButtonSelectFolder = new QPushButton(groupBox);
        pushButtonSelectFolder->setObjectName(QStringLiteral("pushButtonSelectFolder"));
        pushButtonSelectFolder->setGeometry(QRect(370, 80, 101, 41));
        pushButtonSelectFolder->setFont(font);
        lineEditEmailAddr = new QLineEdit(groupBox);
        lineEditEmailAddr->setObjectName(QStringLiteral("lineEditEmailAddr"));
        lineEditEmailAddr->setGeometry(QRect(160, 140, 191, 41));
        lineEditEmailAddr->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 140, 101, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral(""));
        lineEditPassword = new QLineEdit(groupBox);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(160, 200, 191, 41));
        lineEditPassword->setFont(font);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 200, 91, 41));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral(""));
        linEditSmtpServer = new QLineEdit(groupBox);
        linEditSmtpServer->setObjectName(QStringLiteral("linEditSmtpServer"));
        linEditSmtpServer->setGeometry(QRect(160, 260, 191, 41));
        linEditSmtpServer->setFont(font);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 260, 111, 41));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral(""));
        pushButtonReturn = new QPushButton(centralwidget);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(50, 390, 191, 61));
        pushButtonReturn->setFont(font);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 10, 231, 371));
        groupBox_2->setFont(font);
        pushButtonNewUser = new QPushButton(groupBox_2);
        pushButtonNewUser->setObjectName(QStringLiteral("pushButtonNewUser"));
        pushButtonNewUser->setGeometry(QRect(20, 30, 191, 141));
        pushButtonNewUser->setFont(font);
        pushButtonEditUser = new QPushButton(groupBox_2);
        pushButtonEditUser->setObjectName(QStringLiteral("pushButtonEditUser"));
        pushButtonEditUser->setGeometry(QRect(20, 200, 191, 141));
        pushButtonEditUser->setFont(font);
        SettingsPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SettingsPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 791, 21));
        SettingsPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(SettingsPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SettingsPageCls->setStatusBar(statusbar);

        retranslateUi(SettingsPageCls);

        QMetaObject::connectSlotsByName(SettingsPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *SettingsPageCls)
    {
        SettingsPageCls->setWindowTitle(QApplication::translate("SettingsPageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pushButtonSave->setText(QApplication::translate("SettingsPageCls", "KAYDET", nullptr));
        label_2->setText(QApplication::translate("SettingsPageCls", "G\303\226R\303\234NT\303\234 LOKASYONU", nullptr));
        label->setText(QApplication::translate("SettingsPageCls", "SUNUCU ADRES\304\260", nullptr));
        pushButtonSelectFolder->setText(QApplication::translate("SettingsPageCls", "KLAS\303\226R SE\303\207", nullptr));
        label_3->setText(QApplication::translate("SettingsPageCls", "E-MAIL ADRESI", nullptr));
        label_4->setText(QApplication::translate("SettingsPageCls", "SIFRE", nullptr));
        label_5->setText(QApplication::translate("SettingsPageCls", "SMTP SUNUCUSU", nullptr));
        pushButtonReturn->setText(QApplication::translate("SettingsPageCls", "GER\304\260", nullptr));
        groupBox_2->setTitle(QString());
        pushButtonNewUser->setText(QApplication::translate("SettingsPageCls", "YEN\304\260 KULLANICI OLU\305\236TUR", nullptr));
        pushButtonEditUser->setText(QApplication::translate("SettingsPageCls", "KULLANICI D\303\234ZENLE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsPageCls: public Ui_SettingsPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSPAGECLS_H
