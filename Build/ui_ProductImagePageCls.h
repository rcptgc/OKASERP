/********************************************************************************
** Form generated from reading UI file 'ProductImagePageCls.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTIMAGEPAGECLS_H
#define UI_PRODUCTIMAGEPAGECLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductImagePageCls
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButtonReturn;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProductImagePageCls)
    {
        if (ProductImagePageCls->objectName().isEmpty())
            ProductImagePageCls->setObjectName(QStringLiteral("ProductImagePageCls"));
        ProductImagePageCls->resize(868, 679);
        ProductImagePageCls->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(ProductImagePageCls);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 841, 611));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        pushButtonReturn = new QPushButton(groupBox);
        pushButtonReturn->setObjectName(QStringLiteral("pushButtonReturn"));
        pushButtonReturn->setGeometry(QRect(720, 40, 111, 71));
        pushButtonReturn->setFont(font);
        graphicsView = new QGraphicsView(groupBox);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 671, 581));
        graphicsView->setFont(font);
        ProductImagePageCls->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProductImagePageCls);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 868, 21));
        ProductImagePageCls->setMenuBar(menubar);
        statusbar = new QStatusBar(ProductImagePageCls);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ProductImagePageCls->setStatusBar(statusbar);

        retranslateUi(ProductImagePageCls);

        QMetaObject::connectSlotsByName(ProductImagePageCls);
    } // setupUi

    void retranslateUi(QMainWindow *ProductImagePageCls)
    {
        ProductImagePageCls->setWindowTitle(QApplication::translate("ProductImagePageCls", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pushButtonReturn->setText(QApplication::translate("ProductImagePageCls", "GER\304\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductImagePageCls: public Ui_ProductImagePageCls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTIMAGEPAGECLS_H
