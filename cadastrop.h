#ifndef CADASTROP_H
#define CADASTROP_H

typedef struct {
      char nome[80];
      char rg[6];
      int  idade;
      int  sinistros;
      char cnh;
  } Condutor;

  Condutor cadastrop();

  #endif
