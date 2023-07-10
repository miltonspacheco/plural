#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <QDialog>
#include "newprofessor.h"

namespace Ui {
class professor;
}

class professor : public QDialog
{
    Q_OBJECT

public:
    explicit professor(QWidget *parent = nullptr);
    ~professor();

private slots:
    void on_extensivoAlunosBtn_clicked();

private:
    Ui::professor *ui;
};

#endif // PROFESSOR_H
