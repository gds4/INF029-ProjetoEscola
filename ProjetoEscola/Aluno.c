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

void AtualizarAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
  int icont;
  int jcont;
  int matricula;
  int MenuAtualizar;
  printf("Insira a Matrícula do Aluno: ");
  scanf("%d",&matricula);

  for(icont=0;icont<qtd_alunos_cadastrados+1;icont++){
	  if(ListaDeAlunos[icont].Matricula==matricula){
		  printf("\nATUALIZAÇÃO DE DADOS\n\n");
		  printf("\nInforme o dado que deseja atualizar\n");
		  printf("1 - Matrícula\n");
		  printf("2 - Nome\n");
		  printf("3 - CPF\n");
		  printf("4 - Data de nascimento\n");
		  scanf("%d", &MenuAtualizar);
		  getchar();

		  switch(MenuAtualizar){
			  case 1:			  
				  printf("\nInforme a matrícula: ");
				  //fgets(ListaDeAlunos[icont].Matricula,Tam_Matricula,stdin);
			  	break;

			  case 2:
			  	  printf("\nInforme o nome: ");
			  	  fgets(ListaDeAlunos[icont].Nome,Tam_Nome,stdin);
				  getchar();
			  	break;
			  
			  case 3:
			  	  printf("\nInforme o CPF: ");
			  	  fgets(ListaDeAlunos[icont].Cpf,Tam_Cpf,stdin);
			  	break;

			  case 4:
			  	  /*printf("\nInforme a data de nascimento (apenas números): ");
			  	  scanf("%d %d %d", &ListaDeAlunos[icont].DataNasc.dia, 
					&ListaDeAlunos[icont].DataNasc.mes, &ListaDeAlunos[icont].DataNasc.ano);*/
			  	break;
		  }
	  }else{
		  //printf("Matrícula não encontrada!");
	  }
  }
}
