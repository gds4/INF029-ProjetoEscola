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