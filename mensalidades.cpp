#include "mensalidades.h"
#include "ui_mensalidades.h"
#include "administrativo.h"
#include "financeiro.h"
#include "fm_principal.h"

#include <QtSql>
#include <QMessageBox>

Mensalidades::Mensalidades(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mensalidades)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from tb_alunos");

    QString modalidade = "Extensivo";
    QString modalidade2 = "Intensivo";
    QString modalidade3 = "Medicina";

    if (query.exec("select * from tb_alunos where turmaAluno='"+modalidade+"'"))
    {
        int cont=0;
        ui->tw_extensivo->setColumnCount(4);
        while(query.next())
        {
            ui->tw_extensivo->insertRow(cont);
            ui->tw_extensivo->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tw_extensivo->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tw_extensivo->setItem(cont, 2, new QTableWidgetItem(query.value(6).toString()));
            ui->tw_extensivo->setItem(cont, 3, new QTableWidgetItem(query.value(7).toString()));
            ui->tw_extensivo->setRowHeight(cont, 20); //tamanho linha
            cont++;


        }
        //ajustes tabela
        ui->tw_extensivo->setColumnWidth(0,30);
        ui->tw_extensivo->setColumnWidth(1,200);
        ui->tw_extensivo->setColumnWidth(3,50);


        QStringList cabecalhos = {"ID", "Nome", "Mensalidade","Parcela"};
        ui->tw_extensivo->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_extensivo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_extensivo->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_extensivo->verticalHeader()->setVisible(false);
        ui->tw_extensivo->setStyleSheet("QTableView {selection-backgroud-color: blue}");
    }
    else
    {
        QMessageBox::warning(this,"ERRO", "Erro ao pesquisar na tabela para extensivo");
    }
    //---------------------------------------------------------------------

    if (query.exec("select * from tb_alunos where turmaAluno='"+modalidade2+"'"))
    {
        int cont=0;
        ui->tw_intensivo->setColumnCount(4);
        while(query.next())
        {
            ui->tw_intensivo->insertRow(cont);
            ui->tw_intensivo->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tw_intensivo->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tw_intensivo->setItem(cont, 2, new QTableWidgetItem(query.value(6).toString()));
            ui->tw_intensivo->setItem(cont, 3, new QTableWidgetItem(query.value(7).toString()));
            ui->tw_intensivo->setRowHeight(cont, 20); //tamanho linha
            cont++;


        }
        //ajustes tabela
        ui->tw_intensivo->setColumnWidth(0,30);
        ui->tw_intensivo->setColumnWidth(1,200);
        ui->tw_intensivo->setColumnWidth(3,50);

        QStringList cabecalhos = {"ID", "Nome", "Mensalidade","Parcela"};
        ui->tw_intensivo->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_intensivo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_intensivo->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_intensivo->verticalHeader()->setVisible(false);
        ui->tw_intensivo->setStyleSheet("QTableView {selection-backgroud-color: blue}");
    }
    else
    {
        QMessageBox::warning(this,"ERRO", "Erro ao pesquisar na tabela para extensivo");
    }
    //---------------------------------------------------------------------

    if (query.exec("select * from tb_alunos where turmaAluno='"+modalidade3+"'"))
    {
        int cont=0;
        ui->tw_med->setColumnCount(4);
        while(query.next())
        {
            ui->tw_med->insertRow(cont);
            ui->tw_med->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tw_med->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tw_med->setItem(cont, 2, new QTableWidgetItem(query.value(6).toString()));
            ui->tw_med->setItem(cont, 3, new QTableWidgetItem(query.value(7).toString()));
            ui->tw_med->setRowHeight(cont, 20); //tamanho linha
            cont++;


        }
        //ajustes tabela
        ui->tw_med->setColumnWidth(0,30);
        ui->tw_med->setColumnWidth(1,200);
        ui->tw_med->setColumnWidth(3,50);

        QStringList cabecalhos = {"ID", "Nome", "Mensalidade","Parcela"};
        ui->tw_med->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_med->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_med->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_med->verticalHeader()->setVisible(false);
        ui->tw_med->setStyleSheet("QTableView {selection-backgroud-color: blue}");
    }
    else
    {
        QMessageBox::warning(this,"ERRO", "Erro ao pesquisar na tabela para extensivo");
    }



}

Mensalidades::~Mensalidades()
{
    delete ui;
}

