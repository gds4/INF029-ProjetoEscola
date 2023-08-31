#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncoesUsoGeral.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

int MenuRelatorios(){
  int MenuRelatorio;
  printf("\n\n------ RELATÓRIOS ------\n");
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
  MenuRelatorio=VerificacaoValorMenu(0,15);

  return MenuRelatorio;
}

void ListarAlunos(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados){
  int icont;

	printf("\nLISTA DE ALUNOS\n");
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
	printf("\nLISTA DE PROFESSORES\n\n");
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
  printf("\nLista de Professores do sexo: masculino\n");
	printf("%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",     
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
    for (icont = 0; icont < qtd_prof_cadastrado; icont++)
    {
      if ((ListaDeProfessor[icont].Sexo == 'M') || (ListaDeProfessor[icont].Sexo == 'm'))
        {        
        printf("%-9s %-30s %-4c %-15s %-10s\n",  
			ListaDeProfessor[icont].Matricula,  
			ListaDeProfessor[icont].Nome, 
			ListaDeProfessor[icont].Sexo,                                
			ListaDeProfessor[icont].Cpf,
			ListaDeProfessor[icont].DataNasc.str_data);
      }
    }

  printf("\nLista de Professores do sexo: feminino\n");
	printf("%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",     
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
    for (icont = 0; icont < qtd_prof_cadastrado; icont++){
      if ((ListaDeProfessor[icont].Sexo == 'F') || (ListaDeProfessor[icont].Sexo == 'f'))
        {        
        printf("%-9s %-30s %-4c %-15s %-10s\n",  
                  ListaDeProfessor[icont].Matricula, 
                  ListaDeProfessor[icont].Nome,
            			ListaDeProfessor[icont].Sexo,    
            			ListaDeProfessor[icont].Cpf,
            			ListaDeProfessor[icont].DataNasc.str_data);
      }
    }
}
    


void ListarDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado){
  int icont;
 // int jcont;
  	printf("\nLISTA DE DISCIPLINAS\n");
	printf("\n%-7s  %-20s %-9s %-30s \n","Código","Nome","Semestre","Professor");
    printf("------- -------------------- --------- ------------------------------\n");
  for(icont = 0; icont < qtd_disc_cadastrado; icont++)
  {    

    printf("%-7d %-20s %-9s %-30s \n",  ListaDeDisciplina[icont].Codigo,                                                       ListaDeDisciplina[icont].Nome,  
                                        ListaDeDisciplina[icont].Semestre,  
                                        ListaDeDisciplina[icont].Professor);

      
  }
}   


void ListarUmaDisciplina(Disciplina ListaDeDisciplina[] , int qtd_disc_cadastrado,const Aluno ListaDeAluno[],int qtd_alunos_cadastrados){
  int sair=1;
  int icont;  
  int jcont;
  int compare;
  char disciplina[Tam_Nome_Disc];
  char discVerificada;
	printf("\nLISTANDO UMA DISCIPLINA\n");
  while (sair!=0){
    printf("\nInforme o nome da disciplina:\n");
    fgets(disciplina,Tam_Nome_Disc, stdin);
    delbar0(disciplina);
  
    discVerificada=0;
    for(icont = 0; icont < qtd_disc_cadastrado; icont++)
    {										
      if (strcmp(ListaDeDisciplina[icont].Nome,disciplina)==0)
      {  printf("\n%-7s  %-20s %-9s %-30s \n","Código","Nome","Semestre","Professor");
         printf("------- -------------------- --------- ------------------------------\n");
         printf("%-7d %-20s %-9s %-30s \n", ListaDeDisciplina[icont].Codigo,                                                       ListaDeDisciplina[icont].Nome,  
                                            ListaDeDisciplina[icont].Semestre,  
                                            ListaDeDisciplina[icont].Professor);

          printf("\n\nLista de Alunos Matriculados:\n");
          printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",     
        "Nascimento");
    
    
          printf("--------- ------------------------------ ---- --------------- ----------\n");
          for(jcont=0;jcont<qtd_alunos_cadastrados;jcont++){
            if(ListaDeAluno[jcont].Qtd_Mat_Cadast[icont]==1){
              printf("%-9s %-30s %-4c %-15s %-10s\n", ListaDeAluno[jcont].Matricula, 
                                                      ListaDeAluno[jcont].Nome,  
                                                      ListaDeAluno[jcont].Sexo,    
                      						                    ListaDeAluno[jcont].Cpf,
                                     		              ListaDeAluno[jcont].DataNasc.str_data);
            }
          }
          
        discVerificada=1;
      } 
      
    }
    if (icont==qtd_disc_cadastrado && discVerificada==0){
        printf("\nDisciplina não encontrada\n");
          
    }else if(discVerificada==1)
      sair=0;
  }
}
  


