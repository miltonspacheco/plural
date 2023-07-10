#ifndef EXTENSIVO_H
#define EXTENSIVO_H

#include <QDialog>

namespace Ui {
class extensivo;
}

class extensivo : public QDialog
{
    Q_OBJECT

public:
    explicit extensivo(QWidget *parent = nullptr);
    ~extensivo();

private:
    Ui::extensivo *ui;
};

#endif // EXTENSIVO_H
