#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Data.h"

#define Tam_Matricula 7
#define Tam_Nome 101
#define Tam_Data 12
#define Tam_Nome_Disc 20
#define Tam_Cpf 16
#define QTD_Professor 10

typedef struct {
  char Matricula[Tam_Matricula];
  char Nome[Tam_Nome];
  char Sexo;
  Data DataNasc;
  char Cpf[Tam_Cpf];
} Professor;

int MenudeProfessores();
int MenuRelatorios();
void InserirProfessor(Professor ListaDeProfessor[],int qtd_prof_cadastrado);
void ExcluirProfessor(Professor ListaDeProfessor[],int qtd_prof_cadastrado);
void AtualizarProfessor(Professor ListaDeProfessor[], int qtd_prof_cadastrado);


#endif