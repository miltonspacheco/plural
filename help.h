#ifndef HELP_H
#define HELP_H

#include <QDialog>
#include "fm_principal.h"

namespace Ui {
class help;
}

class help : public QDialog
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = nullptr);
    ~help();

private slots:
    void on_finButton_clicked();

    void on_homeButton_clicked();

    void on_admButton_clicked();

    void on_helpButton_clicked();

    void on_infoButton_clicked();

private:
    Ui::help *ui;
};

#endif // HELP_H
