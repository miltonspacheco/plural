#ifndef NEWPROF_H
#define NEWPROF_H

#include <QDialog>

namespace Ui {
class newProf;
}

class newProf : public QDialog
{
    Q_OBJECT

public:
    explicit newProf(QWidget *parent = nullptr);
    ~newProf();

private:
    Ui::newProf *ui;
};

#endif // NEWPROF_H
