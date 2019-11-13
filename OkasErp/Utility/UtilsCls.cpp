#include "UtilsCls.h"

UtilsCls::UtilsCls()
{

}

QString UtilsCls::GetDateString(QDate a_Date)
{
    QString l_DateStr;
    l_DateStr.sprintf("%02d-%02d-%02d", a_Date.year(), a_Date.month(), a_Date.day());
    return l_DateStr;
}

QString UtilsCls::GetTimeString(QTime a_Time)
{
    QString l_HourStr   = QString::number(a_Time.hour());
    QString l_MinuteStr = QString::number(a_Time.minute());
    QString l_SecondStr = QString::number(a_Time.second());

    QString l_TimeStr   = a_Time.toString();

    return l_TimeStr;
}
