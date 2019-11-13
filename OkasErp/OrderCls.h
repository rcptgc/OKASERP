#pragma once

#ifndef ORDERCLS_H
#define ORDERCLS_H

#include <QString>
#include <QDate>
#include <QSharedPointer>
#include "CustomerCls.h"



class CustomerCls;

/*! \class OrderCls OrderCls.h
 *
 *  Docs for MyClassName
 */
class OrderCls
{
private:

    public:
/** @brief Holds true for negative values */
        OrderCls();
        /** @brief Holds true for negative values */
        void PrintAttributes();

        /** @brief Holds true for negative values */
        uint32_t m_ulnID;
        /** @brief Holds true for negative values */
        QString m_CustNameStr;
        /** @brief Holds true for negative values */
        QString m_EntryDateStr;
        /** @brief Holds true for negative values */
        QString m_ProjectStr;
        /** @brief Holds true for negative values */
        QString m_PartNumStr;
        /** @brief Holds true for negative values */
        QString m_PONumStr;
        /** @brief Holds true for negative values */
        QString m_SOWNumStr;
        /** @brief Holds true for negative values */
        uint32_t m_ulnRcvdQty;
        /** @brief Holds true for negative values */
        uint32_t m_ulnAcptdQty;
        /** @brief Holds true for negative values */
        uint32_t m_ulnRejctdQty;
        /** @brief Holds true for negative values */
        QString m_GKRNumStr;
        /** @brief Holds true for negative values */
        QString m_BarcodeNumStr;
        /** @brief Holds true for negative values */
        QString m_UrgencyStr;
        /** @brief Holds true for negative values */
        QString m_BrandDateStr;
        /** @brief Holds true for negative values */
        QString m_SoirStr;
        /** @brief Holds true for negative values */
        QString m_SaleDateStr;
        /** @brief Holds true for negative values */
        QString m_CostStr;
        /** @brief Holds true for negative values */
        QString m_DispatchStr;
};
/*
inline bool operator<(const OrderCls &a_c1,  const OrderCls &a_c2)
{
    uint32_t l_ulnID1 = a_c1.GetID();
    uint32_t l_ulnID2 = a_c2.GetID();
    return (l_ulnID1 < l_ulnID2);
}
*/

inline bool operator<(const OrderCls &a_c1,  const OrderCls &a_c2)
{
    uint32_t l_ulnID1 = a_c1.m_ulnID;
    uint32_t l_ulnID2 = a_c2.m_ulnID;
    return (l_ulnID1 < l_ulnID2);
}

#endif // ORDERCLS_H
