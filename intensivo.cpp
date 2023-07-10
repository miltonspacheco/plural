#include "intensivo.h"
#include "ui_intensivo.h"

intensivo::intensivo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::intensivo)
{
    ui->setupUi(this);
}

intensivo::~intensivo()
{
    delete ui;
}
