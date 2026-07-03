#include <stdio.h>
#include <ctype.h>
#include "cadastrov.h"

Veiculo cadastrov(){
    Veiculo carro;

    printf("Digite a marca do carro: ");
        fgets(carro.marca, 50, stdin);

    printf("Digite o modelo do carro: ");
        fgets(carro.modelo, 50, stdin);

    printf("Digite o ano do carro: ");
        scanf("%d", &carro.ano);
        getchar(); 

    printf("Digite o valor de mercado do carro: ");
        scanf("%f", &carro.valor_mercado);
        getchar(); 
    
     do {
        printf("Tipo do carro (P) Passeio (U) Utilitario (E) Esportivo: ");
        scanf(" %c", &carro.tipo);

        carro.tipo = toupper(carro.tipo);

        if (carro.tipo != 'P' && carro.tipo != 'U' && carro.tipo != 'E') {
            printf("Tipo invalido! Tente novamente.\n");
        }

    } while (carro.tipo != 'P' && carro.tipo != 'U' && carro.tipo != 'E');

    return carro;
 
}