/********************************************************************************
** Form generated from reading UI file 'ProductionEntryPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTIONENTRYPAGECLS_H
#define UI_PRODUCTIONENTRYPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductionEntryPageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_8;
    QTextEdit *textEditNotes;
    QPushButton *pushButtonReturn;
    QPushButton *pushButtonSave;
    QLineEdit *lineEditBarcode;
    QLineEdit *lineEditGKR;
    QLineEdit *lineEditReceivedQuantity;
    QLabel *label_7;
    QLineEdit *lineEditProcessedQuantity;
    QLabel *label_9;
    QLineEdit *lineEditOperatorName;
    QGroupBox *groupBox_2;
    QRadioButton *radioButtonStartTime;
    QRadioButton *radioButton_2;
    QDateTimeEdit *dateTimeEditEntry;
    QPushButton *pushButtonProcess;
    QGroupBox *groupBox_3;
    QRadioButton *radioButtonQuality;
    QRadioButton *radioButtonPrePaint;
    QRadioButton *radioButtonPaintApp;
    QRadioButton *radioButtonCoating;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProductionEntryPageCls)
    {
        if (ProductionEntryPageCls->objectName().isEmpty())
            ProductionEntryPageCls->setObjectName(QStringLiteral("ProductionEntryPageCls"));
        ProductionEntryPageCls->resize(948, 456);
        centralwidget = new QWidget(ProductionEntryPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 50, 311, 101));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 10, 51, 31));
        QFont font;
        font.setPointSize(10);
        label_4->setFont(font);
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 50, 271, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 50, 71, 31));
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 90, 61, 31));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 130, 101, 31));
        label_3->setFont(font);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(710, 20, 111, 31));
        label_8->setFont(font);
        textEditNotes = new QTextEdit(centralwidget);
        textEditNotes->setObjectName(QStringLiteral("textEditNotes"));
        textEditNotes->setGeometry(QRect(600, 50, 321, 191));
        pushButtonReturn = new QPushButton(centralwidget);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(290, 350, 191, 51));
        pushButtonReturn->setFont(font);
        pushButtonSave = new QPushButton(centralwidget);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(490, 350, 191, 51));
        pushButtonSave->setFont(font);
        lineEditBarcode = new QLineEdit(centralwidget);
        lineEditBarcode->setObjectName(QStringLiteral("lineEditBarcode"));
        lineEditBarcode->setGeometry(QRect(460, 50, 113, 31));
        lineEditGKR = new QLineEdit(centralwidget);
        lineEditGKR->setObjectName(QStringLiteral("lineEditGKR"));
        lineEditGKR->setGeometry(QRect(460, 90, 113, 31));
        lineEditGKR->setReadOnly(true);
        lineEditReceivedQuantity = new QLineEdit(centralwidget);
        lineEditReceivedQuantity->setObjectName(QStringLiteral("lineEditReceivedQuantity"));
        lineEditReceivedQuantity->setGeometry(QRect(460, 130, 113, 31));
        lineEditReceivedQuantity->setReadOnly(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(350, 170, 131, 31));
        label_7->setFont(font);
        lineEditProcessedQuantity = new QLineEdit(centralwidget);
        lineEditProcessedQuantity->setObjectName(QStringLiteral("lineEditProcessedQuantity"));
        lineEditProcessedQuantity->setGeometry(QRect(460, 170, 113, 31));
        lineEditProcessedQuantity->setReadOnly(false);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(350, 210, 131, 31));
        label_9->setFont(font);
        lineEditOperatorName = new QLineEdit(centralwidget);
        lineEditOperatorName->setObjectName(QStringLiteral("lineEditOperatorName"));
        lineEditOperatorName->setGeometry(QRect(460, 210, 113, 31));
        lineEditOperatorName->setReadOnly(false);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 160, 311, 101));
        groupBox_2->setFont(font);
        radioButtonStartTime = new QRadioButton(groupBox_2);
        radioButtonStartTime->setObjectName(QStringLiteral("radioButtonStartTime"));
        radioButtonStartTime->setGeometry(QRect(10, 40, 141, 17));
        radioButtonStartTime->setFont(font);
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 70, 82, 17));
        radioButton_2->setFont(font);
        dateTimeEditEntry = new QDateTimeEdit(groupBox_2);
        dateTimeEditEntry->setObjectName(QStringLiteral("dateTimeEditEntry"));
        dateTimeEditEntry->setGeometry(QRect(140, 30, 161, 51));
        dateTimeEditEntry->setFont(font);
        pushButtonProcess = new QPushButton(centralwidget);
        pushButtonProcess->setObjectName(QStringLiteral("pushButtonProcess"));
        pushButtonProcess->setGeometry(QRect(710, 350, 191, 51));
        pushButtonProcess->setFont(font);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 260, 261, 141));
        radioButtonQuality = new QRadioButton(groupBox_3);
        radioButtonQuality->setObjectName(QStringLiteral("radioButtonQuality"));
        radioButtonQuality->setGeometry(QRect(30, 110, 82, 17));
        radioButtonQuality->setFont(font);
        radioButtonPrePaint = new QRadioButton(groupBox_3);
        radioButtonPrePaint->setObjectName(QStringLiteral("radioButtonPrePaint"));
        radioButtonPrePaint->setGeometry(QRect(30, 20, 141, 17));
        radioButtonPrePaint->setFont(font);
        radioButtonPaintApp = new QRadioButton(groupBox_3);
        radioButtonPaintApp->setObjectName(QStringLiteral("radioButtonPaintApp"));
        radioButtonPaintApp->setGeometry(QRect(30, 50, 211, 17));
        radioButtonPaintApp->setFont(font);
        radioButtonCoating = new QRadioButton(groupBox_3);
        radioButtonCoating->setObjectName(QStringLiteral("radioButtonCoating"));
        radioButtonCoating->setGeometry(QRect(30, 80, 82, 17));
        radioButtonCoating->setFont(font);
        ProductionEntryPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProductionEntryPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 948, 21));
        ProductionEntryPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(ProductionEntryPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ProductionEntryPageCls->setStatusBar(statusbar);

        retranslateUi(ProductionEntryPageCls);

        QMetaObject::connectSlotsByName(ProductionEntryPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *ProductionEntryPageCls)
    {
        ProductionEntryPageCls->setWindowTitle(QApplication::translate("ProductionEntryPageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label_4->setText(QApplication::translate("ProductionEntryPageCls", "\304\260\305\236LEM", nullptr));
        label->setText(QApplication::translate("ProductionEntryPageCls", "BARKOD", nullptr));
        label_2->setText(QApplication::translate("ProductionEntryPageCls", "GKR NO", nullptr));
        label_3->setText(QApplication::translate("ProductionEntryPageCls", "K. E. M\304\260KTAR", nullptr));
        label_8->setText(QApplication::translate("ProductionEntryPageCls", "A\303\207IKLAMALAR", nullptr));
        pushButtonReturn->setText(QApplication::translate("ProductionEntryPageCls", "GER\304\260", nullptr));
        pushButtonSave->setText(QApplication::translate("ProductionEntryPageCls", "KAYDET", nullptr));
        label_7->setText(QApplication::translate("ProductionEntryPageCls", "\304\260\305\236LENEN M\304\260KTAR", nullptr));
        label_9->setText(QApplication::translate("ProductionEntryPageCls", "\303\207ALI\305\236AN ADI", nullptr));
        groupBox_2->setTitle(QApplication::translate("ProductionEntryPageCls", "Zaman Se\303\247imi", nullptr));
        radioButtonStartTime->setText(QApplication::translate("ProductionEntryPageCls", "BA\305\236LANGI\303\207", nullptr));
        radioButton_2->setText(QApplication::translate("ProductionEntryPageCls", "B\304\260T\304\260\305\236", nullptr));
        pushButtonProcess->setText(QApplication::translate("ProductionEntryPageCls", "PROSES \304\260\305\236LE", nullptr));
        groupBox_3->setTitle(QString());
        radioButtonQuality->setText(QApplication::translate("ProductionEntryPageCls", "KAL\304\260TE", nullptr));
        radioButtonPrePaint->setText(QApplication::translate("ProductionEntryPageCls", "BOYA HAZIRLAMA", nullptr));
        radioButtonPaintApp->setText(QApplication::translate("ProductionEntryPageCls", "BOYA UYGULAMA VE K\303\234RLE\305\236ME", nullptr));
        radioButtonCoating->setText(QApplication::translate("ProductionEntryPageCls", "KAPLAMA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductionEntryPageCls: public Ui_ProductionEntryPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTIONENTRYPAGECLS_H
