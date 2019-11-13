#ifndef CREATEORDERCLS_H
#define CREATEORDERCLS_H

#include <QMainWindow>
#include "CustomerCls.h"
#include "PageCls.h"

namespace Ui
{
    class CreateOrderPageCls;
}

typedef struct
{
    QString     BarcodeNumberStr;
    QDate       CurrentDate;
    QString     BrandDateStr;
    OrderCls    Order;
} CreateOrderPageDataStc;

/*! \class CreateOrderPageCls CreateOrderPageCls.h
 *
 *  Docs for MyClassName
 */
class CreateOrderPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    explicit CreateOrderPageCls(QString a_CustNameStr = QString(), QWidget * a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
    ~CreateOrderPageCls();

private slots:
/** @brief Holds true for negative values */
    void LoadProductTrackingPage(void);
    /** @brief Holds true for negative values */
    void AddOrderToDatabase(void);

private:
/** @brief Holds true for negative values */
    Ui::CreateOrderPageCls * ui;
/** @brief Holds true for negative values */
    QString m_SelectedCustomerStr;

    CreateOrderPageDataStc m_PageData;
};

#endif // CREATEORDERCLS_H
