#include "addfun.h"
#include "ui_addfun.h"

addFun::addFun(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addFun)
{
    ui->setupUi(this);
}

addFun::~addFun()
{
    delete ui;
}
