#include <stdio.h>
#include <string.h>
#include <time.h>     // Necessário para puxar a data automaticamente do sistema
#include "cotacao.h"  // Atualizado para o nome exigido no edital

// Requisito 4.3: Recebendo ponteiros (*v e *c) em vez de cópias
Cotacao calculocotacao(Veiculo *v, Condutor *c) {
    float acrescimos = 0.0;
    float descontos = 0.0;
    float taxa_base = 4.0;
    float taxa_total = 0.0;
    
    Cotacao resultado_cotacao;

    // --- CÁLCULO DOS DESCONTOS ---
    if (c->cnh == 'C') {
        descontos = 0.5;
    }

    // Pega a data atual do sistema para usar na validação do ano e salvar na struct
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int ano_atual = tm.tm_year + 1900;

    // --- CÁLCULO DOS ACRÉSCIMOS ---
   
    if ((ano_atual - v->ano) <= 3) {
        acrescimos += 1.5;
    }

    
    if (c->idade < 25) {
        acrescimos += 2.0;
    } else if (c->idade >= 65) {
        acrescimos += 1.0;
    }

    int num_sinistros = (c->sinistros > 3) ? 3 : c->sinistros;
    acrescimos += (num_sinistros * 1.5);

    // --- CÁLCULO FINAL DAS TAXAS ---
    taxa_total = taxa_base + acrescimos - descontos;

    // --- CÁLCULO DOS PRÊMIOS ---
    // Divide por 100.0 para transformar a porcentagem (ex: 5.5) no fator multiplicador (0.055)
    resultado_cotacao.premio_anual = v->valor_mercado * (taxa_total / 100.0);

    if (v->tipo == 'E') {
        resultado_cotacao.premio_anual *= 1.4;
    }

    resultado_cotacao.premio_mensal = resultado_cotacao.premio_anual / 12.0;

    // --- PREENCHIMENTO DA STRUCT DE RETORNO ---

    resultado_cotacao.veiculo = *v;
    resultado_cotacao.condutor = *c;

    // Gera a string de data no formato DD/MM/AAAA automaticamente
    sprintf(resultado_cotacao.data, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, ano_atual);

    // Exibição do resumo para o usuário (opcional, baseado no que vocês já tinham)
    printf("\n--- Resumo do Calculo ---\n");
    printf("Taxa Base: %.2f%%\n", taxa_base);
    printf("Acrescimos: %.2f%%\n", acrescimos);
    printf("Descontos: %.2f%%\n", descontos);
    printf("Taxa Total Aplicada: %.2f%%\n", taxa_total);

    return resultado_cotacao;
}
