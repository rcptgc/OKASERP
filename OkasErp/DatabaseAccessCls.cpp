#include "DatabaseAccessCls.h"
#include "Utility/UtilsCls.h"

DataBaseCls * DataBaseCls::s_instance = nullptr;
QSqlQueryModel DatabaseAccessCls::m_Model;
QString DatabaseAccessCls::m_QueryStr;

DatabaseAccessCls::DatabaseAccessCls()
{
    qDebug() << Q_FUNC_INFO;
    m_LoggerPtr = LoggerCls::instance();
    m_DataBasePtr = DataBaseCls::instance();

    ReadConfigurationAndConnect("conf_test.json");
}

void DatabaseAccessCls::GetImagesPath(QString &a_PathStr)
{
    m_DataBasePtr->GetImagesPath(a_PathStr);
}

void DatabaseAccessCls::ReadConfigurationAndConnect(const QString &a_ConfigurationFileStr)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");

    QFile l_File;
    QString l_LogStr;

    l_File.setFileName(a_ConfigurationFileStr);

    if (true == l_File.open(QFile::ReadOnly | QFile::Text))
    {
        QJsonDocument l_JsonDocument = QJsonDocument::fromJson(l_File.readAll());
        QJsonObject l_Json = l_JsonDocument.object();

        l_File.close();

        m_DataBasePtr->SetIpAddress(l_Json["ipAddress"].toString());
        m_DataBasePtr->SetImagesPath(l_Json["ServerPath"].toString());

        m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
        l_LogStr = QString("Ip Address: %1 Server Path %2").arg(l_Json["ipAddress"].toString()).arg(l_Json["Server Path"].toString());
        l_LogStr.append("Database Name : testdb");
        l_LogStr.append("Database Port: " + QString::number(m_ushDATABASE_PORT));
        l_LogStr.append("Database login name: root");

        m_DataBasePtr->Initialize("root", m_ushDATABASE_PORT, "testdb");
        m_DataBasePtr->Connect();

        m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO , l_LogStr);
    }
    else
    {
        m_LoggerPtr->CreateErrorLog(Q_FUNC_INFO, a_ConfigurationFileStr + " Dosyası Bulunamadı!", true);
    }
}

bool DatabaseAccessCls::GetLastLoadNumber(QString &a_LoadIDStr)
{
    m_QueryStr = QString("SELECT ExtractNumber('ee') AS MaxID");
    SetQueryAndPrintError(m_QueryStr);
    a_LoadIDStr = GET_DATA(0, "MaxID",    toString);
    if (a_LoadIDStr.isEmpty())
    {
        a_LoadIDStr = "LOAD1";
    }
    return true;
}

bool DatabaseAccessCls::GetLoad(LoadStc &a_Load, QString a_LoadIDStr)
{
    QList<uint32_t> l_ulnOrderID;
    QString l_BarcodeStr;
    QList<uint32_t> l_ulnQuantity;
    OrderCls l_Order;

    m_QueryStr = QString("SELECT * FROM loads WHERE LoadID = '%1'").arg(a_LoadIDStr);
    SetQueryAndPrintError(m_QueryStr);

    a_Load.m_LoadIDStr      = GET_DATA(0, "LoadID",     toString);
    a_Load.m_ulnFinishIDStr = GET_DATA(0, "FinishID",   toString);
    a_Load.m_OrderList.clear();
    qDebug() << "Row Count : " << m_Model.rowCount();

    int32_t intOrderCount = m_Model.rowCount();

    for (int32_t l_intOrderCtr = 0; l_intOrderCtr < intOrderCount; l_intOrderCtr++)
    {
        l_ulnOrderID.append(GET_DATA(l_intOrderCtr, "OrderID",    toUInt));
        l_ulnQuantity.append(GET_DATA(l_intOrderCtr, "Quantity",   toUInt));
    }

    for (int32_t l_intOrderCtr = 0; l_intOrderCtr < intOrderCount; l_intOrderCtr++)
    {
        GetOrder(l_Order, l_ulnOrderID[l_intOrderCtr]);
        a_Load.m_OrderList[l_Order] = l_ulnQuantity[l_intOrderCtr];
    }

    return true;
}

bool DatabaseAccessCls::AddLoad(LoadStc &a_Load, QString &a_NewIDStr, bool a_blnIsNew)
{
    OrderCls l_Order;
    uint32_t l_ulnQty;
    QMap<OrderCls, uint32_t> l_OrderList;
    QString l_ulnLastLoadIDStr;

    l_OrderList = a_Load.m_OrderList;
    if (l_OrderList.size() == 0)
    {
        return false;
    }

    QMap<OrderCls, uint32_t>::const_iterator iterator = l_OrderList.constBegin();

    l_ulnLastLoadIDStr = a_NewIDStr;

    if (a_blnIsNew == true)
    {
        GetLastLoadNumber(l_ulnLastLoadIDStr);
    }

    a_Load.m_LoadIDStr = l_ulnLastLoadIDStr;
    while (iterator != l_OrderList.constEnd())
    {
        l_Order = iterator.key();
        l_ulnQty = iterator.value();
        m_QueryStr = QString("INSERT INTO loads (LoadID, OrderID, FinishID, Quantity) "
                                         "VALUES('%1'  , '%2'   , '%3'    , '%4')")
                            .arg(a_Load.m_LoadIDStr).arg(l_Order.m_ulnID).arg(a_Load.m_ulnFinishIDStr)
                            .arg(l_ulnQty);
        SetQueryAndPrintError(m_QueryStr);
        ++iterator;
    }
    a_NewIDStr = l_ulnLastLoadIDStr;
    return true;
}

void DatabaseAccessCls::RemoveLoad(QString a_LoadIDStr)
{
    m_QueryStr = QString("DELETE FROM loads WHERE LoadID = '%1'").arg(a_LoadIDStr);
    SetQueryAndPrintError(m_QueryStr);
}

