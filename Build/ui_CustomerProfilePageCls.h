/********************************************************************************
** Form generated from reading UI file 'CustomerProfilePageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERPROFILEPAGECLS_H
#define UI_CUSTOMERPROFILEPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomerProfilePageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButtonAddCustomer;
    QPushButton *pushButtonEditCustomer;
    QPushButton *pushButtonReturn;
    QLineEdit *lineEditCustomerName;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditBarcodePrefix;
    QLineEdit *lineEditSowPrefix;
    QLabel *label_3;
    QLabel *label_7;
    QCheckBox *checkBox;
    QLabel *label_8;
    QComboBox *comboBoxDateTimeType;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CustomerProfilePageCls)
    {
        if (CustomerProfilePageCls->objectName().isEmpty())
            CustomerProfilePageCls->setObjectName(QStringLiteral("CustomerProfilePageCls"));
        CustomerProfilePageCls->resize(630, 345);
        CustomerProfilePageCls->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(CustomerProfilePageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 591, 241));
        pushButtonAddCustomer = new QPushButton(groupBox);
        pushButtonAddCustomer->setObjectName(QStringLiteral("pushButtonAddCustomer"));
        pushButtonAddCustomer->setGeometry(QRect(220, 170, 151, 41));
        QFont font;
        font.setPointSize(10);
        pushButtonAddCustomer->setFont(font);
        pushButtonEditCustomer = new QPushButton(groupBox);
        pushButtonEditCustomer->setObjectName(QStringLiteral("pushButtonEditCustomer"));
        pushButtonEditCustomer->setGeometry(QRect(400, 170, 151, 41));
        pushButtonEditCustomer->setFont(font);
        pushButtonReturn = new QPushButton(groupBox);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(40, 170, 151, 41));
        pushButtonReturn->setFont(font);
        lineEditCustomerName = new QLineEdit(groupBox);
        lineEditCustomerName->setObjectName(QStringLiteral("lineEditCustomerName"));
        lineEditCustomerName->setGeometry(QRect(150, 20, 121, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 91, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 20, 101, 31));
        label_2->setFont(font1);
        lineEditBarcodePrefix = new QLineEdit(groupBox);
        lineEditBarcodePrefix->setObjectName(QStringLiteral("lineEditBarcodePrefix"));
        lineEditBarcodePrefix->setGeometry(QRect(430, 20, 121, 31));
        lineEditSowPrefix = new QLineEdit(groupBox);
        lineEditSowPrefix->setObjectName(QStringLiteral("lineEditSowPrefix"));
        lineEditSowPrefix->setGeometry(QRect(150, 70, 121, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 70, 101, 31));
        label_3->setFont(font1);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 110, 91, 31));
        label_7->setFont(font1);
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(150, 110, 16, 31));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(290, 70, 131, 31));
        label_8->setFont(font1);
        comboBoxDateTimeType = new QComboBox(groupBox);
        comboBoxDateTimeType->setObjectName(QStringLiteral("comboBoxDateTimeType"));
        comboBoxDateTimeType->setGeometry(QRect(430, 70, 121, 31));
        CustomerProfilePageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CustomerProfilePageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 630, 21));
        CustomerProfilePageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(CustomerProfilePageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CustomerProfilePageCls->setStatusBar(statusbar);
        QWidget::setTabOrder(lineEditCustomerName, lineEditBarcodePrefix);
        QWidget::setTabOrder(lineEditBarcodePrefix, lineEditSowPrefix);
        QWidget::setTabOrder(lineEditSowPrefix, checkBox);
        QWidget::setTabOrder(checkBox, comboBoxDateTimeType);
        QWidget::setTabOrder(comboBoxDateTimeType, pushButtonAddCustomer);
        QWidget::setTabOrder(pushButtonAddCustomer, pushButtonEditCustomer);
        QWidget::setTabOrder(pushButtonEditCustomer, pushButtonReturn);

        retranslateUi(CustomerProfilePageCls);

        QMetaObject::connectSlotsByName(CustomerProfilePageCls);
    } // setupUi

    void retranslateUi(QMainWindow *CustomerProfilePageCls)
    {
        CustomerProfilePageCls->setWindowTitle(QApplication::translate("CustomerProfilePageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pushButtonAddCustomer->setText(QApplication::translate("CustomerProfilePageCls", "M\303\234\305\236TER\304\260 EKLE", nullptr));
        pushButtonEditCustomer->setText(QApplication::translate("CustomerProfilePageCls", "M\303\234\305\236TER\304\260 D\303\234ZENLE", nullptr));
        pushButtonReturn->setText(QApplication::translate("CustomerProfilePageCls", "GER\304\260", nullptr));
        label->setText(QApplication::translate("CustomerProfilePageCls", "M\303\234\305\236TER\304\260 ADI", nullptr));
        label_2->setText(QApplication::translate("CustomerProfilePageCls", "BARKOD \303\226N EK\304\260", nullptr));
        label_3->setText(QApplication::translate("CustomerProfilePageCls", "\304\260\305\236 EMR\304\260 \303\226N EK\304\260", nullptr));
        label_7->setText(QApplication::translate("CustomerProfilePageCls", "SOIR S\303\234TUNU", nullptr));
        checkBox->setText(QString());
        label_8->setText(QApplication::translate("CustomerProfilePageCls", "M\303\234\305\236TER\304\260 TAR\304\260H T\304\260P\304\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerProfilePageCls: public Ui_CustomerProfilePageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERPROFILEPAGECLS_H
