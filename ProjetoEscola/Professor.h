#include "Data.h"

int MenudeProfessores();
int MenuRelatorios();

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



