#pragma once
#ifndef CUSTOMERCLS_H
#define CUSTOMERCLS_H

#include <QString>
#include <QList>
#include "OrderCls.h"
#include "DatabaseAccessCls.h"
#include <QRegularExpression>

class OrderCls;

enum DateTimeTypeEnum
{
    DateTimeType_DayMonth,
    DateTimeType_MonthDay
};

/*! \class SowNumberClass CustomerCls.h
 *
 *  Docs for MyClassName
 */
class SowNumberClass
{
private:

        /** @brief Holds true for negative values */
        int m_intCountNum;
    /** @brief Holds true for negative values */
        QString m_YearStr;
        /** @brief Holds true for negative values */
        QString m_MonthStr;
        /** @brief Holds true for negative values */
        QString m_DayStr;
        /** @brief Holds true for negative values */
        QString m_CustomerPrefixStr;
        /** @brief Holds true for negative values */
        QString m_CountStr;
public:


    int GetCountNum(void)
    {
        return m_intCountNum;
    }

    void SetCountNum(int a_intCountNum)
    {
        m_intCountNum = a_intCountNum;
        m_CountStr.sprintf("%.2d", m_intCountNum);
    }

    /** @brief Holds true for negative values */
    QString ToString()
    {
        QString l_GkrStr = m_YearStr + m_MonthStr + m_DayStr + m_CustomerPrefixStr + m_CountStr;

        return l_GkrStr;
    }
    /** @brief Holds true for negative values */
    SowNumberClass FromString(QString a_SowStr)
    {
        SowNumberClass * l_Ptr = new SowNumberClass();
        QDate Currdate = QDate::currentDate();
        l_Ptr->m_YearStr = a_SowStr.left(4);
        l_Ptr->m_MonthStr = a_SowStr.mid(4, 2);
        l_Ptr->m_DayStr = a_SowStr.mid(6, 2);
        QDate LastDate = QDate(l_Ptr->m_YearStr.toInt(), l_Ptr->m_MonthStr.toInt(), l_Ptr->m_DayStr.toInt());

        QRegularExpression l_re2("(?<date>\\d+)(?<name>\[a-zA-ZğüşöçİĞÜŞÖÇ]+)(?<number>\\d+)");
        QRegularExpressionMatch l_match2 = l_re2.match(a_SowStr);

        if (Currdate != LastDate)
        {
            l_Ptr->m_YearStr.sprintf("%.2d", Currdate.year());
            l_Ptr->m_MonthStr.sprintf("%.2d", Currdate.month());
            l_Ptr->m_DayStr.sprintf("%.2d", Currdate.day());
            l_Ptr->m_CountStr = "00"; // first == "23"
            l_Ptr->m_intCountNum = 0;
            l_Ptr->m_CustomerPrefixStr = l_match2.captured("name");
        }
        else
        {
            l_Ptr->m_CountStr = l_match2.captured("number"); // first == "23"
            l_Ptr->m_intCountNum = l_Ptr->m_CountStr.toInt();
            l_Ptr->m_CustomerPrefixStr = l_match2.captured("name");
        }

        return *l_Ptr;
    }
};

/*! \class CustomerCls CustomerCls.h
 *
 *  Docs for MyClassName
 */
class CustomerCls
{

public:
/** @brief Holds true for negative values */
    CustomerCls();

    /** @brief Holds true for negative values */
    QList<OrderCls> m_OrderList;
    /** @brief Holds true for negative values */
    QString CalculateNextBarcodeNumber(void);
    /** @brief Holds true for negative values */
    QString CalculateNextGKRNumber(void);
    /** @brief Holds true for negative values */
    void PrintAttributes();

    /** @brief Holds true for negative values */
    bool operator==(const CustomerCls& a_c1)
    {
        if (QString::compare(a_c1.m_CustomerNameStr, this->m_CustomerNameStr) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /** @brief Holds true for negative values */
    SowNumberClass m_SowNumber;
    /** @brief Holds true for negative values */
    QString m_CustomerNameStr;
    /** @brief Holds true for negative values */
    QString m_BarcodePrefixStr;
    /** @brief Holds true for negative values */
    QString m_GKRPrefixStr;
    /** @brief Holds true for negative values */
    bool m_blnIsSoirUsed;
    /** @brief Holds true for negative values */
    DateTimeTypeEnum m_enmDateTimeType;
    /** @brief Holds true for negative values */
    uint32_t m_ulnID;
    /** @brief Holds true for negative values */
    QString m_LastBarcodeNumberStr;
    /** @brief Holds true for negative values */
    QString m_LastGKRNumberStr;

private:

};
#endif // CUSTOMERCLS_H

