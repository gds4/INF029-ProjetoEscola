#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncoesUsoGeral.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Relatorio.h"

int TelaInicial();
int MenuPrincipal();


int main(void) {
  
  int TeladeInicio;
  int InicioCont = 8;
  int MenuInicial=8;
  int MenuAluno;
  int MenuProfessor;
  int MenuDisciplina;
  int MenuRelatorio;
  Aluno ListaDeAlunos[QTD_Alunos];
  Professor ListaDeProfessor[QTD_Professor];
  Disciplina ListaDeDisciplina[QTD_Disc];
  int qtd_alunos_cadastrados=0;
  int qtd_prof_cadastrado=0;
  int qtd_disc_cadastrado=0;
  int codigo_disciplina_atualizar = 0;
  int resultado_atualizacao = 0;
  int matricula;
  int matriculaprof;
  int icont=0;
  int jcont=0;
  PreencherDados(ListaDeAlunos,qtd_alunos_cadastrados,ListaDeProfessor,qtd_prof_cadastrado,ListaDeDisciplina,qtd_disc_cadastrado);
  qtd_alunos_cadastrados=6;
  qtd_prof_cadastrado=4;
  qtd_disc_cadastrado=4;

  printf(" %d %d %d %d ",ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0],
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1],
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2],
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3]);
  int numero_limite_Alunos = 1;
  printf("----Bem vindo ao Sistema Escolar----\n");

	while (InicioCont != 0) {
		TeladeInicio = TelaInicial();
	     
	    if (TeladeInicio == 1) {
			InicioCont = 1;
			MenuInicial= 8;
			while(MenuInicial!=0){
				MenuInicial = MenuPrincipal();
		          
		        switch (MenuInicial) {
					case 0:{
						MenuInicial=0;
						break;
					}
					case 1:{
						//MÓDULO ALUNO
						MenuAluno = MenudeAlunos();
					
			            switch (MenuAluno) 
                  {
							case 0:{
								break;
							}		              
							case 1:{
								InserirAluno(ListaDeAlunos, qtd_alunos_cadastrados,qtd_disc_cadastrado);
								qtd_alunos_cadastrados++;
								break;
							}
							case 2:{
								ExcluirAluno(ListaDeAlunos, qtd_alunos_cadastrados, qtd_disc_cadastrado, ListaDeDisciplina);
								qtd_alunos_cadastrados--;
								break;
							}
							case 3:{
								AtualizarAluno(ListaDeAlunos, qtd_alunos_cadastrados);
								break;
							}  
			            }	                
		            	break;
					}	          
					case 2:{
						//MÓDULO PROFESSOR
						MenuProfessor = MenudeProfessores();
						switch (MenuProfessor){
							case 0:{
								break;
							}
							case 1:{
								InserirProfessor( ListaDeProfessor, qtd_prof_cadastrado);
								qtd_prof_cadastrado++;
								break;
							}
							case 2:{
								ExcluirProfessor(ListaDeProfessor, qtd_prof_cadastrado);
								qtd_prof_cadastrado--;
								break;
							}
							case 3:{
								AtualizarProfessor(ListaDeProfessor, qtd_prof_cadastrado);
								break;
							}
						
						}
						break;
					}
		            
					case 3:{
						//MÓDULO DISCIPLINA		
						MenuDisciplina = MenudeDisciplina();
						switch (MenuDisciplina){ 
							case 0:{
								break;
							}
							case 1:{           
								InserirDisciplina(ListaDeDisciplina, qtd_disc_cadastrado,ListaDeProfessor, qtd_prof_cadastrado);
								qtd_disc_cadastrado++;
                
								break;
							}
							case 2:{            
								ExcluirDisciplina(ListaDeDisciplina, qtd_disc_cadastrado, ListaDeAlunos, qtd_alunos_cadastrados);
								qtd_disc_cadastrado--;
								break;
							}
							case 3:{
								AtualizarDisciplina(ListaDeDisciplina, ListaDeProfessor, codigo_disciplina_atualizar, qtd_disc_cadastrado, qtd_prof_cadastrado);							
								break;
							}
							case 4:{
								InserirTurma(ListaDeDisciplina, ListaDeAlunos, qtd_alunos_cadastrados, qtd_disc_cadastrado);
                printf("%d",ListaDeAlunos[0].Qtd_Mat_Cadast[0]);
								break;
							}
						} 
						break;
					}  
		          
					case 4:{
						//RELATÓRIOS
						MenuRelatorio = MenuRelatorios();
						switch (MenuRelatorio){
							case 0:{
								break;
							}
							case 1:{
								ListarAlunos(ListaDeAlunos, qtd_alunos_cadastrados);
								break;
							}
							case 2:{
								ListarProfessor(ListaDeProfessor, qtd_prof_cadastrado);
								break;
							}              
							case 3:{
								ListarDisciplina(ListaDeDisciplina, qtd_disc_cadastrado);
								break;
              }  
							case 4:{
								ListarUmaDisciplina(ListaDeDisciplina, qtd_disc_cadastrado,ListaDeAlunos,qtd_alunos_cadastrados);
								break;
							}
							case 5:{
								ListarAlunoSexo(ListaDeAlunos, qtd_alunos_cadastrados);	
                				break;
							}							
							case 6: {
								ListarAlunosNome(ListaDeAlunos, qtd_alunos_cadastrados);
								break;
							}
							case 7: {
								ListarAlunoDataNasc(ListaDeAlunos, qtd_alunos_cadastrados);
								break;
							}
							case 8:{
								ListarProfessorSexo(ListaDeProfessor, qtd_prof_cadastrado);
								break;
							}
							case 9:{
								ListarProfessoresNome(ListaDeProfessor, qtd_prof_cadastrado);
								break;
							}
							case 10:{
								ListarProfDataNasc(ListaDeProfessor, qtd_prof_cadastrado);
                break;
							}
							case 11:{
								ListarAniversariantesDoMes(ListaDeProfessor, qtd_prof_cadastrado, ListaDeAlunos, qtd_alunos_cadastrados);              
								break;
							}
							case 12:{
								ListaDePessoas(ListaDeProfessor, qtd_prof_cadastrado, ListaDeAlunos, qtd_alunos_cadastrados);
								break;
						  	}
							case 13:{
								ListarAlunosMatriculadosDisc(ListaDeAlunos, qtd_alunos_cadastrados);
								break;
							}
							case 14:{
								ImprimeDisciplinaExtrapolaAlunos(ListaDeDisciplina, numero_limite_Alunos);                
								break;
							}
						}
						  break;
					}
				}
	    }
	  }else if(TeladeInicio==0)
	    InicioCont=0;
    
	}
  printf("\nPrograma Finalizado!");
  return 0;
}

//Funções--Menus

int TelaInicial(){
  int TeladeInicio;
  
  printf("\nPara Continuar aperte '1'\n");
  printf("Para Sair aperte '0'\n");
  TeladeInicio = VerificacaoValorMenu(0,1);
  
  return TeladeInicio;
}

int MenuPrincipal(){
  int MenuInicial;
  
  printf("\nSelecione a opção desejada:\n");
  printf("\n* Para selecionar, pressione o valor correspondente a opção:\n\n");
  printf("0 - Retornar\n");
  printf("1 - Módulo Aluno\n");
  printf("2 - Módulo Professor\n");
  printf("3 - Módulo Disciplina\n");
  printf("4 - Relatórios\n");
  MenuInicial= VerificacaoValorMenu(0,4);

  return MenuInicial;
  
}
