#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncoesUsoGeral.h"


void delbar0(char string[]){
  int dbcont;
  for(dbcont=0;string[dbcont]!='\0';dbcont++)
    if(string[dbcont]=='\n')
      string[dbcont]='\0';
}

void ValidarNome(char Lista[]){
  char verificacao[200];
  int verif = 0;
  while(verif!=1)
  {    
    printf("\nDigite o Nome (limite de %d caracteres):\n",Tam_Nome-1);
    fgets(verificacao,200,stdin);
    delbar0(verificacao);
    if(strlen(verificacao)<=Tam_Nome-1)
    {
      strcpy(Lista,verificacao);
      verif=1;
    }else
      printf("\nLimite de caracteres excedido. Tente Novamente:\n");
  }
}

int ValidarSexo(char sexo){
  if (sexo == 'M' || sexo == 'm' || sexo == 'f' || sexo == 'F'){
    return 1;
  }
  return 0; 
}

void ValidarMatricula(char Matricula[]){
  char verificacao[20];
  int verif = 0;
  while(verif!=1)
  {    
    printf("\nDigite a Matrícula (limite de %d caracteres):\n",Tam_Matricula-1);
    fgets(verificacao,20,stdin);
    delbar0(verificacao);
    if(strlen(verificacao)==Tam_Matricula-1)
    {
      strcpy(Matricula,verificacao);
      verif=1;
    }else
      printf("\nMatrícula Inválida. Tente Novamente:\n");
  }
}
