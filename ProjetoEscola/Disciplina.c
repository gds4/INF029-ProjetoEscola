#include "Disciplina.h"
#include "FuncoesUsoGeral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MenudeDisciplina() {
  int MenuDisciplina;
  printf("\n  0 > Retornar\n");
  printf("  1 > Inserir Disciplina \n");
  printf("  2 > Excluir Disciplina \n");
  printf("  3 > Atualizar Cadastro da Disciplina \n");
  MenuDisciplina=VerificacaoValorMenu(0,4);
  getchar();

  return MenuDisciplina;
}

void InserirDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado) {

  printf("\nInsira o nome da disciplina\n");
  fgets(ListaDeDisciplina[qtd_disc_cadastrado].Nome, Tam_Nome_Disc, stdin);

  printf("\nInsira o código da disciplina:\n");
  scanf("%d", &ListaDeDisciplina[qtd_disc_cadastrado].Codigo);
  getchar();

  printf("\nInsira o semestre\n");
  scanf("%d", &ListaDeDisciplina[qtd_disc_cadastrado].Semestre);
  getchar();

  printf("\nInsira a nome do professor correspondente à disciplina:\n");
  fgets(ListaDeDisciplina[qtd_disc_cadastrado].Professor, Tam_Nome, stdin);
}

/*int AtualizarDisciplina(Disciplina ListaDeDisciplina[], int codigo_disciplina_atualizar, int qtd_disc_cadastrado) {

  
  if(codigo_disciplina_atualizar >=0 && codigo_disciplina_atualizar < qtd_disc_cadastrado){
    printf("\nInsira o novo nome da disciplina\n");
    fgets(ListaDeDisciplina[codigo_disciplina_atualizar].Nome, Tam_Nome_Disc, stdin);
  
    printf("\nInsira o novo código da disciplina:\n");
    scanf("%d", &ListaDeDisciplina[codigo_disciplina_atualizar].Codigo);
    getchar();
  
    printf("\nInsira o novo semestre\n");
    scanf("%d", &ListaDeDisciplina[codigo_disciplina_atualizar].Semestre);
    getchar();
  
    printf("\nInsira o novo nome do professor correspondente à disciplina:\n");
    fgets(ListaDeDisciplina[codigo_disciplina_atualizar].Professor, Tam_Nome, stdin);
    return 1;
  }
  return 0;
}*/

int AtualizarDisciplina(Disciplina ListaDeDisciplina[], int codigo_disciplina_atualizar, int qtd_disc_cadastrado) {
    int encontrou = 0;
    int i, j;
    int codigo;
    printf("Insira o código da disciplina que deseja atualizar:\n");
    scanf("%d", &codigo);
    for (i=0; i< qtd_disc_cadastrado; i++){
      if(ListaDeDisciplina[i].Codigo == codigo){
              printf("\n\nDisciplina encontrada\n\n");
              printf("\nInsira o novo nome da disciplina\n");
              fgets(ListaDeDisciplina[qtd_disc_cadastrado].Nome, Tam_Nome_Disc, stdin);
              setbuf(stdin, NULL);
            
              printf("\nInsira o novo código da disciplina:\n");
              scanf("%d", &ListaDeDisciplina[qtd_disc_cadastrado].Codigo);
              setbuf(stdin, NULL);
            
              printf("\nInsira o novo semestre\n");
              scanf("%d", &ListaDeDisciplina[qtd_disc_cadastrado].Semestre);
              setbuf(stdin, NULL);
            
              printf("\nInsira a nome do novo professor correspondente à disciplina:\n");
              fgets(ListaDeDisciplina[qtd_disc_cadastrado].Professor, Tam_Nome, stdin);
        }      
        encontrou = 1;
        break; 
      }
    if (encontrou){
            printf("Disciplina atualizada com sucesso\n ");
            
    } else {
      printf("Código de disciplina inválido\n");
    }
  }
  

void ExcluirDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado) {
  int encontrou = 0;
  int i, j;
  int codigo;
  printf("Insira o código da disciplina a ser excluída:\n");
  scanf("%d", &codigo);
  for (i=0; i< qtd_disc_cadastrado; i++){
    if(ListaDeDisciplina[i].Codigo == codigo){
      for(j=i; j < (QTD_Disc - 1); j++){
        strcpy(ListaDeDisciplina[j].Nome,ListaDeDisciplina[j+1].Nome);
        ListaDeDisciplina[j].Codigo = ListaDeDisciplina[j+1].Codigo;
        ListaDeDisciplina[j].Semestre = ListaDeDisciplina[j+1].Semestre;
        strcpy(ListaDeDisciplina[j].Professor, ListaDeDisciplina[j+1].Professor);      
        
      }      
      encontrou = 1;
      break; 
    }
  }
  if (encontrou){
    printf("Disciplina excluída com sucesso!\n");
  } else {
    printf("Código da disciplina inválido!");
  }

  
}
