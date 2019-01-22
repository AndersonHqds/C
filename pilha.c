#include <stdio.h>
#include <stdlib.h>

int contRegistro;

typedef struct no{
char nome[40];
int codigo;
struct no *back, *next;
	
}no;

struct no *auxiliar, *corrente, *topo;

void enterData(){
	printf("Digite o codigo: \n");
	scanf("%d",&topo->codigo);
	printf("Digite o nome: \n");
	scanf("%s",&topo->nome);
}

void push(no **Pilha){
if(topo == NULL){
	topo = (no*)malloc(sizeof(no));
	topo->back = NULL;
	topo->next = NULL;
	auxiliar = topo;
	contRegistro++;
	enterData();
}	
else{
	if(contRegistro > 10){
		printf("StackOverflow...\n");
		system("pause");
	}
	else{
	topo = (no*)malloc(sizeof(no));
	topo->back = auxiliar;
	auxiliar->next = topo;
	auxiliar = topo;
	topo->next = NULL;
	contRegistro++;
	enterData();
	}
}
	
}

void pop(no **Pilha){
	if(topo==NULL){
		printf("Pilha Vazia...\n");
		system("pause");
	}
	else{
		printf("Codigo -> %d\nNome -> %s\n",topo->codigo,topo->nome);
	}
}

void top(no **Pilha){
	if(topo == NULL){
		printf("StackUnderFlow...\n");
		system("pause");
	}
	if(contRegistro == 1){
		auxiliar = topo;
		topo->back = NULL;
		topo->next = NULL;
		free(auxiliar);
		auxiliar = NULL;
		topo = NULL;
		printf("Elemento excluido com exito\n");
	}
	else{
		auxiliar = topo;
		topo = topo->back;
		topo->next = NULL;
		free(auxiliar);
		printf("1 Elemento excluido da pilha\n");
		contRegistro--;
	}
}

int main (){
	int opcao;
	while(1){
	printf("Digite a opcao desejada:\n1 - Push\n2 - Pop\n3 - Top\n");
	scanf("%d",&opcao);
	switch(opcao){
		case 1: push(&topo);
		break;
		case 2: pop(&topo);
		break;
		case 3: top(&topo);
		break;
		default:
			printf("Opcao invalida\n");
	}
		
}
	
	return 0;
}
