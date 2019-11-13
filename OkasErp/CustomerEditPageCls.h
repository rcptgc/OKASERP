#ifndef CUSTOMEREDITPAGECLS_H
#define CUSTOMEREDITPAGECLS_H

#include <QMainWindow>
#include "PageCls.h"

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
};

#endif // CUSTOMEREDITPAGECLS_H
