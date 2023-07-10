#include "administrativo.h"
#include "ui_administrativo.h"


administrativo::administrativo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrativo)
{
    ui->setupUi(this);
}

administrativo::~administrativo()
{
    delete ui;
}



void administrativo::on_extensivoAlunosBtn_clicked()
{
    this->close();

    newAluno m_newAluno;
    m_newAluno.setModal(true);
    m_newAluno.setWindowState(Qt::WindowMaximized);
    m_newAluno.exec();
}


void administrativo::on_extensivoProfBtn_clicked()
{
    this->close();

    newProfessor m_professor;
    m_professor.setModal(true);
    m_professor.setWindowState(Qt::WindowMaximized);
    m_professor.exec();
}


void administrativo::on_extensivoAlunosBtn_3_clicked()
{
    this->close();

    editAluno m_editAluno;
    m_editAluno.setModal(true);
    m_editAluno.setWindowState(Qt::WindowMaximized);
    m_editAluno.exec();
}

void administrativo::on_extensivoProfBtn_4_clicked()
{
    this->close();

    editProf m_editProf;
    m_editProf.setModal(true);
    m_editProf.setWindowState(Qt::WindowMaximized);
    m_editProf.exec();
}


void administrativo::on_homeButton_clicked()
{
    this->close();

        fm_principal f_principal;
        f_principal.setModal(true);
        f_principal.setWindowState(Qt::WindowMaximized);
        f_principal.exec();
}


void administrativo::on_finButton_clicked()
{
    this->close();

        financeiro m_financeiro;
        m_financeiro.setModal(true);
        m_financeiro.setWindowState(Qt::WindowMaximized);
        m_financeiro.exec();
}


void administrativo::on_admButton_clicked()
{
    this->close();

        administrativo m_administrativo;
        m_administrativo.setModal(true);
        m_administrativo.setWindowState(Qt::WindowMaximized);
        m_administrativo.exec();
}


void administrativo::on_infoButton_clicked()
{
    this->close();
    infos m_infos;
    m_infos.setModal(true);
    m_infos.setWindowState(Qt::WindowMaximized);
    m_infos.exec();
}


void administrativo::on_helpButton_clicked()
{
    this->close();
        help m_help;
        m_help.setModal(true);
        m_help.setWindowState(Qt::WindowMaximized);
        m_help.exec();
}

