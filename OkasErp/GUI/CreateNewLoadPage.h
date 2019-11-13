#ifndef CREATENEWLOADPAGE_H
#define CREATENEWLOADPAGE_H

#include <QMainWindow>
#include "PageCls.h"
#include "LoadCls.h"

namespace Ui {
class CreateNewLoadPage;
}

class CreateNewLoadPage : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    explicit CreateNewLoadPage(QWidget *parent = nullptr);
    ~CreateNewLoadPage();

private:
    Ui::CreateNewLoadPage *ui;

    LoadStc m_Load;
private slots:
    void FillTable();
    void GetOrder(void);
    void DeleteOrder(void);
    void AddOrderToBatch(void);
    void LoadProcessPage();
    void CreateLoad();

};

#endif // CREATENEWLOADPAGE_H
