#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Relatorio.h"
#include "FuncoesUsoGeral.h"

int TelaInicial();
int MenuPrincipal();
void delbar0(char string[]);

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
  char stringteste[50];
  int matricula;
  int matriculaprof;
  int icont=0;
  int jcont=0;

  printf("----Bem vindo ao Sistema Escolar----\n\n");

  while (InicioCont != 0) {
    TeladeInicio = TelaInicial();
     
    if (TeladeInicio == 1) {
      InicioCont = 1;
    } 
    else if (TeladeInicio != 0 && TeladeInicio != 1)
      printf("Comando Desconhecido, por favor escolha uma opção válida:\n\n");
  
    MenuInicial= 8;
    while(MenuInicial!=0){
      MenuInicial = MenuPrincipal();
        
      switch (MenuInicial) {
        case 0:{
          MenuInicial=0;
          break;
        }
        case 1:{
          MenuAluno = MenudeAlunos();
          
          switch (MenuAluno) {
            
            case 1:{
            	InserirAluno(ListaDeAlunos, qtd_alunos_cadastrados);
            	qtd_alunos_cadastrados++;
            	break;
            }
            case 2:{
            	ExcluirAluno(ListaDeAlunos, qtd_alunos_cadastrados);
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
          
          MenuProfessor = MenudeProfessores();
          switch (MenuProfessor){
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
          
          MenuDisciplina = MenudeDisciplina();
          switch (MenuDisciplina)
            case 1:
            {
              InserirDisciplina(ListaDeDisciplina, qtd_disc_cadastrado);
              qtd_disc_cadastrado++;
              break;
            }
          break;
        }
          
        case 4:{
          
          MenuRelatorio = MenuRelatorios();
          switch (MenuRelatorio)
            case 1:
            {
              ListarAlunos(ListaDeAlunos, qtd_alunos_cadastrados);
              break;
            }
          break;
        }
            
        
        default:
          
          printf("Valor Inválido");
          break;
        
      }
    }
  }
  printf("Programa Finalizado!");
  return 0;
}

//Funções--Menus

int TelaInicial(){
  int TeladeInicio;
  
  printf("Para Continuar aperte '1'\n");
  printf("Para Sair aperte '0'\n");
  scanf("%d", &TeladeInicio);
  
  return TeladeInicio;
}

int MenuPrincipal(){
  int MenuInicial;
  
  printf("\nSelecione a opção desejada:\n");
  printf("\n* Para selecionar a opção, pressione o valor referente a mesma:\n\n");
  printf("0 - Retornar\n");
  printf("1 - Cadastrar Aluno\n");
  printf("2 - Cadastrar Professor\n");
  printf("3 - Cadastrar Disciplina\n");
  printf("4 - Relatorios\n");
  scanf("%d", &MenuInicial);

  return MenuInicial;
  
}
