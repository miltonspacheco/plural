#ifndef FM_EDITALUNO_H
#define FM_EDITALUNO_H

#include <QDialog>

namespace Ui {
class fm_editAluno;
}

class fm_editAluno : public QDialog
{
    Q_OBJECT

public:
    explicit fm_editAluno(QWidget *parent = nullptr, int id_aluno=0);
    ~fm_editAluno();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::fm_editAluno *ui;
};

#endif // FM_EDITALUNO_H
