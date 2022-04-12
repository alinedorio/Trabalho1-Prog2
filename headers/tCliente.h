//pasta criada para chamar as funções existentes na pasta "tCliente.c"
#ifndef TCLIENTE_H
#define TCLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tData.h"

typedef struct tcliente tCliente;

char* getNomeCliente(tCliente* t);
int* getCPF(tCliente* t);
char getSexo(tCliente* t);
char* getTelefone(tCliente* t);
char* getEmail(tCliente* t);

tCliente* cadastrar_cliente(char nome[], int cpf[], char sexo, char telefone[], char email[]);
// tLocacao* retorna_locacoes();

tCliente* getCliente(int cpf[]);

void deletarAllClientes();
void deletarCliente(tCliente* c);
void deletarClienteList(tCliente** clientes);
void adicionarClienteFile(tCliente* c);

void inicializarClientes(int size);
tCliente** getAllClientes();

#endif