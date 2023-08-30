#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
#include "FuncoesUsoGeral.h"
#include "Aluno.h"
#include "Disciplina.h"

int MenudeAlunos(){
  int MenuAluno;
  printf("\n  0 > Retornar\n");
  printf("  1 > Inserir aluno \n");
  printf("  2 > Excluir aluno \n");
  printf("  3 > Atualizar cadastro do aluno \n");
  MenuAluno = VerificacaoValorMenu(0,3);
  
  return MenuAluno;
}

void InserirAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados,int qtd_disc_cadastrados){
  int icont;
	ValidarMatricula(ListaDeAlunos[qtd_alunos_cadastrados].Matricula);
	ValidarNome(ListaDeAlunos[qtd_alunos_cadastrados].Nome);
	ValidarSexo(ListaDeAlunos[qtd_alunos_cadastrados].Sexo);
	ValidarData(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data,&ListaDeAlunos[qtd_alunos_cadastrados].DataNasc);
	ValidarCPF(ListaDeAlunos[qtd_alunos_cadastrados].Cpf);
  for(icont=0;icont<qtd_disc_cadastrados;icont++)
    ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[icont]=0;
  
}

void ExcluirAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados,int qtd_disc_cadastrado){//, Disciplina ListaDeDisciplinas[]){
  int icont;
  int jcont;
  int kcont;
  int lcont;
  int mcont;
  int ncont;
  char matricula[Tam_Matricula];
  printf("Insira a matrícula do aluno");
  fgets(matricula,Tam_Matricula,stdin);
  for(icont=0;icont<qtd_alunos_cadastrados+1;icont++)
  {
    if(ListaDeAlunos[icont].Matricula==matricula)
    { 
      if(icont!=qtd_alunos_cadastrados-1)
      {
        for(jcont=icont+1;jcont<qtd_alunos_cadastrados;jcont++)
        {  
          /*for(lcont=0;lcont<qtd_disc_cadastrado;lcont++){
            if(ListaDeAlunos[jcont-1].Qtd_Mat_Cadast[lcont]==1)
              for(mcont=0;mcont<ListaDeDisciplina[lcont].NumAlunos;mcont++)
                if(strcmp(ListaDeDisciplina[lcont].Turma[mcont],matricula)==0)
                  for(ncont=mcont+1;ncont<ListaDeDisciplina[lcont].NumAlunos;ncont++)
                    strcpy(ListaDeDisciplina[lcont].Turma[ncont-1],ListaDeDisciplina[lcont].Turma[ncont]);
          }*/
          strcpy(ListaDeAlunos[jcont-1].Matricula,ListaDeAlunos[jcont].Matricula);
          strcpy(ListaDeAlunos[jcont-1].Nome,ListaDeAlunos[jcont].Nome);
          strcpy(ListaDeAlunos[jcont-1].Cpf,ListaDeAlunos[jcont].Cpf);
          ListaDeAlunos[jcont-1].Sexo=ListaDeAlunos[jcont].Sexo;
          strcpy(ListaDeAlunos[jcont-1].DataNasc.str_data,ListaDeAlunos[jcont].DataNasc.str_data);
          ListaDeAlunos[jcont-1].DataNasc.dia=ListaDeAlunos[jcont].DataNasc.dia;
          ListaDeAlunos[jcont-1].DataNasc.mes=ListaDeAlunos[jcont].DataNasc.mes;
          ListaDeAlunos[jcont-1].DataNasc.ano=ListaDeAlunos[jcont].DataNasc.ano;
          for(kcont=0;kcont < qtd_disc_cadastrado;kcont++){
            ListaDeAlunos[jcont-1].Qtd_Mat_Cadast[kcont]=ListaDeAlunos[jcont].Qtd_Mat_Cadast[kcont];
          }
            
            
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
  printf("Insira a matrícula do aluno: ");
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

int BuscarPosicaoAluno(Aluno alunos[], char matricula[],int qtd_alunos_cadastrados){
  int icont;
  int posicao=-1;
  for(icont=0;icont<qtd_alunos_cadastrados;icont++)
    if(strcmp(matricula, alunos[icont].Matricula)==0)
      posicao = icont;
  return posicao;
}


void PreencherDados(Aluno ListaDeAlunos[],int qtd_alunos_cadastrados){
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Matricula, "202301");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Nome, "Maria Santos");
  ListaDeAlunos[qtd_alunos_cadastrados].Sexo = 'F';
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Cpf, "987.654.321-00");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data, "20/11/2002");
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.dia = 20;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.mes = 11;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.ano = 2002;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3] = 1;

  qtd_alunos_cadastrados++;

  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Matricula, "202302");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Nome, "Joao Silva");
  ListaDeAlunos[qtd_alunos_cadastrados].Sexo = 'M';
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Cpf, "932.615.341-01");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data, "11/04/2001");
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.dia = 11;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.mes = 04;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.ano = 2001;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0] = 0;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2] = 0;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3] = 0;
  qtd_alunos_cadastrados++;

  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Matricula, "202201");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Nome, "Claudio Santos");
  ListaDeAlunos[qtd_alunos_cadastrados].Sexo = 'M';
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Cpf, "912.621.521-01");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data, "03/03/1999");
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.dia = 03;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.mes = 03;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.ano = 1999;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1] = 0;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3] = 0;
  qtd_alunos_cadastrados++;

  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Matricula, "202202");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Nome, "Juliana Oliveira");
  ListaDeAlunos[qtd_alunos_cadastrados].Sexo = 'F';
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Cpf, "127.654.356-05");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data, "01/01/2001");
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.dia = 01;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.mes = 01;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.ano = 2001;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2] = 0;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3] = 0;
  qtd_alunos_cadastrados++;

  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Matricula, "202102");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Nome, "Claudineia Azevedo");
  ListaDeAlunos[qtd_alunos_cadastrados].Sexo = 'F';
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Cpf, "220.376.982-02");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data, "01/06/1997");
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.dia = 01;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.mes = 06;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.ano = 1997;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3] = 0;
  qtd_alunos_cadastrados++;
  

  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Matricula, "202101");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Nome, "Clodovil Oliveira");
  ListaDeAlunos[qtd_alunos_cadastrados].Sexo = 'M';
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Cpf, "349.031.843-00");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data, "03/10/1998");
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.dia = 03;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.mes = 10;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.ano = 1998;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1] = 0;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2] = 0;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3] = 1;
  qtd_alunos_cadastrados++;

  /*strcpy(ListaDeProfessor[qtd_prof_cadastrado].Matricula, "202101");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Nome, "Clodovil Oliveira");
  ListaDeProfessor[qtd_prof_cadastrado].Sexo = 'M';
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Cpf, "349.731.843-00");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data, "03/10/1998");
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.dia = 03;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.mes = 10;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.ano = 1998;
  qtd_prof_cadastrado++;

  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Matricula, "202110");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Nome, "Mario Antonio");
  ListaDeProfessor[qtd_prof_cadastrado].Sexo = 'M';
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Cpf, "349.031.123-00");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data, "17/04/1982");
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.dia = 17;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.mes = 04;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.ano = 1982;
  qtd_prof_cadastrado++;

  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Matricula, "202103");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Nome, "Maria Antonieta dos Santos");
  ListaDeProfessor[qtd_prof_cadastrado].Sexo = 'F';
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Cpf, "169.031.843-00");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data, "02/12/1970");
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.dia = 02;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.mes = 12;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.ano = 1970;
  qtd_prof_cadastrado++;

  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Matricula, "202112");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Nome, "Ana Maria Oliveira");
  ListaDeProfessor[qtd_prof_cadastrado].Sexo = 'F';
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Cpf, "349.077.773-07");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data, "27/02/1988");
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.dia = 27;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.mes = 02;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.ano = 1988;
  qtd_prof_cadastrado++;

  ListaDeDisciplina[qtd_disc_cadastrado]
*/


}