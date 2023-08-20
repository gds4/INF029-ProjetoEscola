#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Professor.h"
#include "FuncoesUsoGeral.h"


int MenudeProfessores(){
  int MenuProfessor;
  
  printf("\n  1 > Inserir Professor \n");
  printf("  2 > Excluir Professor \n");
  printf("  3 > Atualizar Cadastro do Professor \n");
  scanf("%d", &MenuProfessor);

  return MenuProfessor;
}

void InserirProfessor(Professor ListaDeProfessor[],int qtd_prof_cadastrado){
  printf("Insira a Matrícula\n");
  scanf("%d", &ListaDeProfessor[qtd_prof_cadastrado].Matricula);
  getchar();
  printf("Insira o nome do Professor:\n");
  fgets(ListaDeProfessor[qtd_prof_cadastrado].Nome, Tam_Nome, stdin);
  delbar0(ListaDeProfessor[qtd_prof_cadastrado].Nome);
  printf("Insira o sexo do Professor: M/F\n");
  scanf(" %c", &ListaDeProfessor[qtd_prof_cadastrado].Sexo);
  getchar();
  /*printf("Insira a data de nascimento do Professor:\n");
  fgets(ListaDeProfessor[qtd_prof_cadastrado].DataNasc, Tam_Data, stdin);
  delbar0(ListaDeProfessor[qtd_prof_cadastrado].DataNasc);*/            
  printf("Insira o cpf do Professor:\n");
  fgets(ListaDeProfessor[qtd_prof_cadastrado].Cpf,Tam_Cpf,stdin);
  delbar0(ListaDeProfessor[qtd_prof_cadastrado].Cpf);
  
}

void ExcluirProfessor(Professor ListaDeProfessor[],int qtd_prof_cadastrado){
  int icont;
  int jcont;
  int matriculaprof;
  printf("Insira a Matrícula do Professor");
  scanf("%d",&matriculaprof);
  for(icont=0;icont<qtd_prof_cadastrado+1;icont++){
    if(ListaDeProfessor[icont].Matricula==matriculaprof){
      for(jcont=icont+1;jcont<qtd_prof_cadastrado;jcont++){
        ListaDeProfessor[jcont-1].Matricula=ListaDeProfessor[jcont].Matricula;
        strcpy(ListaDeProfessor[jcont-1].Cpf,ListaDeProfessor[jcont].Cpf);
        strcpy(ListaDeProfessor[jcont-1].Nome,ListaDeProfessor[jcont].Nome);
        ListaDeProfessor[jcont-1].Sexo=ListaDeProfessor[jcont].Sexo;
        /*strcpy(ListaDeProfessor[jcont-1].DataNasc,ListaDeProfessor[jcont].DataNasc);*/
        
      }
    }
  }
}

void AtualizarProfessor(Professor ListaDeProfessor[], int qtd_prof_cadastrado){
  int icont;
  int jcont;
  int matriculaprof;
  int MenuAtualizarprof;
  printf("Insira a Matrícula do Aluno: ");
  scanf("%d",&matriculaprof);

  for(icont=0;icont<qtd_prof_cadastrado+1;icont++){
	  if(ListaDeProfessor[icont].Matricula==matriculaprof){
		  printf("\nATUALIZAÇÃO DE DADOS PROFESSOR\n\n");
		  printf("\nInforme o dado que deseja atualizar\n");
		  printf("1 - Matrícula\n");
		  printf("2 - Nome\n");
		  printf("3 - CPF\n");
		  printf("4 - Data de nascimento\n");
		  scanf("%d", &MenuAtualizarprof);
		  getchar();

		  switch(MenuAtualizarprof){
			  case 1:			  
				  printf("\nInforme a matrícula: ");
				  //fgets(ListaDeProfessor[icont].Matricula,Tam_Matricula,stdin);
			  	break;

			  case 2:
			  	  printf("\nInforme o nome: ");
			  	  fgets(ListaDeProfessor[icont].Nome,Tam_Nome,stdin);
				  getchar();
			  	break;
			  
			  case 3:
			  	  printf("\nInforme o CPF: ");
			  	  fgets(ListaDeProfessor[icont].Cpf,Tam_Cpf,stdin);
			  	break;

			  case 4:
			  	  /*printf("\nInforme a data de nascimento (apenas números): ");
			  	  scanf("%d %d %d", &ListaDeProfessor[icont].DataNasc.dia, 
					&ListaDeAlunos[icont].DataNasc.mes, 			 	 
					&ListaDeProfessor[icont].DataNasc.ano);*/
			  	break;
		  }
	  }else{
		  //printf("Matrícula não encontrada!");
	  }
  }
}