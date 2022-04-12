//pasta criada para organizar os diferentes menus que aparecerão na tela do computador baseado nas escolhas do usuário.
#include "../headers/Menu.h"

//abaixo temos a função que abre o primeiro menu que aparece na tela.
void menu0() {
  system("clear");
  int num;
  //esse menu aparecerá sempre que a opção escolhida no switch case logo abaixo for diferente de 6.
  do {
    //a primeira coisa que aparece na tela quando o programa roda.
    printf ("1- Cadastrar\n");
    printf ("2- Pesquisar\n");
    printf ("3- Locacao\n");
    printf ("4- Relatorios\n");
    printf ("5- Devolucao\n");
    printf ("6- Sair\n");

    //é necessário escolher uma das opções dentre as existentes acima, escolhendo um número de 1 a 6 para selecionar a opção desejada.
    scanf("%i", &num);

    //switch case criado para que o programa realize diferentes ações dependendo da opção escolhida pelo usuário.
    switch(num){
      //se o usuario escolher a opcao "cadastrar".
      case 1:
        menu1();
        break;
      //se o usuario escolher a opcao "pesquisar".
      case 2:
        menu2();
        break; 
      //se o usuario escolher a opcao "locação".
      case 3:
        system("clear");
        menu3();
        break;
      //se o usuario escolher a opcao "relatorios".
      case 4:
        system("clear");
        menu4();
        break;
      //se o usuario escolher a opcao "devolucao".
      case 5:
        system("clear");
        menu5();
        break;
      //se o usuario escolher a opcao "sair".
      case 6:
        finalizar();
        break;
      //caso ele escolha algum numero que nao esteja entre as opções disponiveis.
      default:
        system("clear");
        printf("Opcao invalida.\n\n");
    }

  }
  while(num != 6);
}

//função criada para caso o usuário escolha a opção 1 no menu0.
void menu1(){
  int n;
  //esse menu aparecerá sempre que a opção escolhida no switch case logo abaixo for diferente de 4.
  do{
    //função usada para limpar a tela
    system("clear");
    //o que aparece na tela ao se escolher menu1.
    printf ("1- Cadastrar Cliente\n");
    printf ("2- Cadastrar Livro\n");
    printf ("3- Voltar\n");
    printf ("4- Sair\n");

    //é necessário escolher uma das opções dentre as existentes acima, escolhendo um número de 1 a 4 para selecionar a opção desejada. 
    scanf("%d", &n);

    //switch case criado para que o programa realize diferentes ações dependendo da opção escolhida pelo usuário.
    switch(n){
      //caso o usuario escolha "cadastrar cliente".
      case 1:
        system("clear");
        usuario_CadastrarCliente();
        break;
      //caso o usuario escolha "cadastrar livro".
      case 2:
        usuario_CadastrarLivro();
        break;
      //caso o usuario escolha "voltar".
      case 3:
        menu0();
        break;
      //caso o usuario escolha "sair".
      case 4:
        finalizar();
        break;
      //caso o usuario nao escolha nenhuma das opções disponiveis.
      default:
        printf("\nOpcao invalida.");

    };
  }
  while(n!=4);
}

