#include <stdio.h>
#include <string.h>
#include "cadastrov.h"
#include "cadastrop.h"
#include "calculocotacao.h"
#include "relatorio.h"

// Função que lista todas as cotações cadastradas
void listarCotacoes(Cotacao cotacoes[], int total){

    // Verifica se existem cotações cadastradas
    if (total == 0){
        printf("\nNenhuma cotação encontrada.");
        return; // Encerra a função caso não haja cotações
    }

    // Percorre todas as posições do vetor de cotações
    for(int i = 0; i < total; i++){

        printf("\n----------------------------------\n");

        // Exibe o número da cotação
        printf("Cotação %d\n", i + 1);

        // Exibe os dados do condutor
        printf("Condutor: %s\n", cotacoes[i].condutor.nome);
        printf("RG: %s\n", cotacoes[i].condutor.rg);

        // Exibe os dados do veículo
        printf("Veículo: %s %s", cotacoes[i].veiculo.marca, cotacoes[i].veiculo.modelo);
        printf("Ano: %d\n", cotacoes[i].veiculo.ano);

        // Exibe o valor do veículo
        printf("Valor de mercado: R$ %.2f\n", cotacoes[i].veiculo.valor_mercado);

        // Exibe o valor do seguro
        printf("Prêmio anual: R$ %.2f\n", cotacoes[i].premio_anual);
    }
}

// Função que busca uma cotação pelo nome do condutor
void buscarPorNome(Cotacao cotacoes[], int total){

    char nomeBusca[100]; // Armazena o nome digitado pelo usuário
    int encontrado = 0;  // Indica se a cotação foi encontrada

    printf("\nDigite o nome do condutor: ");

    // Limpa o buffer do teclado
    getchar();

    // Lê o nome digitado
    fgets(nomeBusca, sizeof(nomeBusca), stdin);

    // Remove o '\n' que o fgets adiciona ao final da string
    nomeBusca[strcspn(nomeBusca,"\n")] = '\0';

    // Percorre todas as cotações
    for(int i = 0; i < total; i++){

        // Compara o nome digitado com o nome armazenado
        if (strcmp(nomeBusca, cotacoes[i].condutor.nome) == 0){

            printf("\nCondutor encontrado!\n");

            // Exibe os dados da cotação encontrada
            printf("Nome: %s\n", cotacoes[i].condutor.nome);
            printf("RG: %s\n", cotacoes[i].condutor.rg);
            printf("Veiculos: %s %s\n", cotacoes[i].veiculo.marca, cotacoes[i].veiculo.modelo);
            printf("Prêmio: R$ %.2f\n", cotacoes[i].premio_anual);

            encontrado = 1; // Indica que a busca foi bem-sucedida
        }
    }

    // Caso nenhuma cotação tenha sido encontrada
    if(!encontrado){
        printf("\nCondutor não encontrado.\n");
    }
}

// Função que encontra a cotação com o menor prêmio anual
void menorCotacao(Cotacao cotacoes[], int total){

    // Verifica se existem cotações cadastradas
    if(total == 0){
        printf("\nNão existem cotações.\n");
        return;
    }

    // Considera inicialmente a primeira cotação como a menor
    int menor = 0;

    // Percorre as demais cotações procurando um prêmio menor
    for(int i = 1; i < total; i++){

        if(cotacoes[i].premio_anual < cotacoes[menor].premio_anual){

            // Atualiza o índice da menor cotação encontrada
            menor = i;
        }
    }

    printf("\n--------- MENOR COTAÇÃO ----------");

    // Exibe os dados da menor cotação
    printf("\nCondutor: %s\n", cotacoes[menor].condutor.nome);
    printf("Veículo: %s %s\n", cotacoes[menor].veiculo.marca, cotacoes[menor].veiculo.modelo);
    printf("Prêmio anual: R$ %.2f\n", cotacoes[menor].premio_anual);
}