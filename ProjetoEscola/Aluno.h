#include "Data.h"

#ifndef ALUNO_H
#define ALUNO_H

#define Tam_Matricula 7
#define Tam_Nome 101
#define Tam_Data 12
#define Tam_Nome_Disc 20
#define Tam_Cpf 16
#define Tam_Codigo 7
#define QTD_Alunos 5
#define QTD_Professor 5
#define QTD_Disc 3
#define Max_Materias 10

typedef struct {
  char Matricula[Tam_Matricula];
  char Nome[Tam_Nome];
  char Sexo;
  char Cpf[Tam_Cpf];
  Data DataNasc;
  char Materias [Max_Materias][Tam_Codigo];
  int Qtd_Mat_Cadast;
}Aluno;

int MenudeAlunos();
void InserirAluno(Aluno array[], int num);
void ExcluirAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados);
void AtualizarAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados);


#endif