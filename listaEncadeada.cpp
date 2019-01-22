#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no
{
  int codigo;
  char nome[10];
  struct no * next;
}no;

int elemento;

struct no * corrente, * auxiliar, *inicio, *aux2;

  int Enterdata()
  {
  printf("Entre com o codigo: ");
  scanf("%d", &corrente -> codigo);
  fflush(stdin);
  printf("Entre com o nome: ");
  scanf("%s", &corrente -> nome);
  fflush(stdin);
  }

int inserir (no **Lista)
{
  int achou;
  corrente = (no*)malloc(sizeof(no));
  Enterdata();
  auxiliar = inicio;
  achou = 0;
  if (inicio == NULL)
  {
  auxiliar = corrente;
  inicio = corrente;
  corrente->next = NULL;
  achou = 1;
  printf("Estabelecendo o 1 no da lista...");
  system("pause");
  }
  else
  {
  if(corrente->codigo < auxiliar->codigo){
  corrente->next = auxiliar;
  inicio = corrente;
  achou = 1;
  printf("Elemento precede o primeiro elemento na lista...");
  system("pause");
  }
  else{
  aux2 = auxiliar->next;
  while(aux2 != NULL){
  if(corrente->codigo > auxiliar->codigo && corrente->codigo < aux2->codigo){
  auxiliar->next = corrente;
  corrente->next=aux2;
  achou = 1;
  printf("Elemento inserido no meio da lista...");
  system("pause");
  break;
  }

  else{
  printf("Nao");
  system("pause");
  auxiliar = auxiliar->next;
  aux2 = aux2->next;
  }
  }
  }
  }
  if(achou==0 && corrente->codigo > auxiliar->codigo){
  auxiliar->next = corrente;
  corrente->next = NULL;
  achou = 1;
  printf("Inserido no final da lista");
  system("pause");
  }
}

int exibir (no **Lista)
{
  if (inicio == NULL)
  {
  printf("Lista Vazia...");
  system("pause");
  }

  auxiliar = inicio;

  while (auxiliar != NULL)
  {

  printf("%d \n", auxiliar -> codigo);
  printf("%s \n", auxiliar -> nome);
  auxiliar = auxiliar -> next;
  }
  system ("pause");
}

int Pesquisa (no **Lista)
{
  int achou, xcod;

if (inicio == NULL)
{
printf("Lista vazia...");
system("pause");
}

else {
auxiliar = inicio;
achou = 0;
printf("Entre com o codigo a ser Pesquisado...");
scanf("%d", &xcod);
}

while (auxiliar != NULL)
{
if (auxiliar -> codigo == xcod)
{
printf("%s \n", auxiliar -> nome);
system("pause");
achou = 1;
break;
}

else {
auxiliar = auxiliar -> next;
}
}

if (achou == 0)
{
printf("Registro nao encontrado...");
system("pause");
}
}

int remover(no **lista){
printf("Digite o codigo a ser removido\n");
scanf("%d",&elemento);
auxiliar = inicio;
if(inicio->codigo == elemento){

  inicio = inicio ->next;
  free(auxiliar);
  printf("Elemento excluido com exito");
}
else{
 corrente=auxiliar->next;
 while(corrente != NULL){
  if(corrente->codigo == elemento){
  auxiliar->next = corrente->next;
  free(corrente);
  printf("Elemento excluido com exito");
  break;
  }
  else{
  auxiliar=auxiliar->next;
  corrente=corrente->next;
 }
}

}
}

int main ()
{
  int i;
  inicio = NULL;
  auxiliar = NULL;
  corrente = NULL;
  int op;
  char finaliza;

  do
  {
  system("cls");
  printf("[1] incluir\n");
  printf("[2] consultar\n");
  printf("[3] exibir todos os registros\n");
  printf("[4] remover registro\n");
  printf("[5] sair\n");
  printf("Escolha a opcao: ");
  scanf("%d", &op);

  switch (op)
  {
  case 1: {
  inserir(&inicio);
  break;
  }
  case 2: {
  Pesquisa(&inicio);
  break;
  }
  case 3: {
  exibir(&inicio);
  break;
  }
  //case 4: {
  // break; }
  case 4: {
  remover(&inicio);
  break;
  }

  }
  }
  while(op != 0);
}

