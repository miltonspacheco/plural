#ifndef NEWPROFESSOR_H
#define NEWPROFESSOR_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class newProfessor;
}

class newProfessor : public QDialog
{
    Q_OBJECT

public:
    explicit newProfessor(QWidget *parent = nullptr);
    ~newProfessor();

private slots:
    void on_addAlunoBtn_clicked();

    void on_cancelarAlunoBtn_clicked();

private:
    Ui::newProfessor *ui;
};

#endif // NEWPROFESSOR_H
