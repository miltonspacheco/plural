#ifndef PAGAMENTOS_H
#define PAGAMENTOS_H

#include <QDialog>

namespace Ui {
class Pagamentos;
}

class Pagamentos : public QDialog
{
    Q_OBJECT

public:
    explicit Pagamentos(QWidget *parent = nullptr);
    ~Pagamentos();

private slots:

    void on_finButton_clicked();
    void on_homeButton_clicked();
    void on_admButton_clicked();


    void on_btnAddFun_clicked();

    void on_btnExcluirFun_clicked();

    void on_btnAddFixos_clicked();

    void on_btnExcluirFixos_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_infoButton_clicked();

    void on_helpButton_clicked();

private:
    Ui::Pagamentos *ui;
};

#endif // PAGAMENTOS_H
