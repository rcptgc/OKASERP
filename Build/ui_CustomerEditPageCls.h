/********************************************************************************
** Form generated from reading UI file 'CustomerEditPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMEREDITPAGECLS_H
#define UI_CUSTOMEREDITPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomerEditPageCls
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *pushButtonReturn;
    QPushButton *pushButtonDelete;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CustomerEditPageCls)
    {
        if (CustomerEditPageCls->objectName().isEmpty())
            CustomerEditPageCls->setObjectName(QStringLiteral("CustomerEditPageCls"));
        CustomerEditPageCls->resize(800, 600);
        centralwidget = new QWidget(CustomerEditPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 60, 741, 441));
        pushButtonReturn = new QPushButton(centralwidget);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(30, 510, 151, 41));
        pushButtonDelete = new QPushButton(centralwidget);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));
        pushButtonDelete->setGeometry(QRect(240, 510, 151, 41));
        CustomerEditPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CustomerEditPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        CustomerEditPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(CustomerEditPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CustomerEditPageCls->setStatusBar(statusbar);

        retranslateUi(CustomerEditPageCls);

        QMetaObject::connectSlotsByName(CustomerEditPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *CustomerEditPageCls)
    {
        CustomerEditPageCls->setWindowTitle(QApplication::translate("CustomerEditPageCls", "MainWindow", nullptr));
        pushButtonReturn->setText(QApplication::translate("CustomerEditPageCls", "GER\304\260 D\303\226N", nullptr));
        pushButtonDelete->setText(QApplication::translate("CustomerEditPageCls", "SE\303\207\304\260LENLER\304\260 S\304\260L", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerEditPageCls: public Ui_CustomerEditPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMEREDITPAGECLS_H
