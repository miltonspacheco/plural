#include "newprofessor.h"
#include "ui_newprofessor.h"

#include "administrativo.h"

newProfessor::newProfessor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newProfessor)
{
    ui->setupUi(this);
}

newProfessor::~newProfessor()
{
    delete ui;
}

void newProfessor::on_addAlunoBtn_clicked()
{
    QString nome=ui->lineEditNome->text();
    QString idade=ui->lineEditIdade->text();
    QString salario=ui->lineEditMensal->text();
    QString telefone=ui->lineEditTelefone->text();
    QString materia=ui->lineEditTurma->text();
    QString email=ui->lineEditEmail->text();

    QSqlQuery query;

    query.prepare("insert into tb_prof (nomeProf, idadeProf, salarioProf, telefoneProf, materiaProf, emailProf) values"
                  "('"+nome+"','"+idade+"','"+salario+"','"+telefone+"','"+materia+"', '"+email+"')");

    if(query.exec())
    {
        QMessageBox::information(this, "", "Prof gravado com sucesso");
        ui->lineEditNome->clear();
        ui->lineEditIdade->clear();
        ui->lineEditMensal->clear();
        ui->lineEditTelefone->clear();
        ui->lineEditTurma->clear();
        ui->lineEditEmail->clear();
        ui->lineEditNome->setFocus();
    }
    else
    {
        qDebug()<<"Erro ao adicionar prof";
    }
}


void newProfessor::on_cancelarAlunoBtn_clicked()
{
    this->close();

    administrativo m_administrativo;
    m_administrativo.setModal(true);
    m_administrativo.setWindowState(Qt::WindowMaximized);
    m_administrativo.exec();
}

