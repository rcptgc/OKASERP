#ifndef CUSTOMERPROFILEPAGECLS_H
#define CUSTOMERPROFILEPAGECLS_H

#include <QMainWindow>
#include "CustomerCls.h"
#include "PageCls.h"


namespace Ui
{
    class CustomerProfilePageCls;
}

/*! \class CustomerProfilePageCls CustomerProfilePageCls.h
 *
 *  Docs for MyClassName
 */
class CustomerProfilePageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
/** @brief Holds true for negative values */
    explicit CustomerProfilePageCls(QWidget * a_ParentPtr = nullptr);
/** @brief Holds true for negative values */
    ~CustomerProfilePageCls();

private slots:
    /** @brief Holds true for negative values */
    void LoadMainPage(void);
    /** @brief Holds true for negative values */
    void AddNewCustomer(void);
    /** @brief Holds true for negative values */
    void UpdateCustomer(void);
    /** @brief Holds true for negative values */
    void FillForm(CustomerCls &a_Customer);
    /** @brief Holds true for negative values */
    void ClearForm(void);

private:
/** @brief Holds true for negative values */
    Ui::CustomerProfilePageCls * ui;

    CustomerCls m_Customer;
    QString m_CustomerNameStr;
    QString m_BarcodePrefixStr;
    DateTimeTypeEnum m_enmDateTimeType;
    uint32_t m_ulnInitialSowNumber;
    bool m_blnIsSoirUsed;
    QString m_SowPrefixStr;
};

#endif // CUSTOMERPROFILEPAGECLS_H
