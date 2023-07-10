#ifndef NEWALUNO_H
#define NEWALUNO_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

#include "fm_principal.h"
#include "financeiro.h"
#include "administrativo.h"

namespace Ui {
class newAluno;
}

class newAluno : public QDialog
{
    Q_OBJECT

public:
    explicit newAluno(QWidget *parent = nullptr);
    ~newAluno();

private slots:
    void on_addAlunoBtn_clicked();

    void on_homeButton_clicked();

    void on_finButton_clicked();

    void on_cancelarAlunoBtn_clicked();

    void on_admButton_clicked();

    void on_infoButton_clicked();

    void on_helpButton_clicked();

private:
    Ui::newAluno *ui;
};

#endif // NEWALUNO_H
