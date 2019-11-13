#include "LoggerCls.h"
#include "QDate"
#include "QTime"
#include <QException>
#include <QDateTime>

LoggerCls::LoggerCls()
{
    m_TraceLogFile.setFileName("TraceLog");
    m_ErrorLogFile.setFileName("ErrorLog");
    m_UserLogFile.setFileName("UserLog");

    m_TraceLogFile.open(QIODevice::WriteOnly | QIODevice::Append);
    m_ErrorLogFile.open(QIODevice::WriteOnly | QIODevice::Append);
    m_UserLogFile.open(QIODevice::WriteOnly | QIODevice::Append);

    m_TraceStream.setDevice(&m_TraceLogFile);
    m_ErrorStream.setDevice(&m_ErrorLogFile);
    m_UserStream.setDevice(&m_UserLogFile);
}

void LoggerCls::DisplayInformation(QString a_MessageStr, QWidget * a_ParentPtr)
{
    QMessageBox * l_MessageBox = new QMessageBox(a_ParentPtr);

    try
    {
        l_MessageBox->setText(a_MessageStr);
        l_MessageBox->show();
    }
    catch (QException &e)
    {
        qDebug() << e.what();
    }

}

void LoggerCls::CreateTraceLog(QString a_FunctionNameStr, QString a_MessageStr)
{
    QDateTime l_DateTime = QDateTime::currentDateTime();

    m_TraceStream << l_DateTime.toString() << " " << "TRACE :" << a_FunctionNameStr << ":" << a_MessageStr << endl;
}

void LoggerCls::CreateUserLog(UserStc * a_UserPtr, QString a_FunctionNameStr, QString a_MessageStr)
{
    QDateTime l_DateTime = QDateTime::currentDateTime();
    m_UserStream << l_DateTime.toString() << " " << "USER :" << a_UserPtr->m_UserNameStr << ":" << a_FunctionNameStr << ":" << a_MessageStr << endl;
}

void LoggerCls::CreateErrorLog(QString a_FunctionNameStr, QString a_MessageStr, bool a_blnIsDisplayed)
{
    QDateTime l_DateTime = QDateTime::currentDateTime();
    m_ErrorStream << l_DateTime.toString() << " " << "ERROR :" << a_FunctionNameStr << ":" << a_MessageStr << endl;

    if (a_blnIsDisplayed)
    {
        m_MessageBoxPtr = new QMessageBox();
        m_MessageBoxPtr->setText(a_MessageStr);
        m_MessageBoxPtr->show();
    }
}
