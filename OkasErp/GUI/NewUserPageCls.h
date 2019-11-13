#ifndef NEWUSERPAGECLS_H
#define NEWUSERPAGECLS_H

#include <QMainWindow>
#include "PageCls.h"

namespace Ui {
class NewUserPageCls;
}

/*! \class NewUserPageCls NewUserPageCls.h
 *
 *  Docs for MyClassName
 */
class NewUserPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    explicit NewUserPageCls(QWidget * a_ParentPtr = nullptr);
    /** @brief Holds true for negative values */
    ~NewUserPageCls();

private slots:
/** @brief Holds true for negative values */
    void CreateUser();
/** @brief Holds true for negative values */
    void LoadSettingsPage();

private:
    /** @brief Holds true for negative values */
    Ui::NewUserPageCls * ui;
};

#endif // NEWUSERPAGECLS_H
