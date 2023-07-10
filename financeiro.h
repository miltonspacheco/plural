#ifndef FINANCEIRO_H
#define FINANCEIRO_H

#include <QDialog>

#include "fm_principal.h"
#include "administrativo.h"
#include "help.h"
#include "infos.h"
#include "mensalidades.h"
#include "pagamentos.h"

namespace Ui {
class financeiro;
}

class financeiro : public QDialog
{
    Q_OBJECT

public:

    explicit financeiro(QWidget *parent = nullptr);



    ~financeiro();

private slots:
    void on_homeButton_clicked();

    void on_admButton_clicked();

    void on_extensivoAlunosBtn_clicked();

    void on_extensivoProfBtn_clicked();

    void on_finButton_clicked();

    void on_infoButton_clicked();

    void on_helpButton_clicked();

private:
    Ui::financeiro *ui;

};

#endif // FINANCEIRO_H