void ListarAlunoSexo (Aluno ListaDeAluno[], int qtd_alunos_cadastrados){
  int icont;
  	printf("\nLista de alunos por sexo: masculino\n\n");
	printf("%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",     
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
    for (icont = 0; icont < qtd_alunos_cadastrados; icont++)
    {
      if ((ListaDeAluno[icont].Sexo == 'M') || (ListaDeAluno[icont].Sexo == 'm'))
      {        
        printf("%-9s %-30s %-4c %-15s %-10s\n", ListaDeAluno[icont].Matricula, 
                                                ListaDeAluno[icont].Nome,  
                                                ListaDeAluno[icont].Sexo,    
                      						              ListaDeAluno[icont].Cpf,
                                     		        ListaDeAluno[icont].DataNasc.str_data);
      }
    }
  
  printf("\nLista de alunos por sexo: feminino\n\n");
	printf("%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",     
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
    for (icont = 0; icont < qtd_alunos_cadastrados; icont++)
    {
      if ((ListaDeAluno[icont].Sexo == 'F') || (ListaDeAluno[icont].Sexo == 'f'))
      {        
        printf("%-9s %-30s %-4c %-15s %-10s\n",  ListaDeAluno[icont].Matricula, 
                                                 ListaDeAluno[icont].Nome,  
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

	printf("\n\nALUNOS ORDENADOS POR NOME\n");
	
	printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF",
        "Nascimento");
    
    
    printf("--------- ------------------------------ ---- --------------- ----------\n");
	
	
    for(icont=0;icont<qtd_alunos_cadastrados;icont++){
		printf("%-9s %-30s %-4c %-15s %-10s\n", 
			ListaDeAlunosPorNome[icont].Matricula, 
			ListaDeAlunosPorNome[icont].Nome, ListaDeAlunosPorNome[icont].Sexo,
			ListaDeAlunosPorNome[icont].Cpf,ListaDeAlunosPorNome[icont].DataNasc.str_data);
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
		strcpy(ListaDeProfNome[icont].DataNasc.str_data, ListaDeProfessor[icont].DataNasc.str_data);
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

	printf("\n\nPROFESSORES ORDENADOS POR NOME\n");
	
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
			  
				printf("%-9s %-30s %-4c %-15s %-10s\n",
					ListaDeAlunos[icont].Matricula, 
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

  printf("\n\nLISTA DE PESSOAS\n");
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
  int somat=0;
  int alunosprintados=0;
	printf("\nALUNOS MATRICULADOS EM MENOS DE 3 DISCIPLINAS\n");
  for (icont = 0; icont < qtd_alunos_cadastrados; icont++){
    somat=0;
    for(jcont=0;jcont<qtd_disc_cadast;jcont++){  
      
      if(ListaDeAlunos[icont].Qtd_Mat_Cadast[jcont]==1){
        somat++;
      }
    }
    
    if (somat < 3)
    {      
        printf("%-9s %-30s %-4c %-15s %-10s\n",
                                          			ListaDeAlunos[icont].Matricula,
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

void ListarDiscDeAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados, Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado){
  char aluno[Tam_Nome];
  char comparar;
  int icont;
  int sairloop=1;
  int posicao;
  while(sairloop!=0){
    printf("Digite o nome do estudante:\n");
    fgets(aluno, sizeof(Tam_Nome), stdin);
    delbar0(aluno);
    posicao=BuscarPosicaoAluno(ListaDeAlunos, aluno, qtd_alunos_cadastrados);
    if(posicao>=0){
      for (icont = 0; icont < qtd_disc_cadastrado; icont++){
       	if(ListaDeAlunos[posicao].Qtd_Mat_Cadast[icont]==1){
          printf("---------------------------------");
          printf("\n%s", ListaDeAlunos[posicao].Nome);
          printf("\n%s\n", ListaDeDisciplina[icont].Nome);
          printf("---------------------------------");
      sairloop=1;
      }
      }
    }else printf("\nMatrícula Inválida. Tente Novamente.\n");
  }
}


int CompareAlunosPorDataNasc(const void *a, const void *b) {
    const Aluno *alunoA = (const Aluno *)a;
    const Aluno *alunoB = (const Aluno *)b;

    if (alunoA->DataNasc.ano != alunoB->DataNasc.ano) {
        return alunoA->DataNasc.ano - alunoB->DataNasc.ano;
    }
    if (alunoA->DataNasc.mes != alunoB->DataNasc.mes) {
        return alunoA->DataNasc.mes - alunoB->DataNasc.mes;
    }
    return alunoA->DataNasc.dia - alunoB->DataNasc.dia;
}

void ListarAlunoDataNasc(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados) {
    
    Aluno ListaAlunosNasc[qtd_alunos_cadastrados];
    memcpy(ListaAlunosNasc, ListaDeAlunos, sizeof(Aluno) * qtd_alunos_cadastrados);
   
    qsort(ListaAlunosNasc, qtd_alunos_cadastrados, sizeof(Aluno), CompareAlunosPorDataNasc);
    
    printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF", "Nascimento");
    printf("--------- ------------------------------ ---- --------------- ----------\n");

    for (int icont = 0; icont < qtd_alunos_cadastrados; icont++) {
        printf("%-9s %-30s %-4c %-15s %-10s\n",
               ListaAlunosNasc[icont].Matricula,
               ListaAlunosNasc[icont].Nome,
               ListaAlunosNasc[icont].Sexo,
               ListaAlunosNasc[icont].Cpf,
               ListaAlunosNasc[icont].DataNasc.str_data);
    }
}

int CompareProfPorDataNasc(const void *a, const void *b) {
    const Professor *professorA = (const Professor *)a;
    const Professor *professorB = (const Professor *)b;

    if (professorA->DataNasc.ano != professorB->DataNasc.ano) {
        return professorA->DataNasc.ano - professorB->DataNasc.ano;
    }
    if (professorA->DataNasc.mes != professorB->DataNasc.mes) {
        return professorA->DataNasc.mes - professorB->DataNasc.mes;
    }
    return professorA->DataNasc.dia - professorB->DataNasc.dia;
}

void ListarProfDataNasc(Professor ListaDeProfessores[], int qtd_prof_cadastrados) {
    
    Professor ListaProfNasc[qtd_prof_cadastrados];
    memcpy(ListaProfNasc, ListaDeProfessores, sizeof(Professor) * qtd_prof_cadastrados);
   
    qsort(ListaProfNasc, qtd_prof_cadastrados, sizeof(Professor), CompareProfPorDataNasc);

    printf("\n%-9s %-30s %-4s %-15s %-10s\n", "Matrícula", "Nome", "Sexo", "CPF", "Nascimento");
    printf("--------- ------------------------------ ---- --------------- ----------\n");

    for (int icont = 0; icont < qtd_prof_cadastrados; icont++) {
        printf("%-9s %-30s %-4c %-15s %-10s\n",
               ListaProfNasc[icont].Matricula,
               ListaProfNasc[icont].Nome,
               ListaProfNasc[icont].Sexo,
               ListaProfNasc[icont].Cpf,
               ListaProfNasc[icont].DataNasc.str_data);
    }
}


void ImprimeDisciplinaExtrapolaAlunos(Disciplina ListaDeDisciplina[], int maximo,int qtd_disc_cadastrado){
    int icont;
    int extrapola = 0;
    
    for (icont = 0; icont < qtd_disc_cadastrado; icont++){
        
      if(ListaDeDisciplina[icont].NumAlunos > maximo){  
        
        if(extrapola==0){
        printf("\n%-7s  %-20s %-7s %-30s\n", "Código", "Nome", "Semestre", "Professor");
        printf("------- -------------------- ------- ------------------------------\n");
      }
        printf("%-7d %-20s %-7s %-30s\n",ListaDeDisciplina[icont].Codigo,
                                         ListaDeDisciplina[icont].Nome,
                                         ListaDeDisciplina[icont].Semestre,
                                         ListaDeDisciplina[icont].Professor);          
        extrapola++;          
      }   
      
    }  
    if(extrapola==0){
        printf("\nNenhuma disciplina extrapolou o número de alunos\n");
    }
}

void ListarDiscDoAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados, Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado){
  char matricula[10];
  int posicao, sair = 1;
  int icont;
  int discencontrada=0;
  while(sair!=0){
    printf("\nInsira a Matrícula do Aluno:\n");
    fgets(matricula,10,stdin);
    delbar0(matricula);

    if(verificarExistenciaMatricula ( ListaDeAlunos,  qtd_alunos_cadastrados, matricula)==1){
      posicao = BuscarPosicaoAluno(ListaDeAlunos,matricula,qtd_alunos_cadastrados);
      for(icont=0;icont<qtd_disc_cadastrado;icont++){
        if(ListaDeAlunos[posicao].Qtd_Mat_Cadast[icont]==1){
          if(discencontrada==0){
            printf("\nDisciplina(s) do Aluno: %s\n",ListaDeAlunos[posicao].Nome);
             printf("\n%-7s  %-20s %-7s %-30s\n", "Código", "Nome", "Semestre", "Professor");
        printf("------- -------------------- ------- ------------------------------\n");
            }
              
            printf("%-7d %-20s %-7s %-30s\n",ListaDeDisciplina[icont].Codigo,
                                         ListaDeDisciplina[icont].Nome,
                                         ListaDeDisciplina[icont].Semestre,
                                         ListaDeDisciplina[icont].Professor);
            discencontrada++;
          
        }
      }
      sair=0;
    }else printf("\nMatricula inválida! Tente Novamente:\n");

    if(discencontrada==0){
      printf("\nO Aluno não está cadastrado em nenhuma disciplina.\n");
      sair=0;
    }
      
  }
  
}


