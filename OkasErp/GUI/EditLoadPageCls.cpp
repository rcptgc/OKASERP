#include "EditLoadPageCls.h"
#include "ui_EditLoadPageCls.h"

EditLoadPageCls::EditLoadPageCls(QWidget *parent) : QMainWindow(parent), ui(new Ui::EditLoadPageCls)
{
    ui->setupUi(this);

    connect(ui->lineEditBarcode,        SIGNAL(returnPressed()),    this,   SLOT(GetOrder()));
    connect(ui->pushButtonAdd,          SIGNAL(clicked()),          this,   SLOT(AddOrderToBatch()));
    connect(ui->pushButtonDelete,       SIGNAL(clicked()),          this,   SLOT(DeleteOrder()));
    connect(ui->pushButtonSave,         SIGNAL(clicked()),          this,   SLOT(UpdateLoad()));
    connect(ui->pushButtonShowLoad,     SIGNAL(clicked()),          this,   SLOT(ShowLoad()));
    connect(ui->pushButtonReturn,       SIGNAL(clicked()),          this,   SLOT(LoadProcessPage()));
}

void EditLoadPageCls::ShowLoad()
{
    QString l_LoadIDStr = ui->lineEditLoadNo->text();

    bool l_blnSuccess = m_DatabasePtr->GetLoad(m_Load, l_LoadIDStr);

    if (true == l_blnSuccess)
    {
        QMap<OrderCls, uint32_t> l_OrderList;

        l_OrderList = m_Load.m_OrderList;

        ui->LoadTable->clear();

        ui->LoadTable->setColumnCount(6);
        ui->LoadTable->setRowCount(0);

        ui->LoadTable->setRowCount(l_OrderList.size());

        QStringList l_Headers;
        l_Headers << "BARKOD" << "GKR NO" << "İŞ EMRİ" << "PARÇA NO" << "ADET" << " " << " ";
        QMap<OrderCls, uint32_t>::const_iterator i = l_OrderList.constBegin();

        int l_intRowNumber = 0;

        while (i != l_OrderList.constEnd())
        {
            ui->LoadTable->setItem(l_intRowNumber, 0, new QTableWidgetItem(i.key().m_BarcodeNumStr));
            ui->LoadTable->setItem(l_intRowNumber, 1, new QTableWidgetItem(i.key().m_GKRNumStr));
            ui->LoadTable->setItem(l_intRowNumber, 2, new QTableWidgetItem(i.key().m_SOWNumStr));
            ui->LoadTable->setItem(l_intRowNumber, 3, new QTableWidgetItem(i.key().m_PartNumStr));
            ui->LoadTable->setItem(l_intRowNumber, 4, new QTableWidgetItem(QString::number(i.value())));

            ++i;
            l_intRowNumber++;
        }

        ui->LoadTable->hideColumn(5);
        ui->LoadTable->setHorizontalHeaderLabels(l_Headers);
        ui->LoadTable->m_CheckedRowsList.clear();
        ui->LoadTable->show();
    }
    else
    {
        ui->LoadTable->setRowCount(0);
    }
}

void EditLoadPageCls::FillTable()
{
    QMap<OrderCls, uint32_t> l_OrderList;

    l_OrderList = m_Load.m_OrderList;

    ui->LoadTable->clear();

    ui->LoadTable->setColumnCount(6);
    ui->LoadTable->setRowCount(0);

    ui->LoadTable->setRowCount(l_OrderList.size());

    QStringList l_Headers;

    l_Headers << "BARKOD" << "GKR NO" << "İŞ EMRİ" << "PARÇA NO" << "ADET" << " " << " ";

    QMap<OrderCls, uint32_t>::const_iterator i = l_OrderList.constBegin();

    int l_intRowNumber = 0;

    while (i != l_OrderList.constEnd())
    {
        ui->LoadTable->setItem(l_intRowNumber, 0, new QTableWidgetItem(i.key().m_BarcodeNumStr));
        ui->LoadTable->setItem(l_intRowNumber, 1, new QTableWidgetItem(i.key().m_GKRNumStr));
        ui->LoadTable->setItem(l_intRowNumber, 2, new QTableWidgetItem(i.key().m_SOWNumStr));
        ui->LoadTable->setItem(l_intRowNumber, 3, new QTableWidgetItem(i.key().m_PartNumStr));
        ui->LoadTable->setItem(l_intRowNumber, 4, new QTableWidgetItem(QString::number(i.value())));

        ++i;
        l_intRowNumber++;
    }

    ui->LoadTable->hideColumn(5);
    ui->LoadTable->setHorizontalHeaderLabels(l_Headers);
    ui->LoadTable->m_CheckedRowsList.clear();
    ui->LoadTable->show();
}

