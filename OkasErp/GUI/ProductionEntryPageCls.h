#ifndef PRODUCTIONENTRYPAGECLS_H
#define PRODUCTIONENTRYPAGECLS_H

#include <QMainWindow>

#include "PageCls.h"

namespace Ui {
class ProductionEntryPageCls;
}

class ProductionEntryPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    explicit ProductionEntryPageCls(QWidget *parent = nullptr);
    ~ProductionEntryPageCls();

private slots:
    void BarcodeRead();
    void LoadProductionPage();
    void SaveEntry();

private slots:
    void LoadProcessPage();
private:
    Ui::ProductionEntryPageCls *ui;
        OrderLogStc m_OrderLog;
};

#endif // PRODUCTIONENTRYPAGECLS_H
