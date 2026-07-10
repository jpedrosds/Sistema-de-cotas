#include <stdio.h>
#include "calculocotacao.h"

//Dados obtidos até agora (condutor): nome, idade, rg, número de sinistros e categoria da CNH
//Dados obtidos até agora (veículo): marca, modelo, ano, valor de mercado e tipo

Cotacao calculocotacao(Veiculo v, Condutor c){

    float acrescimos=0.0,descontos=0.0, premio_anual, *p;
    float taxa_base = 0.04 * v.valor_mercado;
    p = &acrescimos;

    if (c.cnh == 'C'){
        float descontos = 0.5;
    }
    
    if (2026 - v.ano <= 3){
        *p +=1.5;
    }

    if (c.idade < 25){
        *p += 2.0;
    }

    if (c.idade >= 65){
        *p += 1.0;
    }

    for (int i= 1; i <= c.sinistros; i++){
        *p += 1.5;
    }

    if (v.tipo == 'E'){
        premio_anual = premio_anual * 1,4;
    }

    float taxa_total = taxa_base + acrescimos - descontos;
    premio_anual = v.valor_mercado * taxa_total;
    float premio_mensal = premio_anual / 12;

    printf("Acrescimos total: %f", acrescimos);
    printf("Taxa_base: %f", taxa_base);

    Cotacao resultado_cotacao;

    resultado_cotacao.premio_anual = premio_anual;
    resultado_cotacao.premio_mensal = premio_mensal;
    resultado_cotacao.veiculo = v;
    resultado_cotacao.condutor = c;
    
    strcpy(resultado_cotacao.data, "08/07/2026");

    return resultado_cotacao;

}
