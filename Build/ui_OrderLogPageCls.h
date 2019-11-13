/********************************************************************************
** Form generated from reading UI file 'OrderLogPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERLOGPAGECLS_H
#define UI_ORDERLOGPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "CheckTableWidget.h"

QT_BEGIN_NAMESPACE

class Ui_OrderLogPageCls
{
public:
    QWidget *centralwidget;
    CheckTableWidget *tableWidget;
    QPushButton *pushButtonReturn;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonDelete;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OrderLogPageCls)
    {
        if (OrderLogPageCls->objectName().isEmpty())
            OrderLogPageCls->setObjectName(QStringLiteral("OrderLogPageCls"));
        OrderLogPageCls->resize(1149, 672);
        centralwidget = new QWidget(OrderLogPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new CheckTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 70, 1091, 491));
        QFont font;
        font.setPointSize(10);
        tableWidget->setFont(font);
        pushButtonReturn = new QPushButton(centralwidget);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(30, 570, 141, 51));
        pushButtonReturn->setFont(font);
        pushButtonSave = new QPushButton(centralwidget);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(30, 10, 171, 51));
        pushButtonSave->setFont(font);
        pushButtonDelete = new QPushButton(centralwidget);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));
        pushButtonDelete->setGeometry(QRect(250, 10, 171, 51));
        pushButtonDelete->setFont(font);
        OrderLogPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OrderLogPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1149, 21));
        OrderLogPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(OrderLogPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        OrderLogPageCls->setStatusBar(statusbar);

        retranslateUi(OrderLogPageCls);

        QMetaObject::connectSlotsByName(OrderLogPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *OrderLogPageCls)
    {
        OrderLogPageCls->setWindowTitle(QApplication::translate("OrderLogPageCls", "MainWindow", nullptr));
        pushButtonReturn->setText(QApplication::translate("OrderLogPageCls", "GER\304\260", nullptr));
        pushButtonSave->setText(QApplication::translate("OrderLogPageCls", "DE\304\236\304\260\305\236\304\260KL\304\260KLER\304\260 KAYDET", nullptr));
        pushButtonDelete->setText(QApplication::translate("OrderLogPageCls", "SE\303\207\304\260LENLER\304\260 S\304\260L", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrderLogPageCls: public Ui_OrderLogPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERLOGPAGECLS_H
