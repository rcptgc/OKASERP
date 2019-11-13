/********************************************************************************
** Form generated from reading UI file 'ProductionPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTIONPAGECLS_H
#define UI_PRODUCTIONPAGECLS_H

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

class Ui_ProductionPageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButtonReturn;
    QGroupBox *groupBox_2;
    QPushButton *pushButtonPartTrack;
    QFrame *frame;
    QGroupBox *groupBox_3;
    QPushButton *pushButtonBranding;
    QFrame *frame_2;
    QGroupBox *groupBox_4;
    QPushButton *pushButtonProdEntry;
    QFrame *frame_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProductionPageCls)
    {
        if (ProductionPageCls->objectName().isEmpty())
            ProductionPageCls->setObjectName(QStringLiteral("ProductionPageCls"));
        ProductionPageCls->resize(579, 811);
        ProductionPageCls->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(ProductionPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 541, 741));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QStringLiteral(""));
        pushButtonReturn = new QPushButton(groupBox);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(50, 650, 461, 71));
        pushButtonReturn->setFont(font);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 20, 461, 201));
        groupBox_2->setFont(font);
        pushButtonPartTrack = new QPushButton(groupBox_2);
        pushButtonPartTrack->setObjectName(QStringLiteral("pushButtonPartTrack"));
        pushButtonPartTrack->setGeometry(QRect(10, 20, 181, 161));
        pushButtonPartTrack->setFont(font);
        frame = new QFrame(groupBox_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(200, 20, 241, 161));
        frame->setFont(font);
        frame->setStyleSheet(QStringLiteral("image: url(:/new/prefix1/images/ProductionTrackingPage.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 230, 461, 201));
        groupBox_3->setFont(font);
        pushButtonBranding = new QPushButton(groupBox_3);
        pushButtonBranding->setObjectName(QStringLiteral("pushButtonBranding"));
        pushButtonBranding->setGeometry(QRect(10, 20, 181, 161));
        pushButtonBranding->setFont(font);
        frame_2 = new QFrame(groupBox_3);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(200, 20, 241, 161));
        frame_2->setFont(font);
        frame_2->setStyleSheet(QStringLiteral("image: url(:/new/prefix1/images/stamp.jpg);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(40, 440, 461, 201));
        groupBox_4->setFont(font);
        pushButtonProdEntry = new QPushButton(groupBox_4);
        pushButtonProdEntry->setObjectName(QStringLiteral("pushButtonProdEntry"));
        pushButtonProdEntry->setGeometry(QRect(10, 20, 181, 161));
        pushButtonProdEntry->setFont(font);
        frame_3 = new QFrame(groupBox_4);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(200, 20, 241, 161));
        frame_3->setFont(font);
        frame_3->setStyleSheet(QStringLiteral("image: url(:/new/prefix1/images/productionEntryPage.jpg);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        ProductionPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProductionPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 579, 21));
        ProductionPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(ProductionPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ProductionPageCls->setStatusBar(statusbar);

        retranslateUi(ProductionPageCls);

        QMetaObject::connectSlotsByName(ProductionPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *ProductionPageCls)
    {
        ProductionPageCls->setWindowTitle(QApplication::translate("ProductionPageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pushButtonReturn->setText(QApplication::translate("ProductionPageCls", "GER\304\260", nullptr));
        groupBox_2->setTitle(QString());
        pushButtonPartTrack->setText(QApplication::translate("ProductionPageCls", "M\303\234\305\236TER\304\260 PAR\303\207A TAK\304\260P", nullptr));
        groupBox_3->setTitle(QString());
        pushButtonBranding->setText(QApplication::translate("ProductionPageCls", "\303\234R\303\234N G\303\226R\303\234NT\303\234LE", nullptr));
        groupBox_4->setTitle(QString());
        pushButtonProdEntry->setText(QApplication::translate("ProductionPageCls", "\303\234RET\304\260M G\304\260R\304\260\305\236\304\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductionPageCls: public Ui_ProductionPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTIONPAGECLS_H
