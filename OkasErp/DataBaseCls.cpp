#include "DataBaseCls.h"

DataBaseCls::DataBaseCls()
{

}
void DataBaseCls::Initialize(QString a_UserNameStr, uint16_t a_ushPortNumber, QString a_DatabaseNameStr)
{
    if (m_db.isOpen() == false)
    {
        m_db = QSqlDatabase::addDatabase("QMYSQL");
        m_db.setHostName(m_IpAddressStr);
        m_db.setUserName(a_UserNameStr);
        m_db.setPort(a_ushPortNumber);
        m_db.setDatabaseName(a_DatabaseNameStr);
    }
}

bool DataBaseCls::Connect()
{
    bool success = false;

    if (m_db.isOpen() == false)
    {
        if (m_db.open() )
        {
            success = true;
        }
        else
        {
            success = false;
        }
    }
    else
    {
        success = true;
    }

    if (m_db.lastError().isValid() == true)
    {
        qDebug() << m_db.lastError().text();
    }

    return success;
}

void DataBaseCls::GetImagesPath(QString &a_PathStr)
{
    a_PathStr = m_ImagesPathStr;
}

void DataBaseCls::SetIpAddress(QString a_IpAddressStr)
{
    m_IpAddressStr = a_IpAddressStr;
}

void DataBaseCls::SetImagesPath(QString a_ImagesPathStr)
{
    m_ImagesPathStr = a_ImagesPathStr;
}
