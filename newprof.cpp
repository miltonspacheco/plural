#include "newprof.h"
#include "ui_newprof.h"

newProf::newProf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newProf)
{
    ui->setupUi(this);
}

newProf::~newProf()
{
    delete ui;
}
