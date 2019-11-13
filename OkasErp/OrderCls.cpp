#include "OrderCls.h"
#include <QDebug>

OrderCls::OrderCls()
{

}

void OrderCls::PrintAttributes()
{
    qDebug() << "Order Attributes";
    qDebug() << "ID = "                     << m_ulnID;
    qDebug() << "Entry Date = "             << m_EntryDateStr;
    qDebug() << "Project Name = "           << m_ProjectStr;
    qDebug() << "Product Number = "         << m_PartNumStr;
    qDebug() << "PO Number = "              << m_PONumStr;
    qDebug() << "Received Quantity = "      << m_ulnRcvdQty;
    qDebug() << "Accepted Quantity = "      << m_ulnAcptdQty;
    qDebug() << "Rejected Quantity = "      << m_ulnRejctdQty;
    qDebug() << "Internal Sow Number = "    << m_GKRNumStr;
    qDebug() << "Barcode Number = "         << m_BarcodeNumStr;
    qDebug() << "Urgency = "                << m_UrgencyStr;
    qDebug() << "Brand Date = "             << m_BrandDateStr;
    qDebug() << "Soir = "                   << m_SoirStr;
    qDebug() << "Sale Date = "              << m_SaleDateStr;
    qDebug() << "Cost = "                   << m_CostStr;
    qDebug() << "Dispatch No = "            << m_DispatchStr;
    qDebug() << "Customer Name = "          << m_CustNameStr;

}