//função criada para caso o usuário escolha a opção 2 no menu0.
void menu2(){
  int n;
  //esse menu aparecerá sempre que a opção escolhida no switch case logo abaixo for diferente de 5.
  do{
    //função usada para limpar a tela
    system("clear");
    //o que aparece na tela ao se escolher menu2.
    printf ("1- Pesquisar Cliente\n");
    printf ("2- Pesquisar Livro\n");
    printf ("3- Pesquisar Autor\n");
    printf ("4- Voltar\n");
    printf ("5- Sair\n");

    //é necessário escolher uma das opções dentre as existentes acima, escolhendo um número de 1 a 4 para selecionar a opção desejada. 
    scanf("%d", &n);

    //switch case criado para que o programa realize diferentes ações dependendo da opção escolhida pelo usuário.
    switch(n){
      //caso o usuario escolha "pesquisar cliente".
      case 1:
        system("clear");
        usuario_procuraCliente();
        break;
      //caso o usuario escolha "pesquisar livro".
      case 2:
        system("clear");
        printf("Titulo do Livro: ");
        char titulo[256];
        scanf("\n%[^\n]", titulo);
        procuraLivro(titulo);
        break;
      //caso o usuario escolha "pesquisar autor".
      case 3:
        system("clear");
        printf("Nome do Autor: ");
        char autor[128];
        scanf("\n%[^\n]", autor);
        procuraAutor(autor);
        break;
      //caso o usuario escolha "voltar".
      case 4:
        menu0();
        break;
      //caso o usuario escolha "sair".
      case 5:
        finalizar();
        break;
      //caso o usuario nao escolha nenhuma das opções disponiveis.
      default:
        printf("\nOpcao invalida.");

    };
  }
  while(n!=5);
}
//menu criado para permitir que o sistema faça a locação de um livro para um cliente, ou seja, caso escolha a opcao 3 no menu0.
void menu3(){
  int cpf[11];
  int i, id, n;
//inserindo um cpf para proder associá-lo à um cliente e, assim, poder realizar a locação.
  printf("CPF do Cliente: ");
  char aux[128];
  scanf("\n%[^\n]", aux);
  while (aux[i] != '\0') {
    if (aux[i] == '\n') {
      aux[i] = '\0';
      break;
    }
    if (i == 11) {
      system("clear");
      printf("CPF digitado incorretamente! Insira 11 números!\nProcurando novamente...\n\n");
      menu3();
      return;
    }
    if (!isdigit(aux[i])) {
      system("clear");
      printf("CPF digitado incorretamente! Insira apenas números!\nProcurando novamente...\n\n");
      menu3();
      return;
    }
    cpf[i] = aux[i]-'0';
    i++;
  }
  if (i < 11) {
    system("clear");
    printf("CPF digitado incorretamente! Insira 11 números!\nProcurando novamente...\n\n"); 
    menu3();
    return;
  }
  //inserindo a ID do livro que deseja-se alugar para poder realizar a locação.
  printf("ID do Livro: ");
  scanf("%i", &id);

  system("clear");
  //encontrando o cliente por meio e seu cpf e o livro por meio de sua ID.
  tCliente* cliente = getCliente(cpf);
  tLivro* livro = getLivro(id);
  //caso o cpf não seja encontrado, significa que o cliente ainda não foi cadastrado, logo é necessário fazer seu cadastro.
  if (cliente == NULL){
    printf("Cliente inexistente! Criando um novo cliente.\n");
    usuario_CadastrarCliente();
  }
  //caso o cpf seja encontrado, a locação pode ser realizada.
  else{
    //verifica se o livro está disponivel para ser alugado.
    if (!disponivel(livro)) {
      printf("Livro indisponível!");
    //verifica se a biblioteca possui o livro.
    } else if (livro == NULL){
      printf("Livro não encontrado!");
    //caso a biblioteca possua o livro e ele esteja disponivel, é possível seguir para os proximos passos da locação.
    } else {
      int qtddias;
      char confirma;
      double valor;
      double valortotal;
      tLocacao* locacao;
      //é necessário encontrar o valor da locação do livro.
      valor = getValorLivro(livro);
      
      //imprimindo as informações que o sistema possui até o momento, para mostrar ao cliente.
      printf("Nome do Cliente: %s", getNomeCliente(cliente));
      printf("\nTitulo do Livro: %s", getTitulo(livro));
      printf("\nValor: %.2lf", valor);
      //após o cliente verificar o valor da locação do livro, ele escolhe por quantos dias ele decide alugá-lo.
      printf("\nDigite a quantidade de dias para locacao: ");
      scanf("%i", &qtddias);
      //após escolher a quantidade de dias, é preciso descobrir o dia em que o livro foi alugado e a data de devolução esperada a partir dessas informações.
      time_t t = time(NULL);
      struct tm tm = *localtime(&t);
      tData* data_locacao = criarData(tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);

      int diaEntrega = diaDoAno(data_locacao) + qtddias;
      tData* data_devolucao = getData(diaEntrega, getAno(data_locacao));
      
      system("clear");
      //após descobrir todas as informações necessárias, são impressos o Nomm do Cliente, o Título do Livro, o Valor da Locação do Livro, a Data de Locação, a Data de Devolução e e o Valor Total da locação, baseado na quantidade de dias alugado.
      printf("Nome do Cliente: %s\n", getNomeCliente(cliente));
      printf("Titulo do Livro: %s\n", getTitulo(livro));
      printf("Valor: %.2lf\n", valor);//falta completar
      printf("Data de Locacao: %i/%i/%i\n", getDia(data_locacao), getMes(data_locacao), getAno(data_locacao));
      printf("Data de Devolucao: %i/%i/%i\n", getDia(data_devolucao), getMes(data_devolucao), getAno(data_devolucao));

      deletarData(data_devolucao);
      //calculo do valor total da locação.
      valortotal = valor*qtddias;

      printf("Valor total: %.2lf\n", valortotal);
    //verifica se o cliente realmente quer alugar o livro.
      printf("Confirmar Locacao(S/N): ");
      scanf("\n%c", &confirma);
      //switch case criado para trabalhar com as diferentes opções de confirmação de locação.
      switch(confirma){
        //caso o usuario queira confirmar
        case 'S':
        locacao = cadastrar_locacao(data_locacao, qtddias, cliente, livro);
        adicionarLocacaoFile(locacao, "./db/locacoes.csv");
        printf("\nLocacao Confirmada!");
        break;
        //caso não queira confirmar
        case 'N':
        deletarData(data_locacao);
        menu0();
        break;
        //caso não escolha nenhuma das opções disponíveis.
        default:
        printf("\nResponda com S ou N -> ");
      }
    }
    //após terminar tudo, o sistema deseja saber se o usuário quer voltar ao menu inicial para realizar mais coisas ou fechar o programa por completo.
    printf("\n\n");
    printf ("1- Voltar\n");
    printf ("2- Sair\n");
    scanf("%i", &n);
    //switch case criado para decidir se volta ao menu principal ou fecha o programa.
    switch(n){
      //caso escolha "voltar".
      case 1:
        menu0();
        break;
      //caso escolha "sair".
      case 2:
        finalizar();
        break;
      //caso nao escolha nenhuma das opcoes disponiveis.
      default:
        printf("\nOpcao invalida.\n");
    };
  }
}
  

