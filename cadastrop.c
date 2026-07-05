#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "cadastrop.h"

Condutor cadastrop() {
    Condutor condutor;
    printf("Digite o nome do condutor: ");
    fgets(condutor.nome, sizeof(condutor.nome), stdin);

        condutor.nome[strcspn(condutor.nome, "\n")] = '\0';

    do {
    printf("Digite o RG (5 dígitos): ");
    fgets(condutor.rg, sizeof(condutor.rg), stdin);
    condutor.rg[strcspn(condutor.rg, "\n")] = '\0';

    if (strlen(condutor.rg) != 5) {
        printf("RG inválido! Digite exatamente 5 caracteres.\n");
    }

} while (strlen(condutor.rg) != 5);

    printf("Digite a idade do condutor: ");
        scanf("%d", &condutor.idade);
        while (getchar() != '\n');

    printf("Digite o número de sinistros do condutor: ");
        scanf("%d", &condutor.sinistros);
        while (getchar() != '\n');

    do {
        printf("Digite a categoria da CNH (A, B ou C): ");
        scanf(" %c", &condutor.cnh);
        condutor.cnh = toupper(condutor.cnh);
        while (getchar() != '\n');
        
        if (condutor.cnh != 'A' && condutor.cnh != 'B' && condutor.cnh != 'C') {
            printf("Categoria inválida! Digite novamente.\n");
        }

    } while (condutor.cnh != 'A' && condutor.cnh != 'B' && condutor.cnh != 'C');

    return condutor;
}