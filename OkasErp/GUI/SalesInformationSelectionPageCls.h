#ifndef SALESINFORMATIONSELECTIONPAGECLS_H
#define SALESINFORMATIONSELECTIONPAGECLS_H

#include <QMainWindow>
#include "PageCls.h"

namespace Ui {
class SalesInformationSelectionPageCls;
}

/*! \class SalesInformationSelectionPageCls SalesInformationSelectionPageCls.h
 *
 *  Docs for MyClassName
 */
class SalesInformationSelectionPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    explicit SalesInformationSelectionPageCls(QWidget * a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
    ~SalesInformationSelectionPageCls();

private slots:
/** @brief Holds true for negative values */
    void LoadSalesEntryPage();
/** @brief Holds true for negative values */
    void LoadSalesReportPage();
/** @brief Holds true for negative values */
    void LoadMainPage();

private:
    /** @brief Holds true for negative values */
    Ui::SalesInformationSelectionPageCls * ui;
};

#endif // SALESINFORMATIONSELECTIONPAGECLS_H
