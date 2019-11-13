#ifndef CUSTOMERSELECTIONPAGE_H
#define CUSTOMERSELECTIONPAGE_H

#include <QMainWindow>
#include "PageCls.h"
#include "RModel.h"

namespace Ui
{
    class CustomerSelectionPage;
}

/*! \class CustomerSelectionPage CustomerSelectionPage.h
 *
 *  Docs for MyClassName
 */
class CustomerSelectionPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT
public:
    /** @brief Holds true for negative values */
    explicit CustomerSelectionPageCls(QWidget * a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
    ~CustomerSelectionPageCls();
private slots:
    /** @brief Holds true for negative values */
    void SearchAndFilterTableview();
    /** @brief Holds true for negative values */
    void LoadMainPage();
    /** @brief Holds true for negative values */
    void SelectAllClicked();
    /** @brief Holds true for negative values */
    void ClearAllClicked();
    /** @brief Holds true for negative values */
    void LoadProductTrackingPage();
    /** @brief Holds true for negative values */
    void RowCheckHandle(int a_Row, bool a_State);

        void resizeEvent(QResizeEvent *event) override;
private:
    /** @brief Holds true for negative values */
    Ui::CustomerSelectionPage * ui;
    /** @brief Holds true for negative values */
    RModel * m_Model;
    /** @brief Holds true for negative values */
    void FillCustomerTable(void);
};

#endif // CUSTOMERSELECTIONPAGE_H
