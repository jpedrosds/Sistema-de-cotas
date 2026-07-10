#include <stdio.h>
#include "cadastrov.h"
#include "cadastrop.h"

int main() {

    Veiculo veiculo;
    Condutor condutor;

    int opcao;
    int veiculoCadastrado = 0;
    int condutorCadastrado = 0;

    do {
        printf("\n====================================\n");
        printf("        MENU PRINCIPAL\n");
        printf("====================================\n");
        printf("1 - Cadastrar Veiculo na base de dados\n");
        printf("2 - Cadastrar Condutor na base de dados\n");
        printf("3 - Exibir base de dados\n");
        printf("4 - Fazer cálculo de cotação com novo cliente/veículo\n");
        printf("5 - Fazer cálculo de cotação com cliente/veículo já existente na base de dados\n")
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch(opcao) {

            case 1:
                veiculo = cadastrov();
                veiculoCadastrado = 1;
                break;

            case 2:
                condutor = cadastrop();
                condutorCadastrado = 1;
                break;

            case 3:

                printf("\n========== DADOS CADASTRADOS ==========\n");

                if (veiculoCadastrado) {
                    printf("\n--- VEICULO ---\n");
                    printf("Marca: %s\n", veiculo.marca);
                    printf("Modelo: %s\n", veiculo.modelo);
                    printf("Ano: %d\n", veiculo.ano);
                    printf("Valor de Mercado: R$ %.2f\n", veiculo.valor_mercado);
                    printf("Tipo: %c\n", veiculo.tipo);
                } else {
                    printf("\nVeiculo nao cadastrado.\n");
                }

                if (condutorCadastrado) {
                    printf("\n--- CONDUTOR ---\n");
                    printf("Nome: %s\n", condutor.nome);
                    printf("RG: %s\n", condutor.rg);
                    printf("Idade: %d\n", condutor.idade);
                    printf("Sinistros: %d\n", condutor.sinistros);
                    printf("Categoria da CNH: %c\n", condutor.cnh);
                } else {
                    printf("\nCondutor nao cadastrado.\n");
                }

                break;
            
            case 4:
                printf("-----NOVO CÁLCULO DE COTAÇÃO-----\n");
                break;
            
            case 5:
                printf("-----CÁLCULO DE COTAÇÃO COM DADOS EXISTENTES----\n");
                break;
            
            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
