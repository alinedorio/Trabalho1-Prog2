#include "../headers/tLocacao.h"

struct tlocacao {
  tData* data_locacao;
  tData* data_devolucao;

  tCliente* cliente;
  tLivro* livro;
  
  int dias_locado;
};

tLocacao** allLocacoes;
int allLocacoes_size;
int locacoesCounter = 0;

void inicializarLocacoes(int size) {
  allLocacoes = realloc(allLocacoes, size*sizeof(struct tlocacao));
  allLocacoes_size = size;
  if (allLocacoes == NULL) {
    allLocacoes = realloc(allLocacoes, size*sizeof(struct tlocacao));
    for (int i = 0; i < size; i++) {
      allLocacoes[i] = NULL;
    }
  }
}

tLocacao* cadastrar_locacao(tData* dataLocacao, int diasLocados, tCliente* cliente, tLivro* livro) {
  if (locacoesCounter == allLocacoes_size) {
      inicializarEditoras(locacoesCounter + 1);
  }
  tLocacao* locacao = malloc(sizeof(struct tlocacao));
  locacao->data_locacao = dataLocacao;
  locacao->data_devolucao = NULL;
  locacao->dias_locado = diasLocados;
  locacao->cliente = cliente;
  locacao->livro = livro;

  setDisponibilidade(livro, false);

  allLocacoes[locacoesCounter] = locacao;
  locacoesCounter++;

  adicionarLocacoes(livro, 1);
  return locacao;
}

void adicionarLocacaoFile(tLocacao* t, char* arq) {
  FILE *temp;
  char aux_cpf[13];
  int i = 0;
  temp = fopen(arq, "a");

  tData* dataDevolucao = t->data_devolucao;
  char aux_dataDevolucao[] = "00/00/0000";
  if (t->data_devolucao != NULL) {
    sprintf(aux_dataDevolucao, "%d/%d/%d", getMes(dataDevolucao), getDia(dataDevolucao), getAno(dataDevolucao));
  }

  tData* dataLocacao = t->data_locacao;
  char aux_dataLocacao[] = "00/00/0000";

  sprintf(aux_dataLocacao, "%d/%d/%d", getMes(dataLocacao), getDia(dataLocacao), getAno(dataLocacao));

  for (i = 0; i < 11; i++) {
    int digit = getCPF(t->cliente)[i];
    aux_cpf[i] = digit + '0';
  }


  fprintf(temp, "%s,%s,%d,%s,%i\n", aux_dataLocacao, aux_dataDevolucao, t->dias_locado, aux_cpf, getId(t->livro));

  fclose(temp);
}

void atualizaLocacaoFile() {
  int i = 0;
  FILE *original, *alterado;
  original = fopen("./db/locacoes.csv", "r");
  alterado = fopen("./db/alt_locacoes.csv", "w");

  if (original == NULL) {
    printf("Erro ao abrir o arquivo ./db/locacoes.csv\n");
  }
  
  tLocacao* t = allLocacoes[i];
  fprintf(alterado,"data_locacao, data_devolucao, dias_locados, cliente_cpf, livro_id\n");
  while (t!=NULL) {
    adicionarLocacaoFile(t, "../db/alt_locacoes.csv");
    i++;
    t = allLocacoes[i];
  }

  fclose(alterado);
  fclose(original);
  unlink("./db/locacoes.csv");
  rename("./db/alt_locacoes.csv", "./db/locacoes.csv");
}

void devolverLivro(tLocacao* loc, tData* dataDevolucao) {
  if (!disponivel(loc->livro)) {
    setDisponibilidade(loc->livro , true);
    loc->data_devolucao = dataDevolucao;
  }
  atualizaLocacaoFile();
}

void deletarLocacao(tLocacao* locacao) {
  deletarData(locacao->data_locacao);
  deletarData(locacao->data_devolucao);
  free(locacao);
  locacao = NULL;
}


void deletarLocacaoList(tLocacao** loc) {
  int i = 0;
  tLocacao *t = loc[i];
  tLocacao *aux = loc[i+1];
  while(t != NULL){
    deletarLocacao(t);
    if (i == (locacoesCounter-1)) {
      break;
    }
    aux = loc[i+1];

    t = aux;
    i++;
  }
  free(loc);
}

void deletarAllLocacoes() {
  deletarLocacaoList(allLocacoes);
}

int getDiasLocados(tLocacao* t) {
  return t->dias_locado;
}

bool isAtrasado(tLocacao* t, tData* dataAtual){
  if (tempoEntreDatas(t->data_locacao, dataAtual) > t->dias_locado) {
    return 1;
  }
  return 0;
}

tLocacao* getLocacao(tLivro* livro) {
  int i = 0;
  tLocacao* t = allLocacoes[i];
  while (t != NULL) {
    if (t->livro == livro) {
      return t;
    }
    i++;
    t = allLocacoes[i];
  }
  return NULL;
}

tLocacao** getLocacoes(tCliente* c) {
  int i, counter = 0;
  tLocacao** loc = malloc(sizeof(struct tlocacao));

  for (i = 0; i < locacoesCounter; i++) {
    tLocacao* aux = allLocacoes[i];
    if (aux->cliente == c) {
      loc = realloc(loc, (counter+1)*sizeof(struct tlocacao));
      loc[counter] = aux;
      counter++;
    }
  }

  if (loc[0] == NULL) {
    deletarLocacaoList(loc);
    return NULL;
  }
  return loc;
}

tCliente* getClienteLocacao(tLocacao *t) {
  return t->cliente;
}

tData* getDataLocacao(tLocacao* t) {
  return t->data_locacao;
}

tData* getDataDevolucao(tLocacao* t) {
  return t->data_devolucao;
}

tLivro* getLivroLocacao(tLocacao* t) {
  return t->livro;
}

double retorna_valor_locacao(tLocacao* t, tData* dataAtual) {
  double valor = getValorLivro(t->livro) * tempoEntreDatas(t->data_locacao, dataAtual);
  if (isAtrasado(t, dataAtual)) {
    int diasAtrasado = tempoEntreDatas(t->data_locacao, dataAtual);
    valor += 1.1*diasAtrasado*(getValorLivro(t->livro));
  }
  return valor;
}