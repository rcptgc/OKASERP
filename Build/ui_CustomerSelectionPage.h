/********************************************************************************
** Form generated from reading UI file 'CustomerSelectionPage.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERSELECTIONPAGE_H
#define UI_CUSTOMERSELECTIONPAGE_H

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
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomerSelectionPage
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButtonCustomerName;
    QPushButton *pushButtonReturn;
    QLineEdit *lineEditSearch;
    QLabel *label;
    QPushButton *pushButtonSelectAll;
    QPushButton *pushButtonClearAll;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CustomerSelectionPage)
    {
        if (CustomerSelectionPage->objectName().isEmpty())
            CustomerSelectionPage->setObjectName(QStringLiteral("CustomerSelectionPage"));
        CustomerSelectionPage->resize(320, 490);
        CustomerSelectionPage->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(CustomerSelectionPage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 281, 431));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QStringLiteral(""));
        pushButtonCustomerName = new QPushButton(groupBox);
        pushButtonCustomerName->setObjectName(QStringLiteral("pushButtonCustomerName"));
        pushButtonCustomerName->setGeometry(QRect(10, 290, 261, 71));
        pushButtonCustomerName->setFont(font);
        pushButtonReturn = new QPushButton(groupBox);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(10, 370, 91, 51));
        pushButtonReturn->setFont(font);
        lineEditSearch = new QLineEdit(groupBox);
        lineEditSearch->setObjectName(QStringLiteral("lineEditSearch"));
        lineEditSearch->setGeometry(QRect(110, 9, 121, 31));
        lineEditSearch->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 81, 31));
        label->setFont(font);
        pushButtonSelectAll = new QPushButton(groupBox);
        pushButtonSelectAll->setObjectName(QStringLiteral("pushButtonSelectAll"));
        pushButtonSelectAll->setGeometry(QRect(20, 50, 91, 31));
        pushButtonSelectAll->setFont(font);
        pushButtonClearAll = new QPushButton(groupBox);
        pushButtonClearAll->setObjectName(QStringLiteral("pushButtonClearAll"));
        pushButtonClearAll->setGeometry(QRect(170, 50, 91, 31));
        pushButtonClearAll->setFont(font);
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 90, 256, 192));
        CustomerSelectionPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CustomerSelectionPage);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 21));
        CustomerSelectionPage->setMenuBar(menubar);
        statusbar = new QStatusBar(CustomerSelectionPage);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CustomerSelectionPage->setStatusBar(statusbar);

        retranslateUi(CustomerSelectionPage);

        QMetaObject::connectSlotsByName(CustomerSelectionPage);
    } // setupUi

    void retranslateUi(QMainWindow *CustomerSelectionPage)
    {
        CustomerSelectionPage->setWindowTitle(QApplication::translate("CustomerSelectionPage", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pushButtonCustomerName->setText(QApplication::translate("CustomerSelectionPage", "M\303\234\305\236TER\304\260 SE\303\207\304\260N\304\260Z", nullptr));
        pushButtonReturn->setText(QApplication::translate("CustomerSelectionPage", "GER\304\260", nullptr));
        label->setText(QApplication::translate("CustomerSelectionPage", "M\303\234\305\236TER\304\260 ARA", nullptr));
        pushButtonSelectAll->setText(QApplication::translate("CustomerSelectionPage", "T\303\234M\303\234N\303\234 SE\303\207", nullptr));
        pushButtonClearAll->setText(QApplication::translate("CustomerSelectionPage", "TEM\304\260ZLE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerSelectionPage: public Ui_CustomerSelectionPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERSELECTIONPAGE_H
