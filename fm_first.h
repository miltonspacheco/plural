#ifndef FM_FIRST_H
#define FM_FIRST_H

#include <QDialog>

namespace Ui {
class fm_first;
}

class fm_first : public QDialog
{
    Q_OBJECT

public:
    explicit fm_first(QWidget *parent = nullptr);
    ~fm_first();

private:
    Ui::fm_first *ui;
};

#endif // FM_FIRST_H
