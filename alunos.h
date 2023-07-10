#ifndef ALUNOS_H
#define ALUNOS_H

#include <QDialog>
#include "newaluno.h"

namespace Ui {
class alunos;
}

class alunos : public QDialog
{
    Q_OBJECT

public:
    explicit alunos(QWidget *parent = nullptr);
    ~alunos();

private slots:
    void on_extensivoAlunosBtn_clicked();

private:
    Ui::alunos *ui;
};

#endif // ALUNOS_H
