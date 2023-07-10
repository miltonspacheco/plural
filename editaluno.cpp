#include "editaluno.h"
#include "ui_editaluno.h"


editAluno::editAluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editAluno)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from tb_alunos");
    if (query.exec())
    {
        int cont=0;
        ui->twAlunos->setColumnCount(7);
        while(query.next())
        {
            ui->twAlunos->insertRow(cont);
            ui->twAlunos->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->twAlunos->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->twAlunos->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->twAlunos->setItem(cont, 3, new QTableWidgetItem(query.value(3).toString()));
            ui->twAlunos->setItem(cont, 4, new QTableWidgetItem(query.value(4).toString()));
            ui->twAlunos->setItem(cont, 5, new QTableWidgetItem(query.value(5).toString()));
            ui->twAlunos->setItem(cont, 6, new QTableWidgetItem(query.value(6).toString()));
            ui->twAlunos->setRowHeight(cont, 20); //tamanho linha
            cont++;
        }
        //ajustes tabela
        ui->twAlunos->setColumnWidth(0,30);
        ui->twAlunos->setColumnWidth(1,150);
        ui->twAlunos->setColumnWidth(3,200);

        QStringList cabecalhos = {"ID", "Nome", "Telefone", "Idade", "Email", "Turma", "Mensalidade"};
        ui->twAlunos->setHorizontalHeaderLabels(cabecalhos);
        ui->twAlunos->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->twAlunos->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->twAlunos->verticalHeader()->setVisible(false);
        ui->twAlunos->setStyleSheet("QTableView {selection-backgroud-color: blue}");
    }
    else
    {
        QMessageBox::warning(this,"ERRO", "Erro ao pesquisar na tabela alunos");
    }
}

editAluno::~editAluno()
{
    delete ui;
}

void editAluno::on_btnExcluirAluno_clicked() //exclui aluno
{
    int linha = ui->twAlunos->currentRow();
    int id = ui->twAlunos->item(linha, 0)->text().toInt();

    QSqlQuery query;
    query.prepare("delete from tb_alunos where id="+QString::number(id));
    if(query.exec())
    {
        QMessageBox::information(this, "erro", "Aluno Excluido");
        ui->twAlunos->removeRow(linha);
    }
    else
    {
        QMessageBox::warning(this, "erro", "Erro ao excluir aluno");
    }

}


void editAluno::on_btnEditarAluno_clicked()
{
    int linha=ui->twAlunos->currentRow();
    int id = ui->twAlunos->item(linha,0)->text().toInt();
    fm_editAluno f_editAluno(this, id);
    f_editAluno.exec();
    //atualizar tabela
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
}


void editAluno::on_admButton_clicked()
{
    this->close();

    administrativo m_administrativo;
    m_administrativo.setModal(true);
    m_administrativo.setWindowState(Qt::WindowMaximized);
    m_administrativo.exec();

}


void editAluno::on_finButton_clicked()
{
    this->close();

    financeiro m_financeiro;
    m_financeiro.setModal(true);
    m_financeiro.setWindowState(Qt::WindowMaximized);
    m_financeiro.exec();
}


void editAluno::on_homeButton_clicked()
{
    this->close();

    fm_principal f_principal;
    f_principal.setModal(true);
    f_principal.setWindowState(Qt::WindowMaximized);
    f_principal.exec();
}


void editAluno::on_btnAtualizar_clicked()
{
    this->close();
    editAluno m_editAluno;
    m_editAluno.setModal(true);
    m_editAluno.setWindowState(Qt::WindowMaximized);
    m_editAluno.exec();
}


void editAluno::on_infoButton_clicked()
{

    this->close();
    infos m_infos;
    m_infos.setModal(true);
    m_infos.setWindowState(Qt::WindowMaximized);
    m_infos.exec();
}


void editAluno::on_helpButton_clicked()
{
    this->close();
    help m_help;
    m_help.setModal(true);
    m_help.setWindowState(Qt::WindowMaximized);
    m_help.exec();

}

