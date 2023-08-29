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
  printf("  12 > Lista de pessoas (alunos e professores) \n");
  printf("  13 > Lista de alunos matriculados em menos de 3 disciplinas \n");
  printf("  14 > Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas. \n");
  printf("  15 > Listar disciplinas que aluno está matriculado \n");
  MenuRelatorio=VerificacaoValorMenu(0,14);

  return MenuRelatorio;
}

void ListarAlunos(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
  int icont;
  printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
    
    for(icont=0;icont<qtd_alunos_cadastrados;icont++){
      printf("%-9s %-30s %-4c %-15s %-10s\n", ListaDeAlunos[icont].Matricula, 
                                                     ListaDeAlunos[icont].Nome, 
                                                     ListaDeAlunos[icont].Sexo, 
                                                     ListaDeAlunos[icont].Cpf,
                    								 ListaDeAlunos[icont].DataNasc.str_data);
	}
}

void ListarProfessor(Professor ListaDeProfessor[], int qtd_prof_cadastrado){
  int icont;
  printf("%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",     
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
    
    for(icont=0;icont<qtd_prof_cadastrado;icont++)
      printf("%-9s %-30s %-4c %-15s %-10s\n", ListaDeProfessor[icont].Matricula, 
                                         ListaDeProfessor[icont].Nome, 
                                         ListaDeProfessor[icont].Sexo, 
                                         ListaDeProfessor[icont].Cpf,
		  								 ListaDeProfessor[icont].DataNasc.str_data);
}


void ListarProfessorSexo (Professor ListaDeProfessor[], int qtd_prof_cadastrado){
  int icont;
  printf("\nLista de Professores do sexo masculino\n");
    for (icont = 0; icont < qtd_prof_cadastrado; icont++)
    {
      if ((ListaDeProfessor[icont].Sexo == 'M') || (ListaDeProfessor[icont].Sexo == 'm'))
        {        
        printf("%-9s %-30s %-4c %-15s %-10s\n",  ListaDeProfessor[icont].Nome,  
                                            ListaDeProfessor[icont].Matricula, 
                                            ListaDeProfessor[icont].Sexo,                                
                                            ListaDeProfessor[icont].Cpf,																			ListaDeProfessor[icont].DataNasc.str_data);
      }
    }

  printf("\nLista de Professores do sexo feminino\n");
    for (icont = 0; icont < qtd_prof_cadastrado; icont++){
      if ((ListaDeProfessor[icont].Sexo == 'F') || (ListaDeProfessor[icont].Sexo == 'f'))
        {        
        printf("%-9s %-30s %-4c %-15s %-10s\n",  ListaDeProfessor[icont].Nome,  
                                            ListaDeProfessor[icont].Matricula, 
                                            ListaDeProfessor[icont].Sexo,    
											ListaDeProfessor[icont].Cpf,
                                            ListaDeProfessor[icont].DataNasc.str_data);
      }
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
    printf("%s  \n", ListaDeDisciplina[icont].Semestre);
    printf("%s \n", ListaDeDisciplina[icont].Professor);
      //lista de alunos em cada disciplina
  }
}   

void ListarUmaDisciplina(Disciplina ListaDeDisciplina[] , int qtd_disc_cadastrado, char disciplina[]){
  int icont;  
  for(icont = 0; icont < qtd_disc_cadastrado; icont++)
  {										
    if (ListaDeDisciplina[icont].Nome == disciplina)
    {
       printf("%-9s %-d %-4s %-15s \n",  ListaDeDisciplina[icont].Nome,  
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
        printf("%-9s %-30s %-4c %-15s %-10s\n",  ListaDeAluno[icont].Nome,  
                                            ListaDeAluno[icont].Matricula, 
                                            ListaDeAluno[icont].Sexo,    
                      						ListaDeAluno[icont].Cpf,
                                     		ListaDeAluno[icont].DataNasc.str_data);
      }
    }
  
  printf("\nLista de alunos por sexo feminino\n");
    for (icont = 0; icont < qtd_alunos_cadastrados; icont++)
    {
      if ((ListaDeAluno[icont].Sexo == 'F') || (ListaDeAluno[icont].Sexo == 'f'))
      {        
        printf("%-9s %-30s %-4c %-15s %-10s\n",  ListaDeAluno[icont].Nome,  
                                            ListaDeAluno[icont].Matricula, 
                                            ListaDeAluno[icont].Sexo,
                                           	ListaDeAluno[icont].Cpf,
                                     		ListaDeAluno[icont].DataNasc.str_data);
      }
    }
}

void ListarAlunosNome(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
	int icont;
	int jcont;
	int comparar;
	Aluno ListaDeAlunosPorNome[qtd_alunos_cadastrados];
	Aluno aux[qtd_alunos_cadastrados];
	
	for(icont = 0;icont < qtd_alunos_cadastrados; icont++){
		strcpy(ListaDeAlunosPorNome[icont].Matricula, ListaDeAlunos[icont].Matricula);
		strcpy(ListaDeAlunosPorNome[icont].Nome, ListaDeAlunos[icont].Nome);
		strcpy(&ListaDeAlunosPorNome[icont].Sexo, &ListaDeAlunos[icont].Sexo);
		strcpy(ListaDeAlunosPorNome[icont].Cpf, ListaDeAlunos[icont].Cpf);
		strcpy(ListaDeAlunosPorNome[icont].DataNasc.str_data, ListaDeAlunos[icont].DataNasc.str_data);
	}
	
	for(icont = 0; icont < qtd_alunos_cadastrados - 1;icont++){
		for(jcont = icont + 1; jcont < qtd_alunos_cadastrados; jcont++){
			comparar = strcmp(ListaDeAlunosPorNome[icont].Nome, ListaDeAlunosPorNome[jcont].Nome);
			if(comparar > 0){
				strcpy(aux[icont].Nome, ListaDeAlunosPorNome[icont].Nome);
				strcpy(aux[icont].Matricula, ListaDeAlunosPorNome[icont].Matricula);
				strcpy(&aux[icont].Sexo, &ListaDeAlunosPorNome[icont].Sexo);
				strcpy(aux[icont].Cpf, ListaDeAlunosPorNome[icont].Cpf);
				strcpy(aux[icont].DataNasc.str_data, ListaDeAlunosPorNome[icont].DataNasc.str_data);
				
				strcpy(ListaDeAlunosPorNome[icont].Nome, ListaDeAlunosPorNome[jcont].Nome);
				strcpy(ListaDeAlunosPorNome[icont].Matricula, ListaDeAlunosPorNome[jcont].Matricula);
				strcpy(&ListaDeAlunosPorNome[icont].Sexo, &ListaDeAlunosPorNome[jcont].Sexo);
				strcpy(ListaDeAlunosPorNome[icont].Cpf, ListaDeAlunosPorNome[jcont].Cpf);
				strcpy(ListaDeAlunosPorNome[icont].DataNasc.str_data, 			 				ListaDeAlunosPorNome[jcont].DataNasc.str_data);
				
				strcpy(ListaDeAlunosPorNome[jcont].Nome, aux[icont].Nome);
				strcpy(ListaDeAlunosPorNome[jcont].Matricula, aux[icont].Matricula);
				strcpy(&ListaDeAlunosPorNome[jcont].Sexo, &aux[icont].Sexo);
				strcpy(ListaDeAlunosPorNome[jcont].Cpf, aux[icont].Cpf);
				strcpy(ListaDeAlunosPorNome[jcont].DataNasc.str_data, aux[icont].DataNasc.str_data);
				
			}
		}
	}
	
	printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
	
	
    for(icont=0;icont<qtd_alunos_cadastrados;icont++){
      printf("%-9s %-30s %-4c %-15s %-10s\n", ListaDeAlunosPorNome[icont].Matricula, 
        ListaDeAlunosPorNome[icont].Nome, ListaDeAlunosPorNome[icont].Sexo, 		 	ListaDeAlunosPorNome[icont].Cpf,ListaDeAlunosPorNome[icont].DataNasc.str_data);
	}
}

void ListarProfessoresNome(Professor ListaDeProfessor[], int qtd_prof_cadastrado){
	int icont;
	int jcont;
	int comparar;
	Professor ListaDeProfNome[qtd_prof_cadastrado];
	Professor aux[qtd_prof_cadastrado];

	for(icont = 0; icont < qtd_prof_cadastrado; icont++){
		strcpy(ListaDeProfNome[icont].Matricula, ListaDeProfessor[icont].Matricula);
		strcpy(ListaDeProfNome[icont].Nome, ListaDeProfessor[icont].Nome);
		strcpy(&ListaDeProfNome[icont].Sexo, &ListaDeProfessor[icont].Sexo);
		strcpy(ListaDeProfNome[icont].Cpf, ListaDeProfessor[icont].Cpf);
		strcpy(ListaDeProfNome[icont].DataNasc.str_data, ListaDeProfNome[icont].DataNasc.str_data);
	}
	
	for(icont = 0; icont < qtd_prof_cadastrado - 1;icont++){
		for(jcont = icont + 1; jcont < qtd_prof_cadastrado; jcont++){
			comparar = strcmp(ListaDeProfNome[icont].Nome, ListaDeProfNome[jcont].Nome);
			if(comparar > 0){
				strcpy(aux[icont].Nome, ListaDeProfNome[icont].Nome);
				strcpy(aux[icont].Matricula, ListaDeProfNome[icont].Matricula);
				strcpy(&aux[icont].Sexo, &ListaDeProfNome[icont].Sexo);
				strcpy(aux[icont].Cpf, ListaDeProfNome[icont].Cpf);
				strcpy(aux[icont].DataNasc.str_data, ListaDeProfNome[icont].DataNasc.str_data);
				
				strcpy(ListaDeProfNome[icont].Nome, ListaDeProfNome[jcont].Nome);
				strcpy(ListaDeProfNome[icont].Matricula, ListaDeProfNome[jcont].Matricula);
				strcpy(&ListaDeProfNome[icont].Sexo, &ListaDeProfNome[jcont].Sexo);
				strcpy(ListaDeProfNome[icont].Cpf, ListaDeProfNome[jcont].Cpf);
				strcpy(ListaDeProfNome[icont].DataNasc.str_data, 			 			ListaDeProfNome[jcont].DataNasc.str_data);
				
				strcpy(ListaDeProfNome[jcont].Nome, aux[icont].Nome);
				strcpy(ListaDeProfNome[jcont].Matricula, aux[icont].Matricula);
				strcpy(&ListaDeProfNome[jcont].Sexo, &aux[icont].Sexo);
				strcpy(ListaDeProfNome[jcont].Cpf, aux[icont].Cpf);
				strcpy(ListaDeProfNome[jcont].DataNasc.str_data, aux[icont].DataNasc.str_data);
			}
		}
	}
	
	printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
	
    for(icont=0;icont<qtd_prof_cadastrado;icont++){
      printf("%-9s %-30s %-4c %-15s %-10s\n", ListaDeProfNome[icont].Matricula, 
                                  					ListaDeProfNome[icont].Nome, 
                                                    ListaDeProfNome[icont].Sexo, 
		  											ListaDeProfNome[icont].Cpf,
		  											ListaDeProfNome[icont].DataNasc.str_data);
		  											
	}
}

void ListarAniversariantesDoMes(Professor ListaDeProfessor[], int qtd_prof_cadastrado, Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
	int icont;
	int mes;
	printf("Digite o mês:\n");
	scanf("%d", &mes);
	if (mes > 0 && mes <= 12){ 

		//PROFESSORES ANIVERSARIANTES DO MÊS
		printf("Professores aniversariantes no mês:\n");
		printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",
				"Nascimento"); 
	
		printf("--------- ------------------------------ ---- --------------- ----------\n");
		  
		for (icont = 0; icont <qtd_prof_cadastrado; icont++){
			if (ListaDeProfessor[icont].DataNasc.mes == mes){
			
				printf("%-9s %-30s %-4c %-15s %-10s\n",ListaDeProfessor[icont].Matricula, 
											   ListaDeProfessor[icont].Nome, 
											   ListaDeProfessor[icont].Sexo, 
											   ListaDeProfessor[icont].Cpf,
											   ListaDeProfessor[icont].DataNasc.str_data);
			  
			} else {
			printf("\nNão há professores aniversariantes no mês\n");
			}     
		
		}
	
		//ALUNOS ANIVERSARIANTES DO MÊS
		printf("Alunos aniversariantes no mês:\n");
	    printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",
	          "Nascimento");
	
		printf("--------- ------------------------------ ---- --------------- ----------\n");
		  
		for (icont = 0; icont <qtd_alunos_cadastrados; icont++){
			if (ListaDeAlunos[icont].DataNasc.mes == mes){
			  
				printf("%-9s %-30s %-4c %-15s %-10s\n",ListaDeAlunos[icont].Matricula, 
											   ListaDeAlunos[icont].Nome, 
											   ListaDeAlunos[icont].Sexo, 
											   ListaDeAlunos[icont].Cpf,
											   ListaDeAlunos[icont].DataNasc.str_data);
			} else{
				printf("Não há alunos aniversariantes no mês\n");
			}
		}
  
	} else{
		printf("\nO mês cadastrado é inválido!");
	}
}

