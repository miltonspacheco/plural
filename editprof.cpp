#include "editprof.h"
#include "ui_editprof.h"

#include "financeiro.h"
#include "fm_principal.h"
#include "administrativo.h"
#include "fm_editprof.h"

#include <QtSql>
#include <QMessageBox>

editProf::editProf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editProf)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from tb_prof");
    if (query.exec())
    {
        int cont=0;
        ui->twProf->setColumnCount(7);
        while(query.next())
        {
            ui->twProf->insertRow(cont);
            ui->twProf->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->twProf->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->twProf->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->twProf->setItem(cont, 3, new QTableWidgetItem(query.value(3).toString()));
            ui->twProf->setItem(cont, 4, new QTableWidgetItem(query.value(4).toString()));
            ui->twProf->setItem(cont, 5, new QTableWidgetItem(query.value(5).toString()));
            ui->twProf->setItem(cont, 6, new QTableWidgetItem(query.value(6).toString()));
            ui->twProf->setRowHeight(cont, 20); //tamanho linha
            cont++;
        }
        //ajustes tabela
        ui->twProf->setColumnWidth(0,30);
        ui->twProf->setColumnWidth(1,150);
        ui->twProf->setColumnWidth(3,200);

        QStringList cabecalhos = {"ID", "Nome", "Telefone", "Idade", "Email", "Materia", "Salario"};
        ui->twProf->setHorizontalHeaderLabels(cabecalhos);
        ui->twProf->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->twProf->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->twProf->verticalHeader()->setVisible(false);
        ui->twProf->setStyleSheet("QTableView {selection-backgroud-color: blue}");
    }
    else
    {
        QMessageBox::warning(this,"ERRO", "Erro ao pesquisar na tabela prof");
    }
}

editProf::~editProf()
{
    delete ui;
}

void editProf::on_btnExcluirProf_clicked()
{
    int linha = ui->twProf->currentRow();
    int id = ui->twProf->item(linha, 0)->text().toInt();

    QSqlQuery query;
    query.prepare("delete from tb_prof where id="+QString::number(id));
    if(query.exec())
    {
        QMessageBox::information(this, "erro", "Prof Excluido");
        ui->twProf->removeRow(linha);
    }
    else
    {
        QMessageBox::warning(this, "erro", "Erro ao excluir prof");
    }
}


void editProf::on_admButton_clicked()
{
    this->close();

    administrativo m_administrativo;
    m_administrativo.setModal(true);
    m_administrativo.setWindowState(Qt::WindowMaximized);
    m_administrativo.exec();

}


void editProf::on_finButton_clicked()
{
    this->close();

    financeiro m_financeiro;
    m_financeiro.setModal(true);
    m_financeiro.setWindowState(Qt::WindowMaximized);
    m_financeiro.exec();
}


void editProf::on_homeButton_clicked()
{
    this->close();

    fm_principal f_principal;
    f_principal.setModal(true);
    f_principal.setWindowState(Qt::WindowMaximized);
    f_principal.exec();
}




void editProf::on_btnEditarProf_clicked()
{
    int linha=ui->twProf->currentRow();
    int id = ui->twProf->item(linha,0)->text().toInt();
    fm_editprof f_editProf(this, id);
    f_editProf.exec();
    //atualizar tabela
    /*
    QSqlQuery query;
    query.prepare("select * from tb_alunos where id="+QString::number(id));
    if(query.exec())
    {
        query.first();//pega resultado da query
        ui->twAlunos->setItem(linha, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->twAlunos->setItem(linha, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->twAlunos->setItem(linha, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->twAlunos->setItem(linha, 4, new QTableWidgetItem(query.value(4).toString()));
        ui->twAlunos->setItem(linha, 5, new QTableWidgetItem(query.value(5).toString()));


    }
    else
    {
        QMessageBox::warning(this, "erro", "Erro ao excluir aluno");
    }
    */
}


void editProf::on_btnPesquisar_clicked()
{
    this->close();
    editProf m_editProf;
    m_editProf.setModal(true);
    m_editProf.setWindowState(Qt::WindowMaximized);
    m_editProf.exec();
}


void editProf::on_helpButton_clicked()
{

    this->close();
    help m_help;
    m_help.setModal(true);
    m_help.setWindowState(Qt::WindowMaximized);
    m_help.exec();
}


void editProf::on_infoButton_clicked()
{
    this->close();
      infos m_infos;
      m_infos.setModal(true);
      m_infos.setWindowState(Qt::WindowMaximized);
      m_infos.exec();
}

