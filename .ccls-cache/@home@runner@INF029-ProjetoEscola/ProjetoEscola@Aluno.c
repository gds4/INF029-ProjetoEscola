#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

int MenudeAlunos(){
  int MenuAluno;
  printf("\n  1 > Inserir Aluno \n");
  printf("  2 > Excluir Aluno \n");
  printf("  3 > Atualizar Cadastro do Aluno \n");
  scanf("%d", &MenuAluno);
  getchar();
  return MenuAluno;
}
