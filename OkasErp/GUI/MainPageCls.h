#ifndef MAINPAGECLS_H
#define MAINPAGECLS_H

#include <QMainWindow>
#include "PageCls.h"

namespace Ui
{
    class MainPageCls;
}

/*! \class MainPageCls MainPageCls.h
 *
 *  Docs for MyClassName
 */
class MainPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    explicit MainPageCls(QWidget * a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
    ~MainPageCls();

private slots:
/** @brief Holds true for negative values */
    void LoadProductionPage(void);
    /** @brief Holds true for negative values */
    void LoadLoginPage(void);
    /** @brief Holds true for negative values */
    void LoadSettingsPage(void);
    /** @brief Holds true for negative values */
    void LoadSalesInformationPage(void);
    /** @brief Holds true for negative values */
    void LoadCustomerProfilePage(void);

private:
    /** @brief Holds true for negative values */
    Ui::MainPageCls * ui;
};

#endif // MAINPAGECLS_H
