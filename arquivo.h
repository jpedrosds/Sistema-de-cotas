#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "cadastrov.h"
#include "cadastrop.h"
#include "cotacao.h"


int salvarCotacoes(const char *nomeArquivo, Cotacao cotacoes[], int total);
Cotacao *carregarCotacoes(const char *nomeArquivo, int *total);

void salvarVeiculo(char nomeArquivo[], Veiculo *v);
Veiculo carregarVeiculo(char nomeArquivo[], int *existe);

void salvarCondutor(char nomeArquivo[], Condutor *c);
Condutor carregarCondutor(char nomeArquivo[], int *existe);



#endif
