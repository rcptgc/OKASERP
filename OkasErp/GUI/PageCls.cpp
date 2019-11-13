#include "PageCls.h"
#include "LoginPageCls.h"
#include "MainPageCls.h"
#include "PasswordReminderPageCls.h"
#include "SalesInformationSelectionPageCls.h"
#include "ProductionPageCls.h"
#include "CustomerProfilePageCls.h"
#include "SettingsPageCls.h"
#include "ProductImagePageCls.h"
#include "ProductTrackingPageCls.h"
#include "BrandingPageCls.h"
#include "SalesEntryPageCls.h"
#include "CustomerSelectionPageCls.h"
#include "CreateOrderPageCls.h"
#include "SalesReportPageCls.h"
#include "NewUserPageCls.h"
#include "EditUserPageCls.h"
#include "ProductionEntryPageCls.h"
#include "OrderLogPageCls.h"
#include "CoatingProcessViewPageCls.h"
#include "QualityProcessViewPageCls.h"
#include "PrePaintProcessViewCls.h"
#include "EditLoadPageCls.h"
#include "CreateNewLoadPage.h"
#include "CustomerEditPageCls.h"

UserStc * PageCls::m_UserPtr = nullptr;
LoggerCls * PageCls::m_LoggerPtr = nullptr;
OrderCls PageCls::m_SelectedOrder;
QStringList PageCls::m_CustNameList;
ProcessSelectionEnum PageCls::m_enmProcessSelection;

PageCls::PageCls()
{
    static bool s_blnIsFirst = true;

    if (true == s_blnIsFirst)
    {
        s_blnIsFirst = false;
    }
}

void PageCls::LoadPage(PageSelectionEnum a_enmPageSelection, QString a_CustomerNameStr, QString a_BarcodeNumberStr)
{

    switch (a_enmPageSelection)
    {
        case PageSelection_LoginPage :
        {
            LoginPageCls * l_LoginPagePtr = new LoginPageCls();
            l_LoginPagePtr->show();
            break;
        }

        case PageSelection_MainPage:
        {
            MainPageCls * l_MainPagePtr = new MainPageCls();
            l_MainPagePtr->show();
            break;
        }

        case PageSelection_PasswordReminderPage:
        {
            PasswordReminderPageCls * l_PasswordReminderPagePtr = new PasswordReminderPageCls();
            l_PasswordReminderPagePtr->show();
            break;
        }

        case PageSelection_SalesInformationPage :
        {
            SalesInformationSelectionPageCls * l_SalesInfoPagePtr = new SalesInformationSelectionPageCls();
            l_SalesInfoPagePtr->show();
            break;
        }

        case PageSelection_ProductionPage :
        {
            ProductionPageCls * l_ProductionPagePtr = new ProductionPageCls();
            l_ProductionPagePtr->show();
            break;
        }

        case PageSelection_NewCustomerPage :
        {
            CustomerProfilePageCls * l_CustomerProfilePagePtr = new CustomerProfilePageCls();
            l_CustomerProfilePagePtr->show();
            break;
        }

        case PageSelection_SettingsPage :
        {
            SettingsPageCls * l_SettingsPagePtr = new SettingsPageCls();
            l_SettingsPagePtr->show();
            break;
        }

        case PageSelection_ProductImagePage :
        {
            ProductImagePageCls * l_ProductImagePagePtr = new ProductImagePageCls(nullptr, a_BarcodeNumberStr);
            l_ProductImagePagePtr->show();
            break;
        }

        case PageSelection_ProductTrackingPage :
        {
            ProductTrackingPageCls * l_ProductTrackingPagePtr = new ProductTrackingPageCls();
            l_ProductTrackingPagePtr->show();
            break;
        }

        case PageSelection_BrandingPage :
        {
            BrandingPageCls * l_BrandingPageObjectPtr = new BrandingPageCls(a_BarcodeNumberStr);
            l_BrandingPageObjectPtr->show();
            break;
        }

        case PageSelection_SalesEntryPage :
        {
            SalesEntryPageCls * l_SalesEntryPageObjectPtr = new SalesEntryPageCls();
            l_SalesEntryPageObjectPtr->show();
            break;
        }

        case PageSelection_CustomerSelectionPage :
        {
            CustomerSelectionPageCls * l_CustomerPagePtr = new CustomerSelectionPageCls();
            l_CustomerPagePtr->show();
            break;
        }

        case PageSelection_CreateOrderPage :
        {
            CreateOrderPageCls * l_NewOrderPagePtr = new CreateOrderPageCls(a_CustomerNameStr);
            l_NewOrderPagePtr->show();
            break;
        }

        case PageSelection_SalesReportPage :
        {
            SalesReportPageCls * l_SalesReportingPagePtr = new SalesReportPageCls();
            l_SalesReportingPagePtr->show();
            break;
        }

        case PageSelection_NewUserPage :
        {
            NewUserPageCls * l_NewUserPagePtr = new NewUserPageCls();
            l_NewUserPagePtr->show();
            break;
        }

        case PageSelection_EditUserPage :
        {
            EditUserPageCls * l_EditUserPagePtr = new EditUserPageCls();
            l_EditUserPagePtr->show();
            break;
        }

        case PageSelection_ProductionEntryPage :
        {
            ProductionEntryPageCls * l_ProductionEntryPagePtr = new ProductionEntryPageCls();
            l_ProductionEntryPagePtr->show();
            break;
        }

        case PageSelection_OrderLogPage :
        {
            OrderLogPageCls * l_OrderLogPagePtr = new OrderLogPageCls();
            l_OrderLogPagePtr->show();
            break;
        }

        case PageSelection_ProcessViewCoatingPage :
        {
            CoatingProcessViewPageCls * l_ProcessViewPagePtr = new CoatingProcessViewPageCls();
            l_ProcessViewPagePtr->show();
            break;
        }

        case PageSalection_ProcessViewPrePaintPage :
        {
            PrePaintProcessViewCls * l_PrePaintProcViewPagePtr = new PrePaintProcessViewCls();
            l_PrePaintProcViewPagePtr->show();
            break;
        }

        case PageSelection_ProcessViewQualityPage :
        {
            QualityProcessViewPageCls * l_QualProcViewPagePtr = new QualityProcessViewPageCls();
            l_QualProcViewPagePtr->show();
            break;
        }

        case PageSelection_EditLoadPage :
        {
            EditLoadPageCls * l_EditLoadPagePtr = new EditLoadPageCls();
            l_EditLoadPagePtr->show();
            break;
        }

        case PageSelection_CreateLoadPage :
        {
            CreateNewLoadPage * l_CreateNewLoadPagePtr = new CreateNewLoadPage();
            l_CreateNewLoadPagePtr->show();
            break;
        }

        case PageSelection_CustomerEditPage :
        {
            CustomerEditPageCls * l_CustomerEditPagePtr = new CustomerEditPageCls();
            l_CustomerEditPagePtr->show();
            break;
        }
    }
}
