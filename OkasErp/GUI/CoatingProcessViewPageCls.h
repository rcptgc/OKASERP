#ifndef PROCESSVIEWPAGECLS_H
#define PROCESSVIEWPAGECLS_H

#include <QMainWindow>
#include "GUI/PageCls.h"
#include "LoadCls.h"
#include "FinishCls.h"

namespace Ui {
class CoatingProcessViewPageCls;
}

class CoatingProcessViewPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    explicit CoatingProcessViewPageCls(QWidget *parent = nullptr);
    ~CoatingProcessViewPageCls();

private:
    Ui::CoatingProcessViewPageCls *ui;

    LoadStc m_Load;
    CoatingFinishStc m_Finish;

    bool m_blnIsFinishVisible = false;
    bool m_blnIsLoadVisible = false;

    void FillTable(void);

private slots:
    void ShowLoad(void);
    void ShowFinish(void);
    void SaveTankLog(void);

    void LoadProductionEntryPage();
    void LoadEditLoadPage();
    void LoadCreateLoadPage();
};

#endif // PROCESSVIEWPAGECLS_H
