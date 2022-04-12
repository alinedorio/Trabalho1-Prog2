//pasta criada para chamar as funções existentes na pasta "tLocacao.c"
#ifndef TLOCACAO_H
#define TLOCACAO_H 

#include "tCliente.h"
#include "tLivro.h"
#include <unistd.h>
#include <errno.h>

typedef struct tlocacao tLocacao;

tLocacao* cadastrar_locacao(tData* dataLocacao, int diasLocados, tCliente* cliente, tLivro* livro);
double retorna_valor_locacao(tLocacao* t, tData* dataAtual);
bool extrapolou_tempo_limite();
//tCliente* retorna_cliente();
tLivro* retorna_livro();
void adicionarLocacaoFile(tLocacao* t, char* arq);
void devolverLivro(tLocacao* loc, tData* dataDevolucao);
void inicializarLocacoes(int size);
tLocacao* getLocacao(tLivro* livro);
tCliente* getClienteLocacao(tLocacao *t);
tData* getDataLocacao(tLocacao* t);
bool isAtrasado(tLocacao* t, tData* dataAtual);
tData* getDataDevolucao(tLocacao* t);
void atualizaLocacaoFile();
void deletarLocacaoList(tLocacao** loc);
void deletarAllLocacoes();
void deletarLocacao(tLocacao* locacao);
tLocacao** getLocacoes(tCliente* c);
tLivro* getLivroLocacao(tLocacao* t);
int getDiasLocados(tLocacao* t);





#endif