#ifndef DATABASEACCESSCLS_H
#define DATABASEACCESSCLS_H

#include <QSqlQuery>
#include <QDebug>
#include <QtSql>
#include <QSqlTableModel>
#include <QString>

#include "OrderCls.h"
#include "CustomerCls.h"
#include "UserCls.h"

#include "DataBaseCls.h"
#include "Utility/LoggerCls.h"
#include "OrderLogCls.h"

#include "FinishCls.h"
#include "TankCls.h"
#include "QualityLogCls.h"

#include "LoadCls.h"

//class OrderLogCls;
class CustomerCls;
class OrderCls;
//class LoadCls;
//class CoatingFinishCls;
class TankCls;

typedef struct
{
    QString m_LoadIDStr;
    QString m_ulnFinishIDStr;
    QMap <OrderCls, uint32_t> m_OrderList;
    QList<TankCls> m_TankList;

} LoadStc;


#define GET_DATA(ROW_NUM, COLUMN_NAME, TYPE) m_Model.record(ROW_NUM).value(COLUMN_NAME).TYPE()
/*! \class DatabaseAccessCls DatabaseAccessCls.h
 *
 *  Docs for MyClassName
 */
class DatabaseAccessCls
{

public:
/** @brief Holds true for negative values */
    static DatabaseAccessCls * s_instance;
/** @brief Holds true for negative values */
    static DatabaseAccessCls * instance()
    {
        if (!s_instance)
          s_instance = new DatabaseAccessCls;
        return s_instance;
    }
/** @brief Holds true for negative values */
    DatabaseAccessCls();
/** @brief Holds true for negative values */
    void ReadConfigurationAndConnect(const QString &a_ConfigurationFileStr);
    /** @brief Holds true for negative values */
    void GetCustomerNames(QStringList &a_CustomerNamesList);
    /** @brief Holds true for negative values */
    void AddCustomer(CustomerCls &a_Customer);
    /** @brief Holds true for negative values */
    bool GetCustomer(CustomerCls &a_Customer, const QString &a_CustomerNameStr);
    /** @brief Holds true for negative values */
    void UpdateCustomer(CustomerCls &a_Customer);
    /** @brief Holds true for negative values */
    void AddOrder(OrderCls &a_Order);
    /** @brief Holds true for negative values */
    bool GetOrder(OrderCls &a_Order, uint32_t a_ulnID);
    /** @brief Holds true for negative values */
    bool GetOrder(OrderCls &a_Order, const QString &a_BarcodeStr);
    /** @brief Holds true for negative values */
    void GetOrderList(QString &a_SearchStr, QList<OrderCls> &a_OrderList);
    /** @brief Holds true for negative values */
    void GetOrderList(const QString &a_StartDateStr, const QString &a_EndDateStr, QList<OrderCls> &a_OrderList);
    /** @brief Holds true for negative values */
    void GetOrderList(QStringList &a_CustomerNameList, QList<OrderCls> &a_OrderList);
    /** @brief Holds true for negative values */
    void GetOrderList(QString a_CustomerNameStr, const QString &a_StartDateStr, const QString &a_EndDateStr, QList<OrderCls> &a_OrderList);
    /** @brief Holds true for negative values */
    void UpdateOrder(OrderCls &a_Order);
    /** @brief Holds true for negative values */
    void UpdateOrderSaleDate(OrderCls &a_Order);
    /** @brief Holds true for negative values */
    void RemoveOrder(OrderCls &a_Order);
    /** @brief Holds true for negative values */
    void UpdateBarcodes(QString &a_CustNameStr);
    /** @brief Holds true for negative values */
    void AddUser(UserStc &a_User);
    /** @brief Holds true for negative values */
    bool GetUser(UserStc &a_User, const QString &a_UserNameStr);
        /** @brief Holds true for negative values */
    bool GetUserPassword(const QString &a_EmailStr, QString &a_UserNameStr, QString &a_PasswordStr);
    /** @brief Holds true for negative values */
    void UpdateUser(UserStc &a_User);
    /** @brief Holds true for negative values */
    void RemoveUser(UserStc &a_User);
    /** @brief Holds true for negative values */
    void GetUserList(QList<UserStc> &a_UserList);
    /** @brief Holds true for negative values */
    void GetImagesPath(QString &a_PathStr);
    /** @brief Holds true for negative values */
    void AddOrderLog(OrderLogStc &a_OrderLog);
    /** @brief Holds true for negative values */
    void GetOrderLogList(OrderCls &a_Order, QList<OrderLogStc> &a_OrderLogList);
    /** @brief Holds true for negative values */
    void UpdateOrderLog(OrderLogStc &a_OrderLog);
    /** @brief Holds true for negative values */
    void RemoveOrderLog(int32_t a_intID);
    /** @brief Holds true for negative values */
    bool AddLoad(LoadStc &a_Load,  QString &a_NewIDStr, bool a_blnIsNew = false);
    /** @brief Holds true for negative values */
    bool GetLoad(LoadStc &a_Load, QString a_LoadIDStr);
    /** @brief Holds true for negative values */ 
    void RemoveLoad(QString a_LoadIDStr);
    /** @brief Holds true for negative values */
    void AddCoatingFinish(CoatingFinishStc &a_Finish);
    /** @brief Holds true for negative values */
    void RemoveCoatingFinish(uint32_t a_ulnFinishID);
    /** @brief Holds true for negative values */
    bool GetQualityFinish(QString a_FinishIDStr, QualityFinishStc &a_Finish);
    /** @brief Holds true for negative values */
    bool GetCoatingFinish(QString a_FinishIDStr, CoatingFinishStc &a_Finish);
    /** @brief Holds true for negative values */
    void AddTankLog(LoadStc &a_Load);
    /** @brief Holds true for negative values */
    bool GetTankLog(LoadStc &a_Load);
    /** @brief Holds true for negative values */
    bool GetTankLog(TankCls &a_Tank, QString a_TankNo, QString a_LoadIDStr);
    /** @brief Holds true for negative values */
    void UpdateTankLog(TankCls &a_Tank, QString a_TankNo, QString a_LoadIDStr);
    /** @brief Holds true for negative values */
    void GetOperations(QMap<uint32_t, QString> &a_OperationMap);
    /** @brief Holds true for negative values */
    void SetQueryAndPrintError(QString a_QueryStr);
private:
    static QSqlQueryModel m_Model;
    static QString m_QueryStr;
    /** @brief Holds true for negative values */
    bool GetLastLoadNumber(QString &a_LoadIDStr);
    /** @brief Holds true for negative values */
    void GetOrderFromModel(OrderCls &a_Order, int32_t a_intRow);
    /** @brief Holds true for negative values */
    void GetUserFromModel(UserStc &a_User, int32_t a_intRow);
    /** @brief Holds true for negative values */
    DataBaseCls * m_DataBasePtr;
    /** @brief Holds true for negative values */
    LoggerCls * m_LoggerPtr;
    /** @brief Holds true for negative values */
    const uint16_t m_ushDATABASE_PORT = 3306u;
};

#endif // DATABASEACCESSCLS_H
