/********************************************************************************
** Form generated from reading UI file 'EditLoadPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITLOADPAGECLS_H
#define UI_EDITLOADPAGECLS_H

#include <CheckTableWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditLoadPageCls
{
public:
    QWidget *centralwidget;
    CheckTableWidget *LoadTable;
    QPushButton *pushButtonReturn;
    QGroupBox *groupBox;
    QPushButton *pushButtonShowLoad;
    QLabel *label_7;
    QLineEdit *lineEditLoadNo;
    QPushButton *pushButtonSave;
    QLineEdit *lineEditFinishNo;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *lineEditBarcode;
    QGroupBox *groupBox_3;
    QLineEdit *lineEditSowNumber;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEditGKR;
    QLineEdit *lineEditProcessedQuantity;
    QLineEdit *lineEditProductNumber;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EditLoadPageCls)
    {
        if (EditLoadPageCls->objectName().isEmpty())
            EditLoadPageCls->setObjectName(QStringLiteral("EditLoadPageCls"));
        EditLoadPageCls->resize(619, 710);
        centralwidget = new QWidget(EditLoadPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        LoadTable = new CheckTableWidget(centralwidget);
        LoadTable->setObjectName(QStringLiteral("LoadTable"));
        LoadTable->setGeometry(QRect(10, 360, 581, 251));
        pushButtonReturn = new QPushButton(centralwidget);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(10, 620, 91, 41));
        QFont font;
        font.setPointSize(10);
        pushButtonReturn->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 0, 581, 121));
        pushButtonShowLoad = new QPushButton(groupBox);
        pushButtonShowLoad->setObjectName(QStringLiteral("pushButtonShowLoad"));
        pushButtonShowLoad->setGeometry(QRect(200, 30, 91, 31));
        pushButtonShowLoad->setFont(font);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 30, 61, 31));
        label_7->setFont(font);
        lineEditLoadNo = new QLineEdit(groupBox);
        lineEditLoadNo->setObjectName(QStringLiteral("lineEditLoadNo"));
        lineEditLoadNo->setGeometry(QRect(82, 30, 101, 31));
        pushButtonSave = new QPushButton(groupBox);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(300, 30, 81, 31));
        pushButtonSave->setFont(font);
        lineEditFinishNo = new QLineEdit(groupBox);
        lineEditFinishNo->setObjectName(QStringLiteral("lineEditFinishNo"));
        lineEditFinishNo->setGeometry(QRect(80, 70, 101, 31));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 70, 61, 31));
        label_6->setFont(font);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 130, 581, 221));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 61, 31));
        label->setFont(font);
        lineEditBarcode = new QLineEdit(groupBox_2);
        lineEditBarcode->setObjectName(QStringLiteral("lineEditBarcode"));
        lineEditBarcode->setGeometry(QRect(70, 30, 113, 31));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 80, 561, 121));
        lineEditSowNumber = new QLineEdit(groupBox_3);
        lineEditSowNumber->setObjectName(QStringLiteral("lineEditSowNumber"));
        lineEditSowNumber->setGeometry(QRect(270, 30, 91, 31));
        lineEditSowNumber->setReadOnly(true);
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 30, 51, 31));
        label_3->setFont(font);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 61, 31));
        label_2->setFont(font);
        lineEditGKR = new QLineEdit(groupBox_3);
        lineEditGKR->setObjectName(QStringLiteral("lineEditGKR"));
        lineEditGKR->setGeometry(QRect(80, 30, 91, 31));
        lineEditGKR->setReadOnly(true);
        lineEditProcessedQuantity = new QLineEdit(groupBox_3);
        lineEditProcessedQuantity->setObjectName(QStringLiteral("lineEditProcessedQuantity"));
        lineEditProcessedQuantity->setGeometry(QRect(270, 70, 41, 31));
        lineEditProcessedQuantity->setReadOnly(false);
        lineEditProductNumber = new QLineEdit(groupBox_3);
        lineEditProductNumber->setObjectName(QStringLiteral("lineEditProductNumber"));
        lineEditProductNumber->setGeometry(QRect(460, 30, 91, 31));
        lineEditProductNumber->setReadOnly(true);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 30, 61, 31));
        label_4->setFont(font);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 70, 91, 31));
        label_5->setFont(font);
        pushButtonAdd = new QPushButton(groupBox_3);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(320, 70, 75, 31));
        pushButtonAdd->setFont(font);
        pushButtonDelete = new QPushButton(groupBox_3);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));
        pushButtonDelete->setGeometry(QRect(400, 70, 151, 31));
        pushButtonDelete->setFont(font);
        EditLoadPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EditLoadPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 619, 21));
        EditLoadPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(EditLoadPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        EditLoadPageCls->setStatusBar(statusbar);

        retranslateUi(EditLoadPageCls);

        QMetaObject::connectSlotsByName(EditLoadPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *EditLoadPageCls)
    {
        EditLoadPageCls->setWindowTitle(QApplication::translate("EditLoadPageCls", "MainWindow", nullptr));
        pushButtonReturn->setText(QApplication::translate("EditLoadPageCls", "GER\304\260", nullptr));
        groupBox->setTitle(QApplication::translate("EditLoadPageCls", "LOAD", nullptr));
        pushButtonShowLoad->setText(QApplication::translate("EditLoadPageCls", "G\303\226R\303\234NT\303\234LE", nullptr));
        label_7->setText(QApplication::translate("EditLoadPageCls", "LOAD NO", nullptr));
        pushButtonSave->setText(QApplication::translate("EditLoadPageCls", "KAYDET", nullptr));
        label_6->setText(QApplication::translate("EditLoadPageCls", "FINISH NO", nullptr));
        groupBox_2->setTitle(QApplication::translate("EditLoadPageCls", "LOAD B\304\260LE\305\236EN\304\260 EKLE/D\303\234ZENLE", nullptr));
        label->setText(QApplication::translate("EditLoadPageCls", "BARKOD", nullptr));
        groupBox_3->setTitle(QApplication::translate("EditLoadPageCls", "B\304\260LG\304\260LER", nullptr));
        label_3->setText(QApplication::translate("EditLoadPageCls", "\304\260\305\236 EMR\304\260", nullptr));
        label_2->setText(QApplication::translate("EditLoadPageCls", "GKR NO", nullptr));
        label_4->setText(QApplication::translate("EditLoadPageCls", "PAR\303\207A NO", nullptr));
        label_5->setText(QApplication::translate("EditLoadPageCls", "\304\260\305\236LENEN ADET", nullptr));
        pushButtonAdd->setText(QApplication::translate("EditLoadPageCls", "EKLE", nullptr));
        pushButtonDelete->setText(QApplication::translate("EditLoadPageCls", "SE\303\207\304\260LENLER\304\260 S\304\260L", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditLoadPageCls: public Ui_EditLoadPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLOADPAGECLS_H
