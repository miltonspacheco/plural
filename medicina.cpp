#include "medicina.h"
#include "ui_medicina.h"

medicina::medicina(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::medicina)
{
    ui->setupUi(this);
}

medicina::~medicina()
{
    delete ui;
}
