#ifndef ProductionPageCls_H
#define ProductionPageCls_H

#include <QMainWindow>
#include "PageCls.h"

namespace Ui
{
    class ProductionPageCls;
}

/*! \class ProductionPageCls ProductionPageCls.h
 *
 *  Docs for MyClassName
 */
class ProductionPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    explicit ProductionPageCls(QWidget * a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
    ~ProductionPageCls();

private slots:
/** @brief Holds true for negative values */
    void LoadProductTrackPage();
/** @brief Holds true for negative values */
    void LoadBrandingPage();
/** @brief Holds true for negative values */
    void LoadMainPage();
/** @brief Holds true for negative values */
    void LoadProductionEntryPage();

private:
    /** @brief Holds true for negative values */
    Ui::ProductionPageCls * ui;
};

#endif // ProductionPageCls_H
