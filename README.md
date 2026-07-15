# Sistema-de-cotas
Integrantes : João Pedro , Arthur Almeida Costa , João Batista , João Vitor Sousa Ramos

================================================================================
          SISTEMA DE COTAÇÃO AUTOMÁTICA DE SEGUROS AUTOMOTIVOS
================================================================================

Este projeto consiste em um sistema de linha de comando escrito em Linguagem C 
para o cálculo e gerenciamento de cotações de seguros veiculares. O programa 
permite o cadastro de veículos e condutores, aplica fatores de risco baseados em 
regras de negócio dinâmicas e persiste as cotações em arquivos binários.

--------------------------------------------------------------------------------
REQUISITOS DO SISTEMA E COMPILAÇÃO
--------------------------------------------------------------------------------

Para compilar e executar o projeto, você precisará de um compilador C (GCC) 
instalado em seu ambiente de desenvolvimento.

A compilação do projeto deve ser realizada utilizando rigorosamente as flags 
de validação exigidas, garantindo a ausência de Warnings e Erros:

Como compilar manualmente via terminal:
    gcc -Wall -Wextra -o cotacao *.c

Como compilar utilizando o Makefile (Requisito 4.5):
    make

Como executar o programa compilado:
    * No Windows (Git Bash/PowerShell/CMD):
      ./cotacao

    * No Linux / macOS:
      ./cotacao

--------------------------------------------------------------------------------
 ARQUITETURA DO PROJETO E MODULARIZAÇÃO
--------------------------------------------------------------------------------

O projeto está estritamente estruturado em módulos independentes (arquivos .c 
e .h), divididos da seguinte forma:

├── main.c           <- Menu principal interativo e controle do fluxo geral
├── veiculo.c/.h     <- Estruturas, cadastros e validações de veículos
├── condutor.c/.h    <- Perfis de condutores, RG e validações de CNH
├── cotacao.c/.h     <- Lógica matemática e aplicação de regras de sinistros
├── arquivo.c/.h     <- Persistência binária (leitura/escrita) e alocação dinâmica
└── relatorio.c/.h   <- Relatório de dados, filtros de buscas e estatísticas

--------------------------------------------------------------------------------
ESTRUTURAS DE DADOS UTILIZADAS (STRUCTS)
--------------------------------------------------------------------------------

O sistema utiliza os seguintes tipos abstratos de dados para gerenciar as cotações:

* Veiculo:
  - Marca (string)
  - Modelo (string)
  - Ano (inteiro)
  - Valor de mercado (real)
  - Tipo: 'P' (Passeio), 'U' (Utilitário) ou 'E' (Esportivo)

* Condutor:
  - Nome completo (string)
  - RG com cinco dígitos (string/char array)
  - Idade (inteiro)
  - Número de sinistros nos últimos 3 anos (inteiro)
  - Categoria da CNH: 'A', 'B' ou 'C'

* Cotacao:
  - Veiculo (composição de structs)
  - Condutor (composição de structs)
  - Prêmio anual (real)
  - Prêmio mensal (real)
  - Data de cálculo (formato DD/MM/AAAA)

--------------------------------------------------------------------------------
REGRAS DE NEGÓCIO (CÁLCULO DO PRÊMIO)
--------------------------------------------------------------------------------

O prêmio anual de seguro obedece à seguinte lógica matemática:

* Taxa Base: 
  - 4.0% sobre o valor de mercado do veículo.

* Acréscimos (cumulativos sobre a taxa base):
  - Veículo com até 3 anos de fabricação: +1.5%
  - Condutor com menos de 25 anos: +2.0%
  - Condutor com 65 anos ou mais: +1.0%
  - Sinistros nos últimos 3 anos: +1.5% por sinistro (limitado ao máximo de 3)

* Descontos:
  - Condutor com CNH categoria C: -0.5% (sobre a taxa base)

* Ajuste de Categoria:
  - Veículos do tipo Esportivo (E) sofrem um fator multiplicador de 1.4x sobre 
    o valor final do prêmio anual calculado.

--------------------------------------------------------------------------------
PERSISTÊNCIA DE DADOS E ALOCAÇÃO DINÂMICA
--------------------------------------------------------------------------------

* Persistência em Arquivo Binário:
  O sistema carrega automaticamente o histórico de cotações
