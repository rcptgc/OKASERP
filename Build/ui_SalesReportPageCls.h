/********************************************************************************
** Form generated from reading UI file 'SalesReportPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALESREPORTPAGECLS_H
#define UI_SALESREPORTPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "CheckTableWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SalesReportPageCls
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QDateEdit *dateEditStartDate;
    CheckTableWidget *tableWidget;
    QPushButton *pushButtonReturn;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditCustomerName;
    QLabel *label_3;
    QDateEdit *dateEditEndDate;
    QPushButton *pushButtonShowSelected;
    QPushButton *pushButtonSelectedReport;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SalesReportPageCls)
    {
        if (SalesReportPageCls->objectName().isEmpty())
            SalesReportPageCls->setObjectName(QStringLiteral("SalesReportPageCls"));
        SalesReportPageCls->resize(944, 568);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SalesReportPageCls->sizePolicy().hasHeightForWidth());
        SalesReportPageCls->setSizePolicy(sizePolicy);
        SalesReportPageCls->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(SalesReportPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dateEditStartDate = new QDateEdit(centralwidget);
        dateEditStartDate->setObjectName(QStringLiteral("dateEditStartDate"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dateEditStartDate->sizePolicy().hasHeightForWidth());
        dateEditStartDate->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(10);
        dateEditStartDate->setFont(font);

        gridLayout->addWidget(dateEditStartDate, 3, 1, 1, 1);

        tableWidget = new CheckTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setFont(font);

        gridLayout->addWidget(tableWidget, 6, 0, 1, 11);

        pushButtonReturn = new QPushButton(centralwidget);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setFont(font);

        gridLayout->addWidget(pushButtonReturn, 7, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        lineEditCustomerName = new QLineEdit(centralwidget);
        lineEditCustomerName->setObjectName(QStringLiteral("lineEditCustomerName"));
        sizePolicy1.setHeightForWidth(lineEditCustomerName->sizePolicy().hasHeightForWidth());
        lineEditCustomerName->setSizePolicy(sizePolicy1);
        lineEditCustomerName->setFont(font);

        gridLayout->addWidget(lineEditCustomerName, 0, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 2, 1, 1);

        dateEditEndDate = new QDateEdit(centralwidget);
        dateEditEndDate->setObjectName(QStringLiteral("dateEditEndDate"));
        sizePolicy1.setHeightForWidth(dateEditEndDate->sizePolicy().hasHeightForWidth());
        dateEditEndDate->setSizePolicy(sizePolicy1);
        dateEditEndDate->setFont(font);

        gridLayout->addWidget(dateEditEndDate, 3, 3, 1, 1);

        pushButtonShowSelected = new QPushButton(centralwidget);
        pushButtonShowSelected->setObjectName(QStringLiteral("pushButtonShowSelected"));
        sizePolicy1.setHeightForWidth(pushButtonShowSelected->sizePolicy().hasHeightForWidth());
        pushButtonShowSelected->setSizePolicy(sizePolicy1);
        pushButtonShowSelected->setFont(font);

        gridLayout->addWidget(pushButtonShowSelected, 0, 2, 1, 1);

        pushButtonSelectedReport = new QPushButton(centralwidget);
        pushButtonSelectedReport->setObjectName(QStringLiteral("pushButtonSelectedReport"));
        sizePolicy1.setHeightForWidth(pushButtonSelectedReport->sizePolicy().hasHeightForWidth());
        pushButtonSelectedReport->setSizePolicy(sizePolicy1);
        pushButtonSelectedReport->setFont(font);

        gridLayout->addWidget(pushButtonSelectedReport, 0, 3, 1, 1);

        SalesReportPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SalesReportPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 944, 21));
        SalesReportPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(SalesReportPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SalesReportPageCls->setStatusBar(statusbar);

        retranslateUi(SalesReportPageCls);

        QMetaObject::connectSlotsByName(SalesReportPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *SalesReportPageCls)
    {
        SalesReportPageCls->setWindowTitle(QApplication::translate("SalesReportPageCls", "MainWindow", nullptr));
        pushButtonReturn->setText(QApplication::translate("SalesReportPageCls", "GER\304\260", nullptr));
        label->setText(QApplication::translate("SalesReportPageCls", "M\303\234\305\236TER\304\260 ADI", nullptr));
        label_2->setText(QApplication::translate("SalesReportPageCls", "BA\305\236LANGI\303\207 TAR\304\260H\304\260", nullptr));
        label_3->setText(QApplication::translate("SalesReportPageCls", "B\304\260T\304\260\305\236 TAR\304\260H\304\260", nullptr));
        pushButtonShowSelected->setText(QApplication::translate("SalesReportPageCls", "G\303\226STER", nullptr));
        pushButtonSelectedReport->setText(QApplication::translate("SalesReportPageCls", "EXCEL'E RAPORLA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SalesReportPageCls: public Ui_SalesReportPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALESREPORTPAGECLS_H
