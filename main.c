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

    int opcao;
    int veiculoCadastrado = 0;
    int condutorCadastrado = 0;

    int existeVeiculo = 0;
    int existeCondutor = 0;

    Cotacao *cotacoes;
    int totalCotacoes = 0;

    int opRelatorio;



    // CARREGAR DADOS SALVOS

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
        printf("          MENU PRINCIPAL\n");
        printf("====================================\n");

        printf("1 - Cadastrar Veiculo\n");
        printf("2 - Cadastrar Condutor\n");
        printf("3 - Exibir Dados Cadastrados\n");
        printf("4 - Fazer Calculo de Cotacao\n");
        printf("5 - Relatorios\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        while(getchar() != '\n');





        switch(opcao){



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



                if(veiculoCadastrado){


                    printf("\n--- VEICULO ---\n");

                    printf("Marca: %s\n", veiculo.marca);

                    printf("Modelo: %s\n", veiculo.modelo);

                    printf("Ano: %d\n", veiculo.ano);

                    printf("Valor de Mercado: R$ %.2f\n",
                    veiculo.valor_mercado);

                    printf("Tipo: %c\n", veiculo.tipo);


                }
                else{


                    printf("\nVeiculo nao cadastrado.\n");

                }





                if(condutorCadastrado){


                    printf("\n--- CONDUTOR ---\n");

                    printf("Nome: %s\n", condutor.nome);

                    printf("RG: %s\n", condutor.rg);

                    printf("Idade: %d\n", condutor.idade);

                    printf("Sinistros: %d\n", condutor.sinistros);

                    printf("Categoria CNH: %c\n", condutor.cnh);


                }
                else{


                    printf("\nCondutor nao cadastrado.\n");

                }



                break;






            case 4:



                if(!veiculoCadastrado || !condutorCadastrado){


                    printf("\nCadastre primeiro um veiculo e um condutor.\n");

                    break;

                }




                if(totalCotacoes >= 100){


                    printf("\nLimite de cotacoes atingido!\n");

                    break;

                }





                cotacoes[totalCotacoes] =
                calculocotacao(&veiculo, &condutor);




                printf("\n===== COTACAO REALIZADA =====\n");


                printf("Premio anual : R$ %.2f\n",
                cotacoes[totalCotacoes].premio_anual);


                printf("Premio mensal: R$ %.2f\n",
                cotacoes[totalCotacoes].premio_mensal);




                totalCotacoes++;




                salvarCotacoes("cotacoes.dat",
                cotacoes,
                totalCotacoes);



                break;







            case 5:



                do{


                    printf("\n=========== RELATORIOS ===========\n");

                    printf("1 - Listar todas as cotacoes\n");

                    printf("2 - Buscar cotacao pelo nome\n");

                    printf("3 - Mostrar menor cotacao\n");

                    printf("0 - Voltar\n");


                    printf("Escolha: ");

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

                            printf("\nVoltando...\n");

                            break;




                        default:

                            printf("\nOpcao invalida!\n");

                    }



                }while(opRelatorio != 0);



                break;







            case 0:


                printf("\nEncerrando programa...\n");

                break;






            default:


                printf("\nOpcao invalida!\n");


        }



    }while(opcao != 0);





    free(cotacoes);



    return 0;
}