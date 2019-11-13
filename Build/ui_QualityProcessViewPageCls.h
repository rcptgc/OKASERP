/********************************************************************************
** Form generated from reading UI file 'QualityProcessViewPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUALITYPROCESSVIEWPAGECLS_H
#define UI_QUALITYPROCESSVIEWPAGECLS_H

#include <CheckTableWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QualityProcessViewPageCls
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonEditLoad;
    QPushButton *pushButtonReturn;
    QPushButton *pushButtonNewLoad;
    QLineEdit *lineEditLoadNo;
    QPushButton *pushButtonShowLoad;
    QGroupBox *groupBox_2;
    CheckTableWidget *FinishTable;
    QLineEdit *lineEditFinishCode;
    QLabel *label_8;
    QDateTimeEdit *dateTimeEditEntry;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEditOperatorName;
    QLineEdit *lineEditFinishName;
    QLabel *label_11;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_12;
    QLineEdit *lineEditOperatorName_2;
    QGroupBox *groupBox;
    CheckTableWidget *LoadContentTable;
    QPushButton *pushButtonSaveFinish;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QualityProcessViewPageCls)
    {
        if (QualityProcessViewPageCls->objectName().isEmpty())
            QualityProcessViewPageCls->setObjectName(QStringLiteral("QualityProcessViewPageCls"));
        QualityProcessViewPageCls->resize(1411, 743);
        centralwidget = new QWidget(QualityProcessViewPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButtonEditLoad = new QPushButton(centralwidget);
        pushButtonEditLoad->setObjectName(QStringLiteral("pushButtonEditLoad"));
        pushButtonEditLoad->setGeometry(QRect(20, 10, 121, 31));
        QFont font;
        font.setPointSize(10);
        pushButtonEditLoad->setFont(font);
        pushButtonReturn = new QPushButton(centralwidget);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(10, 620, 101, 41));
        pushButtonReturn->setFont(font);
        pushButtonNewLoad = new QPushButton(centralwidget);
        pushButtonNewLoad->setObjectName(QStringLiteral("pushButtonNewLoad"));
        pushButtonNewLoad->setGeometry(QRect(160, 10, 121, 31));
        pushButtonNewLoad->setFont(font);
        lineEditLoadNo = new QLineEdit(centralwidget);
        lineEditLoadNo->setObjectName(QStringLiteral("lineEditLoadNo"));
        lineEditLoadNo->setGeometry(QRect(80, 60, 71, 31));
        lineEditLoadNo->setReadOnly(false);
        pushButtonShowLoad = new QPushButton(centralwidget);
        pushButtonShowLoad->setObjectName(QStringLiteral("pushButtonShowLoad"));
        pushButtonShowLoad->setGeometry(QRect(160, 60, 91, 31));
        pushButtonShowLoad->setFont(font);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(520, 10, 861, 601));
        FinishTable = new CheckTableWidget(groupBox_2);
        FinishTable->setObjectName(QStringLiteral("FinishTable"));
        FinishTable->setGeometry(QRect(10, 110, 841, 391));
        lineEditFinishCode = new QLineEdit(groupBox_2);
        lineEditFinishCode->setObjectName(QStringLiteral("lineEditFinishCode"));
        lineEditFinishCode->setGeometry(QRect(90, 20, 71, 31));
        lineEditFinishCode->setReadOnly(true);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 20, 81, 31));
        label_8->setFont(font);
        dateTimeEditEntry = new QDateTimeEdit(groupBox_2);
        dateTimeEditEntry->setObjectName(QStringLiteral("dateTimeEditEntry"));
        dateTimeEditEntry->setGeometry(QRect(270, 20, 141, 31));
        dateTimeEditEntry->setFont(font);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(180, 20, 81, 31));
        label_9->setFont(font);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(440, 20, 81, 31));
        label_10->setFont(font);
        lineEditOperatorName = new QLineEdit(groupBox_2);
        lineEditOperatorName->setObjectName(QStringLiteral("lineEditOperatorName"));
        lineEditOperatorName->setGeometry(QRect(530, 20, 113, 31));
        lineEditOperatorName->setReadOnly(false);
        lineEditFinishName = new QLineEdit(groupBox_2);
        lineEditFinishName->setObjectName(QStringLiteral("lineEditFinishName"));
        lineEditFinishName->setGeometry(QRect(90, 70, 191, 31));
        lineEditFinishName->setReadOnly(true);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 70, 81, 31));
        label_11->setFont(font);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(530, 540, 47, 13));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(580, 510, 271, 71));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(160, 550, 81, 31));
        label_12->setFont(font);
        lineEditOperatorName_2 = new QLineEdit(groupBox_2);
        lineEditOperatorName_2->setObjectName(QStringLiteral("lineEditOperatorName_2"));
        lineEditOperatorName_2->setGeometry(QRect(250, 550, 113, 31));
        lineEditOperatorName_2->setReadOnly(false);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 100, 501, 511));
        LoadContentTable = new CheckTableWidget(groupBox);
        LoadContentTable->setObjectName(QStringLiteral("LoadContentTable"));
        LoadContentTable->setGeometry(QRect(10, 20, 481, 481));
        pushButtonSaveFinish = new QPushButton(centralwidget);
        pushButtonSaveFinish->setObjectName(QStringLiteral("pushButtonSaveFinish"));
        pushButtonSaveFinish->setGeometry(QRect(260, 60, 91, 31));
        pushButtonSaveFinish->setFont(font);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 60, 61, 31));
        label_7->setFont(font);
        QualityProcessViewPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QualityProcessViewPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1411, 21));
        QualityProcessViewPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(QualityProcessViewPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QualityProcessViewPageCls->setStatusBar(statusbar);

        retranslateUi(QualityProcessViewPageCls);

        QMetaObject::connectSlotsByName(QualityProcessViewPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *QualityProcessViewPageCls)
    {
        QualityProcessViewPageCls->setWindowTitle(QApplication::translate("QualityProcessViewPageCls", "MainWindow", nullptr));
        pushButtonEditLoad->setText(QApplication::translate("QualityProcessViewPageCls", "LOAD D\303\234ZENLE >>", nullptr));
        pushButtonReturn->setText(QApplication::translate("QualityProcessViewPageCls", "GER\304\260", nullptr));
        pushButtonNewLoad->setText(QApplication::translate("QualityProcessViewPageCls", "YEN\304\260 LOAD >>", nullptr));
        pushButtonShowLoad->setText(QApplication::translate("QualityProcessViewPageCls", "G\303\226R\303\234NT\303\234LE", nullptr));
        groupBox_2->setTitle(QApplication::translate("QualityProcessViewPageCls", "FINISH B\304\260LG\304\260LER\304\260", nullptr));
        label_8->setText(QApplication::translate("QualityProcessViewPageCls", "FINISH KODU", nullptr));
        label_9->setText(QApplication::translate("QualityProcessViewPageCls", "TAR\304\260H/ZAMAN", nullptr));
        label_10->setText(QApplication::translate("QualityProcessViewPageCls", "\303\207ALI\305\236AN ADI", nullptr));
        label_11->setText(QApplication::translate("QualityProcessViewPageCls", "FINISH ADI", nullptr));
        label->setText(QApplication::translate("QualityProcessViewPageCls", "NOTLAR", nullptr));
        label_12->setText(QApplication::translate("QualityProcessViewPageCls", "B\304\260T\304\260\305\236 ZAMANI", nullptr));
        groupBox->setTitle(QApplication::translate("QualityProcessViewPageCls", "LOAD B\304\260LG\304\260LER\304\260", nullptr));
        pushButtonSaveFinish->setText(QApplication::translate("QualityProcessViewPageCls", "KAYDET", nullptr));
        label_7->setText(QApplication::translate("QualityProcessViewPageCls", "LOAD NO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QualityProcessViewPageCls: public Ui_QualityProcessViewPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUALITYPROCESSVIEWPAGECLS_H
