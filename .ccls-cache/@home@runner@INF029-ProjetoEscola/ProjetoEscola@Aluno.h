#ifndef ALUNO_H
#define ALUNO_H

#define Tam_Matricula 7
#define Tam_Nome 101
#define Tam_Data 12
#define Tam_Nome_Disc 20
#define Tam_Cpf 16
#define Tam_Codigo 6
#define QTD_Alunos 10
#define QTD_Disc_Max 10
#define Num_Max_Alunos 40
//QTD_Disc_Max deve ser igual a QTD_Disc
#include "Data.h"

typedef struct Aluno{
  char Matricula[Tam_Matricula];
  char Nome[Tam_Nome];
  char Sexo;
  char Cpf[Tam_Cpf];
  Data DataNasc;
  int Qtd_Mat_Cadast[QTD_Disc_Max]; 
} Aluno;

#include "Disciplina.h"

int MenudeAlunos();
void InserirAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados, int qtd_disc_cadastrados);
void ExcluirAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados,
int qtd_disc_cadastrado, Disciplina ListaDeDisciplina[]); 
void AtualizarAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados);
int BuscarPosicaoAluno(Aluno alunos[], char matricula[],int qtd_alunos_cadastrados);
int verificarExistenciaMatricula(Aluno alunos[], int qtd_alunos_cadastrados, const char *matricula);

#endif