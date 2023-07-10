#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include <QDialog>
#include <QDebug>
#include "fm_principal.h"
#include "financeiro.h"
#include "newprofessor.h"
#include "newaluno.h"
#include "editaluno.h"
#include "editprof.h"

namespace Ui {
class administrativo;
}

class administrativo : public QDialog
{
    Q_OBJECT

public:
    explicit administrativo(QWidget *parent = nullptr);
    ~administrativo();

private slots:

    void on_extensivoAlunosBtn_clicked();

    void on_extensivoProfBtn_clicked();

    void on_extensivoAlunosBtn_3_clicked();

    void on_extensivoProfBtn_4_clicked();

    void on_homeButton_clicked();

    void on_finButton_clicked();

    void on_admButton_clicked();

    void on_infoButton_clicked();

    void on_helpButton_clicked();

private:
    Ui::administrativo *ui;

};

#endif // ADMINISTRATIVO_H
