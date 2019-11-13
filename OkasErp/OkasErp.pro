#-------------------------------------------------
#
# Project created by QtCreator 2017-11-04T22:37:37
#
#-------------------------------------------------

QT       += core gui network sql axcontainer printsupport
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OkasErp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    GUI\CustomerSelectionPageCls.cpp \
    GUI\ProductTrackingPageCls.cpp \
    GUI\CustomerProfilePageCls.cpp \
    GUI\LoginPageCls.cpp \
    GUI\BrandingPageCls.cpp \
    GUI\ProductImagePageCls.cpp \
    GUI\SalesInformationSelectionPageCls.cpp \
    GUI\SalesEntryPageCls.cpp \
    GUI\SalesReportPageCls.cpp \
    GUI\NewUserPageCls.cpp \
    GUI\EditUserPageCls.cpp \
    GUI\ProductionPageCls.cpp \
    GUI\MainPageCls.cpp \
    GUI\SettingsPageCls.cpp \
    Utility\LoggerCls.cpp \
    Utility\ExcelHandlerCls.cpp \
    OrderCls.cpp \
    DataBaseCls.cpp \
    DatabaseAccessCls.cpp \
    GUI/PasswordReminderPageCls.cpp \
    GUI/CreateOrderPageCls.cpp \
    CheckTableWidget.cpp \
    Utility/ExcellOrderCls.cpp \
    GUI/PageCls.cpp \
    GUI/OrderLogPageCls.cpp \
    GUI/ProductionEntryPageCls.cpp \
    Utility/UtilsCls.cpp \
    Utility/smtp.cpp \
    TankCls.cpp \
    GUI/EditLoadPageCls.cpp \
    GUI/CreateNewLoadPage.cpp \
    GUI/CoatingProcessViewPageCls.cpp \
    GUI/QualityProcessViewPageCls.cpp \
    GUI/PrePaintProcessViewCls.cpp \
    RModel.cpp \
    CustomerCls.cpp \
    RelationalModelodel.cpp \
    GUI/CreateCoatFinishCls.cpp \
    GUI/CustomerEditPageCls.cpp \
    TableModelCls.cpp

HEADERS += \
    GUI\CustomerSelectionPageCls.h \
    GUI\ProductTrackingPageCls.h \
    GUI\CustomerProfilePageCls.h \
    GUI\LoginPageCls.h \
    GUI\BrandingPageCls.h \
    GUI\ProductImagePageCls.h \
    GUI\SalesInformationSelectionPageCls.h \
    GUI\SalesEntryPageCls.h \
    GUI\SalesReportPageCls.h \
    GUI\NewUserPageCls.h \
    GUI\EditUserPageCls.h \
    GUI\ProductionPageCls.h \
    GUI\MainPageCls.h \
    GUI\SettingsPageCls.h \
    Utility\LoggerCls.h \
    Utility\ExcelHandlerCls.h \
    OrderCls.h \
    CustomerCls.h \
    DataBaseCls.h \
    UserCls.h \
    DatabaseAccessCls.h \
    GUI/PasswordReminderPageCls.h \
    GUI/CreateOrderPageCls.h \
    CheckTableWidget.h \
    Utility/ExcellOrderCls.h \
    Utility/smtp.h \
    GUI/PageCls.h \
    GUI/OrderLogPageCls.h \
    OrderLogCls.h \
    GUI/ProductionEntryPageCls.h \
    Utility/UtilsCls.h \
    LoadCls.h \
    FinishCls.h \
    TankCls.h \
    GUI/EditLoadPageCls.h \
    GUI/CreateNewLoadPage.h \
    GUI/CoatingProcessViewPageCls.h \
    GUI/QualityProcessViewPageCls.h \
    GUI/PrePaintProcessViewCls.h \
    PaintLogCls.h \
    QualityLogCls.h \
    RModel.h \
    RelationalModel.h \
    GUI/CreateCoatFinishCls.h \
    GUI/CustomerEditPageCls.h \
    TableModelCls.h


FORMS += \
    CustomerSelectionPage.ui \
    ProductTrackingPageCls.ui \
    CustomerProfilePageCls.ui \
    LoginPageCls.ui \
    BrandingPageCls.ui \
    ProductImagePageCls.ui \
    SalesInformationSelectionPageCls.ui \
    SalesEntryPageCls.ui \
    SalesReportPageCls.ui \
    NewUserPageCls.ui \
    EditUserPageCls.ui \
    ProductionPageCls.ui \
    MainPageCls.ui \
    SettingsPageCls.ui \
    PasswordReminderPageCls.ui \
    CreateOrderPageCls.ui \
    OrderLogPageCls.ui \
    ProductionEntryPageCls.ui \
    EditLoadPageCls.ui \
    CreateNewLoadPage.ui \
    CoatingProcessViewPageCls.ui \
    QualityProcessViewPageCls.ui \
    PrePaintProcessViewCls.ui \
    CreateCoatFinishCls.ui \
    CustomerEditPageCls.ui

CONFIG += mobility
MOBILITY =

RESOURCES += \
    images.qrc

# Location of SMTP Library
# SMTP_LIBRARY_LOCATION = $$PWD/../Build/release

# LIBS += -L$$SMTP_LIBRARY_LOCATION -libeay32
# LIBS += -L$$SMTP_LIBRARY_LOCATION -libssl32
# LIBS += -L$$SMTP_LIBRARY_LOCATION -ssleay32

# INCLUDEPATH += $$SMTP_LIBRARY_LOCATION
# DEPENDPATH += $$SMTP_LIBRARY_LOCATION
