#include "fm_first.h"
#include "ui_fm_first.h"

fm_first::fm_first(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_first)
{
    ui->setupUi(this);
}

fm_first::~fm_first()
{
    delete ui;
}
