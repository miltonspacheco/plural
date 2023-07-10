#include "newaluno.h"
#include "ui_newaluno.h"

newAluno::newAluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newAluno)
{
    ui->setupUi(this);
}

newAluno::~newAluno()
{
    delete ui;
}

void newAluno::on_addAlunoBtn_clicked()
{
    QString nome=ui->lineEditNome->text();
    QString idade=ui->lineEditIdade->text();
    QString mensalidade=ui->lineEditMensal->text();
    QString telefone=ui->lineEditTelefone->text();
    QString turma=ui->lineEditTurma->text();
    QString email=ui->lineEditEmail->text();

    QSqlQuery query;

    query.prepare("insert into tb_alunos (nomeAluno, idadeAluno, mensalidadeAluno, telefoneAluno, turmaAluno, emailAluno) values"
                  "('"+nome+"','"+idade+"','"+mensalidade+"','"+telefone+"','"+turma+"', '"+email+"')");

    if(query.exec())
    {
        QMessageBox::information(this, "", "Aluno gravado com sucesso");
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
        qDebug()<<"Erro ao adicionar aluno";
    }
}


void newAluno::on_homeButton_clicked()
{
    this->close();

    fm_principal f_principal;
    f_principal.setModal(true);
    f_principal.setWindowState(Qt::WindowMaximized);
    f_principal.exec();
}


void newAluno::on_finButton_clicked()
{
    this->close();

    financeiro m_financeiro;
    m_financeiro.setModal(true);
    m_financeiro.setWindowState(Qt::WindowMaximized);
    m_financeiro.exec();
}


void newAluno::on_cancelarAlunoBtn_clicked()
{
    this->close();

    administrativo m_administrativo;
    m_administrativo.setModal(true);
    m_administrativo.setWindowState(Qt::WindowMaximized);
    m_administrativo.exec();
}


void newAluno::on_admButton_clicked()
{
    this->close();
    administrativo m_administrativo;
    m_administrativo.setModal(true);
    m_administrativo.setWindowState(Qt::WindowMaximized);
    m_administrativo.exec();

}


void newAluno::on_infoButton_clicked()
{
    this->close();
     infos m_infos;
     m_infos.setModal(true);
     m_infos.setWindowState(Qt::WindowMaximized);
     m_infos.exec();

}

void newAluno::on_helpButton_clicked()
{
    this->close();
    help m_help;
    m_help.setModal(true);
    m_help.setWindowState(Qt::WindowMaximized);
    m_help.exec();

}