void ListaDePessoas(Professor ListaDeProfessor[], int qtd_prof_cadastrado, Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
  int icont;

  printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",
          "Nascimento");
  
  printf("--------- ------------------------------ ---- --------------- ----------\n");
	
  for (icont = 0; icont < qtd_prof_cadastrado; icont++){
     printf("%-9s %-30s %-4c %-15s %-10s\n",ListaDeProfessor[icont].Matricula, 
                                           ListaDeProfessor[icont].Nome, 
                                           ListaDeProfessor[icont].Sexo, 
                                           ListaDeProfessor[icont].Cpf,
										   ListaDeProfessor[icont].DataNasc.str_data);
    
  }
  for (icont = 0; icont <qtd_alunos_cadastrados; icont++){
    printf("%-9s %-30s %-4c %-15s %-10s\n",ListaDeAlunos[icont].Matricula, 
                                           ListaDeAlunos[icont].Nome, 
                                           ListaDeAlunos[icont].Sexo, 
                                           ListaDeAlunos[icont].Cpf,
										   ListaDeAlunos[icont].DataNasc.str_data);
  }
  
}

void ListarAlunosMatriculadosDisc(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados,int qtd_disc_cadast){
  int icont;
  int jcont;
  int somat;
  int alunosprintados=0;
  for (icont = 0; icont < qtd_alunos_cadastrados; icont++){
    somat=0;
    for(jcont=0;ListaDeAlunos[icont].Qtd_Mat_Cadast[jcont]<qtd_disc_cadast;jcont++)
    {
      somat++;
    }
    if (somat < 3)
    {      
        printf("%-9s %-30s %-4c %-15s %-10s\n",ListaDeAlunos[icont].Matricula,
                                               ListaDeAlunos[icont].Nome, 
                                               ListaDeAlunos[icont].Sexo, 
                                               ListaDeAlunos[icont].Cpf,
										                           ListaDeAlunos[icont].DataNasc.str_data);
        alunosprintados++;
    }
    if(icont==qtd_alunos_cadastrados-1 && alunosprintados==0)
      printf("\nNão há alunos matriculados em menos de 3 disciplinas");
      
  }

}

/*void ListarDiscDeAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados, Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado){
  char aluno[Tam_Nome];
  char comparar;
  int icont;  
  printf("Digite o nome do estudante:\n");
  fgets(aluno, sizeof(Tam_Nome), stdin);
  for (icont = 0; icont < qtd_alunos_cadastrados; icont++){
    comparar = strcmp(ListaDeAlunos[icont].Nome, aluno);
  	if(comparar > 0){
      printf("---------------------------------");
      printf("\n%s", ListaDeAlunos[icont].Nome);
      printf("\n%s\n", ListaDeDisciplina[icont].Nome);
      printf("---------------------------------");
        }
          }
}*/
