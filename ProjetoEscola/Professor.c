#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Professor.h"


int MenudeProfessores(){
  int MenuProfessor;
  
  printf("\n  1 > Inserir Professor \n");
  printf("  2 > Excluir Professor \n");
  printf("  3 > Atualizar Cadastro do Professor \n");
  scanf("%d", &MenuProfessor);

  return MenuProfessor;
}


