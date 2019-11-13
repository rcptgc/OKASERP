/********************************************************************************
** Form generated from reading UI file 'PasswordReminderPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDREMINDERPAGECLS_H
#define UI_PASSWORDREMINDERPAGECLS_H

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

class Ui_PasswordReminderPageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButtonSendCredentals;
    QPushButton *pushButtonReturn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PasswordReminderPageCls)
    {
        if (PasswordReminderPageCls->objectName().isEmpty())
            PasswordReminderPageCls->setObjectName(QStringLiteral("PasswordReminderPageCls"));
        PasswordReminderPageCls->resize(351, 280);
        centralwidget = new QWidget(PasswordReminderPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 301, 141));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 91, 31));
        label->setFont(font);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 20, 161, 31));
        lineEdit->setFont(font);
        pushButtonSendCredentals = new QPushButton(groupBox);
        pushButtonSendCredentals->setObjectName(QStringLiteral("pushButtonSendCredentals"));
        pushButtonSendCredentals->setGeometry(QRect(110, 60, 161, 41));
        pushButtonSendCredentals->setFont(font);
        pushButtonReturn = new QPushButton(centralwidget);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(120, 180, 161, 41));
        pushButtonReturn->setFont(font);
        PasswordReminderPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PasswordReminderPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 351, 21));
        PasswordReminderPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(PasswordReminderPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PasswordReminderPageCls->setStatusBar(statusbar);

        retranslateUi(PasswordReminderPageCls);

        QMetaObject::connectSlotsByName(PasswordReminderPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *PasswordReminderPageCls)
    {
        PasswordReminderPageCls->setWindowTitle(QApplication::translate("PasswordReminderPageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("PasswordReminderPageCls", "E-Posta Adresi", nullptr));
        pushButtonSendCredentals->setText(QApplication::translate("PasswordReminderPageCls", "Kullan\304\261c\304\261 Bilgilerini G\303\266nder", nullptr));
        pushButtonReturn->setText(QApplication::translate("PasswordReminderPageCls", "GER\304\260 D\303\226N", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordReminderPageCls: public Ui_PasswordReminderPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDREMINDERPAGECLS_H
