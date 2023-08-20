#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#define Tam_Nome 101
#define Tam_Data 12
#define Tam_Nome_Disc 20
#define Tam_Cpf 16
#define QTD_Alunos 5
#define QTD_Professor 5
#define QTD_Disc 3

typedef struct{
  char Nome[Tam_Nome_Disc];
  int Codigo;
  int Semestre;
  char Professor[Tam_Nome];  
}Disciplina;

int MenudeDisciplina();
void InserirDisciplina(Disciplina ListaDeDisciplina[], int qtd_disc_cadastrado);

#endif
