#ifndef PAGECLS_H
#define PAGECLS_H

#include "DatabaseAccessCls.h"
#include "Utility/LoggerCls.h"
#include "UserCls.h"
#include "OrderCls.h"
#include <QStringList>
enum PageSelectionEnum
{
    PageSelection_LoginPage,
    PageSelection_MainPage,
    PageSelection_PasswordReminderPage,
    PageSelection_ProductionPage,
    PageSelection_SettingsPage,
    PageSelection_SalesInformationPage,
    PageSelection_NewCustomerPage,
    PageSelection_CustomerEditPage,
    PageSelection_ProductImagePage,
    PageSelection_ProductTrackingPage,
    PageSelection_BrandingPage,
    PageSelection_SalesEntryPage,
    PageSelection_CustomerSelectionPage,
    PageSelection_CreateOrderPage,
    PageSelection_SalesReportPage,
    PageSelection_NewUserPage,
    PageSelection_EditUserPage,
    PageSelection_ProductionEntryPage,
    PageSelection_OrderLogPage,
    PageSelection_ProcessViewCoatingPage,
    PageSalection_ProcessViewPrePaintPage,
    PageSelection_ProcessViewPaintAppPage,
    PageSelection_ProcessViewQualityPage,
    PageSelection_CreateLoadPage,
    PageSelection_EditLoadPage
};

enum ProcessSelectionEnum
{
    ProcessSelection_Coating,
    ProcessSelection_PrePaint,
    ProcessSelection_Quality,
    ProcessSelection_PaintApp
};

class PageCls
{
public:

    PageCls();
    /** @brief Holds true for negative values */
    static UserStc * m_UserPtr;
    /** @brief Holds true for negative values */
    static LoggerCls * m_LoggerPtr;

    static void SetUser(UserStc * a_UserPtr)
    {
        m_UserPtr = a_UserPtr;
    }

    static void SetLogger(LoggerCls * a_LoggerPtr)
    {
        m_LoggerPtr = a_LoggerPtr;
    }

    void LoadPage(PageSelectionEnum a_enmPageSelection, QString a_CustomerNameStr = QString(), QString a_BarcodeNumberStr = QString());
    static QStringList m_CustNameList;
    /** @brief Holds true for negative values */
    static OrderCls m_SelectedOrder;
    static ProcessSelectionEnum m_enmProcessSelection;

protected:
/** @brief Holds true for negative values */
    DatabaseAccessCls * m_DatabasePtr;

    QString m_ImagesPathStr;


};

#endif // PAGECLS_H
