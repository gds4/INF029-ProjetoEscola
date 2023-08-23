#include "Aluno.h"
#include "Disciplina.h"
#include "Professor.h"

#define Tam_Nome 101
#define Tam_Data 12
#define Tam_Nome_Disc 20
#define Tam_Cpf 16
#define QTD_Alunos 5
#define QTD_Professor 5


int MenuRelatorios();
void ListarAlunos(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados);
void ListarProfessor(Professor ListaDeProfessor[], int qtd_prof_cadastrado);
void ListarUmaDisciplina(Disciplina ListaDeDisciplina[] , int qtd_disc_cadastrado, int disciplina);
void ListarProfessorSexo (Professor ListaDeProfessor[], int qtd_prof_cadastrado);
void ListarAlunosNome(Aluno ListaDeAlunos[], int qtd_alunos_cadastrados);
void ListarProfessoresNome(Professor ListaDeProfessor[], int qtd_prof_cadastrado);