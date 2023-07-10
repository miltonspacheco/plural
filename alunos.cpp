#include "alunos.h"
#include "ui_alunos.h"

alunos::alunos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alunos)
{
    ui->setupUi(this);
}

alunos::~alunos()
{
    delete ui;
}

void alunos::on_extensivoAlunosBtn_clicked()
{
    this->close();

    newAluno m_newAluno;
    m_newAluno.setModal(true);
    m_newAluno.setWindowState(Qt::WindowMaximized);
    m_newAluno.exec();
}



