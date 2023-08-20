#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncoesUsoGeral.h"
#include "Disciplina.h"


int MenudeDisciplina(){
  int MenuDisciplina;
  printf("\n  1 > Inserir Disciplina \n");
  printf("  2 > Excluir Disciplina \n");
  printf("  3 > Atualizar Cadastro da Disciplina \n");
  scanf("%d", &MenuDisciplina);
  getchar();

  return MenuDisciplina;
}

void InserirDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado){
  printf("Insira a Nome da Disciplina\n");
  fgets(ListaDeDisciplina[qtd_disc_cadastrado].Nome,Tam_Nome_Disc,stdin);
  printf("Insira o Codigo da Disciplina:\n");
  scanf("%d", &ListaDeDisciplina[qtd_disc_cadastrado].Codigo);
  getchar();
  printf("Insira o Semestre\n");
  scanf("%d", &ListaDeDisciplina[qtd_disc_cadastrado].Semestre);
  getchar();
  printf("Insira a nome do Professor correspondente à disciplina:\n");
  fgets(ListaDeDisciplina[qtd_disc_cadastrado].Professor, Tam_Nome, stdin);
}