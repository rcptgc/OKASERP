#include "CoatingProcessViewPageCls.h"
#include "ui_CoatingProcessViewPageCls.h"
#include "Utility/UtilsCls.h"

CoatingProcessViewPageCls::CoatingProcessViewPageCls(QWidget *parent) : QMainWindow(parent), ui(new Ui::CoatingProcessViewPageCls)
{
    m_DatabasePtr = DatabaseAccessCls::instance();

    QDate l_CurrentDate = QDate::currentDate();
    QTime l_CurentTime  = QTime::currentTime();

    ui->setupUi(this);

    ui->dateTimeEditEntry->setDate(l_CurrentDate);
    ui->dateTimeEditEntry->setTime(l_CurentTime);

    connect(ui->pushButtonShowLoad,     SIGNAL(clicked()),          this,   SLOT(ShowLoad()));
    connect(ui->pushButtonSaveFinish,   SIGNAL(clicked()),          this,   SLOT(SaveTankLog()));
    connect(ui->pushButtonReturn,       SIGNAL(clicked()),          this,   SLOT(LoadProductionEntryPage()));
    connect(ui->pushButtonEditLoad,     SIGNAL(clicked()),          this,   SLOT(LoadEditLoadPage()));
    connect(ui->pushButtonNewLoad,      SIGNAL(clicked()),          this,   SLOT(LoadCreateLoadPage()));
}

void CoatingProcessViewPageCls::SaveTankLog(void)
{

    QList<TankCls> l_TankList;
    l_TankList = m_Finish.m_TankList;

    QString l_TankNoStr;
    QString l_TankNameStr;
    QString l_TimeMinRangeStr;
    QString l_TimeMinResultStr;
    QString l_TempRangeStr;
    QString l_TempResultStr;
    QString l_VoltageRangeStr;
    QString l_VoltageResultStr;
    QString l_DateStr;
    QString l_TimeStr;
    int32_t l_intRowNumber = 0;
    QString l_EmployeeNameStr;

    QString l_LogDateStr;
    QString l_LogTimeStr;

    m_Load.m_ulnFinishIDStr = m_Finish.m_FinishNoStr;

    if (false == m_DatabasePtr->GetTankLog(m_Load))
    {
        m_Load.m_TankList.clear();

        foreach (TankCls l_Tank, l_TankList)
        {
            l_TankNoStr         = ui->FinishTable->item(l_intRowNumber, 0)->data(Qt::DisplayRole).toString();
            l_TankNameStr       = ui->FinishTable->item(l_intRowNumber, 1)->data(Qt::DisplayRole).toString();
            l_TimeMinRangeStr   = ui->FinishTable->item(l_intRowNumber, 2)->data(Qt::DisplayRole).toString();
            l_TimeMinResultStr  = ui->FinishTable->item(l_intRowNumber, 3)->data(Qt::DisplayRole).toString();
            l_TempRangeStr      = ui->FinishTable->item(l_intRowNumber, 4)->data(Qt::DisplayRole).toString();
            l_TempResultStr     = ui->FinishTable->item(l_intRowNumber, 5)->data(Qt::DisplayRole).toString();
            l_VoltageRangeStr   = ui->FinishTable->item(l_intRowNumber, 6)->data(Qt::DisplayRole).toString();
            l_VoltageResultStr  = ui->FinishTable->item(l_intRowNumber, 7)->data(Qt::DisplayRole).toString();

            l_LogDateStr = UtilsCls::GetDateString(ui->dateTimeEditEntry->date());

            l_LogTimeStr = UtilsCls::GetTimeString(ui->dateTimeEditEntry->time());

            l_EmployeeNameStr = ui->lineEditOperatorName->text();

            l_Tank.m_ulnFinishIDStr = m_Finish.m_FinishNoStr;
            l_Tank.m_LoadIDStr = m_Load.m_LoadIDStr;
            l_Tank.m_TankNameStr = l_TankNameStr;
            l_Tank.m_TankNoStr = l_TankNoStr;
            l_Tank.m_TemperatureResultStr = l_TempResultStr;
            l_Tank.m_TimeMinResultStr = l_TimeMinResultStr;
            l_Tank.m_VoltageResultStr = l_VoltageResultStr;
            l_Tank.m_DateStr = l_LogDateStr;
            l_Tank.m_TimeStr = l_LogTimeStr;
            l_Tank.m_EmployeeNameStr = l_EmployeeNameStr;

            m_Load.m_TankList.append(l_Tank);

            l_intRowNumber++;
        }

        m_DatabasePtr->AddTankLog(m_Load);
    }
    else
    {
        for (int32_t l_intRowCtr = 0; l_intRowCtr < ui->FinishTable->rowCount(); l_intRowCtr++)
        {
            TankCls l_Tank;
            l_TankNoStr         = ui->FinishTable->item(l_intRowCtr, 0)->data(Qt::DisplayRole).toString();
            l_TankNameStr       = ui->FinishTable->item(l_intRowCtr, 1)->data(Qt::DisplayRole).toString();
            l_TimeMinRangeStr   = ui->FinishTable->item(l_intRowCtr, 2)->data(Qt::DisplayRole).toString();
            l_TimeMinResultStr  = ui->FinishTable->item(l_intRowCtr, 3)->data(Qt::DisplayRole).toString();
            l_TempRangeStr      = ui->FinishTable->item(l_intRowCtr, 4)->data(Qt::DisplayRole).toString();
            l_TempResultStr     = ui->FinishTable->item(l_intRowCtr, 5)->data(Qt::DisplayRole).toString();
            l_VoltageRangeStr   = ui->FinishTable->item(l_intRowCtr, 6)->data(Qt::DisplayRole).toString();
            l_VoltageResultStr  = ui->FinishTable->item(l_intRowCtr, 7)->data(Qt::DisplayRole).toString();
            l_LogDateStr = UtilsCls::GetDateString(ui->dateTimeEditEntry->date());

            l_LogTimeStr = UtilsCls::GetTimeString(ui->dateTimeEditEntry->time());
            l_EmployeeNameStr = ui->lineEditOperatorName->text();

            l_Tank.m_ulnFinishIDStr = m_Finish.m_FinishNoStr;
            l_Tank.m_LoadIDStr = m_Load.m_LoadIDStr;
            l_Tank.m_TankNameStr = l_TankNameStr;
            l_Tank.m_TankNoStr = l_TankNoStr;
            l_Tank.m_TemperatureResultStr = l_TempResultStr;
            l_Tank.m_TimeMinResultStr = l_TimeMinResultStr;
            l_Tank.m_VoltageResultStr = l_VoltageResultStr;
            l_Tank.m_DateStr = l_LogDateStr;
            l_Tank.m_TimeStr = l_LogTimeStr;
            l_Tank.m_EmployeeNameStr = l_EmployeeNameStr;

            m_DatabasePtr->UpdateTankLog(l_Tank, l_TankNoStr, m_Load.m_LoadIDStr);
        }
    }

}

