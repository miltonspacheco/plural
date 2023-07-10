#include "principal.h"
#include "caixa.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    principal w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    //Caixa caixa();
    return a.exec();
}
