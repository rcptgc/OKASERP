#include "CreateCoatFinishCls.h"
#include "ui_CreateCoatFinishCls.h"

CreateCoatFinishCls::CreateCoatFinishCls(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateCoatFinishCls)
{
    ui->setupUi(this);
}

CreateCoatFinishCls::~CreateCoatFinishCls()
{
    delete ui;
}
