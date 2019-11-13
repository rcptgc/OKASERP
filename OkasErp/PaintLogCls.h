#ifndef PAINTLOGCLS_H
#define PAINTLOGCLS_H

#include <QString>
typedef struct
{
    QString m_IDStr;
    QString m_FinishIDStr;
    QString m_FinishNameStr;
    QString m_AppStartTimeStr;
    QString m_AppFinishTimeStr;
    QString m_AppTempStr;
    QString m_AppHumidityStr;
    QString m_FlashOffStartTimeStr;
    QString m_FlashOffFinishTimeStr;
    QString m_FlashOffTempStr;
    QString m_FlashOffHumidityStr;
    QString m_AirCureStartTimeStr;
    QString m_AirCureTempStr;
    QString m_EquipmentStr;
    QString m_OperatorStr;
} PaintLogStc;

#endif // PAINTLOGCLS_H
