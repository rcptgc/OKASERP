#ifndef PRODUCTIMAGEPAGECLS_H
#define PRODUCTIMAGEPAGECLS_H

#include <QMainWindow>
#include "PageCls.h"

namespace Ui {
class ProductImagePageCls;
}

/*! \class ProductImagePageCls ProductImagePageCls.h
 *
 *  Docs for MyClassName
 */
class ProductImagePageCls : public QMainWindow, public PageCls
{
    Q_OBJECT

public:
    /** @brief Holds true for negative values */
    explicit ProductImagePageCls(QWidget * a_ParentPtr = nullptr, QString a_BarcodeNumberStr = QString());
    /** @brief Holds true for negative values */
    ~ProductImagePageCls();

private slots:
/** @brief Holds true for negative values */
    void LoadBrandingPage();
private:
    /** @brief Holds true for negative values */
    Ui::ProductImagePageCls * ui;

    QString m_BarcodeStr;
};

#endif // PRODUCTIMAGEPAGECLS_H