bool DatabaseAccessCls::GetCoatingFinish(QString a_FinishIDStr, CoatingFinishStc &a_Finish)
{
    TankCls l_Tank;
    m_QueryStr = QString("SELECT * FROM coatfinish WHERE FinishID = '%1'").arg(a_FinishIDStr);
    SetQueryAndPrintError(m_QueryStr);

    a_Finish.m_FinishNoStr = a_FinishIDStr;
    a_Finish.m_TankList.clear();

    for (int32_t a_intTankCtr = 0; a_intTankCtr < m_Model.rowCount(); a_intTankCtr++)
    {
        QString l_TankNoStr         = GET_DATA(a_intTankCtr, "TankNo",          toString);
        QString l_TankNameStr       = GET_DATA(a_intTankCtr, "TankName",        toString);
        QString l_TimeMinRangeStr   = GET_DATA(a_intTankCtr, "TimeMinRange",    toString);
        QString l_TempMinRangeStr   = GET_DATA(a_intTankCtr, "TempMinRange",    toString);
        QString l_VoltageRangeStr   = GET_DATA(a_intTankCtr, "VoltageMinRange", toString);
        QString l_FinishNameStr     = GET_DATA(a_intTankCtr, "FinishName",      toString);

        l_Tank.m_TankNoStr = l_TankNoStr;
        l_Tank.m_TankNameStr = l_TankNameStr;
        l_Tank.m_TimeMinRangeStr = l_TimeMinRangeStr;
        l_Tank.m_TemperatureRangeStr = l_TempMinRangeStr;
        l_Tank.m_VoltageRangeStr = l_VoltageRangeStr;

        a_Finish.m_FinishNameStr = l_FinishNameStr;

        a_Finish.m_TankList.append(l_Tank);
    }

    return true;
}

bool DatabaseAccessCls::GetQualityFinish(QString a_FinishIDStr, QualityFinishStc &a_Finish)
{
    TankCls l_Tank;
    m_QueryStr = QString("SELECT * FROM qualityfinish WHERE FinishID = '%1'").arg(a_FinishIDStr);
    SetQueryAndPrintError(m_QueryStr);


    QString l_AdhesionStr           = GET_DATA(0, "Adhesion",            toString);
    QString l_ThicknessStr          = GET_DATA(0, "Thickness",           toString);
    QString l_VisualInpsectionStr   = GET_DATA(0, "VisualInspection",    toString);
    QString l_FinishNameStr         = GET_DATA(0, "FinishName",          toString);

    a_Finish.m_AdhesionStr = l_AdhesionStr;
    a_Finish.m_ThicknessStr = l_ThicknessStr;
    a_Finish.m_VisualInspectionStr = l_VisualInpsectionStr;
    a_Finish.m_FinishNameStr = l_FinishNameStr;
    a_Finish.m_FinishNoStr = a_FinishIDStr;


    return true;
}

void DatabaseAccessCls::AddTankLog(LoadStc &a_Load)
{
    foreach(TankCls l_Tank, a_Load.m_TankList)
    {
        m_QueryStr = QString("INSERT INTO tanklogs (TankNo, TankName, TimeMinResult, TempResult, VoltageResult, FinishID, LoadID, LogDate, LogTime, EmployeeName) "
                                            "VALUES('%1'  , '%2'    , '%3'         , '%4'      , '%5'         , '%6'    , '%7'  , '%8'   , '%9'   , '%10'   )")
                             .arg(l_Tank.m_TankNoStr).arg(l_Tank.m_TankNameStr).arg(l_Tank.m_TimeMinResultStr)
                             .arg(l_Tank.m_TemperatureResultStr).arg(l_Tank.m_VoltageResultStr).arg(l_Tank.m_ulnFinishIDStr)
                             .arg(a_Load.m_LoadIDStr).arg(l_Tank.m_DateStr).arg(l_Tank.m_TimeStr).arg(l_Tank.m_EmployeeNameStr);

        SetQueryAndPrintError(m_QueryStr);
    }
}

