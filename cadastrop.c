#include <stdio.h>
#include <ctype.h>
#include "cadastrop.h"

Condutor cadastrop() {
    Condutor condutor;
    printf("Digite o nome do condutor: ");
    scanf("%s", condutor.nome);
    printf("Digite o RG do condutor: ");
    scanf("%s", condutor.rg);
    printf("Digite a idade do condutor: ");
    scanf("%d", &condutor.idade);
    printf("Digite o número de sinistros do condutor: ");
    scanf("%d", &condutor.sinistros);
    printf("Digite a categoria da CNH do condutor ('A', 'B' ou 'C'): ");
    scanf(" %c", &condutor.cnh);
    return condutor;
}