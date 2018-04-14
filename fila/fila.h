#ifndef FILA_H
#define FILA_H

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

void cria_fila(FILA *f);
int fila_vazia(FILA* f);
NO* front(FILA f);
void push(FILA *f, elem chave);
void pop(FILA *f);

#endif