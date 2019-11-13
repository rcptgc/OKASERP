/********************************************************************************
** Form generated from reading UI file 'EditUserPageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITUSERPAGECLS_H
#define UI_EDITUSERPAGECLS_H

#include <CheckTableWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditUserPageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonReturn;
    UserTableWidget *tableWidget;
    QPushButton *pushButtonErase;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EditUserPageCls)
    {
        if (EditUserPageCls->objectName().isEmpty())
            EditUserPageCls->setObjectName(QStringLiteral("EditUserPageCls"));
        EditUserPageCls->resize(800, 600);
        EditUserPageCls->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(EditUserPageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 781, 451));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        pushButtonSave = new QPushButton(groupBox);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(280, 390, 191, 51));
        pushButtonSave->setFont(font);
        pushButtonReturn = new QPushButton(groupBox);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(10, 390, 191, 51));
        pushButtonReturn->setFont(font);
        tableWidget = new UserTableWidget(groupBox);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 771, 381));
        tableWidget->setFont(font);
        pushButtonErase = new QPushButton(groupBox);
        pushButtonErase->setObjectName(QStringLiteral("pushButtonErase"));
        pushButtonErase->setGeometry(QRect(520, 390, 191, 51));
        pushButtonErase->setFont(font);
        EditUserPageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EditUserPageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        EditUserPageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(EditUserPageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        EditUserPageCls->setStatusBar(statusbar);

        retranslateUi(EditUserPageCls);

        QMetaObject::connectSlotsByName(EditUserPageCls);
    } // setupUi

    void retranslateUi(QMainWindow *EditUserPageCls)
    {
        EditUserPageCls->setWindowTitle(QApplication::translate("EditUserPageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pushButtonSave->setText(QApplication::translate("EditUserPageCls", "KAYDET", nullptr));
        pushButtonReturn->setText(QApplication::translate("EditUserPageCls", "GER\304\260", nullptr));
        pushButtonErase->setText(QApplication::translate("EditUserPageCls", "SE\303\207\304\260LENLER\304\260 S\304\260L", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditUserPageCls: public Ui_EditUserPageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITUSERPAGECLS_H
