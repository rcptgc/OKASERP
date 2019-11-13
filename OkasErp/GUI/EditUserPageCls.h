#ifndef EDITUSERPAGECLS_H
#define EDITUSERPAGECLS_H

#include <QMainWindow>
#include "PageCls.h"

namespace Ui {
class EditUserPageCls;
}

/*! \class EditUserPageCls EditUserPageCls.h
 *
 *  Docs for MyClassName
 */
class EditUserPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    explicit EditUserPageCls(QWidget * a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
    ~EditUserPageCls();

private slots:
/** @brief Holds true for negative values */
    void LoadSettingsPage();
    /** @brief Holds true for negative values */
    void SaveChanges();
    /** @brief Holds true for negative values */
    void EraseSelected();
    /** @brief Holds true for negative values */
    void FillTable(QList<UserStc> a_UserList);
    /** @brief Holds true for negative values */
    void GetUserFromRow(int32_t a_Row, UserStc &a_User);

private:
    /** @brief Holds true for negative values */
    Ui::EditUserPageCls * ui;
};

#endif // EDITUSERPAGECLS_H
