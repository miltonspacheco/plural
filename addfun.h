#ifndef ADDFUN_H
#define ADDFUN_H

#include <QDialog>

namespace Ui {
class addFun;
}

class addFun : public QDialog
{
    Q_OBJECT

public:
    explicit addFun(QWidget *parent = nullptr);
    ~addFun();

private:
    Ui::addFun *ui;
};

#endif // ADDFUN_H
