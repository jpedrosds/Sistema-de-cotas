#ifndef CALCULOCOTACAO_H
#define CALCULOCOTACAO_H
#include "cadastrov.h" 
#include "cadastrop.h"

typedef struct {
    Veiculo  veiculo;
    Condutor condutor;
    float    premio_anual;
    float    premio_mensal;
    char     data[11];    /* formato DD/MM/AAAA */
  } Cotacao;

Cotacao calculocotacao(Veiculo v, Condutor c);
//Agora, a struct "Cotacao" conseguirá receber os valores das variáveis de outros arquivos. 

#endif
