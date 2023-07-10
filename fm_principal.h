#ifndef FM_PRINCIPAL_H
#define FM_PRINCIPAL_H

#include <QDialog>
#include "financeiro.h"
#include "administrativo.h"
#include "infos.h"
#include "help.h"

namespace Ui {
class fm_principal;
}

class fm_principal : public QDialog
{
    Q_OBJECT

public:
    explicit fm_principal(QWidget *parent = nullptr);
    ~fm_principal();

private slots:

    void on_finButton_clicked();

    void on_admButton_clicked();

    void on_infoButton_clicked();

    void on_helpButton_clicked();

    void on_homeButton_clicked();

private:
    Ui::fm_principal *ui;
};

#endif // FM_PRINCIPAL_H
