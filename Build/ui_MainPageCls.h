/********************************************************************************
** Form generated from reading UI file 'MainPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGECLS_H
#define UI_MAINPAGECLS_H

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

class Ui_MainPageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_1;
    QPushButton *pushButtonProduction;
    QFrame *frame;
    QGroupBox *groupBox_3;
    QPushButton *pushButtonSales;
    QFrame *frame_3;
    QGroupBox *groupBox_4;
    QPushButton *pushButtonCustomer;
    QFrame *frame_4;
    QGroupBox *groupBox_2;
    QPushButton *pushButtonSettings;
    QFrame *frame_2;
    QPushButton *pushButtonLogOff;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainPageCls)
    {
        if (MainPageCls->objectName().isEmpty())
            MainPageCls->setObjectName(QStringLiteral("MainPageCls"));
        MainPageCls->resize(964, 634);
        MainPageCls->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 881, 561));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        groupBox_1 = new QGroupBox(groupBox);
        groupBox_1->setObjectName(QStringLiteral("groupBox_1"));
        groupBox_1->setGeometry(QRect(30, 20, 391, 211));
        groupBox_1->setFont(font);
        pushButtonProduction = new QPushButton(groupBox_1);
        pushButtonProduction->setObjectName(QStringLiteral("pushButtonProduction"));
        pushButtonProduction->setGeometry(QRect(20, 20, 171, 171));
        pushButtonProduction->setFont(font);
        frame = new QFrame(groupBox_1);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(200, 20, 171, 171));
        frame->setFont(font);
        frame->setStyleSheet(QStringLiteral("image: url(:/new/prefix1/images/ProductionPage.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(460, 20, 391, 211));
        groupBox_3->setFont(font);
        pushButtonSales = new QPushButton(groupBox_3);
        pushButtonSales->setObjectName(QStringLiteral("pushButtonSales"));
        pushButtonSales->setGeometry(QRect(20, 20, 171, 171));
        pushButtonSales->setFont(font);
        frame_3 = new QFrame(groupBox_3);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(200, 20, 171, 171));
        frame_3->setFont(font);
        frame_3->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/images/sales.jpg);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 250, 391, 211));
        groupBox_4->setFont(font);
        pushButtonCustomer = new QPushButton(groupBox_4);
        pushButtonCustomer->setObjectName(QStringLiteral("pushButtonCustomer"));
        pushButtonCustomer->setGeometry(QRect(20, 20, 171, 171));
        pushButtonCustomer->setFont(font);
        frame_4 = new QFrame(groupBox_4);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(200, 20, 171, 171));
        frame_4->setFont(font);
        frame_4->setStyleSheet(QStringLiteral("image: url(:/new/prefix1/images/users.png);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(460, 250, 391, 211));
        groupBox_2->setFont(font);
        pushButtonSettings = new QPushButton(groupBox_2);
        pushButtonSettings->setObjectName(QStringLiteral("pushButtonSettings"));
        pushButtonSettings->setGeometry(QRect(20, 20, 171, 171));
        pushButtonSettings->setFont(font);
        pushButtonSettings->setStyleSheet(QStringLiteral(""));
        frame_2 = new QFrame(groupBox_2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(200, 20, 171, 171));
        frame_2->setFont(font);
        frame_2->setStyleSheet(QStringLiteral("image: url(:/new/prefix1/images/settingspage.jpg);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        pushButtonLogOff = new QPushButton(groupBox);
        pushButtonLogOff->setObjectName(QStringLiteral("pushButtonLogOff"));
        pushButtonLogOff->setGeometry(QRect(190, 470, 391, 81));
        pushButtonLogOff->setFont(font);
        MainPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 964, 21));
        MainPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(MainPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainPageCls->setStatusBar(statusbar);

        retranslateUi(MainPageCls);

        QMetaObject::connectSlotsByName(MainPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *MainPageCls)
    {
        MainPageCls->setWindowTitle(QApplication::translate("MainPageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        groupBox_1->setTitle(QString());
        pushButtonProduction->setText(QApplication::translate("MainPageCls", "\303\234RET\304\260M B\304\260LG\304\260LER\304\260", nullptr));
        groupBox_3->setTitle(QString());
        pushButtonSales->setText(QApplication::translate("MainPageCls", "SATI\305\236 B\304\260LG\304\260LER\304\260", nullptr));
        groupBox_4->setTitle(QString());
        pushButtonCustomer->setText(QApplication::translate("MainPageCls", "M\303\234\305\236TER\304\260 B\304\260LG\304\260LER\304\260", nullptr));
        groupBox_2->setTitle(QString());
        pushButtonSettings->setText(QApplication::translate("MainPageCls", "AYARLAR", nullptr));
        pushButtonLogOff->setText(QApplication::translate("MainPageCls", "\303\207IKI\305\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPageCls: public Ui_MainPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGECLS_H
