#ifndef MENSALIDADES_H
#define MENSALIDADES_H

#include <QDialog>

namespace Ui {
class Mensalidades;
}

class Mensalidades : public QDialog
{
    Q_OBJECT

public:
    explicit Mensalidades(QWidget *parent = nullptr);
    ~Mensalidades();

private slots:
    void on_pushButtonExtAdd_clicked();

    void on_pushButton_2_clicked();

    void on_finButton_clicked();
    void on_homeButton_clicked();
    void on_admButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_infoButton_clicked();

    void on_helpButton_clicked();

private:
    Ui::Mensalidades *ui;
};

#endif // MENSALIDADES_H
