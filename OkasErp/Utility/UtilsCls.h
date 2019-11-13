#ifndef UTILSCLS_H
#define UTILSCLS_H

#include <QString>
#include <QDate>
#include <QTime>

class UtilsCls
{
public:
    UtilsCls();

    static QString GetDateString(QDate a_Date);
    static QString GetTimeString(QTime a_Time);
};

#endif // UTILSCLS_H
