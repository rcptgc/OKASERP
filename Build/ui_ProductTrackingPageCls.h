/********************************************************************************
** Form generated from reading UI file 'ProductTrackingPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTTRACKINGPAGECLS_H
#define UI_PRODUCTTRACKINGPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductTrackingPageCls
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEditSearch;
    QPushButton *pushButtonBack;
    QLabel *labelSearch;
    QPushButton *pushButtonAddOrder;
    QPushButton *pushButtonAssignBarcode;
    QPushButton *pushButtonReportExcel;
    QPushButton *pushButtonEraseSelected;
    QPushButton *pushButtonAddOrderScreen;
    QProgressBar *progressBar;
    QTableView *tableView;
    QPushButton *pushButtonPrev;
    QPushButton *pushButtonNext;
    QLineEdit *lineEditPageNum;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProductTrackingPageCls)
    {
        if (ProductTrackingPageCls->objectName().isEmpty())
            ProductTrackingPageCls->setObjectName(QStringLiteral("ProductTrackingPageCls"));
        ProductTrackingPageCls->resize(1430, 582);
        ProductTrackingPageCls->setStyleSheet(QStringLiteral(""));
        ProductTrackingPageCls->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(ProductTrackingPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lineEditSearch = new QLineEdit(centralwidget);
        lineEditSearch->setObjectName(QStringLiteral("lineEditSearch"));
        lineEditSearch->setGeometry(QRect(1280, 10, 133, 50));
        lineEditSearch->setMinimumSize(QSize(100, 50));
        QFont font;
        font.setPointSize(10);
        lineEditSearch->setFont(font);
        pushButtonBack = new QPushButton(centralwidget);
        pushButtonBack->setObjectName(QStringLiteral("pushButtonBack"));
        pushButtonBack->setGeometry(QRect(10, 490, 111, 50));
        pushButtonBack->setMinimumSize(QSize(0, 50));
        pushButtonBack->setFont(font);
        labelSearch = new QLabel(centralwidget);
        labelSearch->setObjectName(QStringLiteral("labelSearch"));
        labelSearch->setGeometry(QRect(1240, 10, 31, 50));
        labelSearch->setMinimumSize(QSize(0, 50));
        labelSearch->setFont(font);
        pushButtonAddOrder = new QPushButton(centralwidget);
        pushButtonAddOrder->setObjectName(QStringLiteral("pushButtonAddOrder"));
        pushButtonAddOrder->setGeometry(QRect(10, 10, 181, 50));
        pushButtonAddOrder->setMinimumSize(QSize(0, 50));
        pushButtonAddOrder->setFont(font);
        pushButtonAssignBarcode = new QPushButton(centralwidget);
        pushButtonAssignBarcode->setObjectName(QStringLiteral("pushButtonAssignBarcode"));
        pushButtonAssignBarcode->setGeometry(QRect(200, 10, 261, 50));
        pushButtonAssignBarcode->setMinimumSize(QSize(0, 50));
        pushButtonAssignBarcode->setFont(font);
        pushButtonReportExcel = new QPushButton(centralwidget);
        pushButtonReportExcel->setObjectName(QStringLiteral("pushButtonReportExcel"));
        pushButtonReportExcel->setGeometry(QRect(470, 10, 121, 50));
        pushButtonReportExcel->setMinimumSize(QSize(0, 50));
        pushButtonReportExcel->setFont(font);
        pushButtonEraseSelected = new QPushButton(centralwidget);
        pushButtonEraseSelected->setObjectName(QStringLiteral("pushButtonEraseSelected"));
        pushButtonEraseSelected->setGeometry(QRect(770, 10, 220, 50));
        pushButtonEraseSelected->setMinimumSize(QSize(220, 50));
        pushButtonEraseSelected->setFont(font);
        pushButtonAddOrderScreen = new QPushButton(centralwidget);
        pushButtonAddOrderScreen->setObjectName(QStringLiteral("pushButtonAddOrderScreen"));
        pushButtonAddOrderScreen->setGeometry(QRect(600, 10, 161, 50));
        pushButtonAddOrderScreen->setMinimumSize(QSize(0, 50));
        pushButtonAddOrderScreen->setFont(font);
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(160, 492, 221, 41));
        progressBar->setFont(font);
        progressBar->setValue(24);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 70, 1401, 411));
        pushButtonPrev = new QPushButton(centralwidget);
        pushButtonPrev->setObjectName(QStringLiteral("pushButtonPrev"));
        pushButtonPrev->setGeometry(QRect(410, 490, 71, 50));
        pushButtonPrev->setMinimumSize(QSize(0, 50));
        pushButtonPrev->setFont(font);
        pushButtonNext = new QPushButton(centralwidget);
        pushButtonNext->setObjectName(QStringLiteral("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(620, 490, 71, 50));
        pushButtonNext->setMinimumSize(QSize(0, 50));
        pushButtonNext->setFont(font);
        lineEditPageNum = new QLineEdit(centralwidget);
        lineEditPageNum->setObjectName(QStringLiteral("lineEditPageNum"));
        lineEditPageNum->setGeometry(QRect(500, 490, 100, 50));
        lineEditPageNum->setMinimumSize(QSize(100, 50));
        lineEditPageNum->setFont(font);
        lineEditPageNum->setReadOnly(false);
        ProductTrackingPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProductTrackingPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1430, 21));
        ProductTrackingPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(ProductTrackingPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ProductTrackingPageCls->setStatusBar(statusbar);

        retranslateUi(ProductTrackingPageCls);

        QMetaObject::connectSlotsByName(ProductTrackingPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *ProductTrackingPageCls)
    {
        ProductTrackingPageCls->setWindowTitle(QApplication::translate("ProductTrackingPageCls", "MainWindow", nullptr));
        pushButtonBack->setText(QApplication::translate("ProductTrackingPageCls", "GER\304\260", nullptr));
        labelSearch->setText(QApplication::translate("ProductTrackingPageCls", "ARA", nullptr));
        pushButtonAddOrder->setText(QApplication::translate("ProductTrackingPageCls", " DOSYADAN S\304\260PAR\304\260\305\236 EKLE", nullptr));
        pushButtonAssignBarcode->setText(QApplication::translate("ProductTrackingPageCls", "YEN\304\260 S\304\260PAR\304\260\305\236LERE \304\260\305\236 EMR\304\260 VE BARKOD ATA", nullptr));
        pushButtonReportExcel->setText(QApplication::translate("ProductTrackingPageCls", "EXCEL'E RAPORLA", nullptr));
        pushButtonEraseSelected->setText(QApplication::translate("ProductTrackingPageCls", "SE\303\207\304\260LENLER\304\260 S\304\260L", nullptr));
        pushButtonAddOrderScreen->setText(QApplication::translate("ProductTrackingPageCls", "EKRANDAN S\304\260PAR\304\260\305\236 EKLE", nullptr));
        pushButtonPrev->setText(QApplication::translate("ProductTrackingPageCls", "<<", nullptr));
        pushButtonNext->setText(QApplication::translate("ProductTrackingPageCls", ">>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductTrackingPageCls: public Ui_ProductTrackingPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTTRACKINGPAGECLS_H
