#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Data.h"

#define Tam_Nome 101
#define Tam_Data 12
#define Tam_Nome_Disc 20
#define Tam_Cpf 16
#define QTD_Alunos 5
#define QTD_Professor 5
#define QTD_Disc 3

typedef struct {
  int Matricula;
  char Nome[Tam_Nome];
  char Sexo;
  Data DataNasc;
  char Cpf[Tam_Cpf];
} Professor;

int MenudeProfessores();
int MenuRelatorios();
void InserirProfessor(Professor ListaDeProfessor[],int qtd_prof_cadastrado);
void ExcluirProfessor(Professor ListaDeProfessor[],int qtd_prof_cadastrado);

#endif