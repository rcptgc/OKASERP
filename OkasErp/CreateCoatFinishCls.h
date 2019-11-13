#ifndef CREATECOATFINISHCLS_H
#define CREATECOATFINISHCLS_H

#include <QMainWindow>

namespace Ui {
class CreateCoatFinishCls;
}

class CreateCoatFinishCls : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateCoatFinishCls(QWidget *parent = nullptr);
    ~CreateCoatFinishCls();

private:
    Ui::CreateCoatFinishCls *ui;
};

#endif // CREATECOATFINISHCLS_H
