#include <stdio.h>
#include <stdlib.h>

#include "arquivo.h"

int salvarCotacoes(const char *nomeArquivo, Cotacao cotacoes[], int total){

    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return 0;
    }

    if(arquivo == NULL){
        return 0;

    }


    fwrite(&total, sizeof(int), 1, arquivo);

    if(total > 0){
        fwrite(cotacoes, sizeof(Cotacao), total, arquivo);
    }

    fclose(arquivo);

    return 1;

}





Cotacao *carregarCotacoes(const char *nomeArquivo, int *total){

    FILE *arquivo = fopen(nomeArquivo, "rb");

    if(arquivo == NULL){
        *total = 0;

        return NULL;

    }





    if(fread(total, sizeof(int), 1, arquivo) != 1){
        *total = 0;
        fclose(arquivo);
        return NULL;
    }

    if(*total == 0){
        fclose(arquivo);
        return NULL;
    }

    Cotacao *cotacoes = (Cotacao *) malloc(sizeof(Cotacao) * (*total));

    if(cotacoes == NULL){
        *total = 0;
        fclose(arquivo);

        *total = 0;

        return NULL;

    }





    fread(cotacoes, sizeof(Cotacao), *total, arquivo);

    fclose(arquivo);

    return cotacoes;

}
