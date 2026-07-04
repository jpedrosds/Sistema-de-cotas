#ifndef CADASTROP_H
#define CADASTROP_H

typedef struct {
      char nome[80];
      char rg[5];
      int  idade;
      int  sinistros;
      char cnh;             /* 'A', 'B' ou 'C' */
  } Condutor;

  Condutor cadastrop();

  #endif
