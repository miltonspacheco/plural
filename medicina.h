#ifndef MEDICINA_H
#define MEDICINA_H

#include <QDialog>

namespace Ui {
class medicina;
}

class medicina : public QDialog
{
    Q_OBJECT

public:
    explicit medicina(QWidget *parent = nullptr);
    ~medicina();

private:
    Ui::medicina *ui;
};

#endif // MEDICINA_H
