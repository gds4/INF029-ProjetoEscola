#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MenudeDisciplina(){
  int MenuDisciplina;
  printf("\n  1 > Inserir Disciplina \n");
  printf("  2 > Excluir Disciplina \n");
  printf("  3 > Atualizar Cadastro da Disciplina \n");
  scanf("%d", &MenuDisciplina);
  getchar();

  return MenuDisciplina;
}