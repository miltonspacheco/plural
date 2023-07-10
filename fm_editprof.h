#ifndef FM_EDITPROF_H
#define FM_EDITPROF_H

#include <QDialog>

namespace Ui {
class fm_editprof;
}

class fm_editprof : public QDialog
{
    Q_OBJECT

public:
    explicit fm_editprof(QWidget *parent = nullptr, int id_contato=0);
    ~fm_editprof();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::fm_editprof *ui;
};

#endif // FM_EDITPROF_H
