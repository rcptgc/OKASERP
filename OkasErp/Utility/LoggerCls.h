#ifndef ERRORLOGGERCLS_H
#define ERRORLOGGERCLS_H

#include <QMessageBox>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include "../UserCls.h"
#include <QFile>

/*! \class LoggerCls LoggerCls.h
 *
 *  Docs for MyClassName
 */
class LoggerCls
{
public:
    /** @brief Holds true for negative values */
    static LoggerCls *s_instance;
/** @brief Holds true for negative values */
    static LoggerCls *instance()
    {
        if (!s_instance)
          s_instance = new LoggerCls;
        return s_instance;
    }
/** @brief Holds true for negative values */
    LoggerCls();
/** @brief Holds true for negative values */
    void CreateErrorLog(QString a_FunctionNameStr, QString a_MessageStr, bool a_blnIsDisplayed);
/** @brief Holds true for negative values */
    void CreateTraceLog(QString a_FunctionNameStr, QString a_MessageStr);
/** @brief Holds true for negative values */
    void CreateUserLog(UserStc * a_UserPtr, QString a_FunctionNameStr, QString a_MessageStr);
/** @brief Holds true for negative values */
    void DisplayInformation(QString a_MessageStr, QWidget * a_ParentPtr);
/** @brief Holds true for negative values */
    static void MessageHandler(QtMsgType type, const QMessageLogContext &, const QString & msg);

private:
    /** @brief Holds true for negative values */
    QMessageBox * m_MessageBoxPtr;
/** @brief Holds true for negative values */
    QFile m_TraceLogFile;
/** @brief Holds true for negative values */
    QFile m_UserLogFile;
/** @brief Holds true for negative values */
    QFile m_ErrorLogFile;
/** @brief Holds true for negative values */
    QTextStream m_TraceStream;
/** @brief Holds true for negative values */
    QTextStream m_UserStream;
/** @brief Holds true for negative values */
    QTextStream m_ErrorStream;

};

#endif // ERRORLOGGERCLS_H
