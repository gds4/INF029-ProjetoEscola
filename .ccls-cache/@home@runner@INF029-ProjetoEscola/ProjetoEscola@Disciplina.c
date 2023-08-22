#include "Disciplina.h"
#include "FuncoesUsoGeral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MenudeDisciplina() {
  int MenuDisciplina;
  printf("\n  1 > Inserir Disciplina \n");
  printf("\n  2 > Excluir Disciplina \n");
  printf("\n  3 > Atualizar Cadastro da Disciplina \n");
  scanf("%d", &MenuDisciplina);
  getchar();

  return MenuDisciplina;
}

void InserirDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado) {

  printf("Insira a nome da disciplina\n");
  fgets(ListaDeDisciplina[qtd_disc_cadastrado].Nome, Tam_Nome_Disc, stdin);

  printf("Insira o Codigo da Disciplina:\n");
  scanf("%d", &ListaDeDisciplina[qtd_disc_cadastrado].Codigo);
  getchar();

  printf("Insira o Semestre\n");
  scanf("%d", &ListaDeDisciplina[qtd_disc_cadastrado].Semestre);
  getchar();

  printf("Insira a nome do Professor correspondente à disciplina:\n");
  fgets(ListaDeDisciplina[qtd_disc_cadastrado].Professor, Tam_Nome, stdin);
}

int AtualizarDisciplina(Disciplina ListaDeDisciplina[], int codigo_disciplina_atualizar, int qtd_disc_cadastrado) {

  
  if(codigo_disciplina_atualizar >=0 && codigo_disciplina_atualizar < qtd_disc_cadastrado){
    printf("Insira o novo nome da disciplina\n");
    fgets(ListaDeDisciplina[codigo_disciplina_atualizar].Nome, Tam_Nome_Disc, stdin);
  
    printf("Insira o novo código da disciplina:\n");
    scanf("%d", &ListaDeDisciplina[codigo_disciplina_atualizar].Codigo);
    getchar();
  
    printf("Insira o novo semestre\n");
    scanf("%d", &ListaDeDisciplina[codigo_disciplina_atualizar].Semestre);
    getchar();
  
    printf("Insira o novo nome do professor correspondente à disciplina:\n");
    fgets(ListaDeDisciplina[codigo_disciplina_atualizar].Professor, Tam_Nome, stdin);
    return 1;
  }
  return 0;
}

void ExcluirDisciplina(Disciplina ListaDeDisciplina[], int QTD_Disc, Codigo codigo) {
  int encontrou = 0;
  int i, j;
  int codigo;
  printf("Insira o código da disciplina a ser excluída:\n");
  for (i=0; i< QTD_Disc; i++){
    if(ListaDeDisciplina[i].Codigo == codigo){
      for(j=i; j < (QTD_Disc - 1); j++){
        ListaDeDisciplina[j].Nome = ListaDeDisciplina[j+1].Nome;
        ListaDeDisciplina[j].Codigo = ListaDeDisciplina[j+1].Codigo;
        ListaDeDisciplina[j].Semestre = ListaDeDisciplina[j+1].Semestre;
        ListaDeDisciplina[j].Professor = ListaDeDisciplina[j+1].Professor;
        
        
      }
      ListaDeDisciplina--;
      encontrou = 1;
      break 
    }
  }
  if (encontrou){
    printf("Disciplina excluída com sucesso!\n");
  } else {
    printf("Código da disciplina inválido!");
  }

  
}
