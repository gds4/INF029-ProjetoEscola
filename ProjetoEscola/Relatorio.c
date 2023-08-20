#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "FuncoesUsoGeral.h"

int MenuRelatorios(){
  int MenuRelatorio;
  printf("\n  1 > Listar Alunos \n");
  printf("  2 > Listar Professores \n");
  printf("  3 > Listar Disciplinas \n");
  printf("  4 > Listar uma disciplina \n");
  printf("  5 > Listar Alunos por sexo \n");
  printf("  6 > Listar Alunos ordenados por Nome \n");
  printf("  7 > Listar Alunos ordenados por data de nascimento \n");
  printf("  8 > Listar Professores por sexo \n");
  printf("  9 > Listar Professores ordenados por Nome \n");
  printf("  10 > Listar Professores ordenados por data de nascimento \n");
  printf("  11 > Aniversariantes do mês \n");
  printf("  12 > Lista de pessoas \n");
  printf("  13 > Lista de alunos matriculados em menos de 3 disciplinas \n");
  printf("  14 > Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas. \n");
  scanf("%d", &MenuRelatorio);

  return MenuRelatorio;
}

void ListarAlunos(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
  int icont;
  for(icont=0;icont<qtd_alunos_cadastrados;icont++){
                printf("%d  %s %c %s\n" , ListaDeAlunos[icont].Matricula, ListaDeAlunos[icont].Nome, ListaDeAlunos[icont].Sexo, ListaDeAlunos[icont].Cpf);
              }
}