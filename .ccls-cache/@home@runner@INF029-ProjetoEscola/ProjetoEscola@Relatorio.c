#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncoesUsoGeral.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

int MenuRelatorios(){
  int MenuRelatorio;
  printf("\n  0 > Retornar\n");
  printf("  1 > Listar Alunos \n");
  printf("  2 > Listar Professores \n");
  printf("  3 > Listar Disciplinas \n");
  printf("  4 > Listar uma disciplina \n");
  printf("  5 > Listar Alunos por sexo \n");
  printf("  6 > Listar Alunos ordenados por Nome \n");
  printf("  7 > Listar Alunos ordenados por data de nascimento \n");
  printf("  8 > Listar Professores por sexo \n");
  printf("  9 > Listar Professores ordenados por Nome \n");
  printf("  10 > Listar Professores ordenados por data de nascimento \n");
  printf("  11 > Aniversariantes do mês \n");
  printf("  12 > Lista de pessoas \n");
  printf("  13 > Lista de alunos matriculados em menos de 3 disciplinas \n");
  printf("  14 > Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas. \n");
  MenuRelatorio=VerificacaoValorMenu(0,14);

  return MenuRelatorio;
}

void ListarAlunos(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
  int icont;
  printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
    
    for(icont=0;icont<qtd_alunos_cadastrados;icont++){
      printf("%-9s %-30s %-4c %-15s %.2d/%.2d/%d\n", ListaDeAlunos[icont].Matricula, 
                                                     ListaDeAlunos[icont].Nome, 
                                                     ListaDeAlunos[icont].Sexo, 
                                                     ListaDeAlunos[icont].Cpf,
                    										             ListaDeAlunos[icont].DataNasc.dia,
									                    	             ListaDeAlunos[icont].DataNasc.mes,
		  								                               ListaDeAlunos[icont].DataNasc.ano);

	/*printf("\n--------------------------------------------------------\n");
 	printf("\nMatrícula\n");
    printf("------------\n");
	printf(" %-9s\n", ListaDeAlunos[icont].Matricula);
 	printf("------------\n");
  	printf("\nNome\n");
   	printf("--------------------------------\n");
   	printf(" %-30s\n", ListaDeAlunos[icont].Nome);
	printf("--------------------------------\n");
 	printf("\nSexo\n");
  	printf("-----\n");
   	printf("  %-4c\n", ListaDeAlunos[icont].Sexo);
	printf("-----\n");
 	printf("\nCPF\n");
  	printf("-----------------\n");
   	printf(" %-15s", ListaDeAlunos[icont].Cpf);
	printf("-----------------\n");
 	printf("\nData de nascimento\n");
  	printf("------------------\n");
   	printf(" %.2d/%.2d/%d\n", ListaDeAlunos[icont].DataNasc.dia,
							ListaDeAlunos[icont].DataNasc.mes,
		  					ListaDeAlunos[icont].DataNasc.ano);
	printf("------------------\n");
	
 	printf("\n--------------------------------------------------------\n");*/
	}
}

void ListarProfessor(Professor ListaDeProfessor[], int qtd_prof_cadastrado){
  int icont;
  printf("%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",     
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
    
    for(icont=0;icont<qtd_prof_cadastrado;icont++)
      printf("%-9s %-30s %-4c %-15s \n", ListaDeProfessor[icont].Matricula, 
                                         ListaDeProfessor[icont].Nome, 
                                         ListaDeProfessor[icont].Sexo, 
                                         ListaDeProfessor[icont].Cpf);
}


void ListarProfessorSexo (Professor ListaDeProfessor[], int qtd_prof_cadastrado){
  int icont;
  printf("\nLista de Professores do sexo masculino\n");
    for (icont = 0; icont < qtd_prof_cadastrado; icont++)
    {
      if ((ListaDeProfessor[icont].Sexo == 'M') || (ListaDeProfessor[icont].Sexo == 'm'))
        printf(" %s \n", ListaDeProfessor[icont].Nome);
    }

  printf("\nLista de Professores do sexo feminino\n");
    for (icont = 0; icont < qtd_prof_cadastrado; icont++){
      if ((ListaDeProfessor[icont].Sexo == 'F') || (ListaDeProfessor[icont].Sexo == 'f'))
        printf(" %s \n", ListaDeProfessor[icont].Nome);
    }
}
    


void ListarDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado){
  int icont;
 // int jcont;
  
  for(icont = 0; icont < qtd_disc_cadastrado; icont++)
  {
    printf("\nLista de Disciplinas\n");
    puts(ListaDeDisciplina[icont].Nome);
    printf("%d \n", ListaDeDisciplina[icont].Codigo);
    printf("%d  \n", ListaDeDisciplina[icont].Semestre);
    printf("%s \n", ListaDeDisciplina[icont].Professor);
      //lista de alunos em cada disciplina
  }
}   

