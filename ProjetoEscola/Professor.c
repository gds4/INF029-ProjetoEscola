#include "Professor.h"
#include "FuncoesUsoGeral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int MenudeProfessores() {
	int MenuProfessor;
	printf("\n\n------ MÓDULO PROFESSOR ------\n");
	printf("\n  0 > Retornar\n");
	printf("  1 > Inserir Professor \n");
	printf("  2 > Excluir Professor \n");
	printf("  3 > Atualizar Cadastro do Professor \n");
	MenuProfessor=VerificacaoValorMenu(0,3);
	
	return MenuProfessor;
}

void InserirProfessor(Professor ListaDeProfessor[], int qtd_prof_cadastrado) {
  ValidarMatricula(ListaDeProfessor[qtd_prof_cadastrado].Matricula);
  ValidarNome(ListaDeProfessor[qtd_prof_cadastrado].Nome);
  ValidarSexo(&ListaDeProfessor[qtd_prof_cadastrado].Sexo);
  ValidarData(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data,
	  &ListaDeProfessor[qtd_prof_cadastrado].DataNasc);
  ValidarCPF(ListaDeProfessor[qtd_prof_cadastrado].Cpf);
}

void ExcluirProfessor(Professor ListaDeProfessor[], int qtd_prof_cadastrado) {
  int icont;
  int jcont;
  char matriculaprof[Tam_Matricula];
  int sair = 1;
  while (sair != 0) {
    printf("\nInsira a Matrícula do Professor que deseja excluir:\n\n");
    fgets(matriculaprof, Tam_Matricula, stdin);
    delbar0(matriculaprof);

    for (icont = 0; icont < qtd_prof_cadastrado; icont++) {
      if (strcmp(ListaDeProfessor[icont].Matricula, matriculaprof) == 0) {
        sair = 0;
        if (icont != qtd_prof_cadastrado - 1) {
          for (jcont = icont + 1; jcont < qtd_prof_cadastrado; jcont++) {
            if (jcont < qtd_prof_cadastrado) {
              strcpy(ListaDeProfessor[jcont - 1].Matricula, ListaDeProfessor[jcont].Matricula);
              strcpy(ListaDeProfessor[jcont - 1].Cpf, ListaDeProfessor[jcont].Cpf);
              strcpy(ListaDeProfessor[jcont - 1].Nome, ListaDeProfessor[jcont].Nome);
              ListaDeProfessor[jcont - 1].Sexo = ListaDeProfessor[jcont].Sexo;
              strcpy(ListaDeProfessor[jcont - 1].DataNasc.str_data, ListaDeProfessor[jcont].DataNasc.str_data);
              ListaDeProfessor[jcont - 1].DataNasc.dia = ListaDeProfessor[jcont].DataNasc.dia;
              ListaDeProfessor[jcont - 1].DataNasc.mes = ListaDeProfessor[jcont].DataNasc.mes;
              ListaDeProfessor[jcont - 1].DataNasc.ano = ListaDeProfessor[jcont].DataNasc.ano;
            }
          }
          break;
        }
      }
      
      
    }
    if (sair != 0) {
      printf("\nMatrícula não Encontrada. Tente Novamente:\n\n");
    }else if(sair==0)
       printf("\nProfessor Excluído com sucesso!\n\n");
  }
}

void AtualizarProfessor(Professor ListaDeProfessor[], int qtd_prof_cadastrado) {
  int mat_encontrado=0;
  int icont;
  int jcont;
  int sair=1;
  char matriculaprof[Tam_Matricula];
  int MenuAtualizarprof;
  while(sair!=0){
    printf("Insira a Matrícula do professor: ");
    fgets(matriculaprof, Tam_Matricula, stdin);
    delbar0(matriculaprof);
  
    for (icont = 0; icont < qtd_prof_cadastrado + 1; icont++) {
      if (strcmp(ListaDeProfessor[icont].Matricula,matriculaprof)==0) {
        printf("\nATUALIZAÇÃO DE DADOS: PROFESSOR\n\n");
        printf("\nInforme o dado que deseja atualizar\n");
        printf("1 - Matrícula\n");
        printf("2 - Nome\n");
        printf("3 - CPF\n");
        printf("4 - Data de nascimento\n");
        printf("5 - Sexo\n");
        MenuAtualizarprof = VerificacaoValorMenu(0,5);
        mat_encontrado=1;

        switch (MenuAtualizarprof) {
          case 1:{
        	  ValidarMatricula(ListaDeProfessor[qtd_prof_cadastrado].Matricula);
            break;
          }
          case 2:{
           ValidarNome(ListaDeProfessor[qtd_prof_cadastrado].Nome);
           break;
          }
          case 3:{
            ValidarCPF(ListaDeProfessor[qtd_prof_cadastrado].Cpf);
             break;
          }
          case 4:{
            ValidarData(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data,
          &ListaDeProfessor[qtd_prof_cadastrado].DataNasc);
             break;
          }
          case 5:{
            ValidarSexo(&ListaDeProfessor[qtd_prof_cadastrado].Sexo);
            break;
          }
        }
      }
      if(icont==qtd_prof_cadastrado-1 && mat_encontrado==0){
        printf("Matrícula não encontrada!");
      }else
        sair=0;
    
    }
  }
}

/*
void ImprimeProfessor(Professor ListaDeProfessor[], int qtd_prof_cadastrado, char Matricula){
  int matricula;
	int j;
  for(j = 0; j <  qtd_prof_cadastrado; j++){
        if (ListaDeProfessor[j].Matricula == matricula){
            printf("%s\n", ListaDeProfessor[j].Nome);
            break;
        }    
    }
}*/