#include "CustomerEditPageCls.h"
#include "ui_CustomerEditPageCls.h"

CustomerEditPageCls::CustomerEditPageCls(QWidget *parent) : QMainWindow(parent), ui(new Ui::CustomerEditPageCls)
{
    ui->setupUi(this);
}

CustomerEditPageCls::~CustomerEditPageCls()
{
    delete ui;
}
