/********************************************************************************
** Form generated from reading UI file 'CreateOrderPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEORDERPAGECLS_H
#define UI_CREATEORDERPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateOrderPageCls
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLineEdit *lineEditProjectName;
    QLabel *label_3;
    QLineEdit *lineEditPartNumber;
    QLabel *label_4;
    QLineEdit *lineEditPoNumber;
    QLineEdit *lineEditSowNumber;
    QLabel *label_5;
    QLineEdit *lineEditReceiveQuantity;
    QLabel *label_6;
    QLineEdit *lineEditAcceptedQuantity;
    QLabel *label_7;
    QLineEdit *lineEditRejectedQuantity;
    QLabel *label_8;
    QLineEdit *lineEditUrgency;
    QLabel *label_10;
    QLineEdit *lineEditSoir;
    QLabel *label_11;
    QDateEdit *dateEdit;
    QLabel *label_12;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonReturn;
    QLabel *label_9;
    QLineEdit *lineEditDispatchNo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateOrderPageCls)
    {
        if (CreateOrderPageCls->objectName().isEmpty())
            CreateOrderPageCls->setObjectName(QStringLiteral("CreateOrderPageCls"));
        CreateOrderPageCls->resize(752, 371);
        centralwidget = new QWidget(CreateOrderPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 51, 41));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        lineEditProjectName = new QLineEdit(centralwidget);
        lineEditProjectName->setObjectName(QStringLiteral("lineEditProjectName"));
        lineEditProjectName->setGeometry(QRect(120, 90, 131, 41));
        lineEditProjectName->setFont(font);
        lineEditProjectName->setReadOnly(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 150, 71, 41));
        label_3->setFont(font);
        lineEditPartNumber = new QLineEdit(centralwidget);
        lineEditPartNumber->setObjectName(QStringLiteral("lineEditPartNumber"));
        lineEditPartNumber->setGeometry(QRect(120, 150, 131, 41));
        lineEditPartNumber->setFont(font);
        lineEditPartNumber->setReadOnly(false);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 210, 71, 41));
        label_4->setFont(font);
        lineEditPoNumber = new QLineEdit(centralwidget);
        lineEditPoNumber->setObjectName(QStringLiteral("lineEditPoNumber"));
        lineEditPoNumber->setGeometry(QRect(120, 210, 131, 41));
        lineEditPoNumber->setFont(font);
        lineEditPoNumber->setReadOnly(false);
        lineEditSowNumber = new QLineEdit(centralwidget);
        lineEditSowNumber->setObjectName(QStringLiteral("lineEditSowNumber"));
        lineEditSowNumber->setGeometry(QRect(590, 30, 131, 41));
        lineEditSowNumber->setFont(font);
        lineEditSowNumber->setReadOnly(false);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(530, 30, 61, 41));
        label_5->setFont(font);
        lineEditReceiveQuantity = new QLineEdit(centralwidget);
        lineEditReceiveQuantity->setObjectName(QStringLiteral("lineEditReceiveQuantity"));
        lineEditReceiveQuantity->setGeometry(QRect(370, 90, 131, 41));
        lineEditReceiveQuantity->setFont(font);
        lineEditReceiveQuantity->setReadOnly(false);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(280, 90, 71, 41));
        label_6->setFont(font);
        lineEditAcceptedQuantity = new QLineEdit(centralwidget);
        lineEditAcceptedQuantity->setObjectName(QStringLiteral("lineEditAcceptedQuantity"));
        lineEditAcceptedQuantity->setGeometry(QRect(370, 150, 131, 41));
        lineEditAcceptedQuantity->setFont(font);
        lineEditAcceptedQuantity->setReadOnly(false);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(280, 150, 71, 41));
        label_7->setFont(font);
        lineEditRejectedQuantity = new QLineEdit(centralwidget);
        lineEditRejectedQuantity->setObjectName(QStringLiteral("lineEditRejectedQuantity"));
        lineEditRejectedQuantity->setGeometry(QRect(370, 210, 131, 41));
        lineEditRejectedQuantity->setFont(font);
        lineEditRejectedQuantity->setReadOnly(false);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(280, 210, 71, 41));
        label_8->setFont(font);
        lineEditUrgency = new QLineEdit(centralwidget);
        lineEditUrgency->setObjectName(QStringLiteral("lineEditUrgency"));
        lineEditUrgency->setGeometry(QRect(590, 90, 131, 41));
        lineEditUrgency->setFont(font);
        lineEditUrgency->setReadOnly(false);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(530, 90, 31, 41));
        label_10->setFont(font);
        lineEditSoir = new QLineEdit(centralwidget);
        lineEditSoir->setObjectName(QStringLiteral("lineEditSoir"));
        lineEditSoir->setGeometry(QRect(590, 150, 131, 41));
        lineEditSoir->setFont(font);
        lineEditSoir->setReadOnly(false);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(530, 150, 31, 41));
        label_11->setFont(font);
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(120, 30, 131, 41));
        dateEdit->setFont(font);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 30, 81, 41));
        label_12->setFont(font);
        pushButtonSave = new QPushButton(centralwidget);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(620, 270, 121, 41));
        pushButtonSave->setFont(font);
        pushButtonReturn = new QPushButton(centralwidget);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(20, 270, 121, 41));
        pushButtonReturn->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(280, 30, 81, 41));
        label_9->setFont(font);
        lineEditDispatchNo = new QLineEdit(centralwidget);
        lineEditDispatchNo->setObjectName(QStringLiteral("lineEditDispatchNo"));
        lineEditDispatchNo->setGeometry(QRect(370, 30, 131, 41));
        lineEditDispatchNo->setFont(font);
        lineEditDispatchNo->setReadOnly(false);
        CreateOrderPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateOrderPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 752, 21));
        CreateOrderPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(CreateOrderPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CreateOrderPageCls->setStatusBar(statusbar);
        QWidget::setTabOrder(dateEdit, lineEditProjectName);
        QWidget::setTabOrder(lineEditProjectName, lineEditPartNumber);
        QWidget::setTabOrder(lineEditPartNumber, lineEditPoNumber);
        QWidget::setTabOrder(lineEditPoNumber, lineEditReceiveQuantity);
        QWidget::setTabOrder(lineEditReceiveQuantity, lineEditAcceptedQuantity);
        QWidget::setTabOrder(lineEditAcceptedQuantity, lineEditRejectedQuantity);
        QWidget::setTabOrder(lineEditRejectedQuantity, lineEditSowNumber);
        QWidget::setTabOrder(lineEditSowNumber, lineEditUrgency);
        QWidget::setTabOrder(lineEditUrgency, lineEditSoir);
        QWidget::setTabOrder(lineEditSoir, pushButtonSave);
        QWidget::setTabOrder(pushButtonSave, pushButtonReturn);

        retranslateUi(CreateOrderPageCls);

        QMetaObject::connectSlotsByName(CreateOrderPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *CreateOrderPageCls)
    {
        CreateOrderPageCls->setWindowTitle(QApplication::translate("CreateOrderPageCls", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("CreateOrderPageCls", "PROJE", nullptr));
        label_3->setText(QApplication::translate("CreateOrderPageCls", "PAR\303\207A NO", nullptr));
        label_4->setText(QApplication::translate("CreateOrderPageCls", "S\304\260PAR\304\260\305\236 EMR\304\260", nullptr));
        label_5->setText(QApplication::translate("CreateOrderPageCls", "\304\260\305\236 EMR\304\260", nullptr));
        label_6->setText(QApplication::translate("CreateOrderPageCls", "G\303\226N. ADET", nullptr));
        label_7->setText(QApplication::translate("CreateOrderPageCls", "K.E. ADET", nullptr));
        label_8->setText(QApplication::translate("CreateOrderPageCls", "RET ADET", nullptr));
        label_10->setText(QApplication::translate("CreateOrderPageCls", "AC\304\260L", nullptr));
        label_11->setText(QApplication::translate("CreateOrderPageCls", "SOIR", nullptr));
        label_12->setText(QApplication::translate("CreateOrderPageCls", "G\304\260R\304\260\305\236 TAR\304\260H\304\260", nullptr));
        pushButtonSave->setText(QApplication::translate("CreateOrderPageCls", "KAYDET", nullptr));
        pushButtonReturn->setText(QApplication::translate("CreateOrderPageCls", "GER\304\260", nullptr));
        label_9->setText(QApplication::translate("CreateOrderPageCls", "\304\260RSAL\304\260YE NO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateOrderPageCls: public Ui_CreateOrderPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEORDERPAGECLS_H
