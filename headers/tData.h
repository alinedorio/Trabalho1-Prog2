//pasta criada para chamar as funções existentes na pasta "tData.c"
#ifndef TDATA_H
#define TDATA_H

typedef struct tdata tData;

#include <stdio.h>
#include <stdlib.h>

tData* criarData(int dia, int mes, int ano);
int tempoEntreDatas(tData* data1, tData* data2);
tData* dataentrega(tData* data1, int qtddias);
void deletarData(tData* data);
int getDia(tData* data);
int getMes(tData* data);
int getAno(tData* data);
tData* getData(int diaDoAno, int ano);
int diaDoAno(tData* data);
tData* filtroDeData(char* data);

#endif