#ifndef SALESENTRYPAGECLS_H
#define SALESENTRYPAGECLS_H

#include <QMainWindow>
#include "CustomerCls.h"
#include "PageCls.h"

namespace Ui {
class SalesEntryPageCls;
}

/*! \class SalesEntryPageCls SalesEntryPageCls.h
 *
 *  Docs for MyClassName
 */
class SalesEntryPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    explicit SalesEntryPageCls(QWidget * a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
    ~SalesEntryPageCls();

private slots:
/** @brief Holds true for negative values */
    void AddSaleToTable();
/** @brief Holds true for negative values */
    void StartBarcodeReading();
/** @brief Holds true for negative values */
    void SaveSalesInTable();
/** @brief Holds true for negative values */
    void LoadSalesMainPage();
/** @brief Holds true for negative values */
    void AssignDate();

private:
    /** @brief Holds true for negative values */
    Ui::SalesEntryPageCls * ui;
/** @brief Holds true for negative values */
    bool m_blnBarcodeReadStarted;

    const uint8_t m_uchTABLE_COLUMN_COUNT   = 4u;

    const uint8_t m_uchBARCODE_COLUMN       = 0u;
    const uint8_t m_uchSOW_NUMBER_COLUMN    = 1u;
    const uint8_t m_uchSALE_DATE_COLUMN     = 2u;
    const uint8_t m_uchCOST_COLUMN          = 3u;

};

#endif // SALESENTRYPAGECLS_H
