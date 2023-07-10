#ifndef EDITPROF_H
#define EDITPROF_H

#include <QDialog>

namespace Ui {
class editProf;
}

class editProf : public QDialog
{
    Q_OBJECT

public:
    explicit editProf(QWidget *parent = nullptr);
    ~editProf();

private slots:
    void on_btnExcluirProf_clicked();

    void on_homeButton_clicked();

    void on_finButton_clicked();

    void on_admButton_clicked();


    void on_btnEditarProf_clicked();

    void on_btnPesquisar_clicked();

    void on_helpButton_clicked();

    void on_infoButton_clicked();

private:
    Ui::editProf *ui;
};

#endif // EDITPROF_H
