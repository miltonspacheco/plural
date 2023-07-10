#include "caixa.h"

Caixa::Caixa()
{
    m_entrada, m_saida = 0;
    m_total = 0;

}

int Caixa::GetEntrada()
{

    return m_entrada;
}

int Caixa::GetSaida()
{
    return m_saida;
}
int Caixa::GetTotal()
{
    return m_total;
}

void Caixa::Calcular()
{
    QSqlQuery query;
    query.prepare("select sum(mensalidadeAluno) from tb_alunos");
    if(query.exec())
    {
        m_entrada = query.first();
    }
    else
    {
       // QMessageBox::information(this, "erro", "AAAAAAAAAAAAAA");
    }

}
