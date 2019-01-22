#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	char nome [40];
	int codigo;
	struct tree *next, *back, *down;	
}tree;

struct tree *auxiliar, *raiz, *corrente;

enterData(){
	fflush(stdin);
	printf("Digite o nome:\n");
	scanf("%s",&corrente->nome);
	fflush(stdin);
	printf("Digite o codigo:\n");
	scanf("%d",&corrente->codigo);
}

aloca_Esquerda(tree **Recebe){
	
	while(auxiliar->back != NULL){
		auxiliar = auxiliar->back;
	}
	auxiliar->back = corrente;
	printf("Alocado com sucesso a esquerda da arvore...\n");
	system("pause");
}

aloca_Direita(tree **Recebe){
	while(auxiliar->next != NULL){
		auxiliar = auxiliar->next;
	}
	auxiliar->next = corrente;
	printf("Alocado com sucesso a direita da arvore...\n");
	system("pause");
}

aloca_Abaixo(){
	while(auxiliar->down != NULL){
		auxiliar = auxiliar->down;
	}
	auxiliar = corrente;
	printf("Alocado com sucesso a abaixo da arvore...\n");
	system("pause");
}

inserir(){
  int choose;
  corrente = (tree*)malloc(sizeof(tree));
  corrente->next = NULL;
  corrente->back = NULL;
  corrente->down = NULL;
  
  auxiliar = raiz;
  
  enterData();
  
  if(raiz == NULL){
  	raiz = corrente;
  	auxiliar = corrente;
  }
  else{
  	printf("Digite a opcao desejada\n1 - Alocar a esquerda\n2 - Alocar a direita\n3 - Alocar abaixo\n4 - Sair\n");
  	scanf("%d",&choose);
  	
  	switch(choose){
  	 case 1: aloca_Esquerda(&corrente);
  	 	break;
  	 case 2: aloca_Direita(&corrente);
  		break;
  	 case 3: aloca_Abaixo(&corrente);
  	 	break;
     case 4: exit(1);
     	break;
  	 default:
  	 	printf("Opcao invalida\n");
  	 	break;	
	  }
  }
}

int main(){
	while(1){
		inserir();
	}
	
	return 0;
}