bool DatabaseAccessCls::GetTankLog(LoadStc &a_Load)
{
    m_QueryStr = QString("SELECT * FROM tanklogs WHERE LoadID = '%1'").arg(a_Load.m_LoadIDStr);
    SetQueryAndPrintError(m_QueryStr);

    if (m_Model.rowCount() != 0)
    {
        a_Load.m_TankList.clear();
        for (int32_t a_intTankCtr = 0; a_intTankCtr < m_Model.rowCount(); a_intTankCtr++)
        {
            TankCls l_Tank;
            uint32_t l_ulnTankID        = GET_DATA(a_intTankCtr, "ID",             toUInt);
            QString l_TankNoStr         = GET_DATA(a_intTankCtr, "TankNo",         toString);
            QString l_TankNameStr       = GET_DATA(a_intTankCtr, "TankName",       toString);
            QString l_TimeMinResultStr  = GET_DATA(a_intTankCtr, "TimeMinResult",  toString);
            QString l_TempResultStr     = GET_DATA(a_intTankCtr, "TempResult",     toString);
            QString l_VoltageResultStr  = GET_DATA(a_intTankCtr, "VoltageResult",  toString);
            QString l_DateStr           = GET_DATA(a_intTankCtr, "LogDate",        toString);
            QString l_TimeStr           = GET_DATA(a_intTankCtr, "LogTime",        toString);
            QString l_EmployeeNameStr   = GET_DATA(a_intTankCtr, "EmployeeName",   toString);

            QRegularExpression l_RegexTime("(?<hour>[0-9]+):(?<minute>[0-9]+):(?<second>[0-9]+)");
            QRegularExpressionMatch l_RegexMatch = l_RegexTime.match(l_TimeStr);

            if (l_RegexMatch.hasMatch())
            {
                QString l_HourStr = l_RegexMatch.captured("hour");
                QString l_MinuteStr = l_RegexMatch.captured("minute");
                QString l_SecondStr = l_RegexMatch.captured("second");
                l_TimeStr = l_HourStr + ":" + l_MinuteStr + ":" + l_SecondStr;
            }

            l_Tank.m_ulnID = l_ulnTankID;
            l_Tank.m_TankNoStr = l_TankNoStr;
            l_Tank.m_ulnFinishIDStr = a_Load.m_ulnFinishIDStr;
            l_Tank.m_LoadIDStr = a_Load.m_LoadIDStr;
            l_Tank.m_TankNameStr = l_TankNameStr;
            l_Tank.m_ulnID = l_ulnTankID;
            l_Tank.m_TimeMinResultStr = l_TimeMinResultStr;
            l_Tank.m_TemperatureResultStr = l_TempResultStr;
            l_Tank.m_VoltageResultStr = l_VoltageResultStr;
            l_Tank.m_DateStr = l_DateStr;
            l_Tank.m_TimeStr = l_TimeStr;
            l_Tank.m_EmployeeNameStr = l_EmployeeNameStr;

            a_Load.m_TankList.append(l_Tank);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool DatabaseAccessCls::GetTankLog(TankCls &a_Tank, QString a_TankNo, QString a_LoadIDStr)
{
    m_QueryStr = QString("SELECT * FROM tanklogs WHERE LoadID = '%1' AND TankNo = '%2'").arg(a_LoadIDStr).arg(a_TankNo);
    SetQueryAndPrintError(m_QueryStr);

    if (m_Model.rowCount() == 0)
    {
        return false;
    }
    else
    {

        QString l_TankNoStr         = GET_DATA(0, "TankNo",         toString);
        QString l_TankNameStr       = GET_DATA(0, "TankName",       toString);
        QString l_TimeMinResultStr  = GET_DATA(0, "TimeMinResult",  toString);
        QString l_TempResultStr     = GET_DATA(0, "TempResult",     toString);
        QString l_VoltageResultStr  = GET_DATA(0, "VoltageResult",  toString);
        QString l_DateStr           = GET_DATA(0, "LogDate",        toString);
        QString l_TimeStr           = GET_DATA(0, "LogTime",        toString);
        QString l_EmployeeNameStr   = GET_DATA(0, "EmployeeName",   toString);

        QRegularExpression l_RegexTime("(?<hour>[0-9]+):(?<minute>[0-9]+):(?<second>[0-9]+)");
        QRegularExpressionMatch l_RegexMatch = l_RegexTime.match(l_TimeStr);

        if (l_RegexMatch.hasMatch())
        {
            QString l_HourStr = l_RegexMatch.captured("hour");
            QString l_MinuteStr = l_RegexMatch.captured("minute");
            QString l_SecondStr = l_RegexMatch.captured("second");
            l_TimeStr = l_HourStr + ":" + l_MinuteStr + ":" + l_SecondStr;
        }

        a_Tank.m_TankNoStr = l_TankNoStr;
        a_Tank.m_LoadIDStr = a_LoadIDStr;
        a_Tank.m_TankNameStr = l_TankNameStr;
        a_Tank.m_TimeMinResultStr = l_TimeMinResultStr;
        a_Tank.m_TemperatureResultStr = l_TempResultStr;
        a_Tank.m_VoltageResultStr = l_VoltageResultStr;
        a_Tank.m_DateStr = l_DateStr;
        a_Tank.m_TimeStr = l_TimeStr;
        a_Tank.m_EmployeeNameStr = l_EmployeeNameStr;

        return true;
    }
}

void DatabaseAccessCls::UpdateTankLog(TankCls &a_Tank, QString a_TankNo, QString a_LoadIDStr)
{
    m_QueryStr = QString("UPDATE tanklogs SET "
                                 "TankNo = '%1', TankName = '%2', TimeMinResult = '%3', "
                                 "TempResult = '%4', VoltageResult = '%5', FinishID = '%6', "
                                 "LoadID = '%7', LogDate = '%8', LogTime = '%9', EmployeeName = '%10' "
                                 "WHERE LoadID = '%11' AND TankNo = '%12'")
                                 .arg(a_TankNo).arg(a_Tank.m_TankNameStr).arg(a_Tank.m_TimeMinResultStr)
                                 .arg(a_Tank.m_TemperatureResultStr).arg(a_Tank.m_VoltageResultStr).arg(a_Tank.m_ulnFinishIDStr)
                                 .arg(a_Tank.m_LoadIDStr).arg(a_Tank.m_DateStr).arg(a_Tank.m_TimeStr).arg(a_Tank.m_EmployeeNameStr)
                                 .arg(a_LoadIDStr).arg(a_TankNo);

    SetQueryAndPrintError(m_QueryStr);
}



void DatabaseAccessCls::AddOrderLog(OrderLogStc &a_OrderLog)
{
    m_QueryStr = QString("INSERT INTO orderlogs (OrderID, ReceivedQuantity, ProcessedQuantity, Operation, OperatorName, LogDate, LogTime, Notes, LogDateTimeType) "
                                        "VALUES('%1'   , '%2'            , '%3'             , '%4'     , '%5'        , '%6'   , '%7'   , '%8' , '%9' )")
                         .arg(a_OrderLog.m_ulnOrderID).arg(a_OrderLog.m_ulnReceivedQuantity).arg(a_OrderLog.m_ulnProcessedQuantity)
                         .arg(a_OrderLog.m_Operation.m_ulnID).arg(a_OrderLog.m_OperatorNameStr).arg(UtilsCls::GetDateString(a_OrderLog.m_Date))
                         .arg(a_OrderLog.m_Time.toString()).arg(a_OrderLog.m_NotesStr).arg(a_OrderLog.m_enmDateType);

    SetQueryAndPrintError(m_QueryStr);
}

void DatabaseAccessCls::GetOrderLogList(OrderCls &a_Order, QList<OrderLogStc> &a_OrderLogList)
{
    m_QueryStr = QString("SELECT processes.*, orderlogs.* FROM orderlogs "
                                 "JOIN processes ON orderlogs.Operation = processes.ID "
                                 "WHERE OrderID = '%1'").arg(a_Order.m_ulnID);
    SetQueryAndPrintError(m_QueryStr);

    a_OrderLogList.clear();
    OrderLogStc l_OrderLog;

    for (int32_t l_intOrderLogCounter = 0; l_intOrderLogCounter < DatabaseAccessCls::m_Model.rowCount(); l_intOrderLogCounter++)
    {
        QDate l_Date;
        QTime l_Time;
        OperationStc l_Operation;

        l_Operation.m_ulnID     = GET_DATA(l_intOrderLogCounter, "processes.ID", toUInt);
        l_Operation.m_GroupName = GET_DATA(l_intOrderLogCounter, "processes.OperationType", toString);
        l_Operation.m_NameStr   = GET_DATA(l_intOrderLogCounter, "processes.Operation", toString);

        QString l_DateStr       = GET_DATA(l_intOrderLogCounter, "orderlogs.LogDate", toString);
        QString l_TimeStr       = GET_DATA(l_intOrderLogCounter, "orderlogs.LogTime", toString);
        LogDateTypeEnum l_enmType  = static_cast<LogDateTypeEnum>(GET_DATA(l_intOrderLogCounter, "orderlogs.LogDateTimeType", toInt));

        QRegularExpression l_Regex("(?<year>[0-9]+)-(?<month>[0-9]+)-(?<day>[0-9]+)");
        QRegularExpressionMatch l_RegexMatch = l_Regex.match(l_DateStr);
        QString l_TempStr;

        if (l_RegexMatch.hasMatch())
        {
            QString l_YearStr = l_RegexMatch.captured("year");
            QString l_MonthStr = l_RegexMatch.captured("month");
            QString l_DayStr = l_RegexMatch.captured("day");
            l_Date = QDate(l_YearStr.toInt(), l_MonthStr.toInt(), l_DayStr.toInt());
        }


        QRegularExpression l_RegexTime("(?<hour>[0-9]+):(?<minute>[0-9]+):(?<second>[0-9]+)");
        l_RegexMatch = l_RegexTime.match(l_TimeStr);

        if (l_RegexMatch.hasMatch())
        {
            QString l_HourStr = l_RegexMatch.captured("hour");
            QString l_MinuteStr = l_RegexMatch.captured("minute");
            QString l_SecondStr = l_RegexMatch.captured("second");
            l_Time = QTime(l_HourStr.toInt(), l_MinuteStr.toInt(), l_SecondStr.toInt());
        }

        l_OrderLog.m_Date                   = l_Date;
        l_OrderLog.m_Time                   = l_Time;
        l_OrderLog.m_NotesStr               = GET_DATA(l_intOrderLogCounter, "Notes", toString);
        l_OrderLog.m_Operation              = l_Operation;
        l_OrderLog.m_OperatorNameStr        = GET_DATA(l_intOrderLogCounter, "orderlogs.OperatorName", toString);
        l_OrderLog.m_ulnOrderID             = a_Order.m_ulnID;
        l_OrderLog.m_ulnProcessedQuantity   = GET_DATA(l_intOrderLogCounter, "orderlogs.ProcessedQuantity", toUInt);
        l_OrderLog.m_ulnReceivedQuantity    = GET_DATA(l_intOrderLogCounter, "orderlogs.ReceivedQuantity", toUInt);
        l_OrderLog.m_intOrderLogID          = GET_DATA(l_intOrderLogCounter, "OrderLogID", toInt);
        l_OrderLog.m_enmDateType            = l_enmType;
        //
        a_OrderLogList.append(l_OrderLog);
    }

}

void DatabaseAccessCls::UpdateOrderLog(OrderLogStc &a_OrderLog)
{
    m_QueryStr = QString("UPDATE orderlogs SET "
                                 "ReceivedQuantity = '%1', ProcessedQuantity = '%2', Operation = '%3', "
                                 "OperatorName = '%4', LogDate = '%5', LogTime = '%6', "
                                 "LogDateTimeType = '%7', Notes = '%8'"
                                 "WHERE OrderLogID = '%9'")
                                 .arg(a_OrderLog.m_ulnReceivedQuantity).arg(a_OrderLog.m_ulnProcessedQuantity).arg(a_OrderLog.m_Operation.m_ulnID)
                                 .arg(a_OrderLog.m_OperatorNameStr).arg(UtilsCls::GetDateString(a_OrderLog.m_Date)).arg(a_OrderLog.m_Time.toString())
                                 .arg(a_OrderLog.m_enmDateType).arg(a_OrderLog.m_NotesStr).arg(a_OrderLog.m_intOrderLogID);

    SetQueryAndPrintError(m_QueryStr);
}

void DatabaseAccessCls::RemoveOrderLog(int32_t a_intID)
{
    m_QueryStr = QString("DELETE FROM orderlogs WHERE OrderLogID = '%1'").arg(a_intID);
    SetQueryAndPrintError(m_QueryStr);
}

void DatabaseAccessCls::GetCustomerNames(QStringList &a_CustomerNamesList)
{
    QString l_CustomerName;
    m_QueryStr = QString("SELECT CustomerName FROM customers");
    SetQueryAndPrintError(m_QueryStr);

    for (int32_t l_intRowNumber = 0; l_intRowNumber < m_Model.rowCount(); l_intRowNumber++)
    {
        l_CustomerName = GET_DATA(l_intRowNumber, "CustomerName", toString);
        a_CustomerNamesList.append(l_CustomerName);
    }
}

bool DatabaseAccessCls::GetCustomer(CustomerCls &a_Customer, const QString &a_CustomerNameStr)
{
    m_QueryStr = QString("SELECT * FROM customers WHERE CustomerName = '%1'").arg(a_CustomerNameStr);
    SetQueryAndPrintError(m_QueryStr);

    DateTimeTypeEnum l_enmDateTimeType;
    QString l_DateTypeStr = m_Model.record(0).value("DateTimeType").toString();

    l_enmDateTimeType = (QString::compare(l_DateTypeStr, "DayMonthYear") == 0) ? DateTimeType_DayMonth : DateTimeType_MonthDay;

    QSqlTableModel l_Model;

    l_Model.setTable("customers");
    l_Model.setFilter("CustomerName = '" + a_CustomerNameStr + "'");
    l_Model.select();

    if (m_Model.rowCount() == 0)
    {
        qDebug() << "Customer " << a_CustomerNameStr << "Not Found!";
        l_Model.setFilter("");
        l_Model.select();
        return false;
    }

    a_Customer.m_enmDateTimeType        = l_enmDateTimeType;
    a_Customer.m_BarcodePrefixStr       = l_Model.record(0).value("BarcodePrefix").toString();
    a_Customer.m_blnIsSoirUsed          = l_Model.record(0).value("SoirApplicable").toBool();
    a_Customer.m_CustomerNameStr        = l_Model.record(0).value("CustomerName").toString();
    a_Customer.m_GKRPrefixStr           = l_Model.record(0).value("GKRPrefix").toString();
    a_Customer.m_ulnID                  = l_Model.record(0).value("CustomerID").toUInt();
    a_Customer.m_LastBarcodeNumberStr   = l_Model.record(0).value("LastBarcodeNumber").toString();
    a_Customer.m_LastGKRNumberStr       = l_Model.record(0).value("LastSowNumber").toString();
    return true;
}

void DatabaseAccessCls::AddCustomer(CustomerCls &a_Customer)
{
    QString l_DateTimeStr = (a_Customer.m_enmDateTimeType == DateTimeType_DayMonth) ? "DayMonthYear" : "MonthDayYear";

    m_QueryStr = QString("INSERT INTO customers (CustomerName, BarcodePrefix, GKRPrefix, SoirApplicable, DateTimeType, LastBarcodeNumber, LastGKRNumber) "
                                                 "VALUES('%1'        , '%2'         , '%3'     , '%4'          , '%5'        , '%6'             , '%7')")
                                 .arg(a_Customer.m_CustomerNameStr).arg(a_Customer.m_BarcodePrefixStr).arg(a_Customer.m_GKRPrefixStr)
                                 .arg(a_Customer.m_blnIsSoirUsed).arg(l_DateTimeStr).arg(a_Customer.m_LastBarcodeNumberStr)
                                 .arg(a_Customer.m_LastGKRNumberStr);

    SetQueryAndPrintError(m_QueryStr);
}

void DatabaseAccessCls::UpdateCustomer(CustomerCls &a_Customer)
{
    QString l_DateTimeStr = (a_Customer.m_enmDateTimeType == DateTimeType_DayMonth) ? "DayMonthYear" : "MonthDayYear";
    m_QueryStr = QString("UPDATE customers SET "
                                 "CustomerName = '%1', BarcodePrefix = '%2', GKRPrefix = '%3', "
                                 "SoirApplicable = '%4', DateTimeType = '%5', LastBarcodeNumber = '%6', "
                                 "LastGKRNumber = '%7'"
                                 "WHERE CustomerID = '%8'")
                                 .arg(a_Customer.m_CustomerNameStr).arg(a_Customer.m_BarcodePrefixStr).arg(a_Customer.m_GKRPrefixStr)
                                 .arg(a_Customer.m_blnIsSoirUsed).arg(l_DateTimeStr).arg(a_Customer.m_LastBarcodeNumberStr)
                                 .arg(a_Customer.m_LastGKRNumberStr).arg(a_Customer.m_ulnID);

    SetQueryAndPrintError(m_QueryStr);
}

void DatabaseAccessCls::GetOperations(QMap<uint32_t, QString> &a_OperationMap)
{
    m_QueryStr = QString("SELECT * FROM processes");
    SetQueryAndPrintError(m_QueryStr);

    uint32_t l_ulnID;
    QString l_Name;

    for (int32_t intOpCtr = 0; intOpCtr < m_Model.rowCount(); intOpCtr++)
    {
        l_ulnID = GET_DATA(intOpCtr, "ID", toUInt);
        l_Name  = GET_DATA(intOpCtr, "Operation", toString);
        a_OperationMap[l_ulnID] = l_Name;
    }

}

void DatabaseAccessCls::AddOrder(OrderCls &a_Order)
{
    QString l_CustomerIDStr;

    m_QueryStr = QString ("SELECT CustomerID FROM customers WHERE CustomerName = '%1'").arg(a_Order.m_CustNameStr);

    SetQueryAndPrintError(m_QueryStr);

    l_CustomerIDStr = GET_DATA(0, "CustomerID", toString);

    m_QueryStr = QString("INSERT INTO orders (EntryDate, DispNum, Project, PartNum, PONum, SOWNum, RecQty, AcptQty, RjcQty, Urgency, Soir, CustomerID) "
                                      "VALUES('%1'     , '%2'   , '%3'   , '%4'   , '%5' , '%6'  , '%7'  , '%8'   , '%9'  , '%10'  , '%11', '%12')")
                         .arg(a_Order.m_EntryDateStr).arg(a_Order.m_DispatchStr).arg(a_Order.m_ProjectStr)
                         .arg(a_Order.m_PartNumStr).arg(a_Order.m_PONumStr).arg(a_Order.m_SOWNumStr)
                         .arg(a_Order.m_ulnRcvdQty).arg(a_Order.m_ulnAcptdQty).arg(a_Order.m_ulnRejctdQty)
                         .arg(a_Order.m_UrgencyStr).arg(a_Order.m_SoirStr).arg(l_CustomerIDStr);

    SetQueryAndPrintError(m_QueryStr);
}

void DatabaseAccessCls::UpdateOrder(OrderCls &a_Order)
{
    m_QueryStr = QString("UPDATE orders SET "
                                 "EntryDate = '%1', Project = '%2', PartNum = '%3', "
                                 "PONum = '%4', SOWNum = '%5', RecQty = '%6', "
                                 "AcptQty = '%7', RjcQty = '%8', Urgency = '%9', "
                                 "Soir = '%10', Cost = '%11', DispNum = '%12', "
                                 "BrandDate = '%13' "
                                 "WHERE OrderID = '%14'")
                                 .arg(a_Order.m_EntryDateStr).arg(a_Order.m_ProjectStr).arg(a_Order.m_PartNumStr)
                                 .arg(a_Order.m_PONumStr).arg(a_Order.m_SOWNumStr).arg(a_Order.m_ulnRcvdQty)
                                 .arg(a_Order.m_ulnAcptdQty).arg(a_Order.m_ulnRejctdQty).arg(a_Order.m_UrgencyStr)
                                 .arg(a_Order.m_SoirStr).arg(a_Order.m_CostStr).arg(a_Order.m_DispatchStr).arg(a_Order.m_BrandDateStr)
                                 .arg(a_Order.m_ulnID);

    SetQueryAndPrintError(m_QueryStr);
}

void DatabaseAccessCls::UpdateOrderSaleDate(OrderCls &a_Order)
{
    m_QueryStr = QString("UPDATE orders SET "
                                 "SaleDate = '%1', Cost = '%2'"
                                 "WHERE OrderID = '%3'")
                                 .arg(a_Order.m_SaleDateStr).arg(a_Order.m_CostStr).arg(a_Order.m_ulnID);
    SetQueryAndPrintError(m_QueryStr);
}

void DatabaseAccessCls::RemoveOrder(OrderCls &a_Order)
{
    m_QueryStr = QString("DELETE FROM orders WHERE OrderID = '%1'").arg(a_Order.m_ulnID);

    SetQueryAndPrintError(m_QueryStr);
}

bool DatabaseAccessCls::GetOrder(OrderCls &a_Order, const QString &a_BarcodeStr)
{
    m_QueryStr = QString("SELECT customers.CustomerName, orders.* FROM orders "
                                 "JOIN customers ON customers.CustomerID = orders.CustomerID WHERE "
                                 "orders.BarcodeNum = '%1'"
                                 ).arg(a_BarcodeStr);
    SetQueryAndPrintError(m_QueryStr);

    if (m_Model.rowCount() == 0)
    {
        return false;
    }
    else
    {
        GetOrderFromModel(a_Order, 0);
        return true;
    }
}

bool DatabaseAccessCls::GetOrder(OrderCls &a_Order, uint32_t a_ulnID)
{
    m_QueryStr = QString("SELECT customers.CustomerName, orders.* FROM orders "
                                 "JOIN customers ON customers.CustomerID = orders.CustomerID WHERE "
                                 "orders.OrderID = '%1'"
                                 ).arg(a_ulnID);
    SetQueryAndPrintError(m_QueryStr);

    if (m_Model.rowCount() == 0)
    {
        return false;
    }
    else
    {
        GetOrderFromModel(a_Order, 0);
        return true;
    }
}

void DatabaseAccessCls::GetOrderList(QString &a_SearchStr, QList<OrderCls> &a_OrderList)
{
    OrderCls l_Order;
    m_QueryStr = QString("SELECT customers.CustomerName, orders.* FROM orders "
                                 "JOIN customers ON customers.CustomerID = orders.CustomerID WHERE "
                                 "orders.BarcodeNum = '%1' OR orders.GKRNum = '%1' OR orders.PONum = '%1' OR orders.PartNum = '%1' OR "
                                 "orders.Project = '%1' OR orders.Soir = '%1' OR orders.SOWNum = '%1' OR orders.Urgency = '%1' OR "
                                 "customers.CustomerName = '%1' OR orders.DispNum = '%1'"
                                 ).arg(a_SearchStr);

    SetQueryAndPrintError(m_QueryStr);

    int l_intOrderCount = m_Model.rowCount();

    a_OrderList.clear();

    for (int32_t intOrderCtr = 0; intOrderCtr < l_intOrderCount; intOrderCtr++)
    {
        GetOrderFromModel(l_Order, intOrderCtr);
        a_OrderList.append(l_Order);
    }

}

void DatabaseAccessCls::GetOrderList(QStringList &a_CustomerNameList, QList<OrderCls> &a_OrderList)
{
    OrderCls l_Order;
    m_QueryStr = QString("SELECT customers.CustomerName, orders.* FROM orders JOIN customers ON customers.CustomerID = orders.CustomerID WHERE ");

    for (int32_t intCustCtr = 0; intCustCtr < a_CustomerNameList.size(); intCustCtr++)
    {
        m_QueryStr.append("customers.CustomerName = ");
        m_QueryStr.append("'" + a_CustomerNameList.at(intCustCtr) + "'");

        if (intCustCtr != (a_CustomerNameList.size() - 1))
        {
           m_QueryStr.append(" OR ");
        }
    }

    SetQueryAndPrintError(m_QueryStr);

    int l_intOrderCount = m_Model.rowCount();
    a_OrderList.clear();
    for (int32_t intOrderCtr = 0; intOrderCtr < l_intOrderCount; intOrderCtr++)
    {
        GetOrderFromModel(l_Order, intOrderCtr);
        a_OrderList.append(l_Order);
    }

}

void DatabaseAccessCls::UpdateBarcodes(QString &a_CustNameStr)
{
    OrderCls l_Order;
    m_QueryStr = QString("SELECT customers.LastGKRNumber, customers.GKRPrefix, customers.BarcodePrefix, customers.LastBarcodeNumber, orders.OrderID FROM orders "
                                 "JOIN customers ON customers.CustomerID = orders.CustomerID "
                                 "WHERE orders.BarcodeNum IS NULL "
                                 "AND customers.CustomerName = '" + a_CustNameStr + "'");
    SetQueryAndPrintError(m_QueryStr);

    QString l_LastBarcodeNumberStr = m_Model.record(0).value("customers.LastBarcodeNumber").toString();
    QString l_OrderIDStr;
    CustomerCls l_Customer;

    int l_intOrderCount = m_Model.rowCount();

    QSqlQueryModel m_Model2;

    l_Customer.m_BarcodePrefixStr       = GET_DATA(0, "customers.BarcodePrefix"     , toString);
    l_Customer.m_LastBarcodeNumberStr   = GET_DATA(0, "customers.LastBarcodeNumber" , toString);
    l_Customer.m_GKRPrefixStr           = GET_DATA(0, "customers.GKRPrefix"         , toString);
    l_Customer.m_LastGKRNumberStr       = GET_DATA(0, "customers.LastGKRNumber"     , toString);

    for (int intOrderCtr = 0; intOrderCtr < l_intOrderCount; intOrderCtr++)
    {
        l_Customer.m_LastBarcodeNumberStr   = l_Customer.CalculateNextBarcodeNumber();
        l_Customer.m_LastGKRNumberStr       = l_Customer.CalculateNextGKRNumber();

        l_OrderIDStr = m_Model.record(intOrderCtr).value("orders.OrderID").toString();

        m_QueryStr = QString("UPDATE orders SET BarcodeNum = '%1' , GKRNum = '%2' WHERE OrderID = '%3'")
                .arg(l_Customer.m_LastBarcodeNumberStr)
                .arg(l_Customer.m_LastGKRNumberStr)
                .arg(l_OrderIDStr);

        m_Model2.setQuery(m_QueryStr);

        if (m_Model.lastError().isValid())
        {
            qDebug() << m_Model.lastError();
        }
    }

    m_QueryStr = QString("UPDATE customers SET LastBarcodeNumber = '%1', LastGKRNumber = '%2' WHERE CustomerName = '%3'")
            .arg(l_Customer.m_LastBarcodeNumberStr)
            .arg(l_Customer.m_LastGKRNumberStr)
            .arg(a_CustNameStr);

    m_Model2.setQuery(m_QueryStr);

    if (m_Model.lastError().isValid())
    {
        qDebug() << m_Model.lastError();
    }
}

void DatabaseAccessCls::GetOrderList(const QString &a_StartDateStr, const QString &a_EndDateStr, QList<OrderCls> &a_OrderList)
{
    a_OrderList.clear();

    OrderCls l_Order;

    m_QueryStr = QString("SELECT customers.CustomerName, orders.* FROM orders JOIN customers ON customers.CustomerID = orders.CustomerID "
                                 "WHERE SaleDate >= '%1' AND SaleDate <= '%2'")
                                 .arg(a_StartDateStr).arg(a_EndDateStr);

    SetQueryAndPrintError(m_QueryStr);

    int l_intOrderCount = m_Model.rowCount();
    a_OrderList.clear();
    //
    for (int32_t intOrderCtr = 0; intOrderCtr < l_intOrderCount; intOrderCtr++)
    {
        GetOrderFromModel(l_Order, intOrderCtr);
        a_OrderList.append(l_Order);
    }
}

void DatabaseAccessCls::GetOrderList(QString a_CustomerNameStr, const QString &a_StartDateStr, const QString &a_EndDateStr, QList<OrderCls> &a_OrderList)
{
    a_OrderList.clear();
    OrderCls l_Order;
    m_QueryStr = QString("SELECT customers.CustomerName, orders.* FROM orders JOIN customers ON customers.CustomerID = orders.CustomerID "
                                 "WHERE customers.CustomerName = '%1' AND SaleDate >= '%2' AND SaleDate <= '%3'")
                                 .arg(a_CustomerNameStr).arg(a_StartDateStr).arg(a_EndDateStr);

    SetQueryAndPrintError(m_QueryStr);

    int l_intOrderCount = m_Model.rowCount();

    a_OrderList.clear();

    for (int32_t intOrderCtr = 0; intOrderCtr < l_intOrderCount; intOrderCtr++)
    {
        GetOrderFromModel(l_Order, intOrderCtr);
        a_OrderList.append(l_Order);
    }

}

void DatabaseAccessCls::AddUser(UserStc &a_User)
{
    m_QueryStr = QString("INSERT INTO users (UserName, EmailAddress, Password, ProdTracAuth, BrandAuth, CustAuth, UserAuth, SalesAuth) "
                                             "VALUES('%1'    , '%2'        , '%3'    , '%4'        , '%5'     , '%6'    , '%7'    , '%8')")
                                 .arg(a_User.m_UserNameStr).arg(a_User.m_EmailStr).arg(a_User.m_PasswordStr)
                                 .arg(a_User.m_blnProductTrackingAuth).arg(a_User.m_blnBrandingAuth).arg(a_User.m_blnCustomerAuth)
                                 .arg(a_User.m_blnUserAuth).arg(a_User.m_blnSalesAuth);

    SetQueryAndPrintError(m_QueryStr);
}

void DatabaseAccessCls::UpdateUser(UserStc &a_User)
{
    m_QueryStr = QString("UPDATE users SET "
                                 "UserName = '%1', EmailAddress = '%2', Password = '%3', "
                                 "ProdTracAuth = '%4', BrandAuth = '%5', CustAuth = '%6', "
                                 "UserAuth = '%7', SalesAuth = '%8' "
                                 "WHERE UserID = '%9'")
                                 .arg(a_User.m_UserNameStr).arg(a_User.m_EmailStr).arg(a_User.m_PasswordStr)
                                 .arg(a_User.m_blnProductTrackingAuth).arg(a_User.m_blnBrandingAuth).arg(a_User.m_blnCustomerAuth)
                                 .arg(a_User.m_blnUserAuth).arg(a_User.m_blnSalesAuth).arg(a_User.m_ulnID);

    SetQueryAndPrintError(m_QueryStr);
}

bool DatabaseAccessCls::GetUser(UserStc &a_User, const QString &a_UserNameStr)
{
    m_QueryStr = QString("SELECT * FROM users WHERE UserName = '%1'").arg(a_UserNameStr);

    SetQueryAndPrintError(m_QueryStr);

    if (m_Model.rowCount() == 0)
    {
        qDebug() << "User " << a_UserNameStr << "Not Found!";
        return false;
    }

    GetUserFromModel(a_User, 0);

    return true;
}

bool DatabaseAccessCls::GetUserPassword(const QString &a_EmailStr, QString &a_UserNameStr, QString &a_PasswordStr)
{
    m_QueryStr = QString("SELECT * FROM users WHERE EmailAddress = '%1'").arg(a_EmailStr);

    SetQueryAndPrintError(m_QueryStr);

    if (m_Model.rowCount() == 0)
    {
        return false;
    }

    a_PasswordStr = GET_DATA(0, "Password"    , toString);
    a_UserNameStr = GET_DATA(0, "UserName"    , toString);

    qDebug() << "PW : " << a_PasswordStr;
    qDebug() << "User Name : " << a_UserNameStr;

    return true;
}

void DatabaseAccessCls::GetUserList(QList<UserStc> &a_UserList)
{
    m_QueryStr = QString("SELECT * FROM users");
    SetQueryAndPrintError(m_QueryStr);
    a_UserList.clear();
    //
    for (int32_t l_intUserCounter = 0; l_intUserCounter < m_Model.rowCount(); l_intUserCounter++)
    {
        UserStc l_User;
        GetUserFromModel(l_User, l_intUserCounter);
        a_UserList.append(l_User);
    }

}

void DatabaseAccessCls::RemoveUser(UserStc &a_User)
{
    m_QueryStr = QString("DELETE FROM users WHERE UserID = '%1'").arg(a_User.m_ulnID);
    SetQueryAndPrintError(m_QueryStr);
}

void DatabaseAccessCls::SetQueryAndPrintError(QString a_QueryStr)
{
    m_Model.setQuery(a_QueryStr);

    qDebug() << a_QueryStr;

    if (m_Model.lastError().isValid())
    {
        qDebug() << m_Model.lastError();
    }
}

void DatabaseAccessCls::GetOrderFromModel(OrderCls &a_Order, int32_t a_intRow)
{
    a_Order.m_ulnAcptdQty   = GET_DATA(a_intRow, "AcptQty"       , toUInt);
    a_Order.m_BarcodeNumStr = GET_DATA(a_intRow, "BarcodeNum"    , toString);
    a_Order.m_BrandDateStr  = GET_DATA(a_intRow, "BrandDate"     , toString);
    a_Order.m_CostStr       = GET_DATA(a_intRow, "Cost"          , toString);
    a_Order.m_CustNameStr   = GET_DATA(a_intRow, "CustomerName"  , toString);
    a_Order.m_DispatchStr   = GET_DATA(a_intRow, "DispNum"       , toString);
    a_Order.m_EntryDateStr  = GET_DATA(a_intRow, "EntryDate"     , toString);
    a_Order.m_GKRNumStr     = GET_DATA(a_intRow, "GKRNum"        , toString);
    a_Order.m_ulnID         = GET_DATA(a_intRow, "OrderID"       , toUInt);
    a_Order.m_PONumStr      = GET_DATA(a_intRow, "PONum"         , toString);
    a_Order.m_PartNumStr    = GET_DATA(a_intRow, "PartNum"       , toString);
    a_Order.m_ProjectStr    = GET_DATA(a_intRow, "Project"       , toString);
    a_Order.m_ulnRcvdQty    = GET_DATA(a_intRow, "RecQty"        , toUInt);
    a_Order.m_ulnRejctdQty  = GET_DATA(a_intRow, "RjcQty"        , toUInt);
    a_Order.m_SaleDateStr   = GET_DATA(a_intRow, "SaleDate"      , toString);
    a_Order.m_UrgencyStr    = GET_DATA(a_intRow, "Urgency"       , toString);
    a_Order.m_SOWNumStr     = GET_DATA(a_intRow, "SOWNum"        , toString);
}

void DatabaseAccessCls::GetUserFromModel(UserStc &a_User, int32_t a_intRow)
{
    a_User.m_blnBrandingAuth        = GET_DATA(a_intRow, "BrandAuth"    , toBool);
    a_User.m_blnCustomerAuth        = GET_DATA(a_intRow, "CustAuth"     , toBool);
    a_User.m_EmailStr               = GET_DATA(a_intRow, "EmailAddress" , toString);
    a_User.m_PasswordStr            = GET_DATA(a_intRow, "Password"     , toString);
    a_User.m_blnProductTrackingAuth = GET_DATA(a_intRow, "ProdTracAuth" , toBool);
    a_User.m_blnSalesAuth           = GET_DATA(a_intRow, "SalesAuth"    , toBool);
    a_User.m_UserNameStr            = GET_DATA(a_intRow, "UserName"     , toString);
    a_User.m_blnUserAuth            = GET_DATA(a_intRow, "UserAuth"     , toBool);
    a_User.m_ulnID                  = GET_DATA(a_intRow, "UserID"       , toUInt);
}
