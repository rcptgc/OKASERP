#include "CustomerCls.h"
#include <QDebug>


/*! @fn     CustomerCls::CustomerCls()
 *
 * @brief   Function initializes Login Page Class Instance. Function reads the configuration file "conf_test.json",
 *          in order to retrieve connection settings. By using configuration settings. Function connects to the
 *          database.
 *
 */
CustomerCls::CustomerCls()
{

}


/*! @fn     QString CustomerCls::CalculateNextBarcodeNumber()
 *
 * @brief   Function initializes Login Page Class Instance. Function reads the configuration file "conf_test.json",
 *          in order to retrieve connection settings. By using configuration settings. Function connects to the
 *          database.
 *
 */
QString CustomerCls::CalculateNextBarcodeNumber()
{
    QString l_LastBarcodeNumberStr;

    l_LastBarcodeNumberStr = m_LastBarcodeNumberStr;

    if (l_LastBarcodeNumberStr.isEmpty() == true)
    {
        l_LastBarcodeNumberStr = m_BarcodePrefixStr + " A000000000000";
    }
    else
    {
        QRegularExpression l_Regex("(?<name>\[a-zA-ZğüşöçİĞÜŞÖÇ]+ \\w)(?<number>\\d+)");
        QRegularExpressionMatch l_RegexMatch = l_Regex.match(l_LastBarcodeNumberStr);
        QString l_TempStr;

        if (l_RegexMatch.hasMatch())
        {
            QString l_NumberStr = l_RegexMatch.captured("number"); // first == "23"

            QString l_NameStr = l_RegexMatch.captured("name"); // name == "Jordan"

            l_TempStr.append(l_NameStr);

            int32_t l_intNumber = l_NumberStr.toInt();
            l_intNumber++;

            int32_t l_inTempNumber = l_intNumber;

            int l_intDigitCount = 1;

            while ( (l_intNumber /= 10) != 0)
            {
                l_intDigitCount++;
            }

            for (int32_t i = 0; i < (12 - l_intDigitCount); i++)
            {
                l_TempStr.append('0');
            }


            l_TempStr.append(QString::number(l_inTempNumber));
            l_LastBarcodeNumberStr = l_TempStr;
        }
    }

    return l_LastBarcodeNumberStr;
}

/*! @fn     QString CustomerCls::CalculateNextSowNumber()
 *
 * @brief   Function initializes Login Page Class Instance. Function reads the configuration file "conf_test.json",
 *          in order to retrieve connection settings. By using configuration settings. Function connects to the
 *          database.
 *
 */
QString CustomerCls::CalculateNextGKRNumber()
{
    QString l_LastSowNumberStr;
    QString l_YearStr;
    QString l_MonthStr;
    QString l_DayStr;
    QString l_PrefixStr;

    QDate l_CurrDate = QDate::currentDate();

    l_LastSowNumberStr = m_LastGKRNumberStr;

    if (l_LastSowNumberStr.isEmpty() == true)
    {
        l_YearStr.sprintf("%.2d", l_CurrDate.year());
        l_MonthStr.sprintf("%.2d", l_CurrDate.month());
        l_DayStr.sprintf("%.2d", l_CurrDate.day());
        l_PrefixStr = this->m_GKRPrefixStr;

        l_LastSowNumberStr = l_YearStr + l_MonthStr + l_DayStr + l_PrefixStr + "01";
    }
    else
    {
        m_SowNumber = m_SowNumber.FromString(l_LastSowNumberStr);

        int l_intCountNum = m_SowNumber.GetCountNum();

        l_intCountNum++;

        m_SowNumber.SetCountNum(l_intCountNum);

        l_LastSowNumberStr = m_SowNumber.ToString();
    }

    return l_LastSowNumberStr;
}

