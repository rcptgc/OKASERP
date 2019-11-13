#pragma once
#ifndef M_ORDERLOGCLS_H
#define M_ORDERLOGCLS_H

#include <QDate>
#include <QTime>
#include "CustomerCls.h"

class CustomerCls;

typedef struct
{
    uint32_t m_ulnID;
    QString m_NameStr;
    QString m_GroupName;

} OperationStc;



typedef enum
{
    LogDateType_Start,
    LogDateType_Finish
} LogDateTypeEnum;



typedef struct
{
    QMap<uint32_t, QString> m_OperationMap;


    OperationStc m_Operation;
    QDate m_Date;
    QTime m_Time;
    LogDateTypeEnum m_enmDateType;
    uint32_t m_ulnReceivedQuantity;
    uint32_t m_ulnProcessedQuantity;

    uint32_t m_ulnOrderID;
    QString m_OperatorNameStr;
    QString m_NotesStr;
    int32_t m_intOrderLogID;

} OrderLogStc;
#endif // M_ORDERLOGCLS_H
