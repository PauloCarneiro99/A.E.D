#include <stdio.h>
#include <stdlib.h>

typedef int elem;

typedef struct no
{
	struct no *prox, *ant;
	elem chave;	
}NO;

typedef struct 
{
	NO *ini;
	NO *fim;
}FILA;

void push(FILA *f, elem chave){
	NO *temp = malloc(sizeof(NO));
	temp->chave = chave;
	temp->prox = NULL;
	temp->ant = f->fim;
	if(f->fim != NULL)
		f->fim->prox = temp;
	f->fim = temp;
}

void pop(FILA *f){
	NO *temp = f->ini;
	if(f->ini != NULL){//removendo elemento de uma fila vazia
		f->ini = temp->prox;
		free(temp);
	}
	if(f->ini != NULL)
		f->ini->ant = NULL;
	else{ //a fila esta vazia
		f->fim = NULL;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
} 