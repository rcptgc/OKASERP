#ifndef QUALITYPROCESSVIEWPAGECLS_H
#define QUALITYPROCESSVIEWPAGECLS_H

#include <QMainWindow>
#include "LoadCls.h"
#include "FinishCls.h"
#include "PageCls.h"

namespace Ui {
class QualityProcessViewPageCls;
}

class QualityProcessViewPageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    explicit QualityProcessViewPageCls(QWidget *parent = nullptr);
    ~QualityProcessViewPageCls();

private:
    Ui::QualityProcessViewPageCls *ui;

    LoadStc m_Load;
    CoatingFinishStc m_Finish;

    bool m_blnIsFinishVisible = false;
    bool m_blnIsLoadVisible = false;

    void FillTable(void);

private slots:
    void ShowLoad(void);
    void ShowFinish(void);
    void SaveQualityLog(void);

    void LoadProductionEntryPage();
    void LoadEditLoadPage();
    void LoadCreateLoadPage();
};

#endif // QUALITYPROCESSVIEWPAGECLS_H
