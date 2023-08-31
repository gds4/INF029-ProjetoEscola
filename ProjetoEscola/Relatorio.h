#include "Aluno.h"
#include "Disciplina.h"
#include "Professor.h"

#define Tam_Nome 101
#define Tam_Data 12
#define Tam_Nome_Disc 20
#define Tam_Cpf 16



int MenuRelatorios();
void ListarAlunos(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados);
void ListarProfessor(Professor ListaDeProfessor[], int qtd_prof_cadastrado);
void ListarDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado);
void ListarUmaDisciplina(Disciplina ListaDeDisciplina[] , int qtd_disc_cadastrado,const Aluno ListaDeAluno[],int qtd_alunos_cadastrados);
void ListarAlunoSexo(Aluno ListaDeAluno[], int qtd_alunos_cadastrados);
void ListarProfessorSexo (Professor ListaDeProfessor[], int qtd_prof_cadastrado);
void ListarAlunosNome(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados);
void ListarProfessoresNome(Professor ListaDeProfessor[], int qtd_prof_cadastrado);
void ListarProfDataNasc(Professor ListaDeProfessores[], int qtd_prof_cadastrados);
void ListarAniversariantesDoMes(Professor ListaDeProfessor[], int qtd_prof_cadastrado, Aluno ListaDeAlunos[], int qtd_alunos_cadastrados);
void ListaDePessoas(Professor ListaDeProfessor[], int qtd_prof_cadastrado, Aluno ListaDeAlunos[], int qtd_alunos_cadastrados);
void ListarAlunosMatriculadosDisc(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados,int qtd_disc_cadast);
void ListarAlunoDataNasc(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados);
void ImprimeDisciplinaExtrapolaAlunos(Disciplina ListaDeDisciplina [], int maximo);