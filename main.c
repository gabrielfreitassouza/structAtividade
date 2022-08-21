#include <stdio.h>

#include <stdlib.h>

#include "colors.h" // incluir funções para o tema e definições de cores fundo/texto

//Variaveis Globais
int contNumberC = 1; // contador de contas criadas
int amzContaDelete[16]; // armazenar a posição das contas deletadas ( Obs.: Recomendado ter mesmo tamanho de scruct conta)
int tema = 0; // definir o tema do console: 0 - Escuro, 1 - Claro
struct conta {
  char * titular;
  char * cpf;
  int id;
  float saldo;
  float limite;
}
c[16]; // Iniciar o struct conta com nome "c" com espaço de 16 pocições 
size_t tam_c = sizeof(c) / sizeof(c[1]); // Armazenar o tamanho do vetor scruct c

//Prototype
void criarConta();
void menu();
int verificarId(int ids); // verificar de ID definido já existe
void consultaSaldo();
void deletaContaMenorSaldo();
int verificarPos(); // verificar se tem alguma conta deletada 
void amzContaDelZero(); // inicializar o vetor amzContaDelete com 0 para evitar erros
int compararStrings(char str1[], char str2[]); // função usada para fazer buscar pelo CPF 

int main() {
  srand(time(NULL)); // Define o ponto de partida para gerar numero aletorio
  amzContaDelZero();
  menu();
  return 0;
}

//Menu
void menu() {
  int menuOpcao = -1;
  while (menuOpcao != 4) {
    temas(1);
    printf("|                MENU               |\n");
    printf("=====================================\n");
    printf("| 1 - Criar Conta                   |\n");
    printf("| 2 - Consultar o Saldo             |\n");
    printf("| 3 - Deletar conta com menor saldo |\n");
    printf("| 4 - Finalizar o programa          |\n");
    printf("| 0 - tema[%s]                  |\n", ((tema == 0) ? "ESCURO" : "CLARO "));
    // Operador Ternário if else. Exemplo: condição ? valor_se_verdadeiro : valor_se_falso
    printf("=====================================\n");
    temas(2);
    printf("=> ");
    scanf("%d", & menuOpcao); {
      (menuOpcao == 1) ?
      criarConta(): (menuOpcao == 2) ?
        consultaSaldo() : (menuOpcao == 3) ?
        deletaContaMenorSaldo() : (menuOpcao == 4) ?
        (limpar(), printf("Finalizando...")) : (menuOpcao == 0) ? ((tema == 0) ? (tema = 1) : (tema = 0)) :
        (printf("Opcao invalida!"), espera());
    }
  }
}
//Criar Conta
void criarConta() {
  temas(1);
  int resultado = -1; // Armazenar se o ID já existe 
  int posC; // Posição onde o nova conta vai ser armazenada
  posC = verificarPos();
  printf("|              CRIAR CONTA            |\n");
  printf("=======================================\n");
  while (resultado == -1) {
    c[posC].id = rand() % (tam_c * 4 + tam_c);
    resultado = verificarId(c[posC].id);
  } // Gerar um ID valido
  printf("ID: %d\n", c[posC].id);
  printf("Digite o nome do titular: ", fflush(stdin)); // fflush limpar de saída
  c[posC].titular = gets(malloc(96)); //gets() armazenar o texto na variavel. 
  //malloc() é usado para defini o tamanho maximo do texto
  printf("Digite o cpf : ", fflush(stdin));
  c[posC].cpf = gets(malloc(16));
  printf("Digite o saldo da conta: ");
  scanf("%f", & c[posC].saldo);
  c[posC].limite = rand() % (int)(c[posC].saldo);
  printf("Limite: %.2f", c[posC].limite);
  printf("\n=======================================\n");
  if (posC == contNumberC) {
    int pos = 0, resultadoV = 0;
    for (pos; pos < sizeof(amzContaDelete) / sizeof(amzContaDelete[0]); pos++) {
      if (amzContaDelete[pos] > 0) {
        resultadoV++;
        break;
      }
    }
    if (resultadoV == 0) {
      ++contNumberC;
    }
  } // verificar se tem alguma conta deletada e caso não tenha aumenta o valor de contado de contas(contNumberC)
  espera();
}

int verificarId(int ids) {
  int i = 1;
  for (i; i <= contNumberC; i++) {
    if (ids == c[1].id && i != contNumberC && ids == 0) {
      ids = -1;
      return ids;
    }
  }
  ids = 0;
  return ids;
}

void consultaSaldo() {
  int j = 1, opcao = -1, tempID = 0;
  char * tempCPF;
  temas(1);
  printf("|          CONSULTAR O SALDO         |\n");
  printf("======================================\n");
  printf("| 1 - ID                             |\n");
  printf("| 2 - CPF                            |\n");
  printf("\n====================================\n");
  temas(2);
  printf("=> ");
  scanf("%d", & opcao);
  switch (opcao) {
  case 1:
    if (contNumberC > 1) {
      temas(3);
      printf("\nDigite o ID : ");
      temas(2);
      scanf("%d", & tempID);
      for (j; j <= contNumberC; j++) { // verificar  se ID existe para mostrar o saldo
        if (c[j].id == tempID) {
          printf("Titular: %s\n CPF: %s\n Saldo : %.2f\n Limite: %.2f\n", c[j].titular, c[j].cpf, c[j].saldo, c[j].limite);
          espera();
          return;
        }
      }
      color(RED);
      printf("Nenhuma conta encontrada");
      espera();
    } else {
      color(RED);
      printf("Nenhuma conta cadastrada");
      espera();
    }
    break;
  case 2:
    if (contNumberC > 1) {
      temas(3);
      printf("\nDigite o CPF : ");
      temas(2);
      fflush(stdin);
      tempCPF = gets(malloc(16));
      for (j; j < contNumberC; j++) { // verificar se o CPF existe para retonar o saldo
        if (compararStrings(tempCPF, c[j].cpf) == 0) {
          printf(" ID: %d\n Titular: %s\n Saldo : %.2f\n Limite: %.2f\n", c[j].id, c[j].titular, c[j].saldo, c[j].limite);
          espera();
          return;
        }
      }
      color(RED);
      printf("Nenhuma conta encontrada");
      espera();
    } else {
      color(RED);
      printf("Nenhuma conta cadastrada");
      espera();
    }
    break;
  default:
    printf("opcao invalida !");
    espera();
    consultaSaldo();
    break;
    temas(3);
    printf("\n=====================================\n");
    espera();
  }
}

void deletaContaMenorSaldo() {
  temas(1);
  printf("|              CONTA DELETADA           |\n");
  printf("=======================================\n");
  if (contNumberC == 2) { // verificar se uma já foi criada e se tem mais de uma para deleta conta com menor saldo
    int pos = 0;
    printf("ID: %d\nTitular: %s\nSaldo : %.2f\n", c[1].id, c[1].titular, c[1].saldo);
    for (pos; pos < sizeof(c[1].cpf) / sizeof(c[1].cpf[0]); pos++) { // limpar o CPF
      c[1].cpf[pos] = '\0';
    }
    pos = 0;
    for (pos; pos < sizeof(c[1].titular) / sizeof(c[1].titular[0]); pos++) { // limpar o nome do titular
      c[1].titular[pos] = '\0';
    }
    c[1].id = 0;
    c[1].limite = 0;
    c[1].saldo = 0;
    pos = 0;
    for (pos; pos < sizeof(amzContaDelete) / sizeof(amzContaDelete[0]); pos++) { // armazenar a posição da conta deletada
      if (amzContaDelete[pos] == 0) {
        amzContaDelete[pos] = 1;
        break;
      }
    }

  } else if (contNumberC > 2) {
    int contaMenorSaldo = 1, pos = 2;
    for (pos; pos < contNumberC; pos++) {
      // percorrer o saldo das contas já cadastrada e armazenar a pocição da conta com menor saldo
      if (c[pos].saldo < c[contaMenorSaldo].saldo) {
        contaMenorSaldo = pos;
      }
    }
    pos = 0;
    printf("ID: %d\nTitular: %s\nSaldo : %.2f\n", c[contaMenorSaldo].id, c[contaMenorSaldo].titular, c[contaMenorSaldo].saldo);
    for (pos; pos < sizeof(c[contaMenorSaldo].cpf) / sizeof(c[contaMenorSaldo].cpf[0]); pos++) {
      c[contaMenorSaldo].cpf[pos] = '\0';
    }
    pos = 0;
    for (pos; pos < sizeof(c[contaMenorSaldo].titular) / sizeof(c[contaMenorSaldo].titular[0]); pos++) {
      c[contaMenorSaldo].titular[pos] = '\0';
    }
    c[contaMenorSaldo].id = 0;
    c[contaMenorSaldo].limite = 0;
    c[contaMenorSaldo].saldo = 0;
    pos = 0;
    for (pos; pos < sizeof(amzContaDelete) / sizeof(amzContaDelete[0]); pos++) {
      if (amzContaDelete[pos] == 0) {
        amzContaDelete[pos] = contaMenorSaldo;
        break;
      }
    }

  } else {
    color(RED);
    printf("Nenhuma conta cadastrada");
  }
  temas(3);
  printf("\n=======================================\n");
  espera();
}

void amzContaDelZero() {
  int z = 0;
  for (z; z < sizeof(amzContaDelete) / sizeof(amzContaDelete[0]); z++) {
    amzContaDelete[z] = 0;
  }
}

int verificarPos() {
  int pos = 0;
  for (pos; pos < sizeof(amzContaDelete) / sizeof(amzContaDelete[0]); pos++) {
    if (amzContaDelete[pos] > 0) {
      return amzContaDelete[pos];
    }
  }
  return contNumberC;
}

int compararStrings(char s1[], char s2[]) {
  int i;
  for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) // teste do for fica falso quando uma das strings chegar ao fim, ou pelo return
  {
    if (s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
  }
  //strings iguais
  return 0;
}
