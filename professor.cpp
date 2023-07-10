#include "professor.h"
#include "ui_professor.h"

professor::professor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::professor)
{
    ui->setupUi(this);
}

professor::~professor()
{
    delete ui;
}

void professor::on_extensivoAlunosBtn_clicked()
{
    this->close();

    newProfessor m_professor;
    m_professor.setModal(true);
    m_professor.setWindowState(Qt::WindowMaximized);
    m_professor.exec();
}

