#ifndef CREATELOADPAGECLS_H
#define CREATELOADPAGECLS_H

#include <QMainWindow>
#include "GUI/PageCls.h"
#include "OrderCls.h"


namespace Ui {
class EditLoadPageCls;
}

class EditLoadPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    explicit EditLoadPageCls(QWidget *parent = nullptr);
    ~EditLoadPageCls();

private:
    Ui::EditLoadPageCls *ui;

    LoadStc m_Load;



private slots:
    void LoadProcessPage();

    void AddOrderToBatch(void);

    void GetOrder(void);

    void DeleteOrder(void);

    void FillTable();

    void UpdateLoad(void);

    void ShowLoad(void);


};

#endif // CREATELOADPAGECLS_H
