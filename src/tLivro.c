//pasta criada para organizar todas as funções que estão relacionadas aos livros da biblioteca.
#include "../headers/tLivro.h"

struct tlivro {
  int id;
  char titulo[128];
  double valor;
  int ano;
  int unidades;
  int locacoes;

  bool disponivel;

  tAutor* autores[60];
  tEditora* editora;
};

tLivro** allLivros;
int allLivros_size;
int livrosCounter = 0;

void inicializarLivros(int size) {
  allLivros = realloc(allLivros, size*sizeof(struct tlivro));
  allLivros_size = size;
  if (allLivros == NULL) {
    allLivros = realloc(allLivros, size*sizeof(struct tlivro));
    for (int i = 0; i < size; i++) {
      allLivros[i] = NULL;
    }
  }
}


tLivro* getLivro(int id) {
  for (int i = 0; i < livrosCounter; i++){
    if (allLivros[i] == NULL) return NULL;
    if (allLivros[i]->id == id) {
      return allLivros[i];
    }
  }
  return NULL;
}

tLivro* getLivroByTitulo(char* titulo) {
  tLivro* t = NULL;
  for(int i = 0; i < livrosCounter; i++){
    if (allLivros[i] == NULL) return NULL;
    if (strcmp(allLivros[i]->titulo, titulo) == 0) {
      t = allLivros[i];
    }
  }
  return t;
}

char* getTitulo(tLivro* livro) {
  return livro->titulo;
}

tAutor** retorna_autores(tLivro* livro) {
  return livro->autores;
}

void retorna_livros(tAutor* autor, tLivro* livros[]) {
  int i = 0,j = 0;
  for (i = 0; i<80; i++) {
    livros[i] = NULL;
  }
  tLivro* aux = NULL;
  for (i = 0; i<livrosCounter; i++) {
    aux = allLivros[i];
    if (aux == NULL) return;
    if (autorListContains(aux->autores, autor)) {
      livros[j] = aux;
      j+=1;
    }
  }
}

tEditora* retorna_editora(tLivro* livro) {
  return livro->editora;
}

void setDisponibilidade(tLivro* t, bool b) {
  t->disponivel = b;
}

bool disponivel(tLivro* t) {
  return t->disponivel;
}

void adicionarUnidades(tLivro* livro, int units) {
  livro->unidades = livro->unidades + units;
}

void adicionarLocacoes(tLivro* livro, int units) {
  livro->locacoes = livro->unidades + units;
}

void removerUnidades(tLivro* livro, int units) {
  livro->unidades = livro->unidades - units;
}

tLivro* cadastrar_livro(int id, char titulo[], tAutor* autores[], tEditora* editora, double valor, int ano) {
  tLivro* livro = getLivro(id);
  if (livro == NULL) {
    if (livrosCounter == allLivros_size) {
      inicializarLivros(livrosCounter + 1);
    }
    livro = (tLivro*) malloc(sizeof(struct tlivro));

    strcpy(livro->titulo, titulo);
    livro->id = id;
    livro->valor = valor;
    livro->ano = ano;
    livro->editora = editora;
    livro->disponivel = true;
    livro->unidades = 1;
    livro->locacoes = 0;
    for (int i = 0; i < 60; i++) {
      livro->autores[i] = autores[i];
    }

    allLivros[livrosCounter] = livro;
    livrosCounter++;
  } else {
    adicionarUnidades(livro, 1);
  }
  return livro;
}

char *itoa ( int value, char * str ){
    char temp;
    int i =0;
    while (value > 0) {
      int digito = value % 10;

        str[i] = digito + '0';
        value /= 10;
        i++;
    }
   i = 0;
   int j = strlen(str) - 1;
   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
    return str;
}

void adicionarLivroFile(tLivro* livro) {
  FILE *temp;
  temp = fopen("./db/livros.csv", "a");
  char aux_autores[1024] = "", data[30] = "1/01/", aux[10];
  int i = 0;

  tAutor* autor = retorna_autores(livro)[i];
  tAutor* autoraux;
  while (autor != NULL) {
    strcat(aux_autores, getNomeAutor(autor));
    i++;
    autoraux = retorna_autores(livro)[i];
    if (autoraux != NULL) {
      strcat(aux_autores, "/");
    }
    autor = autoraux;
  }
    
  itoa(livro->ano, aux);
  strcat(data, aux);
  fprintf(temp, "%d,%s,%s,%s,%.2lf,%s,%s,%d\n", livro->id, livro->titulo, aux_autores, "5.00", livro->valor, data, getNomeEditora(livro->editora), getUnidades(livro));

  fclose(temp);
}

void deletarLivrosList(tLivro** livros) {
  int i = 0;
  tLivro *t = livros[i];
  tLivro *aux = livros[i+1];
  while(t != NULL){
    deletarLivro(t);
    if (i == (livrosCounter-1)) {
      break;
    }
    aux = livros[i+1];
    t = aux;
    i++;
  }
  free(livros);
}

int getId(tLivro* t) {
  return t->id;
}

void deletarAllLivros() {
  deletarLivrosList(allLivros);
}

void deletarLivro(tLivro* livro) {
  free(livro);
  livro = NULL;
}

double getValorLivro(tLivro* livro) {
  return livro->valor;
}

int getAnoLivro(tLivro* livro) {
  return livro->ano;
}

int getUnidades(tLivro* livro) {
  return livro->unidades;
}

int getLocacoesQnt(tLivro* livro) {
  return livro->locacoes;
}

