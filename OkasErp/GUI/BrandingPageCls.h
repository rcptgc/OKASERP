#ifndef BRANDINGPAGECLS_H
#define BRANDINGPAGECLS_H

#include <QMainWindow>
#include "PageCls.h"

typedef struct
{
    QString     BarcodeNumberStr;
    QDate       CurrentDate;
    QString     BrandDateStr;
    OrderCls    Order;
} BrandingPageDataStc;

namespace Ui
{
    class BrandingPageCls;
}

/*! \class BrandingPageCls BrandingPageCls.h
 *
 *  Docs for MyClassName
 */
class BrandingPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    explicit BrandingPageCls(QString a_BarcodeStr = QString(), QWidget * a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
    ~BrandingPageCls();
    /** @brief Holds true for negative values */
    void FillForm(void);

private slots:
    /** @brief Holds true for negative values */
    void LoadProductionPage(void);
    /** @brief Holds true for negative values */
    void LoadProductImagePage(void);
    /** @brief Holds true for negative values */
    void SaveBrandDate(void);

private:
/** @brief Holds true for negative values */
    Ui::BrandingPageCls * ui;
/** @brief Holds true for negative values */
    BrandingPageDataStc m_PageData;
};

#endif // BRANDINGPAGECLS_H
