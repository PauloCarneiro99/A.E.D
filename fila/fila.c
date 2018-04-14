#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//inserindo o elemento no final da fila, atualiza o ponteiro do fim
void push(FILA *f, elem chave){
	NO *temp = malloc(sizeof(NO));
	temp->chave = chave;
	temp->prox = NULL;
	temp->ant = f->fim;
	if(f->fim != NULL)
		f->fim->prox = temp;
	f->fim = temp;
}

//removendo o primeiro elemento da fila e atualizando os ponteiros e atualizando os ponteiros
void pop(FILA *f){
	NO *temp = f->ini;
	if(f->ini != NULL){
		f->ini = temp->prox;
		free(temp);
	}
	if(f->ini != NULL)
		f->ini->ant = NULL;
	else{ //a fila esta vazia
		f->fim = NULL;
	}
}