void ListarUmaDisciplina(Disciplina ListaDeDisciplina[] , int qtd_disc_cadastrado, int disciplina){
  int icont;  
  for(icont = 0; icont < qtd_disc_cadastrado; icont++)
  {
    if (ListaDeDisciplina[icont].Nome == disciplina)
    {
       printf("%-9s %-30s %-4c %-15s \n",  ListaDeDisciplina[icont].Nome,  
                                           ListaDeDisciplina[icont].Codigo,     
                                           ListaDeDisciplina[icont].Semestre,  
                                           ListaDeDisciplina[icont].Professor);     
    } else {
      printf("\nA disciplina não existe");
    }
  }
  
}

void ListarAlunoSexo (Aluno ListaDeAluno[], int qtd_alunos_cadastrados){
  int icont;
  printf("\nLista de alunos por sexo masculino\n");
    for (icont = 0; icont < qtd_alunos_cadastrados; icont++)
    {
      if ((ListaDeAluno[icont].Sexo == 'M') || (ListaDeAluno[icont].Sexo == 'm'))
      {        
        printf("%-9s %-30s %-4c %-15s \n",  ListaDeAluno[icont].Nome,  
                                            ListaDeAluno[icont].Matricula, 
                                            ListaDeAluno[icont].Sexo,    
                                            ListaDeAluno[icont].DataNasc,
                                            ListaDeAluno[icont].Cpf);
      }
    }
  
  printf("\nLista de alunos por sexo feminino\n");
    for (icont = 0; icont < qtd_alunos_cadastrados; icont++)
    {
      if ((ListaDeAluno[icont].Sexo == 'F') || (ListaDeAluno[icont].Sexo == 'f'))
      {        
        printf("%-9s %-30s %-4c %-15s \n",  ListaDeAluno[icont].Nome,  
                                            ListaDeAluno[icont].Matricula, 
                                            ListaDeAluno[icont].Sexo,
                                            ListaDeAluno[icont].DataNasc,
                                            ListaDeAluno[icont].Cpf);
      }
    }
}

void ListarAlunosNome(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
	int icont;
	int jcont;
	int comparar;
	char aux[Tam_Nome];
	for(icont = 0; icont < qtd_alunos_cadastrados - 1;icont++){
		for(jcont = icont + 1; jcont < qtd_alunos_cadastrados; jcont++){
			comparar = strcmp(ListaDeAlunos[icont].Nome, ListaDeAlunos[jcont].Nome);
			if(comparar > 0){
				strcpy(aux, ListaDeAlunos[icont].Nome);
				strcpy(ListaDeAlunos[icont].Nome, ListaDeAlunos[jcont].Nome);
				strcpy(ListaDeAlunos[jcont].Nome, aux);
			}
		}
	}
	
	printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
	
	
    for(icont=0;icont<qtd_alunos_cadastrados;icont++){
      printf("%-9s %-30s %-4c %-15s %.2d/%.2d/%d\n", ListaDeAlunos[icont].Matricula, 
                                                     ListaDeAlunos[icont].Nome, 
                                                     ListaDeAlunos[icont].Sexo, 
		  											ListaDeAlunos[icont].Cpf,
		  											ListaDeAlunos[icont].DataNasc.dia,
		  											ListaDeAlunos[icont].DataNasc.mes,
		  											ListaDeAlunos[icont].DataNasc.ano);
	}
}

void ListarProfessoresNome(Professor ListaDeProfessor[], int qtd_prof_cadastrado){
	int icont;
	int jcont;
	int comparar;
	char aux[Tam_Nome];
	for(icont = 0; icont < qtd_prof_cadastrado - 1;icont++){
		for(jcont = icont + 1; jcont < qtd_prof_cadastrado; jcont++){
			comparar = strcmp(ListaDeProfessor[icont].Nome, ListaDeProfessor[jcont].Nome);
			if(comparar > 0){
				strcpy(aux, ListaDeProfessor[icont].Nome);
				strcpy(ListaDeProfessor[icont].Nome, ListaDeProfessor[jcont].Nome);
				strcpy(ListaDeProfessor[jcont].Nome, aux);
			}
		}
	}
	
	printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
	
	
    for(icont=0;icont<qtd_prof_cadastrado;icont++){
      printf("%-9s %-30s %-4c %-15s \n", ListaDeProfessor[icont].Matricula, 
                                  /*%.2d/%.2d/%d*/   ListaDeProfessor[icont].Nome, 
                                                     ListaDeProfessor[icont].Sexo, 
		  											ListaDeProfessor[icont].Cpf);
		  											/*ListaDeProfessor[icont].DataNasc.dia,
		  											ListaDeProfessor[icont].DataNasc.mes,
		  											ListaDeProfessor[icont].DataNasc.ano);*/
	}
}
