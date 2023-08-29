#include "Professor.h"
#include "FuncoesUsoGeral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int MenudeProfessores() {
  int MenuProfessor;
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
  ValidarSexo(ListaDeProfessor[qtd_prof_cadastrado].Sexo);
  ValidarData(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data,
	  &ListaDeProfessor[qtd_prof_cadastrado].DataNasc);
  ValidarCPF(ListaDeProfessor[qtd_prof_cadastrado].Cpf);
}

void ExcluirProfessor(Professor ListaDeProfessor[], int qtd_prof_cadastrado) {
  int icont;
  int jcont;
  char matriculaprof[Tam_Matricula];
  printf("Insira a Matrícula do Professor");
  fgets(matriculaprof, Tam_Matricula, stdin);
  delbar0(matriculaprof);
  for (icont = 0; icont < qtd_prof_cadastrado + 1; icont++) 
  {
    if (ListaDeProfessor[icont].Matricula == matriculaprof) 
    {
      if(icont!=qtd_prof_cadastrado-1)
      {
        for (jcont = icont + 1; jcont < qtd_prof_cadastrado; jcont++) 
        {
          strcpy(ListaDeProfessor[jcont-1].Matricula,ListaDeProfessor[jcont].Matricula);
          strcpy(ListaDeProfessor[jcont - 1].Cpf, ListaDeProfessor[jcont].Cpf);
          strcpy(ListaDeProfessor[jcont - 1].Nome, ListaDeProfessor[jcont].Nome);
          ListaDeProfessor[jcont - 1].Sexo = ListaDeProfessor[jcont].Sexo;
          strcpy(ListaDeProfessor[jcont-1].DataNasc.str_data,ListaDeProfessor[jcont].DataNasc.str_data);
          ListaDeProfessor[jcont-1].DataNasc.dia=ListaDeProfessor[jcont].DataNasc.dia;
          ListaDeProfessor[jcont-1].DataNasc.mes=ListaDeProfessor[jcont].DataNasc.mes;
          ListaDeProfessor[jcont-1].DataNasc.ano=ListaDeProfessor[jcont].DataNasc.ano;
        }
      }
    }
  }
}

void AtualizarProfessor(Professor ListaDeProfessor[], int qtd_prof_cadastrado) {
  int icont;
  int jcont;
  char matriculaprof[Tam_Matricula];
  int MenuAtualizarprof;
  printf("Insira a Matrícula do professor: ");
  fgets(matriculaprof, Tam_Matricula, stdin);

  for (icont = 0; icont < qtd_prof_cadastrado + 1; icont++) {
    for (jcont = 0; jcont < Tam_Matricula; jcont++) {
      if (ListaDeProfessor[icont].Matricula[jcont] == matriculaprof[jcont]) {
        printf("\nATUALIZAÇÃO DE DADOS PROFESSOR\n\n");
        printf("\nInforme o dado que deseja atualizar\n");
        printf("1 - Matrícula\n");
        printf("2 - Nome\n");
        printf("3 - CPF\n");
        printf("4 - Data de nascimento\n");
        scanf("%d", &MenuAtualizarprof);
        getchar();

        switch (MenuAtualizarprof) {
        case 1:
			ValidarMatricula(ListaDeProfessor[qtd_prof_cadastrado].Matricula);
          	break;

        case 2:
			ValidarNome(ListaDeProfessor[qtd_prof_cadastrado].Nome);
			break;

        case 3:
			ValidarCPF(ListaDeProfessor[qtd_prof_cadastrado].Cpf);
			break;

        case 4:
			ValidarData(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data,&ListaDeProfessor[qtd_prof_cadastrado].DataNasc);
			break;
        }
      } else {
        // printf("Matrícula não encontrada!");
      }
    }
  }
}
