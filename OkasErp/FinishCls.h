#ifndef FINISHCLS_H
#define FINISHCLS_H

#include <QString>
#include <QList>
#include <TankCls.h>

typedef struct
{
    QString m_FinishNoStr;
    QString m_FinishNameStr;
    QList<TankCls> m_TankList;

} CoatingFinishStc;

typedef struct
{
    QString m_FinishNoStr;
    QString m_FinishNameStr;
    QString m_VisualInspectionStr;
    QString m_ThicknessStr;
    QString m_AdhesionStr;
} QualityFinishStc;

typedef struct
{
    QString m_FinishNoStr;
    QString m_FinishNameStr;
    QString m_SpecStr;
    QString m_PaintThicknessStr;
    QString m_AppHumidityStr;
    QString m_FlashOffTimeStr;
    QString m_AppTempStr;
    QString m_FlashOffTempStr;
    QString m_FlashOffHumidityStr;
    QString m_AirCureTempStr;
    QString m_AirCureTimeStr;

} PaintAppFinishStc;




#endif // FINISHCLS_H