void EditLoadPageCls::UpdateLoad(void)
{
    bool l_blnSuccess = false;

    QString l_LoadIDStr = ui->lineEditLoadNo->text();

    // if load is displayed
    if (ui->LoadTable->rowCount() > 0)
    {
        m_DatabasePtr->RemoveLoad(l_LoadIDStr);
        l_blnSuccess = m_DatabasePtr->AddLoad(m_Load, l_LoadIDStr, false);

        if (l_blnSuccess == true)
        {
            m_LoggerPtr->DisplayInformation("Kaydedildi", this);
        }
        else
        {
            m_LoggerPtr->DisplayInformation("Kayıt Başarısız", this);
        }
    }
}

EditLoadPageCls::~EditLoadPageCls()
{
    delete ui;
}

void EditLoadPageCls::GetOrder(void)
{
    OrderCls l_Order;
    QString l_BarcodeStr = ui->lineEditBarcode->text();
    QString l_GRKNumberStr;
    QString l_PartNumberStr;
    QString l_ProcessedQuantityStr;
    QString l_SowNumberStr;

    bool l_blnIsOrderFound = m_DatabasePtr->GetOrder(l_Order, l_BarcodeStr);

    if (true == l_blnIsOrderFound)
    {
        ui->lineEditGKR->setText(l_Order.m_GKRNumStr);
        ui->lineEditProductNumber->setText(l_Order.m_PartNumStr);
        ui->lineEditSowNumber->setText(l_Order.m_SOWNumStr);
    }
    else
    {
        m_LoggerPtr->DisplayInformation("Barkod Bulunamadı!", this);
    }
}

void EditLoadPageCls::DeleteOrder(void)
{
    QMap<OrderCls, uint32_t> l_OrderList;
    l_OrderList = m_Load.m_OrderList;

    QTableWidgetItem * l_ItemPtr;

    OrderCls l_Order;

    foreach (const int32_t &l_intRow, ui->LoadTable->m_CheckedRowsList)
    {
        l_ItemPtr = ui->LoadTable->item(l_intRow, 0);
        m_DatabasePtr->GetOrder(l_Order, l_ItemPtr->text());
        m_Load.m_OrderList.remove(l_Order);
    }

    FillTable();
}

void EditLoadPageCls::AddOrderToBatch(void)
{
    QString l_BarcodeStr = ui->lineEditBarcode->text();
    OrderCls l_Order;

    if (false == ui->lineEditBarcode->text().isEmpty())
    {
        if (false == ui->lineEditProcessedQuantity->text().isEmpty())
        {
            m_DatabasePtr->GetOrder(l_Order, l_BarcodeStr);

            uint32_t l_ulnProcessedQuantity = ui->lineEditProcessedQuantity->text().toUInt();
            m_Load.m_OrderList[l_Order] = l_ulnProcessedQuantity;

            FillTable();

            ui->lineEditBarcode->clear();
            ui->lineEditGKR->clear();
            ui->lineEditProcessedQuantity->clear();
            ui->lineEditProductNumber->clear();
            ui->lineEditSowNumber->clear();
        }
        else
        {
            m_LoggerPtr->DisplayInformation("İşlenen Miktar Boş Olamaz!", this);
        }
    }
    else
    {
        m_LoggerPtr->DisplayInformation("Barkod Numarası Boş Olamaz!", this);
    }
}

void EditLoadPageCls::LoadProcessPage()
{
    LoadPage(PageSelection_ProcessViewCoatingPage);
    delete this;
}
