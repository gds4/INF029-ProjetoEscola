#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Relatorio.h"


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
              printf("Insira a Matrícula\n");
              scanf("%d", &ListaDeAlunos[qtd_alunos_cadastrados].Matricula);
              getchar();
              printf("Insira o nome do aluno:\n");
              fgets(ListaDeAlunos[qtd_alunos_cadastrados].Nome, Tam_Nome, stdin);
              delbar0(ListaDeAlunos[qtd_alunos_cadastrados].Nome);
              printf("Insira o sexo do aluno: M/F\n");
              scanf(" %c", &ListaDeAlunos[qtd_alunos_cadastrados].Sexo);
              getchar();
              printf("Insira a data de nascimento do aluno:\n");
              /*fgets(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc, Tam_Data, stdin);
              getchar();
              delbar0(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc);*/
              printf("Insira o cpf do aluno:\n");
              fgets(ListaDeAlunos[qtd_alunos_cadastrados].Cpf,Tam_Cpf,stdin);
              delbar0(ListaDeAlunos[qtd_alunos_cadastrados].Cpf);
              qtd_alunos_cadastrados++;
              break;
            }
            case 2:{
              printf("Insira a Matrícula do Aluno");
              scanf("%d",&matricula);
              for(icont=0;icont<qtd_alunos_cadastrados+1;icont++){
                if(ListaDeAlunos[icont].Matricula==matricula){
                  for(jcont=icont+1;jcont<qtd_alunos_cadastrados;jcont++){
                    ListaDeAlunos[jcont-1].Matricula=ListaDeAlunos[jcont].Matricula;
                    strcpy(ListaDeAlunos[jcont-1].Cpf,ListaDeAlunos[jcont].Cpf);
                    strcpy(ListaDeAlunos[jcont-1].Nome,ListaDeAlunos[jcont].Nome);
                    ListaDeAlunos[jcont-1].Sexo=ListaDeAlunos[jcont].Sexo;
                    /*strcpy(ListaDeAlunos[jcont-1].DataNasc,ListaDeAlunos[jcont].DataNasc);*/
                    
                  }
                }
              }
              qtd_alunos_cadastrados--;
              break;
            }
          }
            
              
          break;
          }  
        
        case 2:{
          
          MenuProfessor = MenudeProfessores();
          switch (MenuProfessor){
            case 1:{
              printf("Insira a Matrícula\n");
              scanf("%d", &ListaDeProfessor[qtd_prof_cadastrado].Matricula);
              getchar();
              printf("Insira o nome do Professor:\n");
              fgets(ListaDeProfessor[qtd_prof_cadastrado].Nome, Tam_Nome, stdin);
              delbar0(ListaDeProfessor[qtd_prof_cadastrado].Nome);
              printf("Insira o sexo do Professor: M/F\n");
              scanf(" %c", &ListaDeProfessor[qtd_prof_cadastrado].Sexo);
              getchar();
              /*printf("Insira a data de nascimento do Professor:\n");
              fgets(ListaDeProfessor[qtd_prof_cadastrado].DataNasc, Tam_Data, stdin);
              delbar0(ListaDeProfessor[qtd_prof_cadastrado].DataNasc);*/            
              printf("Insira o cpf do Professor:\n");
              fgets(ListaDeProfessor[qtd_prof_cadastrado].Cpf,Tam_Cpf,stdin);
              delbar0(ListaDeProfessor[qtd_prof_cadastrado].Cpf);
              qtd_prof_cadastrado++;
              break;
            }
            case 2:{
              printf("Insira a Matrícula do Professor");
              scanf("%d",&matriculaprof);
              for(icont=0;icont<qtd_prof_cadastrado+1;icont++){
                if(ListaDeProfessor[icont].Matricula==matriculaprof){
                  for(jcont=icont+1;jcont<qtd_prof_cadastrado;jcont++){
                    ListaDeProfessor[jcont-1].Matricula=ListaDeProfessor[jcont].Matricula;
                    strcpy(ListaDeProfessor[jcont-1].Cpf,ListaDeProfessor[jcont].Cpf);
                    strcpy(ListaDeProfessor[jcont-1].Nome,ListaDeProfessor[jcont].Nome);
                    ListaDeProfessor[jcont-1].Sexo=ListaDeProfessor[jcont].Sexo;
                    /*strcpy(ListaDeProfessor[jcont-1].DataNasc,ListaDeProfessor[jcont].DataNasc);*/
                    
                  }
                }
              }
              qtd_prof_cadastrado--;
              break;
            }
          
          }
          break;
        }
          
        case 3:{
          
          MenuDisciplina = MenudeDisciplina();
          switch (MenuDisciplina)
            case 1:{
              printf("Insira a Nome da Disciplina\n");
              fgets(ListaDeDisciplina[qtd_disc_cadastrado].Nome,Tam_Nome_Disc,stdin);
              printf("Insira o Codigo da Disciplina:\n");
              scanf("%d", &ListaDeDisciplina[qtd_disc_cadastrado].Codigo);
              getchar();
              printf("Insira o Semestre\n");
              scanf("%d", &ListaDeDisciplina[qtd_disc_cadastrado].Semestre);
              getchar();
              printf("Insira a nome do Professor correspondente à disciplina:\n");
              fgets(ListaDeDisciplina[qtd_disc_cadastrado].Professor, Tam_Nome, stdin);
              qtd_disc_cadastrado++;
              break;
            }
          break;
        }
          
        case 4:{
          
          MenuRelatorio = MenuRelatorios();
          switch (MenuRelatorio)
            case 1:
              for(icont=0;icont<qtd_alunos_cadastrados;icont++){
                printf("%d  %s %c %s\n" , ListaDeAlunos[icont].Matricula, ListaDeAlunos[icont].Nome, ListaDeAlunos[icont].Sexo, ListaDeAlunos[icont].Cpf);
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



//Funções -- Uso geral
void delbar0(char string[]){
  int dbcont;
  for(dbcont=0;string[dbcont]!='\0';dbcont++)
    if(string[dbcont]=='\n')
      string[dbcont]='\0';
}