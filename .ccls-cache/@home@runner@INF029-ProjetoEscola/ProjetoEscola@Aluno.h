#include "Data.h"

#ifndef ALUNO_H
#define ALUNO_H

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
  char Cpf[Tam_Cpf];
  Data DataNasc;
}Aluno;

int MenudeAlunos();
void InserirAluno();

#endif