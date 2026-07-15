#include <stdio.h>
#include <stdlib.h>
#include "cadastrov.h"
#include "cadastrop.h"
#include "cotacao.h"
#include "relatorio.h"
#include "arquivo.h"

int main() {

    Veiculo veiculo;
    Condutor condutor;

    int totalCotacoes = 0;
    // Carrega as cotações salvas anteriormente (se existirem)
    Cotacao *cotacoes = carregarCotacoes("cotacoes.dat", &totalCotacoes);
    
    int opcao;
    int veiculoCadastrado = 0;
    int condutorCadastrado = 0;
    int existeVeiculo = 0;
    int existeCondutor = 0;
    Cotacao *cotacoes;
    int totalCotacoes = 0;
    int opRelatorio;

cotacoes = carregarCotacoes("cotacoes.dat", &totalCotacoes);

if(cotacoes == NULL){
    cotacoes = malloc(sizeof(Cotacao) * 100);
    totalCotacoes = 0;
}
veiculo = carregarVeiculo("veiculo.dat", &existeVeiculo);
    condutor = carregarCondutor("condutor.dat", &existeCondutor);

    veiculoCadastrado = existeVeiculo;
    condutorCadastrado = existeCondutor;



    do {
        printf("\n====================================\n");
        printf("        MENU PRINCIPAL\n");
        printf("====================================\n");
        printf("1 - Cadastrar Veiculo na base de dados\n");
        printf("2 - Cadastrar Condutor na base de dados\n");
        printf("3 - Exibir base de dados\n");
        printf("4 - Fazer cálculo de cotação com cliente/veículo\n");
        printf("5 - Relatórios\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch(opcao) {

            case 1:
                veiculo = cadastrov();
                veiculoCadastrado = 1;

                 salvarVeiculo("veiculo.dat", &veiculo);

                printf("\nVeiculo salvo com sucesso!\n");


                break;

            case 2:
                condutor = cadastrop();
                condutorCadastrado = 1;

                salvarCondutor("condutor.dat", &condutor);

                printf("\nCondutor salvo com sucesso!\n");
                
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
                 if (!veiculoCadastrado || !condutorCadastrado){
        printf("\nCadastre primeiro um veiculo e um condutor.\n");
        break;
    }

    cotacoes[totalCotacoes] = calculocotacao(&veiculo, &condutor);

    // 2. Realoca memória para caber mais uma cotação (Aumenta o tamanho em +1)
    Cotacao *temp = realloc(cotacoes, sizeof(Cotacao) * (totalCotacoes + 1));
    if (temp == NULL) {
        printf("Erro crítico: Nao foi possivel alocar memoria para salvar a cotacao!\n");
    } else {
        cotacoes = temp;
        cotacoes[totalCotacoes] = nova; // Adiciona a nova cotação no final do vetor
        totalCotacoes++;
    
        // 3. Salva a lista inteira atualizada de volta no arquivo
        if (salvarCotacoes("cotacoes.dat", cotacoes, totalCotacoes)) {
            printf("\nCotacao realizada e salva em disco com sucesso!\n");
        } else {
            printf("\nErro ao salvar a cotacao no arquivo.\n");
        }
    }

    printf("\n===== COTACAO REALIZADA =====\n");
    printf("Premio anual : R$ %.2f\n", cotacoes[totalCotacoes].premio_anual);
    printf("Premio mensal: R$ %.2f\n", cotacoes[totalCotacoes].premio_mensal);

    totalCotacoes++;

    salvarCotacoes("cotacoes.dat", cotacoes, totalCotacoes);

    break;
            
            
            case 5:
                  

    do{

        printf("\n=========== RELATORIOS ===========\n");
        printf("1 - Listar todas as cotacoes\n");
        printf("2 - Buscar cotacao pelo nome\n");
        printf("3 - Mostrar menor cotacao\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opRelatorio);

        while(getchar() != '\n');

        switch(opRelatorio){

            case 1:
                listarCotacoes(cotacoes, totalCotacoes);
                break;

            case 2:
                buscarPorNome(cotacoes, totalCotacoes);
                break;

            case 3:
                menorCotacao(cotacoes, totalCotacoes);
                break;
             case 0:
                printf("\nVoltando ao menu principal...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    }while(opRelatorio != 0);

    break;
    
            
            case 0:
        
                printf("Encerrando o programa...\n");
                if (cotacoes != NULL) {
                    free(cotacoes); // Libera a memória alocada dinamicamente antes de fechar!
                }
                break;
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    free(cotacoes);

    return 0;
}
