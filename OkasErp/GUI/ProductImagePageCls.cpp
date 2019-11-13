#include "ProductImagePageCls.h"
#include "ui_ProductImagePageCls.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "CustomerCls.h"

ProductImagePageCls::ProductImagePageCls(QWidget * a_ParentPtr, QString a_BarcodeNumberStr) : QMainWindow(a_ParentPtr), ui(new Ui::ProductImagePageCls)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    m_DatabasePtr = DatabaseAccessCls::instance();

    ui->setupUi(this);
    OrderCls l_Order;

    m_BarcodeStr = a_BarcodeNumberStr;

    if (m_BarcodeStr.isEmpty() == false)
    {
        bool l_blnIsFound = m_DatabasePtr->GetOrder(l_Order, m_BarcodeStr);

        if (true == l_blnIsFound)
        {
            m_DatabasePtr->GetImagesPath(m_ImagesPathStr);

            QGraphicsScene * l_ScenePtr = new QGraphicsScene();

            ui->graphicsView->setScene(l_ScenePtr);

            m_ImagesPathStr = m_ImagesPathStr + "/" + l_Order.m_PartNumStr+ ".jpg";

            QPixmap l_Image = QPixmap(m_ImagesPathStr);

            l_Image = l_Image.scaled(ui->graphicsView->width(), ui->graphicsView->height(), Qt::IgnoreAspectRatio, Qt::FastTransformation);

            QGraphicsPixmapItem * l_Item = new QGraphicsPixmapItem(l_Image);

            l_ScenePtr->addItem(l_Item);

            ui->graphicsView->show();

            this->setFixedSize(this->size().width(), this->size().height());
            this->setWindowTitle("MARISOFT");
        }
        else
        {
            m_LoggerPtr->DisplayInformation("Barkod Bulunamadı!", this);
        }
    }
    else
    {
        m_LoggerPtr->DisplayInformation("Barkod Bulunamadı!", this);
    }

    connect(ui->pushButtonReturn, SIGNAL(clicked()) , this, SLOT(LoadBrandingPage()));
}

ProductImagePageCls::~ProductImagePageCls()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    delete ui;
}

void ProductImagePageCls::LoadBrandingPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_BrandingPage, nullptr, m_BarcodeStr);

    delete this;
}
