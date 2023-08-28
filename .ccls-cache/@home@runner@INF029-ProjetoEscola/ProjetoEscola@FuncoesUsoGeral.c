#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
#include "FuncoesUsoGeral.h"



void delbar0(char string[]){
  int dbcont;
  for(dbcont=0;string[dbcont]!='\0';dbcont++)
    if(string[dbcont]=='\n')
      string[dbcont]='\0';
}
int VerificacaoValorMenu(int num1,int num2){
  int icont;
  int valido=-1;
  int verificado=-1;
  int validacao=0;
  char str_verif[100];
  while(valido!=0){
    fgets(str_verif,100,stdin);
    delbar0(str_verif);
    int comprimento = strlen(str_verif);
    if(comprimento==1 || comprimento==2){
      for(icont=0;icont<comprimento;icont++)
        if(str_verif[icont]>='0' && str_verif[icont]<='9')
        {
          validacao++;
          
        }else validacao--;
        

      	if(validacao==comprimento){
        	verificado= atoi(str_verif);
        
        if(verificado>=num1 && verificado<=num2){
          valido=0;
        }else printf("\nComando Inválido! Tente Novamente\n");
      }else printf("\nComando Inválido! Tente Novamente\n");
    }else printf("\nComando Inválido! Tente Novamente\n");
  }
  
  return verificado;
  
}

void ValidarNome(char Lista[]){
  char verificacao[200];
  int verif = 0;
  while(verif!=1)
  {    
    printf("\nDigite o Nome (limite de %d caracteres):\n",Tam_Nome-1);
    fgets(verificacao,200,stdin);
    delbar0(verificacao);
    if(strlen(verificacao)<=Tam_Nome-1)
    {
      strcpy(Lista,verificacao);
      verif=1;
    }else
      printf("\nLimite de caracteres excedido. Tente Novamente:\n");
  }
}

void ValidarSexo(){
int verif = 0;
char sexo;
    while(verif!=1){
    printf("\nInsira o sexo do aluno: M/F\n");
    scanf("%c", &sexo);
    getchar();
    if ((sexo == 'M') || (sexo == 'm') || (sexo == 'f') || (sexo == 'F')){
      //printf("Sexo cadastrado com sucesso");
      verif=1;
    }else{
        printf("\nCadastro inválido\n");    
    }
    }
}

void ValidarMatricula(char Matricula[]){
  char verificacao[20];
  int verif = 0;
  int icont;
  int validacao=0;
  while(verif!=1)
  {    
    printf("\nDigite a Matrícula (limite de %d caracteres):\n",Tam_Matricula-1);
    fgets(verificacao,20,stdin);
    delbar0(verificacao);
    if(strlen(verificacao)==Tam_Matricula-1){
      for(icont=0;icont<Tam_Matricula-1;icont++)
        if(verificacao[icont]>='0' && verificacao[icont]<='9')
          validacao++;
      if(validacao==6){
        strcpy(Matricula,verificacao);
        verif=1;
      }else printf("\nMatrícula deve conter apenas números.\nTente Novamente:\n");
    }else printf("\nLimite de caracteres excedido.\nTente Novamente:\n");
  }
}

int PadraoData(char str[]){
  int icont;
  int jcont;
  int kcont;
  int hcont;
  int validacao1=0;
  int validacao2=0;
  int int_aux_dia;
  int int_aux_mes;
  int int_aux_ano;
  char aux_dia[3];
  char aux_mes[3];
  char aux_ano[5];
  for(icont=0;icont<10;icont++)
  {
    if(str[icont]>='0' && str[icont]<='9')
    {
      if(str[2]== '/' && str[5]=='/')
        validacao1++;
      if(icont==1 || icont==4)
        icont++;
    }
  }
  
  if(validacao1==8){ 
    for(jcont=0;jcont<2;jcont++)
      aux_dia[jcont]=str[jcont];
    aux_dia[2]='\0';
    int_aux_dia=atoi(aux_dia);
    
    for(kcont=3;kcont<5;kcont++)
      aux_mes[kcont-3]=str[kcont];
    aux_mes[2]='\0';
    int_aux_mes=atoi(aux_mes);
            
    if(int_aux_mes==4 || int_aux_mes==6 || int_aux_mes==9 || int_aux_mes==11)
      if(int_aux_dia>=1 && int_aux_dia<=30)      
        validacao2=1;
    if(int_aux_mes==1 || int_aux_mes==3 || int_aux_mes==5 || int_aux_mes==7 
        || int_aux_mes==8 || int_aux_mes==10 || int_aux_mes==12)
      if(int_aux_dia>=1 && int_aux_dia<=31)
        validacao2=1;
    if(int_aux_mes==2)
      if( int_aux_dia>=1 && (int_aux_dia<= 28 || int_aux_dia<= 29) )
        validacao2=1;
  }
      
  
  if (validacao1==8 && validacao2==1){
    return 0;
  }else return 1;
  
}

void ValidarData(char Lista[],Data *Referido){
  int icont;
  int jcont;
  int kcont;
  int hcont;
  int int_aux_dia;
  int int_aux_mes;
  int int_aux_ano;
  char aux_dia[3];
  char aux_mes[3];
  char aux_ano[5];
  int validado=0;
  int tam_lista;
  while(validado!=1){
    printf("\nInsira a data de Nascimento no Padrão: DD/MM/AAAA\n");
    fgets(Lista,15,stdin);
    delbar0(Lista);
    tam_lista = strlen(Lista);
        
    if(tam_lista==10){
      
      if(PadraoData(Lista)==0){
        for(jcont=0;jcont<2;jcont++)
          aux_dia[jcont]=Lista[jcont];
        aux_dia[2]='\0';
        int_aux_dia=atoi(aux_dia);
        Referido->dia=int_aux_dia;
        
        
        for(kcont=3;kcont<5;kcont++)
          aux_mes[kcont-3]=Lista[kcont];
        aux_mes[2]='\0';
        int_aux_mes=atoi(aux_mes);
        Referido->mes=int_aux_mes;
        
        for(hcont=6;hcont<10;hcont++)
          aux_ano[hcont-6]=Lista[hcont];
        aux_ano[4]='\0';
        int_aux_ano=atoi(aux_ano);
        Referido->ano=int_aux_ano;
        
        validado=1;
        
      }else printf("Padrão de data Incorreto! Tente Novamente\n");
    }else printf("Padrão de data Incorreto! Tente Novamente\n");
  }
}

void ValidarCPF(char Lista[]){
int valido=0;
int icont;
int int_tam_cpf;
int validacao=0;
  while(valido!=1){
    printf("Insira o Cpf no formato xxx.xxx.xxx-xx\n");
    fgets(Lista,Tam_Cpf,stdin);
    delbar0(Lista);
    int_tam_cpf=strlen(Lista);
    if(int_tam_cpf==14){
      if(Lista[3]>='.' && Lista[7]<='.'){
        if(Lista[11]=='-'){
          for(icont=0;icont<15;icont++){
            if(Lista[icont]>='0' && Lista[icont]<='9')
              validacao++;
            if(icont==2 || icont==6 || icont==10)
              icont++;
          }
          if (validacao==11){
            valido=1;
          }else printf("\nCPF Inválido, Tente Novamente\n");
        }else printf("\nCPF Inválido, Tente Novamente\n");
      }else printf("\nCPF Inválido, Tente Novamente\n");
    }else printf("\nCPF Inválido, Tente Novamente\n");

    
  }
}