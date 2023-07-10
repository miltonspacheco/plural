#include "fm_editprof.h"
#include "ui_fm_editprof.h"
#include "editprof.h"

#include <QtSql>
#include <QMessageBox>

static int id;

fm_editprof::fm_editprof(QWidget *parent, int id_contato) :
    QDialog(parent),
    ui(new Ui::fm_editprof)
{
    ui->setupUi(this);

    id=id_contato;
    QSqlQuery query;
    query.prepare("select * from tb_prof where id="+QString::number(id_contato));
    if (query.exec())
    {
        query.first();
        ui->txt_nome_2->setText(query.value(1).toString());
        ui->txt_telefone_2->setText(query.value(2).toString());
        ui->txt_idade_2->setText(query.value(3).toString());
        ui->txt_email_2->setText(query.value(4).toString());
        ui->txt_turma_2->setText(query.value(5).toString());
        ui->txt_salario->setText(query.value(6).toString());

    }
    else
    {
        QMessageBox::warning(this, "Erro", "Erro ao selecionar aluno para edição");
    }
}

fm_editprof::~fm_editprof()
{
    delete ui;
}

void fm_editprof::on_pushButton_3_clicked()
{
    QString nome = ui->txt_nome_2->text();
    QString telefone = ui->txt_telefone_2->text();
    QString idade = ui->txt_idade_2->text();
    QString email = ui->txt_email_2->text();
    QString materia = ui->txt_turma_2->text();
    QString salario = ui->txt_salario->text();

    QSqlQuery query;

    query.prepare("update tb_prof set nomeProf='"+nome+"', telefoneProf='"+telefone+"', idadeProf='"+idade+"', emailProf='"+email+"', materiaProf='"+materia+"', salarioProf='"+salario+"' where id="+QString::number(id));
    if (query.exec())
    {
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "Erro", "Erro ao editar aluno");
    }
}


void fm_editprof::on_pushButton_4_clicked()
{
    this->close();


}

