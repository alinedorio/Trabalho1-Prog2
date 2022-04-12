//pasta criada para chamar as funções existentes na pasta "tLivro.c"
#ifndef TLIVRO_H
#define TLIVRO_H

#include "tAutor.h"
#include "tEditora.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct tlivro tLivro;

tLivro* cadastrar_livro(int id, char titulo[], tAutor* autores[], tEditora* editora, double valor, int ano);
tEditora* retorna_editora(tLivro* livro);
tAutor** retorna_autores(tLivro* livro);
void deletarLivro(tLivro* livro);
void deletarLivrosList(tLivro* livros[]);
void deletarAllLivros();
void adicionarUnidades(tLivro* livro, int units);
double getValorLivro(tLivro* livro);
bool disponivel(tLivro* t);
void setDisponibilidade(tLivro* t, bool b);
void procuraLivro(char titulo[256]);
void retorna_livros(tAutor* autor, tLivro* livros[]);
char* getTitulo(tLivro* livro);
tLivro* getLivroByTitulo(char* titulo);
tLivro* getLivro(int id);
int getAnoLivro(tLivro* t);
int getLocacoesQnt(tLivro* livro);
int getUnidades(tLivro* livro);
void adicionarLivroFile(tLivro* livro);
char *  itoa ( int value, char * str );
void usuario_CadastrarLivro();
int getId(tLivro* t);
void adicionarLocacoes(tLivro* livro, int units);
void removerLocacoes(tLivro* livro, int units);
void inicializarLivros(int size);

#endif