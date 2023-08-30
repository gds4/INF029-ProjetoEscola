#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "Aluno.h"
#include "Professor.h"

#define Max_Aluno_Turma 60
#define Tam_Nome 101
#define Tam_Semestre 7
#define Tam_Nome_Disc 20
#define Tam_Matricula 7
#define Tam_Cpf 16



typedef struct{
  char Nome[Tam_Nome_Disc];
  int Codigo;
  char Semestre[Tam_Semestre];
  char Professor[Tam_Nome];
  char Turma[Max_Aluno_Turma][Tam_Matricula];
  int NumAlunos;
}Disciplina;

int MenudeDisciplina();
void InserirDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado,Professor ListaDeProfessor[],int qtd_prof_cadast);
int AtualizarDisciplina (Disciplina ListaDeDisciplina[], Professor ListaDeProfessor[], int codigo_disciplina_atualizar, int qtd_disc_cadastrado, int qtd_prof_cadast);
void ExcluirDisciplina (Disciplina ListaDeDisciplina[], int codigo);
int verificarExistenciaMatricula (Aluno alunos[], int qtd_alunos_cadastrados, const char *matricula);
void InserirTurma (Disciplina *disciplina, Aluno alunos[], int qtd_alunos_cadastrados,int qtd_disc_cadast);
void ValidarCodigoDisc (int *codigo);
void ValidarSemestre (char input[]);
void ValidarNomeProf (char professor[], Professor ListaDeProfessor[], int qtd_prof_cadast);

#endif
