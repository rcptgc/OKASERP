#ifndef DATABASECLS_H
#define DATABASECLS_H
#include <QtSql>

/*! \class DataBaseCls DataBaseCls.h
 *
 *  Docs for MyClassName
 */
class DataBaseCls
{
public:
    /** @brief Holds true for negative values */
    static DataBaseCls *s_instance;
    /** @brief Holds true for negative values */
    DataBaseCls();
/** @brief Holds true for negative values */
    void Initialize(QString a_UserNameStr, uint16_t a_ushPortNumber, QString a_DatabaseNameStr);
    /** @brief Holds true for negative values */
    bool Connect();
    /** @brief Holds true for negative values */
    void SetIpAddress(QString a_IpAddressStr);
    /** @brief Holds true for negative values */
    void SetImagesPath(QString a_ImagesPathStr);
    /** @brief Holds true for negative values */
    void GetImagesPath(QString &a_PathStr);
/** @brief Holds true for negative values */
    QSqlDatabase m_db;
/** @brief Holds true for negative values */
    static DataBaseCls *instance()
    {
        if (!s_instance)
          s_instance = new DataBaseCls;
        return s_instance;
    }

private:
    /** @brief Holds true for negative values */
    QString m_IpAddressStr;
    /** @brief Holds true for negative values */
    QString m_ImagesPathStr;
};


#endif // DATABASECLS_H
