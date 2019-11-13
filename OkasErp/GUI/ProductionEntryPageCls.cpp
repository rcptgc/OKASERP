#include "ProductionEntryPageCls.h"
#include "ui_ProductionEntryPageCls.h"

ProductionEntryPageCls::ProductionEntryPageCls(QWidget *parent) : QMainWindow(parent), ui(new Ui::ProductionEntryPageCls)
{
    ui->setupUi(this);

    connect(ui->pushButtonReturn,   SIGNAL(clicked()),          this, SLOT(LoadProductionPage()));
    connect(ui->pushButtonSave,     SIGNAL(clicked()),          this, SLOT(SaveEntry()));
    connect(ui->lineEditBarcode,    SIGNAL(returnPressed()),    this, SLOT(BarcodeRead()));
    connect(ui->pushButtonProcess,  SIGNAL(clicked()),          this, SLOT(LoadProcessPage()));

    QDate l_CurrentDate = QDate::currentDate();
    QTime l_CurrentTime = QTime::currentTime();

    ui->dateTimeEditEntry->setDate(l_CurrentDate);
    ui->dateTimeEditEntry->setTime(l_CurrentTime);



    m_DatabasePtr->GetOperations(m_OrderLog.m_OperationMap);

    QMapIterator<uint32_t, QString> i(m_OrderLog.m_OperationMap);

    while (i.hasNext())
    {
        i.next();
        ui->comboBox->addItem(i.value());
    }

    ui->groupBox_3->setVisible(false);
    ui->pushButtonProcess->setVisible(false);
}

ProductionEntryPageCls::~ProductionEntryPageCls()
{
    delete ui;
}

void ProductionEntryPageCls::LoadProductionPage()
{
    m_LoggerPtr->CreateTraceLog("ProductionEntryPageCls::LoadProductionPage()", " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, "ProductionEntryPageCls::LoadProductionPage()", " ");

    LoadPage(PageSelection_ProductionPage);
    delete this;
}

void ProductionEntryPageCls::BarcodeRead()
{
    OrderCls l_Order;
    QString l_BarcodeStr = ui->lineEditBarcode->text();

    bool l_blnIsOrderFound = m_DatabasePtr->GetOrder(l_Order, l_BarcodeStr);

    if (true == l_blnIsOrderFound)
    {
        ui->lineEditGKR->setText(l_Order.m_GKRNumStr);
        ui->lineEditReceivedQuantity->setText(QString::number(l_Order.m_ulnRcvdQty));
    }
    else
    {
        m_LoggerPtr->DisplayInformation("Sipariş Bulunamadı!", this);
    }

}

void ProductionEntryPageCls::SaveEntry()
{
    OrderCls l_Order;
    QDate l_Date;
    QTime l_Time;

    QString l_BarcodeStr = ui->lineEditBarcode->text();

    bool l_blnIsOrderFound = m_DatabasePtr->GetOrder(l_Order, l_BarcodeStr);

    if (true == l_blnIsOrderFound)
    {
        if ( (ui->radioButtonStartTime->isChecked() == true) ||
             (ui->radioButton_2->isChecked() == true) )
        {
            l_Date = ui->dateTimeEditEntry->date();
            l_Time = ui->dateTimeEditEntry->time();
        }
        else
        {
            m_LoggerPtr->DisplayInformation("Zaman Seçimi Yapılmadı", this);
            return;
        }
        LogDateTypeEnum enmDateType = (ui->radioButtonStartTime->isChecked() == true) ? LogDateType_Start : LogDateType_Finish;
        m_OrderLog.m_enmDateType = enmDateType;
        m_OrderLog.m_Date = l_Date;
        m_OrderLog.m_Time = l_Time;

        m_OrderLog.m_NotesStr = ui->textEditNotes->toPlainText();

        QString l_OperationStr = ui->comboBox->currentText();
        OperationStc l_Operation;
        l_Operation.m_NameStr = ui->comboBox->currentText();
        l_Operation.m_ulnID = m_OrderLog.m_OperationMap.key(ui->comboBox->currentText());
        m_OrderLog.m_Operation = l_Operation;

        if (true == ui->lineEditOperatorName->text().isEmpty())
        {
            m_LoggerPtr->DisplayInformation("ÇALIŞAN ADI BOŞ OLAMAZ", this);
            return;
        }
        else
        {
            QString l_OperatorNameStr = ui->lineEditOperatorName->text();
            m_OrderLog.m_OperatorNameStr = l_OperatorNameStr;
        }

        m_OrderLog.m_ulnOrderID = l_Order.m_ulnID;
        m_OrderLog.m_ulnReceivedQuantity = l_Order.m_ulnRcvdQty;

        if (true == ui->lineEditProcessedQuantity->text().isEmpty())
        {
            m_LoggerPtr->DisplayInformation("MİKTAR BOŞ OLAMAZ", this);
            return;
        }
        else
        {
            uint32_t l_ulnProcessedQuantity = ui->lineEditProcessedQuantity->text().toUInt();
            m_OrderLog.m_ulnProcessedQuantity = l_ulnProcessedQuantity;
        }

        m_DatabasePtr->AddOrderLog(m_OrderLog);

        m_LoggerPtr->DisplayInformation("KAYIT YAPILDI", this);
        ui->lineEditBarcode->setText("");
        ui->lineEditGKR->setText("");
        ui->lineEditOperatorName->setText("");
        ui->lineEditProcessedQuantity->setText("");
        ui->lineEditReceivedQuantity->setText("");
        ui->textEditNotes->setText("");

    }
    else
    {
        m_LoggerPtr->DisplayInformation("Sipariş Bulunamadı!", this);
    }

}

void ProductionEntryPageCls::LoadProcessPage()
{

    if (ui->radioButtonCoating->isChecked() == true)
    {
        LoadPage(PageSelection_ProcessViewCoatingPage);
    }
    else if (ui->radioButtonPaintApp->isChecked() == true)
    {
        LoadPage(PageSelection_ProcessViewPaintAppPage);
    }
    else if (ui->radioButtonPrePaint->isChecked() == true)
    {
        LoadPage(PageSalection_ProcessViewPrePaintPage);
    }
    else if (ui->radioButtonQuality->isChecked() == true)
    {
        LoadPage(PageSelection_ProcessViewQualityPage);
    }
    else
    {
        m_LoggerPtr->DisplayInformation("FINISH TURU SECILMEDI!", this);
    }

    delete this;
}
