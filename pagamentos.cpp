#include "pagamentos.h"
#include "ui_pagamentos.h"
#include "administrativo.h"
#include "financeiro.h"
#include "fm_principal.h"

#include <QtSql>
#include <QMessageBox>

Pagamentos::Pagamentos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pagamentos)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from tb_gastos");

    QString modalidade = "Funcionario";
    QString modalidade2 = "Fixo";

    if (query.exec("select * from tb_gastos where tipoGasto='"+modalidade+"'"))
    {
        int cont=0;
        ui->tw_funcionarios->setColumnCount(3);
        while(query.next())
        {
            ui->tw_funcionarios->insertRow(cont);
            ui->tw_funcionarios->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tw_funcionarios->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tw_funcionarios->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tw_funcionarios->setRowHeight(cont, 20); //tamanho linha
            cont++;


        }
        //ajustes tabela
        ui->tw_funcionarios->setColumnWidth(0,30);
        ui->tw_funcionarios->setColumnWidth(1,150);
        ui->tw_funcionarios->setColumnWidth(3,200);

        QStringList cabecalhos = {"ID", "Gasto", "Valor"};
        ui->tw_funcionarios->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_funcionarios->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_funcionarios->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_funcionarios->verticalHeader()->setVisible(false);
        ui->tw_funcionarios->setStyleSheet("QTableView {selection-backgroud-color: blue}");
    }
    else
    {
        QMessageBox::warning(this,"ERRO", "Erro ao pesquisar na tabela para extensivo");
    }
    //-----------------------------------------------------------------------------
    if (query.exec("select * from tb_gastos where tipoGasto='"+modalidade2+"'"))
    {
        int cont=0;
        ui->tw_fixos->setColumnCount(3);
        while(query.next())
        {
            ui->tw_fixos->insertRow(cont);
            ui->tw_fixos->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tw_fixos->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tw_fixos->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tw_fixos->setRowHeight(cont, 20); //tamanho linha
            cont++;


        }
        //ajustes tabela
        ui->tw_fixos->setColumnWidth(0,30);
        ui->tw_fixos->setColumnWidth(1,150);
        ui->tw_fixos->setColumnWidth(3,200);

        QStringList cabecalhos = {"ID", "Gasto", "Valor"};
        ui->tw_fixos->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_fixos->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_fixos->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_fixos->verticalHeader()->setVisible(false);
        ui->tw_fixos->setStyleSheet("QTableView {selection-backgroud-color: blue}");
    }
    else
    {
        QMessageBox::warning(this,"ERRO", "Erro ao pesquisar na tabela para extensivo");
    }
    //--------------------------------------------------------
    if (query.exec("select * from tb_prof"))
    {
        int cont=0;
        ui->tw_prof->setColumnCount(3);
        while(query.next())
        {
            ui->tw_prof->insertRow(cont);
            ui->tw_prof->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tw_prof->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tw_prof->setItem(cont, 2, new QTableWidgetItem(query.value(6).toString()));
            ui->tw_prof->setRowHeight(cont, 20); //tamanho linha
            cont++;


        }
        //ajustes tabela
        ui->tw_prof->setColumnWidth(0,30);
        ui->tw_prof->setColumnWidth(1,150);
        ui->tw_prof->setColumnWidth(3,200);

        QStringList cabecalhos = {"ID", "Professor", "Salario"};
        ui->tw_prof->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_prof->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_prof->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_prof->verticalHeader()->setVisible(false);
        ui->tw_prof->setStyleSheet("QTableView {selection-backgroud-color: blue}");
    }
    else
    {
        QMessageBox::warning(this,"ERRO", "Erro ao pesquisar na tabela para extensivo");
    }



}

Pagamentos::~Pagamentos()
{
    delete ui;
}

void Pagamentos::on_admButton_clicked()
{
    this->close();

    administrativo m_administrativo;
    m_administrativo.setModal(true);
    m_administrativo.setWindowState(Qt::WindowMaximized);
    m_administrativo.exec();

}


