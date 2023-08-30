#include "Data.h"

#define Tam_Nome 101

#define Tam_Nome_Disc 20
#define Tam_Cpf 16
#define Tam_Matricula 7
#define QTD_Alunos 5
#define QTD_Professor 5
#define QTD_Disc 5

void delbar0(char string[]);
int VerificacaoValorMenu(int num1,int num2);
void ValidarSexo (char sexo);
void ValidarNome(char Lista[]);
void ValidarMatricula(char Matricula[]);
int PadraoData(char str[]);
void ValidarData(char Lista[],Data *Referido);
void ValidarCPF(char Lista[]);