#ifndef CUSTOMEREDITPAGECLS_H
#define CUSTOMEREDITPAGECLS_H

#include <QMainWindow>
#include "PageCls.h"
#include "TableModelCls.h"

namespace Ui {
class CustomerEditPageCls;
}

class CustomerEditPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    explicit CustomerEditPageCls(QWidget *parent = nullptr);
    ~CustomerEditPageCls();

private:
    Ui::CustomerEditPageCls *ui;
    TableModelCls * m_Model;

    void FillTable(void);


private slots:
    void LoadCustomerProfilePage(void);
    void EraseSelected(void);
};

#endif // CUSTOMEREDITPAGECLS_H
