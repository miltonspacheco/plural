#include "fm_editaluno.h"
#include "ui_fm_editaluno.h"
#include "editaluno.h"
#include <QtSql>
#include <QMessageBox>

static int id;

fm_editAluno::fm_editAluno(QWidget *parent, int id_contato) :
    QDialog(parent),
    ui(new Ui::fm_editAluno)
{
    ui->setupUi(this);
    id=id_contato;
    QSqlQuery query;
    query.prepare("select * from tb_alunos where id="+QString::number(id_contato));
    if (query.exec())
    {
        query.first();
        ui->txt_nome->setText(query.value(1).toString());
        ui->txt_telefone->setText(query.value(2).toString());
        ui->txt_idade->setText(query.value(3).toString());
        ui->txt_email->setText(query.value(4).toString());
        ui->txt_turma->setText(query.value(5).toString());
        ui->txt_mensalidade->setText(query.value(6).toString());

    }
    else
    {
        QMessageBox::warning(this, "Erro", "Erro ao selecionar aluno para edição");
    }
}

fm_editAluno::~fm_editAluno()
{
    delete ui;
}

void fm_editAluno::on_pushButton_clicked()
{
    QString nome = ui->txt_nome->text();
    QString telefone = ui->txt_telefone->text();
    QString idade = ui->txt_idade->text();
    QString email = ui->txt_email->text();
    QString turma = ui->txt_turma->text();
    QString mensalidade = ui->txt_mensalidade->text();


    QSqlQuery query;

    query.prepare("update tb_alunos set nomeAluno='"+nome+"', telefoneAluno='"+telefone+"', idadeAluno='"+idade+"', emailAluno='"+email+"', turmaAluno='"+turma+"', mensalidadeAluno='"+mensalidade+"' where id="+QString::number(id));
    if (query.exec())
    {
        this->close();

    }
    else
    {
        QMessageBox::warning(this, "Erro", "Erro ao editar aluno");
    }


}


void fm_editAluno::on_pushButton_2_clicked()
{
    this->close();
}

