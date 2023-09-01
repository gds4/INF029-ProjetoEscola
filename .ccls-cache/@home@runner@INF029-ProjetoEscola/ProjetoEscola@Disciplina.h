#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#define QTD_Disc 10
#define Max_Aluno_Turma 60
#define Tam_Nome 101
#define Tam_Semestre 7
#define Tam_Nome_Disc 20
#define Tam_Cpf 16


typedef struct Disciplina{
  char Nome[Tam_Nome_Disc];
  int Codigo;
  char Semestre[Tam_Semestre];
  char Professor[Tam_Nome];
  int NumAlunos;
}Disciplina;

#include "Aluno.h"
#include "Professor.h"

int MenudeDisciplina();
void InserirDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado,Professor ListaDeProfessor[],int qtd_prof_cadast);
void AtualizarDisciplina (Disciplina ListaDeDisciplina[], Professor ListaDeProfessor[], int codigo_disciplina_atualizar, int qtd_disc_cadastrado, int qtd_prof_cadast);
void ExcluirDisciplina (Disciplina ListaDeDisciplina[], int codigo, Aluno ListaDeAlunos[], int qtd_alunos_cadastrados);
void InserirTurma (Disciplina *disciplina, Aluno alunos[], int qtd_alunos_cadastrados,int qtd_disc_cadast);
int PadraoCodigo();
void PreencherDados(Aluno ListaDeAlunos[],int qtd_alunos_cadastrados,Professor ListaDeProfessor[],int qtd_prof_cadastrado,Disciplina ListaDeDisciplina[],int qtd_disc_cadastrado);
int BuscarPosicaoDisciplina(Disciplina ListaDeDisciplina[],int codigo,int qtd_disc_cadastrado);
#endif
