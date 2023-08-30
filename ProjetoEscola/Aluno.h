#ifndef ALUNO_H
#define ALUNO_H

//#include "Disciplina.h"
#include "Data.h"

#define Tam_Matricula 7
#define Tam_Nome 101
#define Tam_Data 12
#define Tam_Nome_Disc 20
#define Tam_Cpf 16
#define Tam_Codigo 6
#define QTD_Alunos 5
#define QTD_Professor 5
#define QTD_Disc 5
#define Max_Materias 10

typedef struct {
  char Matricula[Tam_Matricula];
  char Nome[Tam_Nome];
  char Sexo;
  char Cpf[Tam_Cpf];
  Data DataNasc;
  int Qtd_Mat_Cadast[QTD_Disc];
} Aluno;


int MenudeAlunos();
void InserirAluno(Aluno array[], int num, int qtd_disc_cadastrados);
void ExcluirAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados,
    int qtd_disc_cadastrado); //, Disciplina ListaDeDisciplinas[]);
void AtualizarAluno(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados);
int BuscarPosicaoAluno(Aluno alunos[], char matricula[],int qtd_alunos_cadastrados);
void PreencherDados(Aluno ListaDeAlunos[],int qtd_alunos_cadastrados);

#endif