//função criada para organizar o menu de relatorios, ou seja, caso escolha a opcao 4 no menu0.
void menu4(){
  int n;
  //esse menu aparecerá sempre que a opção escolhida no switch case logo abaixo for diferente de 5.
  //o que aparece na tela ao se escolher menu2.
  printf ("1- Relatorio de Cliente\n");
  printf ("2- Relatorio de Livro\n");
  printf ("3- Relatorio de Locacoes\n");
  printf ("4- Voltar\n");
  printf ("5- Sair\n");

  //é necessário escolher uma das opções dentre as existentes acima, escolhendo um número de 1 a 4 para selecionar a opção desejada. 
  scanf("%d", &n);

  //switch case criado para que o programa realize diferentes ações dependendo da opção escolhida pelo usuário.
  switch(n){
    //caso o usuario escolha "Relatório de Cliente".
    case 1:
      relatorioClientes();
      system("clear");
      printf("Relatório gerado!\n\n");
      menu4();
      break;
        //caso o usuario escolha "Relatório de Livro".
    case 2:

      break;
        //caso o usuario escolha "Relatório de Locações".
    case 3:

      break;
        //caso o usuario escolha "Voltar".
    case 4:
      menu0();
      break;
        //caso o usuario escolha "Sair".
    case 5:
      finalizar();
      break;
    //caso o usuario não escolha nenhuma das opções disponiveis
    default:
      printf("\nOpção invalida.");
  };
}
//funcao para caso a pessoa escolha a opcao 5 no menu0.
void menu5() {
  int id, n;
  char confirma;
  printf("ID do Livro: ");
  scanf("%d", &id);
  tLivro* livro = getLivro(id);
  if (livro == NULL) {
    system("clear");
    printf("Livro inexistente.");
  } else if (disponivel(livro)) {
    system("clear");
    printf("O livro está disponível.");
  } else {
    tLocacao* loc = getLocacao(livro);
    printf("\nNome do cliente: %s", getNomeCliente(getClienteLocacao(loc)));
    printf("\nTítulo do Livro: %s", getTitulo(livro));

    tData* dataLoc = getDataLocacao(loc);
    printf("\nData de locação: %d/%d/%d", getDia(dataLoc), getMes(dataLoc), getAno(dataLoc));

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    tData* data_devolucao = criarData(tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);

    printf("\nData de devolução: %d/%d/%d", getDia(data_devolucao), getMes(data_devolucao), getAno(data_devolucao));

    printf("\nValor total: %.2lf", retorna_valor_locacao(loc, data_devolucao));

    printf("\nAtrasado: ");
    if (isAtrasado(loc, data_devolucao)) {
      printf("sim");
    } else {
      printf("não");
    }
    printf("\n\nConfirmar devolução(S/N): ");
    while (confirma != 'S' || confirma != 'N') {
      scanf("\n%c", &confirma);
      //switch case criado para trabalhar com as diferentes opções de confirmação de devolucao.
      switch(confirma){
      //caso o usuario queira confirmar
        case 'S':
          devolverLivro(loc, data_devolucao);
          printf("\nDevolução confirmada.");
          break;
          //caso não queira confirmar
        case 'N':
          deletarData(data_devolucao);
          menu0();
          break;
          //caso não escolha nenhuma das opções disponíveis.
        default:
          printf("\nResponda com S ou N -> ");
      }
    }
  }
  //após terminar tudo, o sistema deseja saber se o usuário quer voltar ao menu inicial para realizar mais coisas ou fechar o programa por completo.
  printf("\n\n");
  printf ("1- Voltar\n");
  printf ("2- Sair\n");
  scanf("%i", &n);
  //switch case criado para decidir se volta ao menu principal ou fecha o programa.
  switch(n){
  //caso escolha "voltar".
    case 1:
      menu0();
      break;
      //caso escolha "sair".
    case 2:
      finalizar();
      break;
    //caso nao escolha nenhuma das opcoes disponiveis.
    default:
      printf("\nOpcao invalida.\n");
  };
}
//função criada para pesquisar um cliente dentre todos que foram cadastrados até o momento da procura.
void usuario_procuraCliente(){
  int cpf[11], i;
  system("clear");
  //escaneando um cpf para associá-lo a um cliente.
  printf("CPF do Cliente: ");
  char aux[128];
  scanf("\n%[^\n]", aux);
  while (aux[i] != '\0') {
    if (aux[i] == '\n') {
      aux[i] = '\0';
      break;
    }
    if (i == 11) {
      system("clear");
      printf("CPF digitado incorretamente! Insira 11 números!\nProcurando novamente...\n\n");
      usuario_procuraCliente();
      return;
    }
    if (!isdigit(aux[i])) {
      system("clear");
      printf("CPF digitado incorretamente! Insira apenas números!\nProcurando novamente...\n\n");
      usuario_procuraCliente();
      return;
    }
    cpf[i] = aux[i]-'0';
    i++;
  }
  if (i < 11) {
    system("clear");
    printf("CPF digitado incorretamente! Insira 11 números!\nProcurando novamente...\n\n"); 
    usuario_procuraCliente();
    return;
  }
  procuraCliente(cpf);
}
//função que insere o nome de um autor e mostra todos os livros que ele já publicou.
void procuraAutor(char nome[]){
  int i = 0, n;
  tLivro* livros[80];
  system("clear");
  tAutor* t = getAutor(nome);
  if (t != NULL) {
    printf("Nome: %s\n", getAutorNome(t));

    printf("\n");

    printf("Livros publicados: ");

    retorna_livros(t, livros);
    tLivro* l = livros[i];
    tLivro* aux;
    while (l != NULL) {
      printf("%s", getTitulo(l));
      aux = livros[i+1];
      if (aux != NULL) {
        printf(", ");
      }
      l = aux;
      i++;
    }
    
    printf("\n\n");
    printf ("1- Voltar\n");
    printf ("2- Sair\n");

    while (n!=2) {
      scanf("%i", &n);

      switch(n){
        case 1:
          menu2();
          break;
        case 2:
          finalizar();
          break;
        default:
          printf("\nOpcao invalida.\n");
      }
    }
  }
}

