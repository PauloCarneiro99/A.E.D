#include <stdio.h>
#include <stdlib.h>
#include "matriz_adj.h"
#include "fila_prioridade.h"


void cria_fila(fila *l){
	l->inicio = NULL;
	l->fim = NULL;
}

void insere(fila* l, int v1, int peso){
	NO *novo = malloc(sizeof(NO));
	novo->v1 = v1;
	novo->peso = peso;

	NO *pos = l->inicio;
	if(pos == NULL){
		l->inicio = l->fim = novo;
		novo->prox = NULL;
	}else if(pos->peso > peso){
		novo->prox = pos;
		l->inicio = novo;
	}else{		
		while(pos->prox != NULL){
			if(pos->prox->peso > peso)
				break;
			pos = pos->prox;
		}
		if(pos->prox == NULL){
			novo->prox = NULL;
			l->fim = pos;
		}else{
			novo->prox = pos->prox;
		}
		pos->prox = novo;
	}
}

int empty(fila *l){
	if(l->inicio == NULL)
		return 1;
	return 0;
}

NO* front(fila *l){
	NO* temp = l->inicio;
	return temp;
}

void pop(fila *l){
	NO *p = l->inicio;
	l->inicio = p->prox;
	free(p);
}


void clear(fila *l){
	while(!empty(l))
		pop(l);
}	

void print_fila(fila *l){
	NO *pos = l->inicio;
	while(pos != NULL){
		printf("(%d, %d)\n",pos->v1,pos->peso);
		pos = pos->prox;
	}

}
