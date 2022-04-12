#include "headers/Menu.h"

void leInfo();

int main() {
  leInfo();
  
  menu0();
  finalizar();
}

//Função criada para ler todas as informações do arquivo "books_-_books.csv, clientes.csv e locacoes.csv".
void leInfo() {

  char temp_titulo[256], temp_id[20], temp_autores[1024], temp_nota[20], temp_valor[20], temp_data[20], temp_editora[64], temp_units[20], linha[1024];

  inicializarAutores(500);
  inicializarClientes(1);
  inicializarEditoras(500);
  inicializarLocacoes(1);
  inicializarLivros(1000);

  tAutor* autores[60];

  int i = -1, trash, ano;
  FILE *temp;

  //comando para abrir o arquivo "books_-_books.csv".
  temp = fopen("db/books_-_books.csv", "r");

  //verificando abertura do arquivo
  if (temp == NULL) {
    printf("Erro ao abrir o arquivo /db/books_-_books.csv");
  }

  //enquanto o arquivo não acabar, o programa deverá ler o que está escrito nele.
  while (!feof(temp)) {
    fscanf(temp, "%[^\n]\n", linha);
    if (i >= 0) {
      //em cada linha do arquivo, o programa separa em partes, de acordo com sua utilidade.
      sscanf(linha, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]", temp_id, temp_titulo, temp_autores, temp_nota, temp_valor,temp_data, temp_editora, temp_units);
      sscanf(temp_data, "%d/%d/%d", &trash, &trash, &ano);

      registrarAutores(temp_autores, autores);

      tEditora* editora = cadastrar_editora(temp_editora);

      tLivro* livro = cadastrar_livro(atoi(temp_id), temp_titulo, autores, editora, atof(temp_valor), ano);

      adicionarUnidades(livro, atoi(temp_units)-1);

    }
    i=0;
  }
  //fechando o arquivo "books_-_books.csv".
  fclose(temp);
  
  //abertura do arquivo "clientes.csv".
  temp = fopen("db/clientes.csv", "r");

  //verificando abertura do arquivo
  if (temp == NULL) {
    printf("Erro ao abrir o arquivo /db/clientes.csv");
  }

  i=-1;
  char nome[128], aux_cpf[13], sexo, telefone[128], email[128];
  //enquanto o arquivo não acabar, o programa deverá ler o que está escrito nele.
  while (!feof(temp)) {
    int j = 0, cpf[11];
    fscanf(temp, "%[^\n]\n", linha);
    if (i >= 0) {
      //em cada linha do arquivo, o programa separa em partes, de acordo com sua utilidade.
      sscanf(linha, "%[^,],%[^,],%c,%[^,],%[^,]", nome, aux_cpf, &sexo, telefone, email);
      while (aux_cpf[j] != '\0') {
        if (aux_cpf[j] == '\n') {
          aux_cpf[j] = '\0';
          break;
        }
        cpf[j] = aux_cpf[j]-'0';
        j++;
      }
      cadastrar_cliente(nome, cpf, sexo, telefone, email);
    }
    i=0;
  }
  //fechando o arquivo "clientes.csv".
  fclose(temp);

  //abertura do arquivo "locacoes.csv".
  temp = fopen("db/locacoes.csv", "r");

  //verificando abertura do arquivo
  char aux_dataLocacao[20], aux_dataDevolucao[20];
  int diasLocados, idLivro;

  if (temp == NULL) {
    printf("Erro ao abrir o arquivo /db/locacoes.csv");
  }
  i=-1;
  //enquanto o arquivo não acabar, o programa deverá ler o que está escrito nele.
  while (!feof(temp)) {
    int j = 0, cpf[11];
    fscanf(temp, "%[^\n]\n", linha);
    if (i >= 0) {
      //em cada linha do arquivo, o programa separa em partes, de acordo com sua utilidade.
      sscanf(linha, "%[^,],%[^,],%d,%[^,],%d",aux_dataLocacao,aux_dataDevolucao, &diasLocados,aux_cpf,&idLivro);
      while (aux_cpf[j] != '\0') {
        if (aux_cpf[j] == '\n') {
          aux_cpf[j] = '\0';
          break;
        }
        cpf[j] = aux_cpf[j]-'0';
        j++;
      }
      tData* dataLocacao = filtroDeData(aux_dataLocacao);
      tData* dataDevolucao = filtroDeData(aux_dataDevolucao);

      tCliente* t = getCliente(cpf);
      tLivro* livro = getLivro(idLivro);
      tLocacao* loc = cadastrar_locacao(dataLocacao, diasLocados, t, livro);

      if (getAno(dataDevolucao) == 0) {
        deletarData(dataDevolucao);
      } else {
        devolverLivro(loc, dataDevolucao);
      }
    }
    i = 0;
  }
  //fechando o arquivo "locacoes.csv".
  fclose(temp);
}