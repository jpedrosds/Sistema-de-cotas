#ifndef CADASTROV_H
#define CADASTROV_H

typedef struct {
    char marca[50];
    char modelo[50];
    int ano;
    float valor_mercado;
    char tipo;
} Veiculo;

Veiculo cadastrov();

#endif