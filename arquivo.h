#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "cotacao.h"

int salvarCotacoes(const char *nomeArquivo, Cotacao cotacoes[], int total);
Cotacao *carregarCotacoes(const char *nomeArquivo, int *total);

#endif
