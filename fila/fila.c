#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


//setando os ponteiros da fila para NULL
void cria_fila(FILA *f){
	f->ini =NULL;
	f->fim = NULL;
}

//retorna 1 caso a fila esteja vazia e zero caso o contrario
int fila_vazia(FILA* f){
	if(f->ini == NULL)
		return 1;
	return 0;
}


//retorna o primeiro elemento na fila
NO* front(FILA f){
	return f.ini;
}

//inserindo o elemento no final da fila, atualiza o ponteiro do fim
void push(FILA *f, elem chave){
	NO *temp = malloc(sizeof(NO));
	temp->chave = chave;
	temp->prox = NULL;
	temp->ant = f->fim;
	if(f->fim != NULL)
		f->fim->prox = temp;
	else //Fila vazia, atualiza o ponteiro do inicio da fila
		f->ini = temp;
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

//remove todos os elementos da fila
void clear(FILA *f){
	while(!fila_vazia(f)){
		pop(f);
	}
}