#ifndef TANKCLS_H
#define TANKCLS_H

#include <QString>


class TankCls
{
public:

    TankCls();

    uint32_t m_ulnID;
    QString m_ulnFinishIDStr;
    QString m_LoadIDStr;
    QString m_TankNoStr;
    QString m_TankNameStr;
    QString m_TimeMinRangeStr;
    QString m_TimeMinResultStr;
    QString m_TemperatureRangeStr;
    QString m_TemperatureResultStr;
    QString m_VoltageRangeStr;
    QString m_VoltageResultStr;
    QString m_DateStr;
    QString m_TimeStr;
    QString m_EmployeeNameStr;

private:


};

inline bool operator==(const TankCls &a_c1,  const TankCls &a_c2)
{
    uint32_t l_ulnID1 = a_c1.m_ulnID;
    uint32_t l_ulnID2 = a_c2.m_ulnID;
    return (l_ulnID1 == l_ulnID2);
}

#endif // TANKCLS_H