//função criada para caso o usuário escolha a opção 1 no menu1. Ela permite o cadastro de um cliente no sistema.
void usuario_CadastrarCliente(){

  char aux[128], nome[128], sexo, telefone[128], email[128];
  int cpf[11];
  int n, i = 0;

  printf("Nome: ");
  scanf("\n%[^\n]", nome);

  printf("CPF: ");
  scanf("\n%[^\n]", aux);

  while (aux[i] != '\0') {
    if (aux[i] == '\n') {
      aux[i] = '\0';
      break;
    }
    if (i == 11) {
      system("clear");
      printf("CPF digitado incorretamente! Insira 11 números!\nCadastrando novamente...\n\n");
      usuario_CadastrarCliente();
      return;
    }
    if (!isdigit(aux[i])) {
      system("clear");
      printf("CPF digitado incorretamente! Insira apenas números!\nCadastrando novamente...\n\n");
      usuario_CadastrarCliente();
      return;
    }
    cpf[i] = aux[i]-'0';
    i++;
  }
  if (i < 11) {
      system("clear");
      printf("CPF digitado incorretamente! Insira 11 números!\nCadastrando novamente...\n\n");
      usuario_CadastrarCliente();
      return;
  }

  printf("Sexo: ");
  scanf("\n%c", &sexo);
  while (sexo != 'M' && sexo != 'F' && sexo != 'N') {
    printf("\n");
    printf("Responda com M, F ou N -> ");
    scanf("\n%c", &sexo);
    printf("\n");
  }

  printf("Telefone: ");
  scanf("\n%[^\n]", telefone);


  printf("E-mail: ");
  scanf("\n%[^\n]", email);


  system("clear");
  if(getCliente(cpf) != NULL){
    printf("Cliente já cadastrado.\n");
  } else {
    tCliente* c = cadastrar_cliente(nome, cpf, sexo, telefone, email);
    adicionarClienteFile(c);

    printf("Cliente cadastrado com sucesso!\n");
  }

  printf ("1- Voltar\n");
  printf ("2- Sair\n");

  while (n!= 2) {
    scanf("%i", &n);

    switch(n){
      case 1:
        menu1();
        break;
      case 2:
        finalizar();
        break;
      default:
        printf("\nOpcao invalida.");
    };
  }
}

