#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
#include "FuncoesUsoGeral.h"
#include "Aluno.h"
#include "Disciplina.h"

int MenudeAlunos(){
	int MenuAluno;
	printf("\n\n------ MÓDULO ALUNO ------\n");
	printf("\n  0 > Retornar\n");
	printf("  1 > Inserir aluno \n");
	printf("  2 > Excluir aluno \n");
	printf("  3 > Atualizar cadastro do aluno \n");
	MenuAluno = VerificacaoValorMenu(0,3);
	
	return MenuAluno;
}

void InserirAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados,int qtd_disc_cadastrados){
	int icont;
  if(qtd_alunos_cadastrados<QTD_Alunos){
  	ValidarMatricula(ListaDeAlunos[qtd_alunos_cadastrados].Matricula);
  	ValidarNome(ListaDeAlunos[qtd_alunos_cadastrados].Nome);
  	ValidarSexo(&ListaDeAlunos[qtd_alunos_cadastrados].Sexo);
  	ValidarData(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data,
  				&ListaDeAlunos[qtd_alunos_cadastrados].DataNasc);
  	ValidarCPF(ListaDeAlunos[qtd_alunos_cadastrados].Cpf);
  	for(icont=0;icont<qtd_disc_cadastrados;icont++)
  		ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[icont]=0;
  }else printf("\nNúmero máximo de alunos atingido\nNão é possível cadastrar um novo aluno.\n");
  
}

void ExcluirAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados,int qtd_disc_cadastrado, Disciplina ListaDeDisciplina[]){
	
  int icont, jcont, kcont;	
  char matricula[Tam_Matricula];
  int sair=1;
  
  while(sair!=0){
    printf("\nInsira a matrícula do aluno que deseja excluir:\n\n");
    fgets(matricula,Tam_Matricula,stdin);
    delbar0(matricula);
    for(icont=0;icont<qtd_alunos_cadastrados;icont++){
      
      if(strcmp(ListaDeAlunos[icont].Matricula,matricula)==0){
        sair=0;
        if(icont!=qtd_alunos_cadastrados-1){
          for(jcont=icont+1;jcont<qtd_alunos_cadastrados;jcont++){  
            
            strcpy(ListaDeAlunos[jcont-1].Matricula,ListaDeAlunos[jcont].Matricula);
            strcpy(ListaDeAlunos[jcont-1].Nome,ListaDeAlunos[jcont].Nome);
            strcpy(ListaDeAlunos[jcont-1].Cpf,ListaDeAlunos[jcont].Cpf);
            ListaDeAlunos[jcont-1].Sexo=ListaDeAlunos[jcont].Sexo;
            strcpy(ListaDeAlunos[jcont-1].DataNasc.str_data,ListaDeAlunos[jcont].DataNasc.str_data);
            ListaDeAlunos[jcont-1].DataNasc.dia=ListaDeAlunos[jcont].DataNasc.dia;
            ListaDeAlunos[jcont-1].DataNasc.mes=ListaDeAlunos[jcont].DataNasc.mes;
            ListaDeAlunos[jcont-1].DataNasc.ano=ListaDeAlunos[jcont].DataNasc.ano;
            for(kcont=0;kcont < qtd_disc_cadastrado;kcont++)
            {  if(ListaDeAlunos[jcont-1].Qtd_Mat_Cadast[kcont]==1){
                  ListaDeAlunos[jcont-1].Qtd_Mat_Cadast[kcont]=0;
                  ListaDeDisciplina[kcont].NumAlunos--;
                  }
              ListaDeAlunos[jcont-1].Qtd_Mat_Cadast[kcont]=ListaDeAlunos[jcont].Qtd_Mat_Cadast[kcont];
            }
              
              
          }
          break;
        }
      }
    }
    if(sair==1){
      printf("\nMatricula não encontrada. Tente Novamente:\n");
    }
  }
}

void AtualizarAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
	int icont;
	int jcont;
	int sair = 0;
	int sair0 = 0;
	int mat_valida;
	char matricula[Tam_Matricula];
	int MenuAtualizar;

	while(!sair){
		printf("Insira a matrícula do aluno: ");
		fgets(matricula,Tam_Matricula,stdin);
		delbar0(matricula);
		
		mat_valida=BuscarPosicaoAluno(ListaDeAlunos, matricula,qtd_alunos_cadastrados);
		
		if(mat_valida>=0){
			for(icont=0;icont<qtd_alunos_cadastrados+1 && sair == 0;icont++){
				for(jcont=0;jcont<Tam_Matricula && sair == 0;jcont++){
					if(ListaDeAlunos[icont].Matricula[jcont]==matricula[jcont]){
						printf("\nATUALIZAÇÃO DE DADOS: ALUNO\n\n");
						printf("\nInforme o dado que deseja atualizar\n");
						printf("0 - Retornar\n");
						printf("1 - Matrícula\n");
						printf("2 - Nome\n");
						printf("3 - CPF\n");
						printf("4 - Data de nascimento\n");
						printf("5 - Sexo\n");
						MenuAtualizar=VerificacaoValorMenu(0,5);
						
						switch(MenuAtualizar){
							case 0:{
							  	sair = 1;
							  	break;
							}
							case 1:{			  
							  	ValidarMatricula(ListaDeAlunos[qtd_alunos_cadastrados].Matricula);
								break;
							}
							
							case 2:{
							  	ValidarNome(ListaDeAlunos[qtd_alunos_cadastrados].Nome);
								break;
							}
							case 3:{
							  	ValidarCPF(ListaDeAlunos[qtd_alunos_cadastrados].Cpf);
								break;
							}
							
							case 4:{
							  	ValidarData(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data,
											&ListaDeAlunos[qtd_alunos_cadastrados].DataNasc);
								break;
							}
							case 5:{
								  ValidarSexo(&ListaDeAlunos[qtd_alunos_cadastrados].Sexo);
								  break;
							}
						}
					}
				}
			}
		}else printf("Matrícula não Encontrada! Tente Novamente.");
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
