#ifndef EDITALUNO_H
#define EDITALUNO_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

#include "financeiro.h"
#include "administrativo.h"
#include "fm_principal.h"
#include "fm_editaluno.h"


namespace Ui {
class editAluno;
}

class editAluno : public QDialog
{
    Q_OBJECT

public:
    explicit editAluno(QWidget *parent = nullptr);
    ~editAluno();

private slots:
    void on_btnExcluirAluno_clicked();

    void on_btnEditarAluno_clicked();

    void on_admButton_clicked();

    void on_finButton_clicked();

    void on_homeButton_clicked();

    void on_btnAtualizar_clicked();

    void on_infoButton_clicked();

    void on_helpButton_clicked();

private:
    Ui::editAluno *ui;
};

#endif // EDITALUNO_H
