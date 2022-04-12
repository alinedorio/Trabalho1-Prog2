#include "../headers/Relatorio.h"

void relatorioClientes() {
  int i = 0, j = 0;
  tCliente* c = getAllClientes()[i];

  FILE *temp;
  temp = fopen("./relatorios/relatorio_clientes.txt", "w");
  
  while (c != NULL) {
    char aux_cpf[13] = "";
    printf("teste");
    for (j = 0; j < 11; j++) {
      int digit = getCPF(c)[j];
      aux_cpf[j] = digit + '0';
    }
    fprintf(temp, "Nome: %s\n", getNomeCliente(c));
    fprintf(temp, "CPF: %s\n", aux_cpf);
    fprintf(temp, "Locações:\n");

    tLocacao** locacoes = getLocacoes(c);

    j = 0;
    tLocacao* loc = locacoes[j];
    while (loc != NULL) {

      fprintf(temp,"  Titulo do Livro: %s", getTitulo(getLivroLocacao(loc)));

      fprintf(temp, " Data de Locação: %i/%i/%i\n", getDia(getDataLocacao(loc)), getMes(getDataLocacao(loc)), getAno(getDataLocacao(loc)));

      tData* data_devolucao = getDataDevolucao(loc);

      if (data_devolucao == NULL) {
        int diaEntrega = diaDoAno(getDataLocacao(loc)) + getDiasLocados(loc);
        data_devolucao = getData(diaEntrega, getAno(getDataLocacao(loc)));
        fprintf(temp, " (V) ");
      } else {
        fprintf(temp, " (X) ");
      }
      fprintf(temp, "Data de Devolução: %i/%i/%i\n", getDia(data_devolucao), getMes(data_devolucao), getAno(data_devolucao));

      

      fprintf(temp," Valor total: %.2lf\n", retorna_valor_locacao(loc, data_devolucao));

      fprintf(temp,"\n");
      j++;
    }
    deletarLocacaoList(locacoes);

    fprintf(temp,"\n");
    i++;
    c = getAllClientes()[i];
  }
  fclose(temp);
}