#ifndef INTENSIVO_H
#define INTENSIVO_H

#include <QDialog>

namespace Ui {
class intensivo;
}

class intensivo : public QDialog
{
    Q_OBJECT

public:
    explicit intensivo(QWidget *parent = nullptr);
    ~intensivo();

private:
    Ui::intensivo *ui;
};

#endif // INTENSIVO_H
