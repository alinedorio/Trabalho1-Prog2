//pasta criada para organizar todas as funções que estão relacionadas às editoras dos livros.
#include "../headers/tEditora.h"

struct teditora {
  char nome[128];
};

tEditora** allEditoras;
int allEditoras_size;
int editoraCounter = 0;

void inicializarEditoras(int size) {
  if (allEditoras == NULL) {
    allEditoras = realloc(allEditoras, size*sizeof(struct teditora));
    for (int i = 0; i < size; i++) {
      allEditoras[i] = NULL;
    }
  }
  allEditoras = realloc(allEditoras, size*sizeof(struct teditora));
  allEditoras_size = size;
}

tEditora* getEditora(char nome[]) {
  for (int i = 0; i < editoraCounter; i++){
    if (allEditoras[i] == NULL) return NULL;
    if (strcmp(allEditoras[i]->nome, nome) == 0) {
      return allEditoras[i];
    }
  }
  return NULL;
}

char* getNomeEditora(tEditora* editora) {
  return editora->nome;
}

tEditora* cadastrar_editora(char nome[]) {
  tEditora* editora = getEditora(nome);
  if (editora == NULL) {
    if (editoraCounter == allEditoras_size) {
      inicializarEditoras(editoraCounter + 1);
    }
    editora = (tEditora*) malloc(sizeof(struct teditora));
    strcpy(editora->nome, nome);
    allEditoras[editoraCounter] = editora;
    editoraCounter++;
  }
  return editora;
}

void deletarEditora(tEditora* editora) {
  free(editora);
  editora = NULL;
}

void deletarEditoraList(tEditora** editoras) {
  int i = 0;
  tEditora *t = editoras[i];
  tEditora *aux = allEditoras[i+1];
  while(t != NULL){
    deletarEditora(t);
    if (i == (editoraCounter-1)) {
      break;
    }
    aux = allEditoras[i+1];
    t = aux;
    i++;
  }
  free(editoras);
}

void deletarAllEditoras() {
  deletarEditoraList(allEditoras);
}