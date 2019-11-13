/********************************************************************************
** Form generated from reading UI file 'SalesInformationSelectionPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALESINFORMATIONSELECTIONPAGECLS_H
#define UI_SALESINFORMATIONSELECTIONPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SalesInformationSelectionPageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_4;
    QPushButton *pushButtonSalesReport;
    QFrame *frame;
    QGroupBox *groupBox_3;
    QPushButton *pushButtonSalesEntry;
    QFrame *frame_3;
    QPushButton *pushButtonReturn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SalesInformationSelectionPageCls)
    {
        if (SalesInformationSelectionPageCls->objectName().isEmpty())
            SalesInformationSelectionPageCls->setObjectName(QStringLiteral("SalesInformationSelectionPageCls"));
        SalesInformationSelectionPageCls->resize(511, 714);
        SalesInformationSelectionPageCls->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(SalesInformationSelectionPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 10, 421, 651));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 40, 391, 181));
        groupBox_4->setFont(font);
        pushButtonSalesReport = new QPushButton(groupBox_4);
        pushButtonSalesReport->setObjectName(QStringLiteral("pushButtonSalesReport"));
        pushButtonSalesReport->setGeometry(QRect(20, 30, 151, 121));
        pushButtonSalesReport->setFont(font);
        frame = new QFrame(groupBox_4);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(210, 30, 151, 111));
        frame->setFont(font);
        frame->setStyleSheet(QStringLiteral("image: url(:/new/prefix1/images/report.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 280, 391, 181));
        groupBox_3->setFont(font);
        pushButtonSalesEntry = new QPushButton(groupBox_3);
        pushButtonSalesEntry->setObjectName(QStringLiteral("pushButtonSalesEntry"));
        pushButtonSalesEntry->setGeometry(QRect(20, 30, 151, 121));
        pushButtonSalesEntry->setFont(font);
        frame_3 = new QFrame(groupBox_3);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(210, 30, 151, 111));
        frame_3->setFont(font);
        frame_3->setStyleSheet(QStringLiteral("image: url(:/new/prefix1/images/SalesEntryPage.png);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        pushButtonReturn = new QPushButton(groupBox);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(10, 580, 391, 51));
        pushButtonReturn->setFont(font);
        SalesInformationSelectionPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SalesInformationSelectionPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 511, 21));
        SalesInformationSelectionPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(SalesInformationSelectionPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SalesInformationSelectionPageCls->setStatusBar(statusbar);

        retranslateUi(SalesInformationSelectionPageCls);

        QMetaObject::connectSlotsByName(SalesInformationSelectionPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *SalesInformationSelectionPageCls)
    {
        SalesInformationSelectionPageCls->setWindowTitle(QApplication::translate("SalesInformationSelectionPageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        groupBox_4->setTitle(QString());
        pushButtonSalesReport->setText(QApplication::translate("SalesInformationSelectionPageCls", "SATI\305\236 RAPORU", nullptr));
        groupBox_3->setTitle(QString());
        pushButtonSalesEntry->setText(QApplication::translate("SalesInformationSelectionPageCls", "SATI\305\236 B\304\260LG\304\260LER\304\260 G\304\260R\304\260\305\236\304\260", nullptr));
        pushButtonReturn->setText(QApplication::translate("SalesInformationSelectionPageCls", "GER\304\260 D\303\226N", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SalesInformationSelectionPageCls: public Ui_SalesInformationSelectionPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALESINFORMATIONSELECTIONPAGECLS_H
