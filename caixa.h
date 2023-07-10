#ifndef CAIXA_H
#define CAIXA_H

#include "principal.h"
#include <iostream>
#include <QMessageBox>
#include <QtSql>

using namespace std;

class Caixa
{
protected:
    int m_entrada, m_saida;
    int m_total;

public:
    Caixa();

    int GetEntrada();
    int GetSaida();
    int GetTotal();
    void Calcular();
};

#endif // CAIXA_H
