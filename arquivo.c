#include <stdio.h>
#include <stdlib.h>

#include "arquivo.h"


// ================= VEICULO =================

void salvarVeiculo(char nomeArquivo[], Veiculo *veiculo){

    FILE *arquivo = fopen(nomeArquivo, "wb");

    if(arquivo == NULL){
        printf("Erro ao salvar veiculo!\n");
        return;
    }


    fwrite(veiculo, sizeof(Veiculo), 1, arquivo);


    fclose(arquivo);
}



Veiculo carregarVeiculo(char nomeArquivo[], int *existe){

    Veiculo veiculo;

    FILE *arquivo = fopen(nomeArquivo, "rb");


    if(arquivo == NULL){

        *existe = 0;

        return veiculo;
    }


    fread(&veiculo, sizeof(Veiculo), 1, arquivo);


    fclose(arquivo);


    *existe = 1;


    return veiculo;
}



// ================= CONDUTOR =================

void salvarCondutor(char nomeArquivo[], Condutor *condutor){

    FILE *arquivo = fopen(nomeArquivo, "wb");


    if(arquivo == NULL){

        printf("Erro ao salvar condutor!\n");
        return;

    }


    fwrite(condutor, sizeof(Condutor), 1, arquivo);


    fclose(arquivo);

}





Condutor carregarCondutor(char nomeArquivo[], int *existe){

    Condutor condutor;


    FILE *arquivo = fopen(nomeArquivo, "rb");


    if(arquivo == NULL){

        *existe = 0;

        return condutor;

    }


    fread(&condutor, sizeof(Condutor), 1, arquivo);


    fclose(arquivo);


    *existe = 1;


    return condutor;

}



// ================= COTAÇÕES =================


int salvarCotacoes(const char *nomeArquivo, Cotacao cotacoes[], int total)
{

    FILE *arquivo = fopen(nomeArquivo, "wb");


    if(arquivo == NULL){

        printf("Erro ao salvar cotacoes!\n");

        return 0;

    }



    // Salva a quantidade de cotações primeiro
    fwrite(&total, sizeof(int), 1, arquivo);



    // Salva as cotações
    fwrite(cotacoes, sizeof(Cotacao), total, arquivo);



    fclose(arquivo);



    return 1;

}





Cotacao *carregarCotacoes(const char *nomeArquivo, int *total)
{

    FILE *arquivo = fopen(nomeArquivo, "rb");



    if(arquivo == NULL){

        *total = 0;

        return NULL;

    }




    // Lê quantidade de cotações salvas

    fread(total, sizeof(int), 1, arquivo);




    Cotacao *cotacoes = malloc(sizeof(Cotacao) * 100);




    if(cotacoes == NULL){

        fclose(arquivo);

        *total = 0;

        return NULL;

    }




    // Lê as cotações

    fread(cotacoes, sizeof(Cotacao), *total, arquivo);




    fclose(arquivo);




    return cotacoes;

}