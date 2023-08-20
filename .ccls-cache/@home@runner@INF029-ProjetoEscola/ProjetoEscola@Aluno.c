#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"
#include "FuncoesUsoGeral.h"

int MenudeAlunos(){
  int MenuAluno;
  printf("\n  1 > Inserir Aluno \n");
  printf("  2 > Excluir Aluno \n");
  printf("  3 > Atualizar Cadastro do Aluno \n");
  scanf("%d", &MenuAluno);
  getchar();
  return MenuAluno;
}

void InserirAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
  printf("Insira a Matrícula\n");
  scanf("%d", &ListaDeAlunos[qtd_alunos_cadastrados].Matricula);
  getchar();
  printf("Insira o nome do aluno:\n");
  fgets(ListaDeAlunos[qtd_alunos_cadastrados].Nome, Tam_Nome, stdin);
  delbar0(ListaDeAlunos[qtd_alunos_cadastrados].Nome);
  printf("Insira o sexo do aluno: M/F\n");
  scanf(" %c", &ListaDeAlunos[qtd_alunos_cadastrados].Sexo);
  getchar();
  printf("Insira a data de nascimento do aluno:\n");
  
  
  printf("Insira o cpf do aluno:\n");
  fgets(ListaDeAlunos[qtd_alunos_cadastrados].Cpf,Tam_Cpf,stdin);
  delbar0(ListaDeAlunos[qtd_alunos_cadastrados].Nome);
  qtd_alunos_cadastrados++;
  
}

void ExcluirAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
  int icont;
  int jcont;
  int matricula;
  printf("Insira a Matrícula do Aluno");
  scanf("%d",&matricula);
  for(icont=0;icont<qtd_alunos_cadastrados+1;icont++)
  {
    if(ListaDeAlunos[icont].Matricula==matricula)
    {
      for(jcont=icont+1;jcont<qtd_alunos_cadastrados;jcont++)
      {
        ListaDeAlunos[jcont-1].Matricula=ListaDeAlunos[jcont].Matricula;
        strcpy(ListaDeAlunos[jcont-1].Cpf,ListaDeAlunos[jcont].Cpf);
        strcpy(ListaDeAlunos[jcont-1].Nome,ListaDeAlunos[jcont].Nome);
        ListaDeAlunos[jcont-1].Sexo=ListaDeAlunos[jcont].Sexo;
        /*strcpy(ListaDeAlunos[jcont-1].DataNasc,ListaDeAlunos[jcont].DataNasc);*/
      }
    }
  }
}

void AtualizarAluno(Aluno ){
	
}
