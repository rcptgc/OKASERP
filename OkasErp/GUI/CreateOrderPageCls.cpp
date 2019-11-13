#include "CreateOrderPageCls.h"
#include "ui_CreateOrderPageCls.h"
#include <OrderCls.h>
#include "Utility/UtilsCls.h"

CreateOrderPageCls::CreateOrderPageCls(QString a_CustNameStr, QWidget * a_ParentPtr) : QMainWindow(a_ParentPtr), ui(new Ui::CreateOrderPageCls)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    ui->setupUi(this);
    connect(ui->pushButtonReturn, SIGNAL(clicked()), this, SLOT(LoadProductTrackingPage()));
    connect(ui->pushButtonSave,   SIGNAL(clicked()), this, SLOT(AddOrderToDatabase()));
    m_SelectedCustomerStr = a_CustNameStr;
    ui->dateEdit->setDate(QDate::currentDate());
}

void CreateOrderPageCls::LoadProductTrackingPage(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    LoadPage(PageSelection_ProductTrackingPage);
    delete this;
}

void CreateOrderPageCls::AddOrderToDatabase(void)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    OrderCls l_NewOrder;

    if ( (ui->lineEditProjectName->text().isEmpty() == false) &&
         (ui->lineEditPartNumber->text().isEmpty() == false) &&
         (ui->lineEditPoNumber->text().isEmpty() == false) &&
         (ui->lineEditSowNumber->text().isEmpty() == false) &&
         (ui->lineEditReceiveQuantity->text().isEmpty() == false) &&
         (ui->lineEditAcceptedQuantity->text().isEmpty() == false) &&
         (ui->lineEditRejectedQuantity->text().isEmpty() == false) &&
         (ui->lineEditUrgency->text().isEmpty() == false) &&
         (ui->lineEditSoir->text().isEmpty() == false) &&
         (ui->lineEditDispatchNo->text().isEmpty() == false) )
    {

        l_NewOrder.m_EntryDateStr   = UtilsCls::GetDateString(ui->dateEdit->date());
        l_NewOrder.m_ProjectStr     = ui->lineEditProjectName->text();
        l_NewOrder.m_CustNameStr    = m_SelectedCustomerStr;
        l_NewOrder.m_PONumStr       = ui->lineEditPoNumber->text();
        l_NewOrder.m_PartNumStr     = ui->lineEditPartNumber->text();
        l_NewOrder.m_SoirStr        = ui->lineEditSoir->text();
        l_NewOrder.m_SOWNumStr      = ui->lineEditSowNumber->text();
        l_NewOrder.m_ulnAcptdQty    = ui->lineEditAcceptedQuantity->text().toUInt();
        l_NewOrder.m_ulnRcvdQty     = ui->lineEditReceiveQuantity->text().toUInt();
        l_NewOrder.m_ulnRejctdQty   = ui->lineEditRejectedQuantity->text().toUInt();
        l_NewOrder.m_UrgencyStr     = ui->lineEditUrgency->text();
        l_NewOrder.m_DispatchStr    = ui->lineEditDispatchNo->text();

        m_DatabasePtr->AddOrder(l_NewOrder);
    }
}

CreateOrderPageCls::~CreateOrderPageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    delete ui;
}