void CoatingProcessViewPageCls::ShowFinish(void)
{


}

void CoatingProcessViewPageCls::ShowLoad(void)
{
    QString l_LoadIDStr = ui->lineEditLoadNo->text();

    bool l_blnSuccess = m_DatabasePtr->GetLoad(m_Load, l_LoadIDStr);

    if (true == l_blnSuccess)
    {
        ui->lineEditFinishCode->setText(m_Load.m_ulnFinishIDStr);

        QMap<OrderCls, uint32_t> l_OrderList;

        l_OrderList = m_Load.m_OrderList;

        ui->LoadContentTable->clear();

        ui->LoadContentTable->setColumnCount(6);
        ui->LoadContentTable->setRowCount(0);

        ui->LoadContentTable->setRowCount(l_OrderList.size());

        QStringList l_Headers;
        l_Headers << "BARKOD" << "GKR NO" << "İŞ EMRİ" << "PARÇA NO" << "ADET" << " " << " ";

        QMap<OrderCls, uint32_t>::const_iterator i = l_OrderList.constBegin();

        int l_intRowNumber = 0;

        while (i != l_OrderList.constEnd())
        {
            ui->LoadContentTable->setItem(l_intRowNumber, 0, new QTableWidgetItem(i.key().m_BarcodeNumStr));
            ui->LoadContentTable->setItem(l_intRowNumber, 1, new QTableWidgetItem(i.key().m_GKRNumStr));
            ui->LoadContentTable->setItem(l_intRowNumber, 2, new QTableWidgetItem(i.key().m_SOWNumStr));
            ui->LoadContentTable->setItem(l_intRowNumber, 3, new QTableWidgetItem(i.key().m_PartNumStr));
            ui->LoadContentTable->setItem(l_intRowNumber, 4, new QTableWidgetItem(QString::number(i.value())));

            ++i;
            l_intRowNumber++;
        }

        ui->LoadContentTable->hideColumn(5);
        ui->LoadContentTable->setHorizontalHeaderLabels(l_Headers);
        ui->LoadContentTable->m_CheckedRowsList.clear();
        ui->LoadContentTable->show();
        m_blnIsLoadVisible = true;
        m_Load.m_OrderList.clear();
    }


    l_blnSuccess = m_DatabasePtr->GetCoatingFinish(m_Load.m_ulnFinishIDStr, m_Finish);

    QList<TankCls> l_LoadTankList;

    ui->FinishTable->clear();

    ui->FinishTable->setColumnCount(11);
    ui->FinishTable->setRowCount(0);

    ui->FinishTable->setRowCount(m_Finish.m_TankList.size());

    if (true == l_blnSuccess)
    {
        if (true == l_blnSuccess)
        {
            ui->lineEditFinishName->setText(m_Finish.m_FinishNameStr);
            int32_t l_intRowNumber = 0;
            QList<TankCls> l_TankList;
            l_TankList = m_Finish.m_TankList;

            QStringList l_Headers;

            l_Headers << "Tank No" << "Tank Name" << "Imm. Time Range" << "Imm. Time Result"
                      << "Temp Range" << "Temp Result " << "Voltage Range" << "Voltage Result" << "Tarih" << "Saat" << "Çalışan Adı" << " ";

            ui->lineEditOperatorName->setText(l_TankList.at(0).m_EmployeeNameStr);
            TankCls l_TankLog;
            foreach (TankCls l_Tank, l_TankList)
            {
                m_DatabasePtr->GetTankLog(l_TankLog, l_Tank.m_TankNoStr, m_Load.m_LoadIDStr);

                ui->FinishTable->setItem(l_intRowNumber, 0, new QTableWidgetItem(l_Tank.m_TankNoStr));
                ui->FinishTable->setItem(l_intRowNumber, 1, new QTableWidgetItem(l_Tank.m_TankNameStr));
                ui->FinishTable->setItem(l_intRowNumber, 2, new QTableWidgetItem(l_Tank.m_TimeMinRangeStr));
                ui->FinishTable->setItem(l_intRowNumber, 3, new QTableWidgetItem(l_TankLog.m_TimeMinResultStr));
                ui->FinishTable->setItem(l_intRowNumber, 4, new QTableWidgetItem(l_Tank.m_TemperatureRangeStr));
                ui->FinishTable->setItem(l_intRowNumber, 5, new QTableWidgetItem(l_TankLog.m_TemperatureResultStr));
                ui->FinishTable->setItem(l_intRowNumber, 6, new QTableWidgetItem(l_Tank.m_VoltageRangeStr));
                ui->FinishTable->setItem(l_intRowNumber, 7, new QTableWidgetItem(l_TankLog.m_VoltageResultStr));
                ui->FinishTable->setItem(l_intRowNumber, 8, new QTableWidgetItem(l_TankLog.m_DateStr));
                ui->FinishTable->setItem(l_intRowNumber, 9, new QTableWidgetItem(l_TankLog.m_TimeStr));
                ui->FinishTable->setItem(l_intRowNumber, 10, new QTableWidgetItem(l_TankLog.m_EmployeeNameStr));

                l_intRowNumber++;
            }

            m_blnIsFinishVisible = true;
        }
    }
}

CoatingProcessViewPageCls::~CoatingProcessViewPageCls()
{
    delete ui;
}

void CoatingProcessViewPageCls::LoadProductionEntryPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_ProductionEntryPage);

    this->hide();
}

void CoatingProcessViewPageCls::LoadEditLoadPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_EditLoadPage);

    this->hide();
}

void CoatingProcessViewPageCls::LoadCreateLoadPage()
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    m_LoggerPtr->CreateUserLog(m_UserPtr, Q_FUNC_INFO, " ");

    LoadPage(PageSelection_CreateLoadPage);

    this->hide();
}
