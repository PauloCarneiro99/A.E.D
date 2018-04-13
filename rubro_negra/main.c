#include <stdio.h>
#include <stdlib.h>
#include "rubro_negra.h"

int main(int argc, char const *argv[])
{
	int N; //numero de operacoes
	int i=0;
	int operacao, x;
	NO* aux;
	NO* A; //no raiz
	scanf("%d", &N);
	cria_arvore(&A); //inicializando a arvore como vazia
	while(i < N){
		scanf("%d", &operacao);
		switch(operacao){
			case(1): //insercao
				scanf("%d", &x);
				insere(&A, x);
			break;
			case(2): //sucessor
				scanf("%d", &x);
				aux = sucessor(A, x);
				if(aux == NULL)
					printf("erro\n");
				else
					printf("%d\n",aux->chave);
			break;
			case(3): //predecessor
				scanf("%d", &x);
				aux = predecessor(A, x);
				if(aux == NULL)
					printf("erro\n");
				else
					printf("%d\n",aux->chave);
			break;
			case(4): //maximo
				aux = maximo(A);
				if(aux == NULL) //arvore vazia
					printf("erro\n");
				else
					printf("%d\n", aux->chave);
			break;
			case(5): //minimo
				aux = minimo(A);
				if(aux == NULL)//arvore vazia 
					printf("erro\n");
				else
					printf("%d\n", aux->chave);
			break;
			case(6): //impressao pre-ordem
				preOrdem(A);
				printf("\n");
			break;
			case(7): //impressao em-ordem
				emOrdem(A);
				printf("\n");
			break;
			case(8): //impressao pos-ordem
				posOrdem(A);
				printf("\n");
			break;
			default://operacao invalida
				printf("erro\n");
			break;
		}
		i++;
	}
	apaga_arvore(&A); //apagando a arvore
	return 0;
} 