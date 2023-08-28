#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
#include "FuncoesUsoGeral.h"
#include "Aluno.h"

int MenudeAlunos(){
  int MenuAluno;
  printf("\n  0 > Retornar\n");
  printf("  1 > Inserir Aluno \n");
  printf("  2 > Excluir Aluno \n");
  printf("  3 > Atualizar Cadastro do Aluno \n");
  MenuAluno = VerificacaoValorMenu(0,3);
  
  return MenuAluno;
}

void InserirAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
  
	ValidarMatricula(ListaDeAlunos[qtd_alunos_cadastrados].Matricula);
	ValidarNome(ListaDeAlunos[qtd_alunos_cadastrados].Nome);
	ValidarSexo(ListaDeAlunos[qtd_alunos_cadastrados].Sexo);
	ValidarData(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data,&ListaDeAlunos[qtd_alunos_cadastrados].DataNasc);
	ValidarCPF(ListaDeAlunos[qtd_alunos_cadastrados].Cpf);
  
  
}

void ExcluirAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
  int icont;
  int jcont;
  char matricula[Tam_Matricula];
  printf("Insira a Matrícula do Aluno");
  fgets(matricula,Tam_Matricula,stdin);
  for(icont=0;icont<qtd_alunos_cadastrados+1;icont++)
  {
    if(ListaDeAlunos[icont].Matricula==matricula)
    { 
      if(icont!=qtd_alunos_cadastrados-1)
      {
        for(jcont=icont+1;jcont<qtd_alunos_cadastrados;jcont++)
        {
          strcpy(ListaDeAlunos[jcont-1].Matricula,ListaDeAlunos[jcont].Matricula);
          strcpy(ListaDeAlunos[jcont-1].Cpf,ListaDeAlunos[jcont].Cpf);
          strcpy(ListaDeAlunos[jcont-1].Nome,ListaDeAlunos[jcont].Nome);
          ListaDeAlunos[jcont-1].Sexo=ListaDeAlunos[jcont].Sexo;
          strcpy(ListaDeAlunos[jcont-1].DataNasc.str_data,ListaDeAlunos[jcont].DataNasc.str_data);
          ListaDeAlunos[jcont-1].DataNasc.dia=ListaDeAlunos[jcont].DataNasc.dia;
          ListaDeAlunos[jcont-1].DataNasc.mes=ListaDeAlunos[jcont].DataNasc.mes;
          ListaDeAlunos[jcont-1].DataNasc.ano=ListaDeAlunos[jcont].DataNasc.ano;
        }
      }
    }
  }
}

void AtualizarAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
  int icont;
  int jcont;
  int sair = 0;
  char matricula[Tam_Matricula];
  int MenuAtualizar;
  printf("Insira a Matrícula do Aluno: ");
  fgets(matricula,Tam_Matricula,stdin);

    while(!sair){
	  for(icont=0;icont<qtd_alunos_cadastrados+1 && sair == 0;icont++){
		  for(jcont=0;jcont<Tam_Matricula && sair == 0;jcont++){
			  if(ListaDeAlunos[icont].Matricula[jcont]==matricula[jcont]){
				  printf("\nATUALIZAÇÃO DE DADOS\n\n");
				  printf("\nInforme o dado que deseja atualizar\n");
				  printf("0 - Retornar\n");
				  printf("1 - Matrícula\n");
				  printf("2 - Nome\n");
				  printf("3 - CPF\n");
				  printf("4 - Data de nascimento\n");
				  scanf("%d", &MenuAtualizar);
				  getchar();
		
				  switch(MenuAtualizar){
					  case 0:
					  	  sair = 1;
					  	  break;
					  case 1:			  
						  ValidarMatricula(ListaDeAlunos[qtd_alunos_cadastrados].Matricula);
					  	break;
		
					  case 2:
					  	  ValidarNome(ListaDeAlunos[qtd_alunos_cadastrados].Nome);
					  	break;
					  
					  case 3:
					  	  ValidarCPF(ListaDeAlunos[qtd_alunos_cadastrados].Cpf);
					  	break;
		
					  case 4:
					  	  ValidarData(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data,&ListaDeAlunos[qtd_alunos_cadastrados].DataNasc);
					  	break;
				  }
			  }else{
				  //printf("Matrícula não encontrada!");
			  }
		  }
		}
    }
}