void Pagamentos::on_finButton_clicked()
{
    this->close();

    financeiro m_financeiro;
    m_financeiro.setModal(true);
    m_financeiro.setWindowState(Qt::WindowMaximized);
    m_financeiro.exec();
}


void Pagamentos::on_homeButton_clicked()
{
    this->close();

    fm_principal f_principal;
    f_principal.setModal(true);
    f_principal.setWindowState(Qt::WindowMaximized);
    f_principal.exec();
}


void Pagamentos::on_btnAddFun_clicked()
{
    QString nome=ui->lineEditNome->text();
    QString salario=ui->lineEditSalario->text();
    QString tipo = "Funcionario";


    QSqlQuery query;

    query.prepare("insert into tb_gastos (nomeGasto, valorGasto, tipoGasto) values"
                  "('"+nome+"','"+salario+"', '"+tipo+"')");

    if(query.exec())
    {
        QMessageBox::information(this, "", "Funcionario gravado com sucesso");
        ui->lineEditNome->clear();
        ui->lineEditSalario->clear();

    }
    else
    {
        qDebug()<<"Erro ao adicionar funcionario";
    }
}


void Pagamentos::on_btnExcluirFun_clicked()
{
    int linha = ui->tw_funcionarios->currentRow();
    int id = ui->tw_funcionarios->item(linha, 0)->text().toInt();

    QSqlQuery query;
    query.prepare("delete from tb_gastos where id="+QString::number(id));
    if(query.exec())
    {
        QMessageBox::information(this, "erro", "Funcionario Excluido");
        ui->tw_funcionarios->removeRow(linha);
    }
    else
    {
        QMessageBox::warning(this, "erro", "Erro ao excluir funcionario");
    }
}


void Pagamentos::on_btnAddFixos_clicked()
{
    QString nome=ui->lineEditTipo->text();
    QString preco=ui->lineEditPreco->text();
    QString tipo = "Fixo";


    QSqlQuery query;

    query.prepare("insert into tb_gastos (nomeGasto, valorGasto, tipoGasto) values"
                  "('"+nome+"','"+preco+"', '"+tipo+"')");

    if(query.exec())
    {
        QMessageBox::information(this, "", "Funcionario gravado com sucesso");
        ui->lineEditNome->clear();
        ui->lineEditPreco->clear();

    }
    else
    {
        qDebug()<<"Erro ao adicionar funcionario";
    }
}


void Pagamentos::on_btnExcluirFixos_clicked()
{
    int linha = ui->tw_fixos->currentRow();
    int id = ui->tw_fixos->item(linha, 0)->text().toInt();

    QSqlQuery query;
    query.prepare("delete from tb_gastos where id="+QString::number(id));
    if(query.exec())
    {
        QMessageBox::information(this, "erro", "Gasto Fixo Excluido");
        ui->tw_fixos->removeRow(linha);
    }
    else
    {
        QMessageBox::warning(this, "erro", "Erro ao excluir gastos");
    }
}


void Pagamentos::on_pushButton_clicked()
{
    this->close();
    Pagamentos m_Pagamentos;
    m_Pagamentos.setModal(true);
    m_Pagamentos.setWindowState(Qt::WindowMaximized);
    m_Pagamentos.exec();
}


void Pagamentos::on_pushButton_2_clicked()
{
    this->close();
    Pagamentos m_Pagamentos;
    m_Pagamentos.setModal(true);
    m_Pagamentos.setWindowState(Qt::WindowMaximized);
    m_Pagamentos.exec();
}


void Pagamentos::on_infoButton_clicked()
{
    this->close();
    infos m_infos;
    m_infos.setModal(true);
    m_infos.setWindowState(Qt::WindowMaximized);
    m_infos.exec();

}


void Pagamentos::on_helpButton_clicked()
{
 this->close();
    help m_help;
    m_help.setModal(true);
    m_help.setWindowState(Qt::WindowMaximized);
    m_help.exec();
}