void Mensalidades::on_pushButtonExtAdd_clicked() //adiciona mensalidade extensivo
{
    QString id = ui->lineEditExtAdd->text();
    QString ok = "Pago";

    QSqlQuery query;

    query.prepare("update tb_alunos set parcela1='"+ok+"' where id='"+id+"' ");

    if(query.exec())
    {
        QMessageBox::information(this, "", "Mensalidade atualizada com sucesso!");
        ui->lineEditExtAdd->clear();
    }
    else
    {
        qDebug()<<"Erro ao adicionar mensalidade";
    }
}


void Mensalidades::on_pushButton_2_clicked() //remove mensalidade extensivo
{
    QString id = ui->lineEdit_11->text();
    QString ok = "Pago";
    QString check = NULL;

    QSqlQuery query;

    query.prepare("update tb_alunos set parcela1='"+check+"' where id='"+id+"' ");

    if(query.exec())
    {
        QMessageBox::information(this, "", "Mensalidade atualizada com sucesso!");
        ui->lineEdit_11->clear();
    }
    else
    {
        qDebug()<<"Erro ao adicionar mensalidade";
    }

}


void Mensalidades::on_admButton_clicked()
{
    this->close();

    administrativo m_administrativo;
    m_administrativo.setModal(true);
    m_administrativo.setWindowState(Qt::WindowMaximized);
    m_administrativo.exec();

}


void Mensalidades::on_finButton_clicked()
{
    this->close();

    financeiro m_financeiro;
    m_financeiro.setModal(true);
    m_financeiro.setWindowState(Qt::WindowMaximized);
    m_financeiro.exec();
}


void Mensalidades::on_homeButton_clicked()
{
    this->close();

    fm_principal f_principal;
    f_principal.setModal(true);
    f_principal.setWindowState(Qt::WindowMaximized);
    f_principal.exec();
}





void Mensalidades::on_pushButton_4_clicked()
{
    QString id = ui->lineEdit_13->text();
    QString ok = "Pago";

    QSqlQuery query;

    query.prepare("update tb_alunos set parcela1='"+ok+"' where id='"+id+"' ");

    if(query.exec())
    {
        QMessageBox::information(this, "", "Mensalidade atualizada com sucesso!");
        ui->lineEdit_13->clear();

    }
    else
    {
        qDebug()<<"Erro ao adicionar mensalidade";
    }
}


void Mensalidades::on_pushButton_5_clicked()
{
    QString id = ui->lineEdit_14->text();
    QString ok = "Pago";
    QString check = NULL;

    QSqlQuery query;

    query.prepare("update tb_alunos set parcela1='"+check+"' where id='"+id+"' ");

    if(query.exec())
    {
        QMessageBox::information(this, "", "Mensalidade atualizada com sucesso!");
        ui->lineEdit_14->clear();
    }
    else
    {
        qDebug()<<"Erro ao adicionar mensalidade";
    }
}


void Mensalidades::on_pushButton_7_clicked()
{

    QString id = ui->lineEdit_16->text();
    QString ok = "Pago";

    QSqlQuery query;

    query.prepare("update tb_alunos set parcela1='"+ok+"' where id='"+id+"' ");

    if(query.exec())
    {
        QMessageBox::information(this, "", "Mensalidade atualizada com sucesso!");
        ui->lineEdit_16->clear();

    }
    else
    {
        qDebug()<<"Erro ao adicionar mensalidade";
    }
}


void Mensalidades::on_pushButton_8_clicked()
{

    QString id = ui->lineEdit_17->text();
    QString ok = "Pago";
    QString check = NULL;

    QSqlQuery query;

    query.prepare("update tb_alunos set parcela1='"+check+"' where id='"+id+"' ");

    if(query.exec())
    {
        QMessageBox::information(this, "", "Mensalidade atualizada com sucesso!");
        ui->lineEdit_17->clear();
    }
    else
    {
        qDebug()<<"Erro ao adicionar mensalidade";
    }
}


void Mensalidades::on_pushButton_clicked()
{
    this->close();

    Mensalidades m_Mensalidades;
    m_Mensalidades.setModal(true);
    m_Mensalidades.setWindowState(Qt::WindowMaximized);
    m_Mensalidades.exec();
}


void Mensalidades::on_infoButton_clicked()
{
    this->close();
    infos m_infos;
    m_infos.setModal(true);
    m_infos.setWindowState(Qt::WindowMaximized);
    m_infos.exec();

}


void Mensalidades::on_helpButton_clicked()
{
    this->close();
        help m_help;
        m_help.setModal(true);
        m_help.setWindowState(Qt::WindowMaximized);
        m_help.exec();
}

