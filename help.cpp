#include "help.h"
#include "ui_help.h"

help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}

void help::on_finButton_clicked()
{
    this->close();
       financeiro m_financeiro;
       m_financeiro.setModal(true);
       m_financeiro.setWindowState(Qt::WindowMaximized);
       m_financeiro.exec();
}


void help::on_homeButton_clicked()
{

    this->close();
    fm_principal f_principal;
    f_principal.setModal(true);
    f_principal.setWindowState(Qt::WindowMaximized);
    f_principal.exec();

}


void help::on_admButton_clicked()
{
    this->close();
    administrativo m_administrativo;
    m_administrativo.setModal(true);
    m_administrativo.setWindowState(Qt::WindowMaximized);
    m_administrativo.exec();

}


void help::on_helpButton_clicked()
{
    this->close();
    help m_help;
    m_help.setModal(true);
    m_help.setWindowState(Qt::WindowMaximized);
    m_help.exec();

}


void help::on_infoButton_clicked()
{
    this->close();
    infos m_infos;
    m_infos.setModal(true);
    m_infos.setWindowState(Qt::WindowMaximized);
    m_infos.exec();

}

