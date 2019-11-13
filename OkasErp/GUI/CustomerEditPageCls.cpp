#include "CustomerEditPageCls.h"
#include "ui_CustomerEditPageCls.h"

CustomerEditPageCls::CustomerEditPageCls(QWidget *parent) : QMainWindow(parent), ui(new Ui::CustomerEditPageCls)
{
    m_LoggerPtr->CreateTraceLog(Q_FUNC_INFO, " ");
    ui->setupUi(this);
    m_Model = new TableModelCls(ui->tableView);
    connect(ui->pushButtonReturn, SIGNAL(clicked()), this, SLOT(LoadCustomerProfilePage()));
    connect(ui->pushButtonDelete, SIGNAL(clicked()), this, SLOT(EraseSelected()));

    FillTable();

    this->setFixedSize(this->size().width(), this->size().height());
    this->setWindowTitle("MARISOFT");
}

void CustomerEditPageCls::LoadCustomerProfilePage(void)
{
    LoadPage(PageSelection_NewCustomerPage);
    delete this;
}

CustomerEditPageCls::~CustomerEditPageCls()
{
    delete ui;
}

void CustomerEditPageCls::FillTable(void)
{
    m_Model->setTable("customers");
    m_Model->select();
    m_Model->setEditStrategy(QSqlTableModel::OnFieldChange);

    ui->tableView->setModel(m_Model);

    QStringList Headers;
    Headers << "ID" << "Müşteri Adı"  << "Barkod Ön Eki" << "İş Emri Ön Eki" << "SOIR" << "Tarih Tipi";
    int Column = 0;
    foreach (QString header, Headers)
    {
       m_Model->setHeaderData(Column, Qt::Horizontal, header);
       Column++;
    }

    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->hideColumn(9);
}

void CustomerEditPageCls::EraseSelected(void)
{
    QList<int> RowList;

    RowList = m_Model->getCheckedRowList();

    foreach (int Row, RowList)
    {
        m_Model->removeRows(Row, 1);

        if( m_Model->submitAll() )
        {
            m_Model->database().commit();
        }
        else
        {
            m_Model->database().rollback();
        }
    }

    FillTable();
}
