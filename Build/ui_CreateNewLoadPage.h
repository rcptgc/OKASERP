/********************************************************************************
** Form generated from reading UI file 'CreateNewLoadPage.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWLOADPAGE_H
#define UI_CREATENEWLOADPAGE_H

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

class Ui_CreateNewLoadPage
{
public:
    QWidget *centralwidget;
    CheckTableWidget *LoadTable;
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
    QPushButton *pushButtonReturn;
    QGroupBox *groupBox;
    QLabel *label_7;
    QLineEdit *lineEditLoadNo;
    QPushButton *pushButtonSave;
    QLineEdit *lineEditFinishNo;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateNewLoadPage)
    {
        if (CreateNewLoadPage->objectName().isEmpty())
            CreateNewLoadPage->setObjectName(QStringLiteral("CreateNewLoadPage"));
        CreateNewLoadPage->resize(800, 716);
        centralwidget = new QWidget(CreateNewLoadPage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        LoadTable = new CheckTableWidget(centralwidget);
        LoadTable->setObjectName(QStringLiteral("LoadTable"));
        LoadTable->setGeometry(QRect(30, 370, 581, 251));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 140, 581, 221));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 61, 31));
        QFont font;
        font.setPointSize(10);
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
        pushButtonReturn = new QPushButton(centralwidget);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(30, 630, 91, 41));
        pushButtonReturn->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 581, 121));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 30, 61, 31));
        label_7->setFont(font);
        lineEditLoadNo = new QLineEdit(groupBox);
        lineEditLoadNo->setObjectName(QStringLiteral("lineEditLoadNo"));
        lineEditLoadNo->setGeometry(QRect(82, 30, 101, 31));
        lineEditLoadNo->setReadOnly(true);
        pushButtonSave = new QPushButton(groupBox);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(400, 30, 81, 31));
        pushButtonSave->setFont(font);
        lineEditFinishNo = new QLineEdit(groupBox);
        lineEditFinishNo->setObjectName(QStringLiteral("lineEditFinishNo"));
        lineEditFinishNo->setGeometry(QRect(290, 30, 101, 31));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(220, 30, 61, 31));
        label_6->setFont(font);
        CreateNewLoadPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateNewLoadPage);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        CreateNewLoadPage->setMenuBar(menubar);
        statusbar = new QStatusBar(CreateNewLoadPage);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CreateNewLoadPage->setStatusBar(statusbar);

        retranslateUi(CreateNewLoadPage);

        QMetaObject::connectSlotsByName(CreateNewLoadPage);
    } // setupUi

    void retranslateUi(QMainWindow *CreateNewLoadPage)
    {
        CreateNewLoadPage->setWindowTitle(QApplication::translate("CreateNewLoadPage", "MainWindow", nullptr));
        groupBox_2->setTitle(QApplication::translate("CreateNewLoadPage", "LOAD B\304\260LE\305\236EN\304\260 EKLE/D\303\234ZENLE", nullptr));
        label->setText(QApplication::translate("CreateNewLoadPage", "BARKOD", nullptr));
        groupBox_3->setTitle(QApplication::translate("CreateNewLoadPage", "B\304\260LG\304\260LER", nullptr));
        label_3->setText(QApplication::translate("CreateNewLoadPage", "\304\260\305\236 EMR\304\260", nullptr));
        label_2->setText(QApplication::translate("CreateNewLoadPage", "GKR NO", nullptr));
        label_4->setText(QApplication::translate("CreateNewLoadPage", "PAR\303\207A NO", nullptr));
        label_5->setText(QApplication::translate("CreateNewLoadPage", "\304\260\305\236LENEN ADET", nullptr));
        pushButtonAdd->setText(QApplication::translate("CreateNewLoadPage", "EKLE", nullptr));
        pushButtonDelete->setText(QApplication::translate("CreateNewLoadPage", "SE\303\207\304\260LENLER\304\260 S\304\260L", nullptr));
        pushButtonReturn->setText(QApplication::translate("CreateNewLoadPage", "GER\304\260", nullptr));
        groupBox->setTitle(QApplication::translate("CreateNewLoadPage", "LOAD", nullptr));
        label_7->setText(QApplication::translate("CreateNewLoadPage", "LOAD NO", nullptr));
        pushButtonSave->setText(QApplication::translate("CreateNewLoadPage", "KAYDET", nullptr));
        label_6->setText(QApplication::translate("CreateNewLoadPage", "FINISH NO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateNewLoadPage: public Ui_CreateNewLoadPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWLOADPAGE_H
