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
  if(qtd_prof_cadastrado<QTD_Professor){
    ValidarMatricula(ListaDeProfessor[qtd_prof_cadastrado].Matricula);
    ValidarNome(ListaDeProfessor[qtd_prof_cadastrado].Nome);
    ValidarSexo(&ListaDeProfessor[qtd_prof_cadastrado].Sexo);
    ValidarData(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data,
  	  &ListaDeProfessor[qtd_prof_cadastrado].DataNasc);
    ValidarCPF(ListaDeProfessor[qtd_prof_cadastrado].Cpf);

    printf("\nProfessor Inserido com Sucesso!\n");
  }else printf("\nNúmero máximo de professores atingido\nNão é possível cadastrar um novo professor.\n");
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

  int icont;
  int jcont;
  int sair=1;
  int mat_valida;
  char matriculaprof[Tam_Matricula];
  int MenuAtualizarprof;

  if(qtd_prof_cadastrado>0){
    while(sair!=0){
      printf("\nInsira a Matrícula do professor: \n");
      fgets(matriculaprof, Tam_Matricula, stdin);
      delbar0(matriculaprof);
  
      mat_valida = BuscarPosicaoProfessor(ListaDeProfessor, matriculaprof,qtd_prof_cadastrado);
      
      if(mat_valida>=0){
        
        getchar();
        printf("\nATUALIZAÇÃO DE DADOS: PROFESSOR\n\n");
        printf("\nInforme o dado que deseja atualizar\n");
        printf("0 - Retornar\n");
        printf("1 - Matrícula\n");
        printf("2 - Nome\n");
        printf("3 - CPF\n");
        printf("4 - Data de nascimento\n");
        printf("5 - Sexo\n");
        MenuAtualizarprof = VerificacaoValorMenu(0,5);
        
  
        switch (MenuAtualizarprof) {
          case 0:{
            sair=0;
            break;
          }
          case 1:{
            ValidarMatricula(ListaDeProfessor[mat_valida].Matricula);
            sair=0;
            break;
          }
          case 2:{
           ValidarNome(ListaDeProfessor[mat_valida].Nome);
            sair=0;
           break;
          }
          case 3:{
            ValidarCPF(ListaDeProfessor[mat_valida].Cpf);
            sair=0;
             break;
          }
          case 4:{
            ValidarData(ListaDeProfessor[mat_valida].DataNasc.str_data,
          &ListaDeProfessor[mat_valida].DataNasc);
            sair=0;
             break;
          }
          case 5:{
            ValidarSexo(&ListaDeProfessor[mat_valida].Sexo);
            sair=0;
            break;
          }
        }
      }else printf("\nMatrícula não encontrada.\n");
    }
  }else printf("\nNão há professores cadastrados no sistema.\n");
}

void ValidarNomeProf(char professor[], Professor ListaDeProfessor[], int qtd_prof_cadast){
  int Existeprof=0;
  int icont;
  int valido=1;
  char comparar[Tam_Nome];
  
  if(qtd_prof_cadast==0)
  {
    printf("\nNão existe professor cadastrado no sistema.\n\n");
    valido=0;
  }
  //else
  while(valido!=0)
  {
    printf("\nInsira o nome do professor referente a disciplina\n\n");
    fgets(comparar, Tam_Nome, stdin);
    delbar0(comparar);
    Existeprof=0;
    for(icont=0;icont<qtd_prof_cadast;icont++)
    {
      if(strcmp(comparar, ListaDeProfessor[icont].Nome)==0)
      {
        Existeprof=1;
        break;
      }
    }
    if(Existeprof){
      strcpy(professor,comparar);
      valido=0;
    }else printf("Nome não encontrado. Tente novamente.\n");
  }
}

int BuscarPosicaoProfessor(Professor ListaDeProfessores[], char matricula[],int qtd_prof_cadastrados){
  int icont;
  int posicao=-1;
  for(icont=0;icont<qtd_prof_cadastrados;icont++)
    if(strcmp(matricula, ListaDeProfessores[icont].Matricula)==0)
      posicao = icont;
  return posicao;
}
