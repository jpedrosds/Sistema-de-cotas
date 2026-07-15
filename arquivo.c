#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

// Salva o vetor inteiro de cotações no arquivo binário (sobrescrevendo o anterior com os dados mais recentes)
int salvarCotacoes(const char *nomeArquivo, Cotacao cotacoes[], int total) {
    if (nomeArquivo == NULL) {
        return 0;
    }

    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return 0;
    }

    // Grava o número total de cotações no início do arquivo
    if (fwrite(&total, sizeof(int), 1, arquivo) != 1) {
        fclose(arquivo);
        return 0;
    }

    // Se houver cotações na memória, grava o array inteiro no arquivo
    if (total > 0 && cotacoes != NULL) {
        size_t gravados = fwrite(cotacoes, sizeof(Cotacao), total, arquivo);
        
        // Validação: garante que gravou todas as cotações com sucesso
        if (gravados != (size_t)total) {
            printf("Erro ao escrever as cotacoes no arquivo!\n");
            fclose(arquivo);
            return 0;
        }
    }

    fclose(arquivo);
    return 1;
}

// Carrega as cotações do arquivo binário para a memória alocada dinamicamente
Cotacao *carregarCotacoes(const char *nomeArquivo, int *total) {
    if (nomeArquivo == NULL || total == NULL) {
        if (total != NULL) *total = 0;
        return NULL;
    }

    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        // Se o arquivo não existe (ex: primeira vez rodando o app), define total como 0 e inicia vazio
        *total = 0;
        return NULL;
    }

    // Lê a quantidade de cotações salvas
    if (fread(total, sizeof(int), 1, arquivo) != 1) {
        *total = 0;
        fclose(arquivo);
        return NULL;
    }

    // Se o arquivo estiver vazio ou com total inválido, fecha e retorna NULL
    if (*total <= 0) {
        *total = 0;
        fclose(arquivo);
        return NULL;
    }

    // Aloca exatamente a memória necessária para as cotações salvas (Requisito 4.4)
    Cotacao *cotacoes = (Cotacao *) malloc(sizeof(Cotacao) * (*total));
    if (cotacoes == NULL) {
        printf("Erro de alocacao de memoria ao carregar cotacoes!\n");
        *total = 0;
        fclose(arquivo);
        return NULL;
    }

    // Lê os dados das cotações
    size_t lidos = fread(cotacoes, sizeof(Cotacao), *total, arquivo);
    
    // Validação de Segurança: Se o arquivo estiver corrompido (menos dados do que o esperado)
    if (lidos != (size_t)(*total)) {
        printf("Aviso: Arquivo de dados corrompido. Dados descartados por seguranca.\n");
        free(cotacoes); // Libera a memória para evitar vazamento (Memory Leak)
        *total = 0;
        fclose(arquivo);
        return NULL;
    }

    fclose(arquivo);
    return cotacoes;
}
