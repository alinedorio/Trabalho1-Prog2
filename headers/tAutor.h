//pasta criada para chamar as funções existentes na pasta "tAutor.c"
#ifndef TAUTOR_H
#define TAUTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct tautor tAutor;


tAutor* cadastrar_autor();
//tLivro* retorna_livros();
tAutor* criarAutor(char nome[]);
void deletarAutor(tAutor* autor);
void deletarAutorList(tAutor** autores);
char* getNomeAutor(tAutor* autor);
tAutor* getAutor(char nome[]);
void registrarAutores(char nomes[], tAutor** autores);
void deletarAllAutores();
char* getAutorNome(tAutor* autor);
bool autorListContains(tAutor* autores[], tAutor* autor);
void inicializarAutores(int size);
#endif