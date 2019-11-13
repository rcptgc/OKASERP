/********************************************************************************
** Form generated from reading UI file 'SalesEntryPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALESENTRYPAGECLS_H
#define UI_SALESENTRYPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SalesEntryPageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QPushButton *pushButtonAssignDate;
    QTableWidget *tableWidget;
    QPushButton *pushButtonReturn;
    QPushButton *pushButtonBarcodeRead;
    QPushButton *pushButtonSave;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SalesEntryPageCls)
    {
        if (SalesEntryPageCls->objectName().isEmpty())
            SalesEntryPageCls->setObjectName(QStringLiteral("SalesEntryPageCls"));
        SalesEntryPageCls->resize(800, 600);
        SalesEntryPageCls->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(SalesEntryPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 50, 701, 421));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 130, 141, 31));
        lineEdit->setFont(font);
        pushButtonAssignDate = new QPushButton(groupBox);
        pushButtonAssignDate->setObjectName(QStringLiteral("pushButtonAssignDate"));
        pushButtonAssignDate->setGeometry(QRect(20, 210, 141, 51));
        pushButtonAssignDate->setFont(font);
        tableWidget = new QTableWidget(groupBox);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(180, 10, 511, 261));
        tableWidget->setFont(font);
        pushButtonReturn = new QPushButton(groupBox);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(20, 360, 141, 51));
        pushButtonReturn->setFont(font);
        pushButtonBarcodeRead = new QPushButton(groupBox);
        pushButtonBarcodeRead->setObjectName(QStringLiteral("pushButtonBarcodeRead"));
        pushButtonBarcodeRead->setGeometry(QRect(20, 10, 141, 111));
        pushButtonBarcodeRead->setFont(font);
        pushButtonSave = new QPushButton(groupBox);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(20, 280, 141, 51));
        pushButtonSave->setFont(font);
        SalesEntryPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SalesEntryPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        SalesEntryPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(SalesEntryPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SalesEntryPageCls->setStatusBar(statusbar);

        retranslateUi(SalesEntryPageCls);

        QMetaObject::connectSlotsByName(SalesEntryPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *SalesEntryPageCls)
    {
        SalesEntryPageCls->setWindowTitle(QApplication::translate("SalesEntryPageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pushButtonAssignDate->setText(QApplication::translate("SalesEntryPageCls", "TAR\304\260H ATA", nullptr));
        pushButtonReturn->setText(QApplication::translate("SalesEntryPageCls", "GER\304\260", nullptr));
        pushButtonBarcodeRead->setText(QApplication::translate("SalesEntryPageCls", "BARKOD OKUT", nullptr));
        pushButtonSave->setText(QApplication::translate("SalesEntryPageCls", "KAYDET", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SalesEntryPageCls: public Ui_SalesEntryPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALESENTRYPAGECLS_H
