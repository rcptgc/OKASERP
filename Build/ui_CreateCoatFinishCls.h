/********************************************************************************
** Form generated from reading UI file 'CreateCoatFinishCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECOATFINISHCLS_H
#define UI_CREATECOATFINISHCLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateCoatFinishCls
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateCoatFinishCls)
    {
        if (CreateCoatFinishCls->objectName().isEmpty())
            CreateCoatFinishCls->setObjectName(QStringLiteral("CreateCoatFinishCls"));
        CreateCoatFinishCls->resize(853, 600);
        centralwidget = new QWidget(CreateCoatFinishCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 80, 781, 431));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 91, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 10, 91, 41));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 10, 91, 41));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(430, 10, 113, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(370, 10, 61, 41));
        CreateCoatFinishCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateCoatFinishCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 853, 21));
        CreateCoatFinishCls->setMenuBar(menubar);
        statusbar = new QStatusBar(CreateCoatFinishCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CreateCoatFinishCls->setStatusBar(statusbar);

        retranslateUi(CreateCoatFinishCls);

        QMetaObject::connectSlotsByName(CreateCoatFinishCls);
    } // setupUi

    void retranslateUi(QMainWindow *CreateCoatFinishCls)
    {
        CreateCoatFinishCls->setWindowTitle(QApplication::translate("CreateCoatFinishCls", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("CreateCoatFinishCls", "SATIR EKLE", nullptr));
        pushButton_2->setText(QApplication::translate("CreateCoatFinishCls", "SATIR S\304\260L", nullptr));
        pushButton_3->setText(QApplication::translate("CreateCoatFinishCls", "FINISH S\304\260L", nullptr));
        label->setText(QApplication::translate("CreateCoatFinishCls", "FINISH BUL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateCoatFinishCls: public Ui_CreateCoatFinishCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECOATFINISHCLS_H
