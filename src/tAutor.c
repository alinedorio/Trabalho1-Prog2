//pasta criada para organizar todas as funções que estão relacionadas aos autores dos livros.
#include "../headers/tAutor.h"

struct tautor{
  char nome[64];
};

tAutor** allAutores;
int allAutores_size;
int autoresCounter = 0;

void inicializarAutores(int size) {
  if (allAutores == NULL) {
    allAutores = realloc(allAutores, size*sizeof(struct tautor));
    for (int i = 0; i < size; i++) {
      allAutores[i] = NULL;
    }
  }
  allAutores = realloc(allAutores, size*sizeof(struct tautor));
  allAutores[size] = NULL;
  allAutores_size = size;
}

tAutor* getAutor(char nome[]) {
  for (int i = 0; i < autoresCounter; i++){
    if (allAutores[i] == NULL) return NULL;
    if (strcmp(getNomeAutor(allAutores[i]), nome) == 0) {
      return allAutores[i];
    }
  }
  return NULL;
}

char* getAutorNome(tAutor* autor) {
  return autor->nome;
}

tAutor* criarAutor(char nome[]) {
  tAutor* autor = getAutor(nome);
  if (autor == NULL) {
    if (autoresCounter == allAutores_size) {
      inicializarAutores(autoresCounter + 1);
    }
    autor = (tAutor*) malloc(sizeof(struct tautor));
    strcpy(autor->nome, nome);
    allAutores[autoresCounter] = autor;
    autoresCounter++;
  } 
  return autor;
}

char* getNomeAutor(tAutor* autor) {
  return autor->nome;
}

void deletarAutor(tAutor* autor) {
  free(autor);
  autor = NULL;
}

void deletarAutorList(tAutor** autores) {
  int i = 0;
  tAutor *t = autores[i];
  tAutor* aux = autores[i+1];
  while(t != NULL){
    deletarAutor(t);
    if (i == (autoresCounter-1)) {
      break;
    }
    aux = autores[i+1];
    t = aux;
    i++;
  }
  free(autores);
}

void deletarAllAutores() {
  deletarAutorList(allAutores);
}

void registrarAutores(char nomes[], tAutor* autores[]) {

  int counter = 0;
  char aux_autores[64] = " ", dest[1024] = "";

  for (int i = 0; i < 60; i++){
    autores[i] = NULL;
  }
  while (strlen(nomes) != strlen(aux_autores)) {
    aux_autores[0] = '\0';
    sscanf(nomes, "%[^/]", aux_autores);
    
    if (getAutor(aux_autores) == NULL) {
      autores[counter] = criarAutor(aux_autores);
    } else {
      autores[counter] = getAutor(aux_autores);
    }

    if (strcmp(nomes, aux_autores) == 0) break; 

    strncpy(dest, nomes + strlen(aux_autores) + 1, (strlen(nomes)-strlen(aux_autores)));
    strcpy(nomes, dest);
    counter++;
  }
}

bool autorListContains(tAutor* autores[], tAutor* autor){
  int i = 0;
  if (autores == NULL) return 0;
  tAutor* aux = autores[i];
  while (aux != NULL) {
    if (strcmp(autor->nome, aux->nome) == 0) {
      return 1;
    } else {
      aux = autores[i+1];
      i++;
    }
  }
  return 0;
}
