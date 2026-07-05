#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "cadastrov.h"

Veiculo cadastrov(){
    Veiculo veiculo;

    printf("Digite a marca do carro: ");
        fgets(veiculo.marca, 50, stdin);
        veiculo.marca[strcspn(veiculo.marca, "\n")] = '\0';

    printf("Digite o modelo do carro: ");
        fgets(veiculo.modelo, 50, stdin);
        veiculo.modelo[strcspn(veiculo.modelo, "\n")] = '\0';

    printf("Digite o ano do carro: ");
        scanf("%d", &veiculo.ano);
        while (getchar() != '\n');


    printf("Digite o valor de mercado do carro: ");
        scanf("%f", &veiculo.valor_mercado);
        while (getchar() != '\n');

    
     do {
        printf("Tipo do carro (P) Passeio (U) Utilitario (E) Esportivo: ");
        scanf(" %c", &veiculo.tipo);

        veiculo.tipo = toupper(veiculo.tipo);

        if (veiculo.tipo != 'P' && veiculo.tipo != 'U' && veiculo.tipo != 'E') {
            printf("Tipo invalido! Tente novamente.\n");
        }

    } while (veiculo.tipo != 'P' && veiculo.tipo != 'U' && veiculo.tipo != 'E');

    return veiculo;
 
}