//pasta criada para chamar as funções existentes na pasta "tEditora.c"
#ifndef TEDITORA_H
#define TEDITORA_H

typedef struct teditora tEditora;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tEditora* cadastrar_editora(char nome[]);
void deletarEditora(tEditora* editora);
void deletarEditoraList(tEditora** editoras);
void deletarAllEditoras();
char* getNomeEditora(tEditora* editora);
void inicializarEditoras(int size);

#endif