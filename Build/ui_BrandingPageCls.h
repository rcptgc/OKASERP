/********************************************************************************
** Form generated from reading UI file 'BrandingPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRANDINGPAGECLS_H
#define UI_BRANDINGPAGECLS_H

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

class Ui_BrandingPageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QLineEdit *lineEditMainCustomer;
    QLabel *label_3;
    QGroupBox *groupBox_5;
    QLineEdit *lineEditSoir;
    QLabel *label_5;
    QGroupBox *groupBox_2;
    QLineEdit *lineEditSowNumber;
    QLabel *label_2;
    QGroupBox *groupBox_4;
    QLineEdit *lineEditPartNumber;
    QLabel *label;
    QPushButton *pushButtonReturn;
    QLineEdit *lineEditBarcode;
    QGroupBox *groupBox_8;
    QLineEdit *lineEditDate;
    QLabel *label_4;
    QPushButton *pushButtonSaveBrandDate;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BrandingPageCls)
    {
        if (BrandingPageCls->objectName().isEmpty())
            BrandingPageCls->setObjectName(QStringLiteral("BrandingPageCls"));
        BrandingPageCls->resize(728, 338);
        BrandingPageCls->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(BrandingPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 691, 271));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(280, 80, 131, 91));
        lineEditMainCustomer = new QLineEdit(groupBox_3);
        lineEditMainCustomer->setObjectName(QStringLiteral("lineEditMainCustomer"));
        lineEditMainCustomer->setGeometry(QRect(10, 40, 111, 41));
        lineEditMainCustomer->setReadOnly(true);
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 111, 21));
        QFont font;
        font.setPointSize(10);
        label_3->setFont(font);
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(540, 80, 131, 91));
        lineEditSoir = new QLineEdit(groupBox_5);
        lineEditSoir->setObjectName(QStringLiteral("lineEditSoir"));
        lineEditSoir->setGeometry(QRect(10, 40, 111, 41));
        lineEditSoir->setReadOnly(true);
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 111, 21));
        label_5->setFont(font);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(150, 80, 131, 91));
        lineEditSowNumber = new QLineEdit(groupBox_2);
        lineEditSowNumber->setObjectName(QStringLiteral("lineEditSowNumber"));
        lineEditSowNumber->setGeometry(QRect(10, 40, 111, 41));
        lineEditSowNumber->setReadOnly(true);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 111, 21));
        label_2->setFont(font);
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 80, 131, 91));
        lineEditPartNumber = new QLineEdit(groupBox_4);
        lineEditPartNumber->setObjectName(QStringLiteral("lineEditPartNumber"));
        lineEditPartNumber->setGeometry(QRect(10, 40, 111, 41));
        lineEditPartNumber->setReadOnly(true);
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 111, 21));
        label->setFont(font);
        pushButtonReturn = new QPushButton(groupBox);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(20, 200, 171, 51));
        pushButtonReturn->setFont(font);
        lineEditBarcode = new QLineEdit(groupBox);
        lineEditBarcode->setObjectName(QStringLiteral("lineEditBarcode"));
        lineEditBarcode->setGeometry(QRect(150, 20, 161, 41));
        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(410, 80, 131, 91));
        lineEditDate = new QLineEdit(groupBox_8);
        lineEditDate->setObjectName(QStringLiteral("lineEditDate"));
        lineEditDate->setGeometry(QRect(10, 40, 111, 41));
        lineEditDate->setReadOnly(true);
        label_4 = new QLabel(groupBox_8);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 111, 21));
        label_4->setFont(font);
        pushButtonSaveBrandDate = new QPushButton(groupBox);
        pushButtonSaveBrandDate->setObjectName(QStringLiteral("pushButtonSaveBrandDate"));
        pushButtonSaveBrandDate->setGeometry(QRect(470, 200, 201, 51));
        pushButtonSaveBrandDate->setFont(font);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 20, 51, 41));
        label_6->setFont(font);
        BrandingPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BrandingPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 728, 21));
        BrandingPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(BrandingPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        BrandingPageCls->setStatusBar(statusbar);

        retranslateUi(BrandingPageCls);

        QMetaObject::connectSlotsByName(BrandingPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *BrandingPageCls)
    {
        BrandingPageCls->setWindowTitle(QApplication::translate("BrandingPageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        groupBox_3->setTitle(QString());
        label_3->setText(QApplication::translate("BrandingPageCls", "M\303\234\305\236TER\304\260", nullptr));
        groupBox_5->setTitle(QString());
        label_5->setText(QApplication::translate("BrandingPageCls", "SOIR", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QApplication::translate("BrandingPageCls", "\304\260\305\236 EMR\304\260", nullptr));
        groupBox_4->setTitle(QString());
        label->setText(QApplication::translate("BrandingPageCls", "PAR\303\207A NO", nullptr));
        pushButtonReturn->setText(QApplication::translate("BrandingPageCls", "GER\304\260", nullptr));
        groupBox_8->setTitle(QString());
        label_4->setText(QApplication::translate("BrandingPageCls", "TAR\304\260H", nullptr));
        pushButtonSaveBrandDate->setText(QApplication::translate("BrandingPageCls", "MARKALAMA TAR\304\260H\304\260N\304\260 KAYDET", nullptr));
        label_6->setText(QApplication::translate("BrandingPageCls", "BARKOD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrandingPageCls: public Ui_BrandingPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRANDINGPAGECLS_H
