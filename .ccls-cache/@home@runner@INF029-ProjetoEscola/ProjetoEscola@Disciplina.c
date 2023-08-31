#include "Professor.h"
#include "Disciplina.h"
#include "Aluno.h"
#include "FuncoesUsoGeral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MenudeDisciplina(){
	int MenuDisciplina;
	printf("\n\n------ MÓDULO DISCIPLINA ------\n");
	printf("\n  0 > Retornar\n");
	printf("  1 > Inserir disciplina \n");
	printf("  2 > Excluir disciplina \n");
	printf("  3 > Atualizar cadastro da disciplina \n");
	printf("  4 > Inserir turma\n");
	MenuDisciplina=VerificacaoValorMenu(0,4);


  return MenuDisciplina;
}

void InserirDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado, Professor ListaDeProfessor[], int qtd_prof_cadast){
  if(qtd_disc_cadastrado<QTD_Disc){
    printf("\nInsira o nome da disciplina:\n");
    fgets(ListaDeDisciplina[qtd_disc_cadastrado].Nome, Tam_Nome_Disc, stdin);
  
    ValidarCodigoDisc(&ListaDeDisciplina[qtd_disc_cadastrado].Codigo);
  
    ValidarSemestre(ListaDeDisciplina[qtd_disc_cadastrado].Semestre);
  
    ValidarNomeProf(ListaDeDisciplina[qtd_disc_cadastrado].Professor, ListaDeProfessor, qtd_prof_cadast);
  
    ListaDeDisciplina[qtd_disc_cadastrado].NumAlunos=0;
  }else printf("\nNúmero máximo de disciplinas atingido\nNão é possível cadastrar uma nova disciplina.\n");
}

void AtualizarDisciplina(Disciplina ListaDeDisciplina[], Professor ListaDeProfessor[], int codigo_disciplina_atualizar, int qtd_disc_cadastrado, int qtd_prof_cadast) {
    int encontrou = 0;
    int i, j, sair = 0;
    int codigo, MenuAtualizarDisc;

	while(!sair){	
		printf("\n Insira o código da disciplina que deseja atualizar: \n");
		scanf("%d", &codigo);
		getchar();
		for (i=0; i< qtd_disc_cadastrado && sair == 0; i++){
			if(ListaDeDisciplina[i].Codigo == codigo){
				printf("\nATUALIZAÇÃO DE DADOS: DISCIPLINA\n");
				printf("\nEscolha o dado que deseja atualizar \n");  
				printf("0 - Sair\n");
				printf("1 - Nome\n");
				printf("2 - Código\n");
				printf("3 - Semestre\n");
				printf("4 - Professor\n");
				
				MenuAtualizarDisc = VerificacaoValorMenu(0,4);

				switch(MenuAtualizarDisc){
					case 0:{
						sair = 1;
						break;
					}
					case 1:{
						printf("\nInsira o novo nome da disciplina:\n");
						fgets(ListaDeDisciplina[i].Nome, Tam_Nome_Disc, stdin); 
						break;
					}             
					case 2:{
						ValidarCodigoDisc(&ListaDeDisciplina[i].Codigo);
						break;
					}
					case 3:{
						ValidarSemestre(ListaDeDisciplina[i].Semestre);
						break;
					}			
					case 4:{
						ValidarNomeProf(ListaDeDisciplina[i].Professor, ListaDeProfessor, qtd_prof_cadast);
						break;
					}					              					 
				}
				encontrou = 1;
				break;
			} 
			
		}
		if (encontrou){
			printf("Disciplina atualizada com sucesso\n ");
		
		} else {
			printf("Código de disciplina inválido\n");
		}
  	}

}
  

void ExcluirDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado, Aluno ListaDeAlunos[],int qtd_alunos_cadastrados) {
  int encontrou = 0;
  int icont, jcont, kcont, lcont;
  int codigo;
  int sair=1;
  while(sair!=0){
    printf("Insira o código da disciplina a ser excluída:\n");
    codigo= PadraoCodigo();
    for (icont=0; icont< qtd_disc_cadastrado; icont++){
      if(ListaDeDisciplina[icont].Codigo == codigo){
        for(kcont=0;kcont<qtd_alunos_cadastrados;kcont++)
          for(lcont=icont+1;lcont<qtd_disc_cadastrado;lcont++)
          	ListaDeAlunos[kcont].Qtd_Mat_Cadast[lcont-1]=ListaDeAlunos[kcont].Qtd_Mat_Cadast[lcont];
        for(jcont=icont+1; jcont < qtd_disc_cadastrado;jcont++){
          strcpy(ListaDeDisciplina[jcont-1].Nome,ListaDeDisciplina[jcont].Nome);
          ListaDeDisciplina[jcont-1].Codigo = ListaDeDisciplina[jcont].Codigo;
          strcpy(ListaDeDisciplina[jcont-1].Semestre,ListaDeDisciplina[jcont].Semestre);
          strcpy(ListaDeDisciplina[jcont-1].Professor, ListaDeDisciplina[jcont].Professor);      
          
        }      
        encontrou = 1;
        break; 
      }
    }
    if (encontrou){
      printf("Disciplina excluída com sucesso!\n");
      sair=0;
    } else {
      printf("Código da disciplina inválido!");
    }
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
  int posicao;
  int icont;
  int jcont;
  int encontrada=0;
  int sairdoloop1=1;
  char matricula[10];
  int codigoDisciplina;
  while(sairdoloop1!=0){
    printf("Informe o código da disciplina para inserir a turma: ");
    scanf("%d", &codigoDisciplina);
    getchar();
  
    for (jcont = 0; jcont < qtd_disc_cadast; jcont++)
    {
      if (disciplina[jcont].Codigo == codigoDisciplina) 
      {
        int encontrada=1;
        int numAlunos = disciplina[jcont].NumAlunos;
        printf("\nInserindo alunos na disciplina %s\n", disciplina[jcont].Nome);
        int sairloop2=1;
        while (sairloop2!=0) {
          printf("\nInsira a matrícula do aluno:\n ");
          fgets(matricula,10,stdin);
          delbar0(matricula);
          int variavel = strlen(matricula);
          
          if (variavel == 6) {
              if (verificarExistenciaMatricula(alunos, qtd_alunos_cadastrados, matricula)) {
                posicao = BuscarPosicaoAluno(alunos, matricula, qtd_alunos_cadastrados);
                alunos[posicao].Qtd_Mat_Cadast[jcont]=1;
                //strcpy(disciplina[jcont].Turma[numAlunos], matricula);
                numAlunos++;
                disciplina[jcont].NumAlunos = numAlunos;
                printf("\nInserir novo aluno?\n");
                printf("\n1 - Sim\n2 - Não\n");
                int opcao = VerificacaoValorMenu(1,2);
                if(opcao==1)
                {
                  sairloop2=1;                
                }else if(opcao == 2){
                  sairdoloop1=0;
                  sairloop2=0;
                }
                
              }else printf("\nMatrícula não existe no sistema. Tente novamente.\n");
          }else printf("\nMatrícula inválida. Tente novamente.\n");
        } 
      }
      if (encontrada==0 && jcont==qtd_disc_cadast-1 && disciplina[jcont].Codigo != codigoDisciplina)
        printf("\nDisciplina não encontrada. Tente novamente\n");
    }
  }
}

void ValidarCodigoDisc(int *codigo){
  int icont;
  int valido=1;
  char input[10];
  int somat=0;
  while(valido!=0){
    somat=0;
    printf("\nInsira o código da disciplina\n");
    fgets(input,10,stdin);
    delbar0(input);
    int tam_input=strlen(input);
    if(tam_input==5){
      for(icont=0;input[icont]!='\0';icont++){
        if(input[icont]>='0' && input[icont]<='9'){
          somat++;
        }
      }
      if(somat==5){
        *codigo=atoi(input);
        valido=0;
      }else printf("\nCódigo inválido! Tente novamente.\n");
    }else printf("\nO código deve conter 5 digitos. Tente novamente.\n");
  }
}

void ValidarSemestre(char input[]){
  char validacao[10];
  int icont;
  int valido=1;
  int somat;
  while (valido!=0){
    printf("\nInforme o semestre da disciplina:\n\n");
    fgets(validacao,10,stdin);
    delbar0(validacao);
    if(strlen(validacao)==6)
    {
      if(validacao[5]=='1' || validacao[5]=='2')
      {
        if(validacao[4]=='.')
        {
          somat=0;
          for(icont=0;validacao[icont]!='\0';icont++)
            if(validacao[icont]>='0' && validacao[icont]<='9')
            {
              somat++;
              if(icont==3)
                icont++;
            }
          if(somat==5)
          {
            strcpy(input,validacao);
            valido=0;
          }else printf("\nSemestre inválido. Tente novamente\n");
          
        }else printf("\nPadrão inválido. Tente novamente\n");
        
      }else printf("\nSemestre inválido. Tente novamente\n");
      
    }else printf("\nSemestre inválido. Tente novamente\n");
  }
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

int PadraoCodigo(){
  char str[10];
  int icont;
  int sair=1;
  int validacao=0;
  int codigo;
  while(sair!=0){
    fgets(str,10,stdin);
    delbar0(str);
    int tam_str=strlen(str);
    
    if(tam_str==5){
      validacao=0;
      for(icont=0;str[icont]!='\0';icont++)
        if(str[icont]>='0' && str[icont]<='9'){
          validacao++;
      }else validacao--;
      if(validacao==5){
        codigo=atoi(str);
        sair=0;
      }else printf("Codigo invalido! Tente novamente:");
    }else printf("Codigo invalido! Tente novamente:");
  }
  return codigo;
}

void PreencherDados(Aluno *ListaDeAlunos,int qtd_alunos_cadastrados,Professor ListaDeProfessor[],int qtd_prof_cadastrado,Disciplina ListaDeDisciplina[],int qtd_disc_cadastrado){
  
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Matricula, "202301");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Nome, "Maria Santos");
  ListaDeAlunos[qtd_alunos_cadastrados].Sexo = 'F';
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Cpf, "987.654.321-00");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data, "20/11/2002");
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.dia = 20;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.mes = 11;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.ano = 2002;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3] = 1;

  qtd_alunos_cadastrados++;

  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Matricula, "202302");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Nome, "Joao Silva");
  ListaDeAlunos[qtd_alunos_cadastrados].Sexo = 'M';
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Cpf, "932.615.341-01");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data, "11/04/2001");
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.dia = 11;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.mes = 04;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.ano = 2001;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0] = 0;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2] = 0;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3] = 0;
  qtd_alunos_cadastrados++;

  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Matricula, "202201");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Nome, "Claudio Santos");
  ListaDeAlunos[qtd_alunos_cadastrados].Sexo = 'M';
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Cpf, "912.621.521-01");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data, "03/03/1999");
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.dia = 03;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.mes = 03;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.ano = 1999;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1] = 0;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3] = 0;
  qtd_alunos_cadastrados++;

  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Matricula, "202202");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Nome, "Juliana Oliveira");
  ListaDeAlunos[qtd_alunos_cadastrados].Sexo = 'F';
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Cpf, "127.654.356-05");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data, "01/01/2001");
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.dia = 01;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.mes = 01;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.ano = 2001;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2] = 0;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3] = 0;
  qtd_alunos_cadastrados++;

  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Matricula, "202102");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Nome, "Claudineia Azevedo");
  ListaDeAlunos[qtd_alunos_cadastrados].Sexo = 'F';
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Cpf, "220.376.982-02");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data, "01/06/1997");
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.dia = 01;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.mes = 06;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.ano = 1997;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3] = 0;
  qtd_alunos_cadastrados++;
  

  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Matricula, "202101");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Nome, "Clodovil Oliveira");
  ListaDeAlunos[qtd_alunos_cadastrados].Sexo = 'M';
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].Cpf, "349.031.843-00");
  strcpy(ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.str_data, "03/10/1998");
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.dia = 03;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.mes = 10;
  ListaDeAlunos[qtd_alunos_cadastrados].DataNasc.ano = 1998;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[0] = 1;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[1] = 0;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[2] = 0;
  ListaDeAlunos[qtd_alunos_cadastrados].Qtd_Mat_Cadast[3] = 1;
  qtd_alunos_cadastrados++;

  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Matricula, "202415");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Nome, "Marcos Oliveira");
  ListaDeProfessor[qtd_prof_cadastrado].Sexo = 'M';
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Cpf, "329.731.843-53");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data, "02/10/1999");
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.dia = 02;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.mes = 10;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.ano = 1999;
  qtd_prof_cadastrado++;

  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Matricula, "202110");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Nome, "Mario Antonio");
  ListaDeProfessor[qtd_prof_cadastrado].Sexo = 'M';
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Cpf, "349.031.123-00");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data, "17/04/1982");
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.dia = 17;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.mes = 04;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.ano = 1982;
  qtd_prof_cadastrado++;

  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Matricula, "202103");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Nome, "Maria Antonieta dos Santos");
  ListaDeProfessor[qtd_prof_cadastrado].Sexo = 'F';
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Cpf, "169.031.843-00");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data, "02/12/1970");
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.dia = 02;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.mes = 12;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.ano = 1970;
  qtd_prof_cadastrado++;

  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Matricula, "202112");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Nome, "Ana Maria Oliveira");
  ListaDeProfessor[qtd_prof_cadastrado].Sexo = 'F';
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].Cpf, "349.077.773-07");
  strcpy(ListaDeProfessor[qtd_prof_cadastrado].DataNasc.str_data, "27/02/1988");
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.dia = 27;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.mes = 02;
  ListaDeProfessor[qtd_prof_cadastrado].DataNasc.ano = 1988;
  qtd_prof_cadastrado++;

  ListaDeDisciplina[qtd_disc_cadastrado].Codigo = 12345;
  strcpy(ListaDeDisciplina[qtd_disc_cadastrado].Professor, "Ana Maria Oliveira");
  strcpy(ListaDeDisciplina[qtd_disc_cadastrado].Nome, "Matematica");
  strcpy(ListaDeDisciplina[qtd_disc_cadastrado].Semestre, "2022.2");

  ListaDeDisciplina[qtd_disc_cadastrado].NumAlunos = 5;
  qtd_disc_cadastrado++;
  
  ListaDeDisciplina[qtd_disc_cadastrado].Codigo = 12432;
  strcpy(ListaDeDisciplina[qtd_disc_cadastrado].Professor, "Maria Antonieta dos Santos");
  strcpy(ListaDeDisciplina[qtd_disc_cadastrado].Nome, "Portugues");
  strcpy(ListaDeDisciplina[qtd_disc_cadastrado].Semestre, "2023.1");
  ListaDeDisciplina[qtd_disc_cadastrado].NumAlunos = 4;
  qtd_disc_cadastrado++;

  ListaDeDisciplina[qtd_disc_cadastrado].Codigo = 13532;
  strcpy(ListaDeDisciplina[qtd_disc_cadastrado].Professor, "Mario Antonio");
  strcpy(ListaDeDisciplina[qtd_disc_cadastrado].Nome, "Geografia");
  strcpy(ListaDeDisciplina[qtd_disc_cadastrado].Semestre, "2023.1");

  ListaDeDisciplina[qtd_disc_cadastrado].NumAlunos = 3;
  qtd_disc_cadastrado++;

  ListaDeDisciplina[qtd_disc_cadastrado].Codigo = 22432;
  strcpy(ListaDeDisciplina[qtd_disc_cadastrado].Professor, "Clodovil Oliveira");
  strcpy(ListaDeDisciplina[qtd_disc_cadastrado].Nome, "Sociologia");
  strcpy(ListaDeDisciplina[qtd_disc_cadastrado].Semestre, "2023.2");

  ListaDeDisciplina[qtd_disc_cadastrado].NumAlunos = 2;
  qtd_disc_cadastrado++;



}