#ifndef INFOS_H
#define INFOS_H

#include <QDialog>
#include "fm_principal.h"

namespace Ui {
class infos;
}

class infos : public QDialog
{
    Q_OBJECT

public:
    explicit infos(QWidget *parent = nullptr);
    ~infos();

private slots:
    void on_homeButton_clicked();

    void on_finButton_clicked();

    void on_admButton_clicked();

    void on_infoButton_clicked();

    void on_helpButton_2_clicked();

private:
    Ui::infos *ui;
};

#endif // INFOS_H
