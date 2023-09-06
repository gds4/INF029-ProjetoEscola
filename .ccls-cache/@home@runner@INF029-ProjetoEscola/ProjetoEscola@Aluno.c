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
    printf("\nAluno inserido com sucesso!\n");
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
  if(qtd_alunos_cadastrados>0){
  	while(!sair){
  		printf("\nInsira a matrícula do aluno: \n");
  		fgets(matricula,Tam_Matricula,stdin);
  		delbar0(matricula);
  		
  		mat_valida=BuscarPosicaoAluno(ListaDeAlunos, matricula,qtd_alunos_cadastrados);
  		
  		if(mat_valida>=0){
        
              getchar();
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
  							  ValidarMatricula(ListaDeAlunos[mat_valida].Matricula);
                  printf("\nMatrícula stualizada com sucesso!\n");
                  sair = 1;
  								break;
  							}
  							
  							case 2:{
  							  ValidarNome(ListaDeAlunos[mat_valida].Nome);
                  printf("\nNome atualizado com sucesso!\n");
                  sair = 1;
  								break;
  							}
  							case 3:{
  							  ValidarCPF(ListaDeAlunos[mat_valida].Cpf);
                  printf("\nCPF atualizado com sucesso!\n");
                  sair = 1;
  								break;
  							}
  							
  							case 4:{
  							  ValidarData(ListaDeAlunos[mat_valida].DataNasc.str_data,
  											&ListaDeAlunos[mat_valida].DataNasc);
                  printf("\nData de nascimento atualizada com Sucesso!\n");
                  sair = 1;
  								break;
  							}
  							case 5:{
  								ValidarSexo(&ListaDeAlunos[mat_valida].Sexo);
                  printf("\nSexo Atualizado com Sucesso!\n");
                  sair = 1;
  								break;
  							}
  						}
  		}else printf("\nMatrícula não Encontrada! Tente Novamente.\n");
  	}
  }else printf("\nNão há alunos cadastrados no sistema.\n");
}

int BuscarPosicaoAluno(Aluno alunos[], char matricula[],int qtd_alunos_cadastrados){
  int icont;
  int posicao=-1;
  for(icont=0;icont<qtd_alunos_cadastrados;icont++)
    if(strcmp(matricula, alunos[icont].Matricula)==0)
      posicao = icont;
  return posicao;
}

int verificarExistenciaMatricula(Aluno alunos[], int qtd_alunos_cadastrados, const char *matricula) {
    int icont;
    for (icont = 0; icont < qtd_alunos_cadastrados; icont++) {
        if (strcmp(alunos[icont].Matricula, matricula) == 0) {
            return 1;
        }
    }
    return 0;
}

void SalvarAluno(Aluno ListadeAlunos[],int qtd_alunos_cadastrados){
  FILE *Alunos;
  Alunos = fopen("dados_alunos.txt", "w+");
  int icont;
  for(icont=0;icont<qtd_alunos_cadastrados;icont++){
    fprintf(Alunos,"A;%s;%s;%c;%s;%s;%d;%d;%d;", 
      ListadeAlunos[icont].Matricula,
      ListadeAlunos[icont].Nome,
      ListadeAlunos[icont].Sexo,ListadeAlunos[icont].Cpf,
      ListadeAlunos[icont].DataNasc.str_data,
      ListadeAlunos[icont].DataNasc.dia,
      ListadeAlunos[icont].DataNasc.mes,
      ListadeAlunos[icont].DataNasc.ano);
  }
  fclose(Alunos);
}

void RecuperarAluno(){
  FILE *Alunos;
  char aluno[Tam_Linha_dados_alunos];

  fgets(aluno,Tam_Linha_dados_alunos,Alunos);

  while(!feof(Alunos))
    fgets(aluno,Tam_Linha_dados_alunos,Alunos);
}