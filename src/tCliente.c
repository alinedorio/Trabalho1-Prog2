//pasta criada para organizar todas as funções relacionadas aos clientes da biblioteca.
#include "../headers/tCliente.h"
//struct que apresenta as informações dos clientes.
struct tcliente {
  char nome[128];
  int cpf[11];
  char sexo;
  char telefone[128];
  char email[128];
};

tCliente** allClientes;
int allClientes_size;
int clientesCounter = 0;
//função que chama todos os clientes.
tCliente** getAllClientes() {
  return allClientes;
}
//cria uma estrutura em formato de vetor com todos os clientes.
void inicializarClientes(int size) {
  if (allClientes == NULL) {
    allClientes = realloc(allClientes, size*sizeof(struct tcliente));
    for (int i = 0; i < size; i++) {
      allClientes[i] = NULL;
    }
  }
  allClientes = realloc(allClientes, size*sizeof(struct tcliente));
  allClientes_size = size;
}
//funcao que deleta um determinado cliente do sistema.
void deletarCliente(tCliente* c) {
  free(c);
  c = NULL;
}
//funcao que deleta 
void deletarClienteList(tCliente** clientes) {
  int i = 0;
  tCliente *t = clientes[i];
  tCliente *aux = clientes[i+1];
  while(t != NULL){
    deletarCliente(t);
    if (i == (clientesCounter-1)) {
      break;
    }
    aux = clientes[i+1];
    t = aux;
    i++;
  }
  free(clientes);
}

void deletarAllClientes() {
  deletarClienteList(allClientes);
}

//função que cadatra um cliente.
tCliente* cadastrar_cliente(char nome[], int cpf[], char sexo, char telefone[], char email[]){
  if (clientesCounter == allClientes_size) {
    inicializarClientes(clientesCounter + 1);
  }

  tCliente* cliente = malloc(sizeof(struct tcliente));
  strcpy(cliente->nome, nome);
  for (int i = 0; i < 11; i++) {
    cliente->cpf[i] = cpf[i];
  }
  cliente->sexo = sexo;
  strcpy(cliente->telefone, telefone);
  strcpy(cliente->email, email);
  allClientes[clientesCounter] = cliente;
  clientesCounter++;
  return cliente;
}

void adicionarClienteFile(tCliente* c) {
  FILE *temp;
  int i = 0;
  char aux_cpf[13] = "";
  temp = fopen("./db/clientes.csv", "a");
  for (i = 0; i < 11; i++) {
    int digit = c->cpf[i];
    aux_cpf[i] = digit + '0';
  }
  fprintf(temp, "%s,%s,%c,%s,%s\n",c->nome, aux_cpf, c->sexo, c->telefone, c->email);
  fclose(temp);
}

tCliente* getCliente(int cpf[]){
  tCliente* c = NULL;
  for(int i = 0; i < clientesCounter; i++){
    if (allClientes[i] != NULL) {
      for (int j = 0; j < 11; j++) {
        if (cpf[j] != allClientes[i]->cpf[j]) {
          break;
        } else if (j == 10) {
          c = allClientes[i];
        }
      }
    }
  }
  return c;
}
//função que retorna apenas o nome do cliente ao receber todas as suas informações por meio da struct tCliente.
char* getNomeCliente(tCliente* t) {
  return t->nome;
}
//função que retorna apenas o cpf do cliente ao receber todas as suas informações por meio da struct tCliente.
int* getCPF(tCliente* t) {
  return t->cpf;
}
//função que retorna apenas o sexo do cliente ao receber todas as suas informações por meio da struct tCliente.
char getSexo(tCliente* t) {
  return t->sexo;
}
//função que retorna apenas o telefone do cliente ao receber todas as suas informações por meio da struct tCliente.
char* getTelefone(tCliente* t) {
  return t->telefone;
}
//função que retorna apenas o e-mail do cliente ao receber todas as suas informações por meio da struct tCliente.
char* getEmail(tCliente* t) {
  return t->email;
}

