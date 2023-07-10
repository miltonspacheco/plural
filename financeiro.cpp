#include "financeiro.h"
#include "ui_financeiro.h"

#include <QtSql>
#include <QDebug>

financeiro::financeiro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::financeiro)
{
    ui->setupUi(this);

    QSqlQuery query;
    QString estado = "Pago";

    query.prepare("select sum(mensalidadeAluno) from tb_alunos where parcela1='"+estado+"' "); //mostra entradas
    query.exec();

        query.first();
        int entrada = query.value(0).toInt();
        ui->labelEntrada->setText(query.value(0).toString());



    query.prepare("select sum(salarioProf) from tb_prof"); //mostra saidas

        query.exec();
        query.first();
        int saida = query.value(0).toInt();
        ui->labelSaida->setText(query.value(0).toString());


    int total = entrada-saida;

    ui->labelTotal->setText(QString::number(total));

}



financeiro::~financeiro()
{
    delete ui;
}

void financeiro::on_homeButton_clicked()
{
    this->close();

    fm_principal f_principal;
    f_principal.setModal(true);
    f_principal.setWindowState(Qt::WindowMaximized);
    f_principal.exec();
}


void financeiro::on_admButton_clicked()
{
    this->close();

    administrativo m_administrativo;
    m_administrativo.setModal(true);
    m_administrativo.setWindowState(Qt::WindowMaximized);
    m_administrativo.exec();
}


void financeiro::on_extensivoAlunosBtn_clicked()
{
    this->close();

    Mensalidades m_Mensalidades;
    m_Mensalidades.setModal(true);
    m_Mensalidades.setWindowState(Qt::WindowMaximized);
    m_Mensalidades.exec();
}


void financeiro::on_extensivoProfBtn_clicked()
{
     this->close();
    Pagamentos m_Pagamentos;
    m_Pagamentos.setModal(true);
    m_Pagamentos.setWindowState(Qt::WindowMaximized);
    m_Pagamentos.exec();
}


void financeiro::on_finButton_clicked()
{
    this->close();
        financeiro m_financeiro;
        m_financeiro.setModal(true);
        m_financeiro.setWindowState(Qt::WindowMaximized);
        m_financeiro.exec();
}


void financeiro::on_infoButton_clicked()
{
    this->close();
    infos m_infos;
    m_infos.setModal(true);
    m_infos.setWindowState(Qt::WindowMaximized);
    m_infos.exec();

}


void financeiro::on_helpButton_clicked()
{
    this->close();
    help m_help;
    m_help.setModal(true);
    m_help.setWindowState(Qt::WindowMaximized);
    m_help.exec();

}