void procuraCliente(int cpf[]){
  system("clear");
  tCliente* c = getCliente(cpf);
  if (c != NULL){
    printf("Nome: %s", getNomeCliente(c));
    printf("\nCPF: ");
    for (int i = 0; i < 11; i++) {  
      printf("%i", cpf[i]);
    }
    printf("\nSexo: %c", getSexo(c));
    printf("\nTelefone: %s", getTelefone(c));
    printf("\nE-mail: %s", getEmail(c));
  }else{
      printf("\nCliente Inexistente");
  }
  printf("\n\n1- Voltar");
  printf("\n2- Sair\n");

  int n;

  scanf("%i", &n);

  switch(n){
    case 1:
      menu2();
      break;

    case 2:
      finalizar();
      break;

    default:
     printf("\nOpcao invalida.");
  }
} 

//função criada para caso o usuário escolha a opção 2 no menu1. Ela permite o cadastro de um livro no sistema
void usuario_CadastrarLivro(){
  system("clear");
  int id, ano, qntAutores, n, i;
  char aux_autor[512], aux_editora[128], titulo[128];
  tAutor* autores[30];
  for (i = 0; i < 30; i++) {
    autores[i] = NULL;
  }
  double valor;

  printf("Título: ");
  scanf("\n%[^\n]", titulo);

  printf("ID: ");
  scanf("%d", &id);

  printf("Autores: ");
  scanf("%d", &qntAutores);
  for (i = 0; i < qntAutores; i++) {
    scanf("\n%[^\n]", aux_autor);
    autores[i] = criarAutor(aux_autor);
  }

  printf("Editora: ");
  scanf("\n%[^\n]", aux_editora);
  tEditora* editora = cadastrar_editora(aux_editora);

  printf("Valor: ");
  scanf("%lf", &valor);

  printf("Ano: ");
  scanf("%d", &ano);

  system("clear");
  tLivro* l = getLivro(id);
  if(l != NULL){
    printf("Unidade de livro adicionada!\n\n");
    adicionarUnidades(l, 1);
  } else {
    tLivro *l = cadastrar_livro(id, titulo, autores, editora, valor,ano);
    adicionarLivroFile(l);
    printf("Livro cadastrado com sucesso!\n\n");
  }

  printf ("1- Voltar\n");
  printf ("2- Sair\n");

  while (n!= 2) {
    scanf("%i", &n);
    switch(n){
      case 1:
        menu1();
        break;
      case 2:
        finalizar();
        break;
      default:
        printf("\nOpcao invalida.");
    };
  }
}

void procuraLivro(char titulo[]) {
  int i = 0, n;
  system("clear");
  tLivro* t = getLivroByTitulo(titulo);
  if (t == NULL) {
    printf("Livro inexistente.");
  } else {
    printf("Título: %s", getTitulo(t));
    printf("\nAutores: ");
    i=0;
    tAutor* autor = retorna_autores(t)[i];
    tAutor* aux;
    while (autor != NULL) {
      printf("%s", getNomeAutor(autor));
      i++;
      aux = retorna_autores(t)[i];
      if (aux != NULL) {
        printf(", ");
      }
      autor = aux;
    }
    printf("\nEditora: %s", getNomeEditora(retorna_editora(t)));
    printf("\nValor: %.2lf", getValorLivro(t));
    printf("\nAno: %i", getAnoLivro(t));
    printf("\n\nQuantidade de exemplares: %d", getUnidades(t));
    printf("\nNúmeros de vezes que foi locado: %d", getLocacoesQnt(t));
  }
  printf ("\n\n1- Voltar\n");
  printf ("2- Sair\n");

  scanf("%i", &n);

  while (n!= 2) {
    scanf("%i", &n);

    switch(n){
      case 1:
        menu1();
        break;
      case 2:
        finalizar();
        break;
      default:
        printf("\nOpcao invalida.");
    };
  }
}


void finalizar() {
  printf("Biblioteca finalizada!");
  system("clear");
  deletarAllAutores();
  deletarAllEditoras();
  deletarAllLivros();
  deletarAllClientes();
  deletarAllLocacoes();
  exit(0);
}