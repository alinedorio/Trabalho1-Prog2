//pasta criada para chamar as funções existentes na pasta "Menu.c"
#ifndef MENU_H
#define MENU_H

#include "tCliente.h"
#include "tAutor.h"
#include "tEditora.h"
#include "tLivro.h"
#include "tAutor.h"
#include "tLocacao.h"
#include "Relatorio.h"
#include <time.h>

void menu0();
void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void procuraAutor(char autor[]);
void usuario_procuraCliente();
void usuario_CadastrarCliente();
void procuraCliente(int cpf[]);
void finalizar();


#endif