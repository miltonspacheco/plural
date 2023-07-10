#include "extensivo.h"
#include "ui_extensivo.h"

extensivo::extensivo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::extensivo)
{
    ui->setupUi(this);
}

extensivo::~extensivo()
{
    delete ui;
}
