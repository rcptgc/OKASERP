#ifndef PREPAINTPROCESSVIEWCLS_H
#define PREPAINTPROCESSVIEWCLS_H

#include <QMainWindow>
#include <LoadCls.h>
#include <FinishCls.h>
#include "PageCls.h"

namespace Ui {
class PrePaintProcessViewCls;
}

class PrePaintProcessViewCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    explicit PrePaintProcessViewCls(QWidget *parent = nullptr);
    ~PrePaintProcessViewCls();

private:
    Ui::PrePaintProcessViewCls *ui;

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

#endif // PREPAINTPROCESSVIEWCLS_H
