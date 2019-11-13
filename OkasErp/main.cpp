#include "GUI\LoginPageCls.h"
#include <QApplication>
#include <QDebug>

#include "Utility/LoggerCls.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginPageCls w;
    w.show();
    return a.exec();
}


