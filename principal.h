#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

#include "fm_principal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class principal; }
QT_END_NAMESPACE

class principal : public QMainWindow
{
    Q_OBJECT

public:
    principal(QWidget *parent = nullptr);
    ~principal();

private slots:
    void on_pushButtonConfirm_clicked();

    void on_pushButtonCloseError_clicked();

private:
    Ui::principal *ui;
};
#endif // PRINCIPAL_H
