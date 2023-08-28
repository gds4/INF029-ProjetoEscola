#include "Professor.h"
#include "Disciplina.h"
#include "Aluno.h"
#include "FuncoesUsoGeral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MenudeDisciplina(){
  int MenuDisciplina;
  printf("\n  0 > Retornar\n");
  printf("  1 > Inserir Disciplina \n");
  printf("  2 > Excluir Disciplina \n");
  printf("  3 > Atualizar Cadastro da Disciplina \n");
  printf("  4 > Inserir Turma\n");
  MenuDisciplina=VerificacaoValorMenu(0,4);
  getchar();

  return MenuDisciplina;
}

void InserirDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado, Professor ListaDeProfessor[], int qtd_prof_cadast){

  printf("\nInsira o nome da disciplina:\n");
  fgets(ListaDeDisciplina[qtd_disc_cadastrado].Nome, Tam_Nome_Disc, stdin);

  ValidarCodigoDisc(ListaDeDisciplina[qtd_disc_cadastrado].Codigo);

  ValidarSemestre(ListaDeDisciplina[qtd_disc_cadastrado].Semestre);

  ValidarNomeProf(ListaDeDisciplina[qtd_disc_cadastrado].Professor ,ListaDeProfessor,qtd_prof_cadast);

  ListaDeDisciplina[qtd_disc_cadastrado].NumAlunos=0;
}

/*int AtualizarDisciplina(Disciplina ListaDeDisciplina[], int codigo_disciplina_atualizar, int qtd_disc_cadastrado) {

  
  if(codigo_disciplina_atualizar >=0 && codigo_disciplina_atualizar < qtd_disc_cadastrado){
    printf("\nInsira o novo nome da disciplina\n");
    fgets(ListaDeDisciplina[codigo_disciplina_atualizar].Nome, Tam_Nome_Disc, stdin);
  
    printf("\nInsira o novo código da disciplina:\n");
    scanf("%d", &ListaDeDisciplina[codigo_disciplina_atualizar].Codigo);
    getchar();
  
    printf("\nInsira o novo semestre\n");
    scanf("%d", &ListaDeDisciplina[codigo_disciplina_atualizar].Semestre);
    getchar();
  
    printf("\nInsira o novo nome do professor correspondente à disciplina:\n");
    fgets(ListaDeDisciplina[codigo_disciplina_atualizar].Professor, Tam_Nome, stdin);
    return 1;
  }
  return 0;
}*/

int AtualizarDisciplina(Disciplina ListaDeDisciplina[], int codigo_disciplina_atualizar, int qtd_disc_cadastrado) {
    int encontrou = 0;
    int i, j;
    int codigo;
    printf("\n Insira o código da disciplina que deseja atualizar: \n");
    scanf("%d", &codigo);
	  getchar();
    for (i=0; i< qtd_disc_cadastrado; i++){
      if(ListaDeDisciplina[i].Codigo == codigo){
              printf("\n\nDisciplina encontrada\n\n");              
        
              printf("\nInsira o novo nome da disciplina:\n");
              fgets(ListaDeDisciplina[qtd_disc_cadastrado].Nome, Tam_Nome_Disc, stdin);
              getchar();
            
              printf("\nInsira o novo código da disciplina:\n");
              scanf("%d", &ListaDeDisciplina[qtd_disc_cadastrado].Codigo);
                          
              printf("\nInsira o novo semestre\n");
              scanf("%d", &ListaDeDisciplina[qtd_disc_cadastrado].Semestre);
                          
              printf("\nInsira a nome do novo professor correspondente à disciplina: \n");
              fgets(ListaDeDisciplina[qtd_disc_cadastrado].Professor, Tam_Nome, stdin);
              getchar();
        }      
        encontrou = 1;
        break; 
      }
    if (encontrou){
            printf("Disciplina atualizada com sucesso\n ");
            
    } else {
      printf("Código de disciplina inválido\n");
    }
}
  

void ExcluirDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado) {
  int encontrou = 0;
  int i, j;
  int codigo;
  printf("Insira o código da disciplina a ser excluída:\n");
  scanf("%d", &codigo);
  for (i=0; i< qtd_disc_cadastrado; i++){
    if(ListaDeDisciplina[i].Codigo == codigo){
      for(j=i; j < (QTD_Disc - 1); j++){
        strcpy(ListaDeDisciplina[j].Nome,ListaDeDisciplina[j+1].Nome);
        ListaDeDisciplina[j].Codigo = ListaDeDisciplina[j+1].Codigo;
        strcpy(ListaDeDisciplina[j].Semestre,ListaDeDisciplina[j+1].Semestre);
        strcpy(ListaDeDisciplina[j].Professor, ListaDeDisciplina[j+1].Professor);      
        
      }      
      encontrou = 1;
      break; 
    }
  }
  if (encontrou){
    printf("Disciplina excluída com sucesso!\n");
  } else {
    printf("Código da disciplina inválido!");
  }
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
void InserirTurma(Disciplina *disciplina, Aluno alunos[], int qtd_alunos_cadastrados,int qtd_disc_cadast) {
  
  int icont;
  int jcont;
  int numAlunos = disciplina->NumAlunos;
  char matricula[Tam_Matricula];
  int codigoDisciplina;

  printf("Informe o código da disciplina para inserir a turma: ");
  scanf("%d", &codigoDisciplina);
  getchar();

  for (jcont = 0; jcont < qtd_disc_cadast; jcont++)
  {
    if (disciplina[jcont].Codigo == codigoDisciplina) 
    {
      printf("\nInserindo alunos na disciplina %s\n", disciplina->Nome);
      int sairloop=1;
      while (sairloop!=0) {
        printf("\nInsira a matrícula do aluno (ou '0' para sair): ");
        fgets(matricula,Tam_Matricula,stdin);
        getchar();
        int variavel = strlen(matricula);
        
        if (variavel == 6) {
            if (verificarExistenciaMatricula(alunos, qtd_alunos_cadastrados, matricula)) {
              strcpy(disciplina->Turma[numAlunos], matricula);
              numAlunos++;
              disciplina->NumAlunos = numAlunos;
              printf("\nInserir novo aluno?\n");
              printf("\n1 - Sim\n2 - Não\n");
              int opcao = VerificacaoValorMenu(1,2);
              if(opcao==1)
              {
                sairloop=1;                
              }else if(opcao == 2){
                sairloop=0;
              }
              
            }else printf("\nMatrícula não existe no sistema. Tente novamente.\n");
        }else printf("\nMatrícula inválida. Tente novamente.\n");
      } 
    }
  }
}

void ValidarCodigoDisc(int codigo){
  int icont;
  int valido=1;
  char input[Tam_Codigo];
  int somat=0;
  while(valido!=0){
    
    printf("\nInsira o código da Disciplina\n");
    fgets(input,Tam_Codigo,stdin);
    delbar0(input);
    getchar();
    puts(input);
    somat=0;
    for(icont=0;icont<Tam_Codigo;icont++){
      if(input[icont]>='0' && input[icont]<='9'){
        somat++;
      }
    }
    if(somat==5){
      codigo=atoi(input);
      valido=0;
    }else printf("\nCódigo Inválido! Tente Novamente.\n");
  }
}

void ValidarSemestre(char input[]){
  int icont;
  int valido=1;
  int somat=0;
  while (valido!=0){
    printf("\nInforme o Semestre da disciplina:\n\n");
    fgets(input,Tam_Semestre,stdin);
    delbar0(input);
    if(input[4]=='.'){
      for(icont=0;icont<Tam_Semestre-1;icont++)
        if(input[icont]>='0' || input[icont]<='9'){
          somat++;
          if(icont==3)
            icont++;
        }
    }else printf("\nPadrão incorreto. Tente novamente\n");
    printf("%d",somat);
    if(somat==5){
      valido=0;
    }else printf("\nSemestre Inválido. Tente novamente\n");
  }
}

void ValidarNomeProf(char professor[], Professor ListaDeProfessor[], int qtd_prof_cadast){
  int Existeprof=0;
  int icont;
  int valido=1;
  char comparar[Tam_Nome];
  
  while(valido!=0){
    printf("\nInsira o nome do professor referente a disciplina\n\n");
    fgets(comparar,Tam_Nome,stdin);
    delbar0(comparar);
    for(icont=0;icont<qtd_prof_cadast;icont++){
      if(strcmp(comparar,ListaDeProfessor[icont].Nome)==0){
        Existeprof=1;
      }
    }

    if(Existeprof==1){
      strcpy(professor,comparar);
      valido=0;
    }else printf("Nome não encontrado. Tente novamente.\n");
  }
}
