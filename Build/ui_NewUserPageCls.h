/********************************************************************************
** Form generated from reading UI file 'NewUserPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSERPAGECLS_H
#define UI_NEWUSERPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewUserPageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEditEmail;
    QLineEdit *lineEditSurName;
    QCheckBox *checkBox_UserPriv;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_7;
    QCheckBox *checkBox_ProdPriv;
    QLabel *label_2;
    QPushButton *pushButtonReturn;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButtonSave;
    QLabel *label_3;
    QCheckBox *checkBox_SalePriv;
    QLineEdit *lineEditUserName;
    QLineEdit *lineEditPassword;
    QCheckBox *checkBox_CustPriv;
    QCheckBox *checkBoxBrandingPriv;
    QLineEdit *lineEditName;
    QLabel *label_9;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NewUserPageCls)
    {
        if (NewUserPageCls->objectName().isEmpty())
            NewUserPageCls->setObjectName(QStringLiteral("NewUserPageCls"));
        NewUserPageCls->resize(531, 467);
        NewUserPageCls->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(NewUserPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 491, 401));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 91, 31));
        label->setFont(font);
        lineEditEmail = new QLineEdit(groupBox);
        lineEditEmail->setObjectName(QStringLiteral("lineEditEmail"));
        lineEditEmail->setGeometry(QRect(110, 170, 121, 41));
        lineEditEmail->setFont(font);
        lineEditSurName = new QLineEdit(groupBox);
        lineEditSurName->setObjectName(QStringLiteral("lineEditSurName"));
        lineEditSurName->setGeometry(QRect(110, 70, 121, 41));
        lineEditSurName->setFont(font);
        checkBox_UserPriv = new QCheckBox(groupBox);
        checkBox_UserPriv->setObjectName(QStringLiteral("checkBox_UserPriv"));
        checkBox_UserPriv->setGeometry(QRect(460, 110, 16, 31));
        checkBox_UserPriv->setFont(font);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(280, 110, 171, 31));
        label_8->setFont(font);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(280, 190, 151, 31));
        label_10->setFont(font);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(280, 70, 151, 31));
        label_7->setFont(font);
        checkBox_ProdPriv = new QCheckBox(groupBox);
        checkBox_ProdPriv->setObjectName(QStringLiteral("checkBox_ProdPriv"));
        checkBox_ProdPriv->setGeometry(QRect(460, 30, 16, 31));
        checkBox_ProdPriv->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 91, 31));
        label_2->setFont(font);
        pushButtonReturn = new QPushButton(groupBox);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(10, 340, 171, 41));
        pushButtonReturn->setFont(font);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 220, 91, 31));
        label_5->setFont(font);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(280, 30, 151, 31));
        label_6->setFont(font);
        pushButtonSave = new QPushButton(groupBox);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(10, 280, 471, 41));
        pushButtonSave->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 91, 31));
        label_3->setFont(font);
        checkBox_SalePriv = new QCheckBox(groupBox);
        checkBox_SalePriv->setObjectName(QStringLiteral("checkBox_SalePriv"));
        checkBox_SalePriv->setGeometry(QRect(460, 200, 16, 21));
        checkBox_SalePriv->setFont(font);
        lineEditUserName = new QLineEdit(groupBox);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));
        lineEditUserName->setGeometry(QRect(110, 120, 121, 41));
        lineEditUserName->setFont(font);
        lineEditPassword = new QLineEdit(groupBox);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(110, 220, 121, 41));
        lineEditPassword->setFont(font);
        checkBox_CustPriv = new QCheckBox(groupBox);
        checkBox_CustPriv->setObjectName(QStringLiteral("checkBox_CustPriv"));
        checkBox_CustPriv->setGeometry(QRect(460, 150, 16, 31));
        checkBox_CustPriv->setFont(font);
        checkBoxBrandingPriv = new QCheckBox(groupBox);
        checkBoxBrandingPriv->setObjectName(QStringLiteral("checkBoxBrandingPriv"));
        checkBoxBrandingPriv->setGeometry(QRect(460, 70, 16, 31));
        checkBoxBrandingPriv->setFont(font);
        lineEditName = new QLineEdit(groupBox);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(110, 20, 121, 41));
        lineEditName->setFont(font);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(280, 150, 171, 31));
        label_9->setFont(font);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 170, 91, 31));
        label_4->setFont(font);
        NewUserPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NewUserPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 531, 21));
        NewUserPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(NewUserPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        NewUserPageCls->setStatusBar(statusbar);
        QWidget::setTabOrder(lineEditName, lineEditSurName);
        QWidget::setTabOrder(lineEditSurName, lineEditUserName);
        QWidget::setTabOrder(lineEditUserName, lineEditEmail);
        QWidget::setTabOrder(lineEditEmail, lineEditPassword);
        QWidget::setTabOrder(lineEditPassword, checkBox_ProdPriv);
        QWidget::setTabOrder(checkBox_ProdPriv, checkBoxBrandingPriv);
        QWidget::setTabOrder(checkBoxBrandingPriv, checkBox_UserPriv);
        QWidget::setTabOrder(checkBox_UserPriv, checkBox_CustPriv);
        QWidget::setTabOrder(checkBox_CustPriv, checkBox_SalePriv);
        QWidget::setTabOrder(checkBox_SalePriv, pushButtonSave);
        QWidget::setTabOrder(pushButtonSave, pushButtonReturn);

        retranslateUi(NewUserPageCls);

        QMetaObject::connectSlotsByName(NewUserPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *NewUserPageCls)
    {
        NewUserPageCls->setWindowTitle(QApplication::translate("NewUserPageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("NewUserPageCls", "AD", nullptr));
        checkBox_UserPriv->setText(QString());
        label_8->setText(QApplication::translate("NewUserPageCls", "KULLANICI PROF\304\260L\304\260 OLU\305\236TUR", nullptr));
        label_10->setText(QApplication::translate("NewUserPageCls", "SATI\305\236 B\304\260LG\304\260LER\304\260", nullptr));
        label_7->setText(QApplication::translate("NewUserPageCls", "MARKALAMA EKRANI", nullptr));
        checkBox_ProdPriv->setText(QString());
        label_2->setText(QApplication::translate("NewUserPageCls", "SOYAD", nullptr));
        pushButtonReturn->setText(QApplication::translate("NewUserPageCls", "GER\304\260", nullptr));
        label_5->setText(QApplication::translate("NewUserPageCls", "\305\236\304\260FRE", nullptr));
        label_6->setText(QApplication::translate("NewUserPageCls", "M\303\234\305\236TER\304\260 PAR\303\207A G\304\260RD\304\260", nullptr));
        pushButtonSave->setText(QApplication::translate("NewUserPageCls", "KAYDET", nullptr));
        label_3->setText(QApplication::translate("NewUserPageCls", "KULLANICI ADI", nullptr));
        checkBox_SalePriv->setText(QString());
        checkBox_CustPriv->setText(QString());
        checkBoxBrandingPriv->setText(QString());
        label_9->setText(QApplication::translate("NewUserPageCls", "M\303\234\305\236TER\304\260 PROF\304\260L\304\260 OLU\305\236TUR", nullptr));
        label_4->setText(QApplication::translate("NewUserPageCls", "EMAIL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewUserPageCls: public Ui_NewUserPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSERPAGECLS_H
